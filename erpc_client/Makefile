# This Makefile will build ERPC client DLL.
BIN_DIR = bin
LIB_DIR = lib
OBJ_DIR = obj
SRC_DIR = client
INC_DIR = include/erpc

# Object files to create for the executable
DLL_OBJS = ${OBJ_DIR}/c_StepProfilerInterface_client.o ${OBJ_DIR}/StepProfilerInterface_client.o ${OBJ_DIR}/StepProfilerInterface_interface.o ${LIB_DIR}/liberpc.a

# Warnings to be raised by the C compiler
WARNS = -Wall

# Names of tools to use when building
CC = gcc
DLL = erpc_client.dll

# Compiler flags
EXE_CFLAGS = -O2 ${WARNS} -I${INC_DIR}
DLL_CFLAGS = ${EXE_CFLAGS} -D ERPC_CLIENT_EXPORTS

# Linker flags
DLL_LDFLAGS = -shared -s -Wl,--subsystem,windows,--out-implib,${LIB_DIR}/liberpc_client.a -lstdc++ -lpthread -lws2_32

.PHONY: all clean

# Build DLL and executable by default
all: ${BIN_DIR}/${DLL}

# Delete all build output
clean:
	if exist bin\* del /q bin\*
	if exist lib\* del /q lib\liberpc_client.a
	if exist obj\* del /q obj\*

# Create build output directories if they don't exist
 ${BIN_DIR}  ${OBJ_DIR}:
	@if not exist "$@" mkdir "$@"

# Compile object files for DLL
${OBJ_DIR}/c_StepProfilerInterface_client.o: ${SRC_DIR}/c_StepProfilerInterface_client.cpp ${SRC_DIR}/c_StepProfilerInterface_client.h | ${OBJ_DIR}
	${CC} ${DLL_CFLAGS} -c "$<" -o "$@"
${OBJ_DIR}/StepProfilerInterface_client.o: ${SRC_DIR}/StepProfilerInterface_client.cpp ${SRC_DIR}/StepProfilerInterface_client.hpp | ${OBJ_DIR}
	${CC} ${DLL_CFLAGS} -c "$<" -o "$@"
${OBJ_DIR}/StepProfilerInterface_interface.o: ${SRC_DIR}/StepProfilerInterface_interface.cpp ${SRC_DIR}/StepProfilerInterface_interface.hpp | ${OBJ_DIR}
	${CC} ${DLL_CFLAGS} -c "$<" -o "$@"

# Build the DLL
${BIN_DIR}/${DLL}: ${DLL_OBJS} | ${BIN_DIR} ${LIB_DIR}
	${CC} -o "$@" ${DLL_OBJS} ${DLL_LDFLAGS}

