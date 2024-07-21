// tcpserver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>



#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
#include <time.h>
#include <random>

#pragma comment(lib, "ws2_32.lib")

#define CTRL_PORT 12345
#define DATA_PORT 1003
#define BUFFER_SIZE 806 // 100 sets of 2 floats, each float is 4 bytes
#define DATA_SET_SIZE 8 // 2 floats of 4 bytes each

typedef struct {
    float data1;
    float data2;
} Data;

volatile Data circularBuffer[100];
volatile int writeIndex = 0;
volatile int readIndex = 0;
HANDLE dataMutex;
static bool g_bACK = false;

DWORD WINAPI GenerateData(LPVOID lpParam) {
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_real_distribution<> dis(1000, 5000);
    while (1) {
        WaitForSingleObject(dataMutex, INFINITE);
        circularBuffer[writeIndex].data1 = (float)(dis(gen));
        circularBuffer[writeIndex].data2 = -(float)(dis(gen));
        writeIndex = (writeIndex + 1) % 100;
        ReleaseMutex(dataMutex);
        Sleep(1); // Generate data every 1 millisecond
    }
    return 0;
}

DWORD WINAPI HandleCtrlClient(LPVOID lpParam) {
    SOCKET clientSocket = *(SOCKET*)lpParam;
    char buffer[BUFFER_SIZE];
    int result;

    while (1) {
        result = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (result > 0) {
            buffer[result] = '\0';
            printf("Received control command: %s\n", buffer);

            // Process control commands here
            const char* response = "Control command received";
            send(clientSocket, response, strlen(response), 0);
        }
        else if (result == 0) {
            printf("Control connection closed by client\n");
            break;
        }
        else {
            printf("Control recv failed. Error Code: %d\n", WSAGetLastError());
            break;
        }
    }

    closesocket(clientSocket);
    return 0;
}

DWORD WINAPI HandleDataClient(LPVOID lpParam) {
    SOCKET clientSocket = *(SOCKET*)lpParam;
    char buffer[BUFFER_SIZE];
    auto p = buffer;

    p[0] = 0x5a;
    p[1] = 0x0;
    p[2] = 0x6e;
    p[3] = 0x03;
    p[4] = 0x20;
    p[5] = 0x0;

    auto nPos = 6;
    while (1) {
        WaitForSingleObject(dataMutex, INFINITE);
        readIndex = (readIndex + 1) % 100;

        for (int i = 0; i < 100; ++i) {
            memcpy(p + nPos, (const void*) & circularBuffer[readIndex], DATA_SET_SIZE);
            readIndex = (readIndex + 1) % 100;
            nPos += DATA_SET_SIZE;
        }
        nPos = 6;
        ReleaseMutex(dataMutex);

        send(clientSocket, buffer, BUFFER_SIZE, 0);
        if (g_bACK)
        {
            char ack[4] = { 0 };
            int result = recv(clientSocket, ack, sizeof(ack) - 1, 0);
            if (result <= 0)
            {
                printf("Connection abnormal with result %d", result);
                closesocket(clientSocket);
                break;
            }
            else
                printf("Receive from client: %s\n", ack);
        }
        Sleep(100); // Send data every 100 milliseconds
    }
    closesocket(clientSocket);
    return 0;
}

DWORD WINAPI CtrlServer(LPVOID lpParam) {
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in clientAddr;
    int clientAddrLen = sizeof(clientAddr);

    serverSocket = *(SOCKET*)lpParam;

    while (1) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket == INVALID_SOCKET) {
            printf("Control accept failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }

        printf("Control client connected from 0x%p\n", (void*)clientSocket);

        HANDLE controlThread = CreateThread(NULL, 0, HandleCtrlClient, &clientSocket, 0, NULL);
        if (controlThread == NULL) {
            printf("Control CreateThread failed. Error Code: %d\n", GetLastError());
            closesocket(clientSocket);
        }
        else {
            CloseHandle(controlThread);
        }
    }

    return 0;
}

