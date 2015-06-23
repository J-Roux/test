#include "commands.h"

void WriteMessage(HANDLE hWrite, HANDLE hReadCommand, HANDLE hWaitCommand, char * message)
{
    SetEvent(hReadCommand);
    cout << message << endl;
    WaitForSingleObject(hWaitCommand, INFINITE);
    DWORD bytes_written = 1;
    WriteFile(hWrite, message, strlen(message), &bytes_written, NULL);
    ResetEvent(hReadCommand);
}



void faster_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    char message[] = "f";
    WriteMessage(hEventThreadWrite, hReadCommandEventThread, hWaitCommand, message);
}

void slower_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    char message[] = "s";
    WriteMessage(hEventThreadWrite, hReadCommandEventThread, hWaitCommand, message);
}

void pause_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    char message[] = "p";
    WriteMessage(hEventThreadWrite, hReadCommandEventThread, hWaitCommand, message);
}

void resume_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    char message[] = "r";
    WriteMessage(hEventThreadWrite, hReadCommandEventThread, hWaitCommand, message);
}

void stat_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    char message[] = "s";
}

void level_zero_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    char message[] = "0";
    WriteMessage(hLogThreadWriteCommand, hReadCommandLoggerThread, hWaitCommand, message);
}

void level_one_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    char message[] = "1";
    WriteMessage(hLogThreadWriteCommand, hReadCommandLoggerThread, hWaitCommand, message);
}

void level_two_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    char message[] = "2";
    WriteMessage(hLogThreadWriteCommand, hReadCommandLoggerThread, hWaitCommand, message);
}

void date_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    cout << endl << __DATE__ << endl;
}

void time_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    cout << endl << __TIME__ << endl;
}

void exit_func(HANDLE hEventThreadWrite,
    HANDLE hLogThreadRead,
    HANDLE hWaitCommand,
    HANDLE hReadCommandEventThread,
    HANDLE hReadCommandLoggerThread,
    HANDLE hMainThreadRead,
    HANDLE hLogThreadWriteCommand)
{
    exit_programm = true;
}