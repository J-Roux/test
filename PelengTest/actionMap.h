#ifndef ACTIONMAP_H
#define ACTIONMAP_H

#include <map>
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

typedef void(*Function)(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hLogThreadWriteCommand);
typedef map<string, Function> ActionMap;

char * GetTime();
char * GetDate();
#endif /*ACTIONMAP_H*/