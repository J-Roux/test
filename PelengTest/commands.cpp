#include "commands.h"

void WriteMessage(HANDLE hWrite, HANDLE hReadCommand, HANDLE hWaitCommand, char * message)
{
    SetEvent(hReadCommand);
    WaitForSingleObject(hWaitCommand, INFINITE);
    DWORD bytes_written = 1;
    WriteFile(hWrite, message, strlen(message), &bytes_written, NULL);
    ResetEvent(hReadCommand);
}



void faster_func(FuncArgs args)
{
    char message[] = "f";
    WriteMessage(args.hEventThreadWrite, args.hReadCommandEventThread, args.hWaitCommand, message);
}

void slower_func(FuncArgs args)
{
    char message[] = "s";
    WriteMessage(args.hEventThreadWrite, args.hReadCommandEventThread, args.hWaitCommand, message);
}

void pause_func(FuncArgs args)
{
    char message[] = "p";
    WriteMessage(args.hEventThreadWrite, args.hReadCommandEventThread, args.hWaitCommand, message);
}

void resume_func(FuncArgs args)
{
    char message[] = "r";
    WriteMessage(args.hEventThreadWrite, args.hReadCommandEventThread, args.hWaitCommand, message);
}

void stat_func(FuncArgs args)
{
    char message[] = "s";
    WriteMessage(args.hLogThreadWriteCommand, args.hReadCommandLoggerThread, args.hWaitCommand, message);
}

void level_zero_func(FuncArgs args)
{
    char message[] = "0";
    WriteMessage(args.hLogThreadWriteCommand, args.hReadCommandLoggerThread, args.hWaitCommand, message);
}

void level_one_func(FuncArgs args)
{
    char message[] = "1";
    WriteMessage(args.hLogThreadWriteCommand, args.hReadCommandLoggerThread, args.hWaitCommand, message);
}

void level_two_func(FuncArgs args)
{
    char message[] = "2";
    WriteMessage(args.hLogThreadWriteCommand, args.hReadCommandLoggerThread, args.hWaitCommand, message);
}

void date_func(FuncArgs args)
{
    char * date = GetDate();
    cout << date << endl;
    delete date;
}

void time_func(FuncArgs args)
{
    char * time = GetTime();
    cout << time << endl;
    delete time;
}

void exit_func(FuncArgs args)
{
    exit_programm = true;
}