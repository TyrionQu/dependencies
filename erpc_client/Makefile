# This Makefile will build ERPC client DLL.

# Object files to create for the executable
DLL_OBJS = obj/c_StepProfilerInterface_client.o obj/StepProfilerInterface_interface.o lib/liberpc.a

# Warnings to be raised by the C compiler
WARNS = -Wall

# Names of tools to use when building
CC = gcc
DLL = erpc_client.dll

# Compiler flags
EXE_CFLAGS = -O2 -std=c99 ${WARNS} -Iinclude
DLL_CFLAGS = ${EXE_CFLAGS} -D ERPC_CLIENT_EXPORTS

# Linker flags
DLL_LDFLAGS = -shared -s -Wl,--subsystem,windows,--out-implib,lib/liberpc_client.a

.PHONY: all clean

# Build DLL and executable by default
all: bin/${DLL}

# Delete all build output
clean:
	if exist bin\* del /q bin\*
	if exist lib\* del /q lib\*
	if exist obj\* del /q obj\*

# Create build output directories if they don't exist
bin lib obj:
	@if not exist "$@" mkdir "$@"

# Compile object files for DLL
obj/c_StepProfilerInterface_client.o: client/c_StepProfilerInterface_client.c client/c_StepProfilerInterface_client.h | obj
	${CC} ${DLL_CFLAGS} -c "$<" -o "$@"

# Build the DLL
bin/${DLL}: ${DLL_OBJS} | bin lib
	${CC} -o "$@" ${DLL_OBJS} ${DLL_LDFLAGS}

