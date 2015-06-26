#ifndef ACTIONMAP_H
#define ACTIONMAP_H

#include <map>
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

struct FuncArgs
{
    HANDLE hEventThreadWrite;
    HANDLE hLogThreadRead;
    HANDLE hWaitCommand;
    HANDLE hReadCommandEventThread;
    HANDLE hReadCommandLoggerThread;
    HANDLE hLogThreadWriteCommand;
};

typedef void(*Function)(FuncArgs args);
typedef map<string, Function> ActionMap;


#endif /*ACTIONMAP_H*/