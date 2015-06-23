#ifndef COMMANDS_H
#define COMMANDS_H
#include "actionMap.h"
#include <Windows.h>


extern ActionMap commands;
extern bool exit_programm;

void date_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);
void time_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);
void exit_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);
void faster_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);
void slower_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);
void pause_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);
void resume_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);
void stat_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);
void level_zero_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);
void level_one_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);
void level_two_func(HANDLE hEventThreadWrite, HANDLE hLogThreadRead, HANDLE hWaitCommand, HANDLE hReadCommandEventThread, HANDLE hReadCommandLoggerThread);

#endif /*COMMANDS_H*/
