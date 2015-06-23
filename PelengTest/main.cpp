#include "Logger.h"
#include "main.h"
#include "eventThread.h"
#include "loggerThread.h"



void CreateAnonPipe(HANDLE &child_input_read, HANDLE &child_input_write)
{
    SECURITY_ATTRIBUTES security_attributes;
    security_attributes.nLength = sizeof(SECURITY_ATTRIBUTES);
    security_attributes.bInheritHandle = TRUE;
    security_attributes.lpSecurityDescriptor = NULL;
    if (!CreatePipe(&child_input_read, &child_input_write, &security_attributes, 0))
        cerr << "Create pipe";

}

HANDLE CreateEventThread(HANDLE *argv)
{
    DWORD myThreadID;
    HANDLE hEventThread = CreateThread(0, 0, EventThread, argv, 0, &myThreadID);
    if (hEventThread == NULL)
        cerr << "Create event thread";
    return hEventThread;
}

HANDLE CreateLoggerThread(HANDLE *argv)
{
    DWORD myThreadID;
    HANDLE hLoggerThread = CreateThread(0, 0, LoggerThread, argv, 0, &myThreadID);
    if (hLoggerThread == NULL)
        cerr << "Create event thread";
    return hLoggerThread;
}

void ExecuteUserInput(FuncArgs args)
{
    while (true)
    {
        string input;
        cin >> input;
        auto iter = commands.find(input);
        if (iter != commands.end())
        {
            (*iter->second)(args);
            if (exit_programm == true) break;
        }
        else
        {
            cerr << "Invalid argument" << endl;
        }
    }
}

void main()
{
    HANDLE hEventThreadRead, hEventThreadWrite;
    HANDLE hLogThreadWrite, hLogThreadRead;
    HANDLE hLogThreadReadCommand, hLogThreadWriteCommand;
    CreateAnonPipe(hEventThreadRead, hEventThreadWrite);
    CreateAnonPipe(hLogThreadRead, hLogThreadWrite);
    CreateAnonPipe(hLogThreadReadCommand, hLogThreadWriteCommand);
    HANDLE hWaitCommand = CreateEventA(NULL, false, false, CreateGUID());
    HANDLE hReadCommandEventThread = CreateEventA(NULL, false, false, CreateGUID());
    HANDLE hReadCommandLoggerThread = CreateEventA(NULL, false, false, CreateGUID());
    HANDLE hEventArgs[] = { hReadCommandEventThread, hEventThreadRead, hWaitCommand, hLogThreadWrite };
    HANDLE hLoggerArgs[] = { hReadCommandLoggerThread, hLogThreadRead, hWaitCommand, hLogThreadReadCommand };
    FuncArgs args = { hEventThreadWrite,
         hLogThreadRead,
         hWaitCommand,
         hReadCommandEventThread,
         hReadCommandLoggerThread,
         hLogThreadWriteCommand };
    HANDLE hEventThread = CreateEventThread(hEventArgs);
    HANDLE hLoggerThread = CreateLoggerThread(hLoggerArgs);
    ExecuteUserInput(args);
    CloseHandle(hEventThread);
    CloseHandle(hLoggerThread);
}