DWORD WINAPI DataServer(LPVOID lpParam) {
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in clientAddr;
    int clientAddrLen = sizeof(clientAddr);

    serverSocket = *(SOCKET*)lpParam;

    while (1) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket == INVALID_SOCKET) {
            printf("Data accept failed. Error Code: %d\n", WSAGetLastError());
            continue;
        }

        printf("Data client connected from 0x%p\n", (void *)clientSocket);

        HANDLE dataThread = CreateThread(NULL, 0, HandleDataClient, &clientSocket, 0, NULL);
        if (dataThread == NULL) {
            printf("Data CreateThread failed. Error Code: %d\n", GetLastError());
            closesocket(clientSocket);
        }
        else {
            CloseHandle(dataThread);
        }
    }

    return 0;
}

int main(int argc, const char **argv)
{
    if (argc == 2)
    {
        int nACK = atoi(argv[1]);
        g_bACK = (nACK == 1) ? true : false;
    }
    WSADATA wsaData;

    // Create threads for data generation and client handling
    HANDLE generateDataThread = CreateThread(NULL, 0, GenerateData, NULL, 0, NULL);
    if (generateDataThread == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        CloseHandle(dataMutex);
        WSACleanup();
        return 1;
    }

    dataMutex = CreateMutex(NULL, FALSE, NULL);
    if (dataMutex == NULL) {
        printf("CreateMutex failed. Error code: %d\n", GetLastError());
        WSACleanup();
        return 1;
    }

    SOCKET ctrlSocket, dataSocket;
    struct sockaddr_in ctrlAddr, dataAddr;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Create a server socket
    if ((ctrlSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Prepare the sockaddr_in structure
    ctrlAddr.sin_family = AF_INET;
    ctrlAddr.sin_addr.s_addr = INADDR_ANY;
    ctrlAddr.sin_port = htons(CTRL_PORT);

    // Bind the socket
    if (bind(ctrlSocket, (struct sockaddr*)&ctrlAddr, sizeof(ctrlAddr)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(ctrlSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(ctrlSocket, 3) == SOCKET_ERROR)
    {
        printf("Control listen failed. Error Code: %d\n", WSAGetLastError());
        closesocket(ctrlSocket);
        WSACleanup();
        return 1;
    }
    printf("Control server listening on port %d\n", CTRL_PORT);

    // Create data socket
    dataSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (dataSocket == INVALID_SOCKET) {
        printf("Data socket creation failed. Error Code: %d\n", WSAGetLastError());
        closesocket(ctrlSocket);
        WSACleanup();
        return 1;
    }

    // Prepare data sockaddr_in structure
    dataAddr.sin_family = AF_INET;
    dataAddr.sin_addr.s_addr = INADDR_ANY;
    dataAddr.sin_port = htons(DATA_PORT);

    // Bind data socket
    if (bind(dataSocket, (struct sockaddr*)&dataAddr, sizeof(dataAddr)) == SOCKET_ERROR) {
        printf("Data bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(ctrlSocket);
        closesocket(dataSocket);
        WSACleanup();
        return 1;
    }

    // Listen on data socket
    if (listen(dataSocket, 3) == SOCKET_ERROR) {
        printf("Data listen failed. Error Code: %d\n", WSAGetLastError());
        closesocket(ctrlSocket);
        closesocket(dataSocket);
        WSACleanup();
        return 1;
    }
    printf("Data server listening on port %d\n", DATA_PORT);

    // Create control server thread
    HANDLE ctrlServerThread = CreateThread(NULL, 0, CtrlServer, &ctrlSocket, 0, NULL);
    if (ctrlServerThread == NULL) {
        printf("Control server thread creation failed. Error Code: %d\n", GetLastError());
        closesocket(ctrlSocket);
        closesocket(dataSocket);
        WSACleanup();
        return 1;
    }

    // Create data server thread
    HANDLE dataServerThread = CreateThread(NULL, 0, DataServer, &dataSocket, 0, NULL);
    if (dataServerThread == NULL) {
        printf("Data server thread creation failed. Error Code: %d\n", GetLastError());
        closesocket(ctrlSocket);
        closesocket(dataSocket);
        WSACleanup();
        return 1;
    }

    // Wait for both threads to complete
    WaitForSingleObject(ctrlServerThread, INFINITE);
    WaitForSingleObject(dataServerThread, INFINITE);

    // Cleanup
    CloseHandle(ctrlServerThread);
    CloseHandle(dataServerThread);
    closesocket(ctrlSocket);
    closesocket(dataSocket);
    CloseHandle(dataMutex);
    WSACleanup();

    return 0;
}
