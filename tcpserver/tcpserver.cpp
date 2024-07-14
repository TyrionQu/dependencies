// tcpserver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>



#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
#include <time.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 12345
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

DWORD WINAPI GenerateData(LPVOID lpParam) {
    while (1) {
        WaitForSingleObject(dataMutex, INFINITE);
        circularBuffer[writeIndex].data1 = (float)rand() / RAND_MAX;
        circularBuffer[writeIndex].data2 = (float)rand() / RAND_MAX;
        writeIndex = (writeIndex + 1) % 100;
        ReleaseMutex(dataMutex);
        Sleep(1); // Generate data every 1 millisecond
    }
    return 0;
}

DWORD WINAPI HandleClient(LPVOID lpParam) {
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
        Sleep(100); // Send data every 100 milliseconds
    }
    return 0;
}

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int clientAddrLen = sizeof(clientAddr);

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed. Error Code: %d\n", WSAGetLastError());
        return 1;
    }

    // Create a server socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket. Error Code: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Prepare the sockaddr_in structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);


    // Create threads for data generation and client handling
    HANDLE generateDataThread = CreateThread(NULL, 0, GenerateData, NULL, 0, NULL);
    if (generateDataThread == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        CloseHandle(dataMutex);
        WSACleanup();
        return 1;
    }

    // Bind the socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("Bind failed. Error Code: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    listen(serverSocket, 3);
    printf("Server listening on port %d\n", PORT);

    // Wait for a client to connect
    if ((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen)) == INVALID_SOCKET) {
        printf("Accept failed. Error Code: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    printf("Client connected\n");

    // Create a mutex for data synchronization
    dataMutex = CreateMutex(NULL, FALSE, NULL);
    if (dataMutex == NULL) {
        printf("CreateMutex error: %d\n", GetLastError());
        closesocket(clientSocket);
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    HANDLE clientThread = CreateThread(NULL, 0, HandleClient, &clientSocket, 0, NULL);
    if (clientThread == NULL) {
        printf("CreateThread error: %d\n", GetLastError());
        CloseHandle(generateDataThread);
        CloseHandle(dataMutex);
        closesocket(clientSocket);
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Wait for the threads to finish (they won't in this example)
    WaitForSingleObject(generateDataThread, INFINITE);
    WaitForSingleObject(clientThread, INFINITE);

    // Clean up
    CloseHandle(generateDataThread);
    CloseHandle(clientThread);
    CloseHandle(dataMutex);
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
