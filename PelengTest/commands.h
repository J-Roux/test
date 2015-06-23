#ifndef COMMANDS_H
#define COMMANDS_H
#include "actionMap.h"
#include <Windows.h>
#include <ctime>

extern ActionMap commands;
extern bool exit_programm;

void date_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,     
    HANDLE hLogThreadWriteCommand);

void time_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,     
    HANDLE hLogThreadWriteCommand);

void exit_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,     
    HANDLE hLogThreadWriteCommand);

void faster_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,     
    HANDLE hLogThreadWriteCommand);

void slower_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hLogThreadWriteCommand);

void pause_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread, 
    HANDLE hLogThreadWriteCommand);

void resume_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread, 
    HANDLE hLogThreadWriteCommand);

void stat_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,     
    HANDLE hLogThreadWriteCommand);

void level_zero_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,     
    HANDLE hLogThreadWriteCommand);

void level_one_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hLogThreadWriteCommand);

void level_two_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hLogThreadWriteCommand);

#endif /*COMMANDS_H*/
