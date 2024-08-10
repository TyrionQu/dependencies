@echo off
set PATH=%PATH%;D:\mingw64\bin
if "%1" == "" (
echo %0: build library
mingw32-make.exe
) else (
echo %0 %1: delete all binaries
mingw32-make.exe clean
)