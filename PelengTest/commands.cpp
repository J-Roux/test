#include "commands.h"

void ReadMessageEventThread(HANDLE hWriteEventThread, HANDLE hReadCommand , HANDLE hWaitCommand, char * message)
{
    cout << hReadCommand << endl;
    SetEvent(hReadCommand);
    WaitForSingleObject(hWaitCommand, INFINITE);
    DWORD bytes_written = 1;
    WriteFile(hWriteEventThread, message, strlen(message), &bytes_written, NULL);
    ResetEvent(hReadCommand);
}


void faster_func(HANDLE* hInput)
{
    char * message = "f";
    ReadMessageEventThread(hInput[0], hInput[1], hInput[2] , message);
}

void slower_func(HANDLE* hInput)
{
    char * message = "s";
    ReadMessageEventThread(hInput[0], hInput[1], hInput[2], message);
}

void pause_func(HANDLE* hInput)
{
    char * message = "p";
    ReadMessageEventThread(hInput[0], hInput[1], hInput[2], message);
}

void resume_func(HANDLE* hInput)
{
    char * message = "r";
    ReadMessageEventThread(hInput[0], hInput[1], hInput[2], message);
}

void stat_func(HANDLE* hInput)
{

}

void level_zero_func(HANDLE* hInput)
{

}

void level_one_func(HANDLE* hInput)
{

}

void level_two_func(HANDLE* hInput)
{

}

void date_func(HANDLE* hInput)
{
	cout << endl << __DATE__ << endl;
}

void time_func(HANDLE* hInput)
{
	cout << endl << __TIME__ << endl;
}

void exit_func(HANDLE* hInput)
{
	exit_programm = true;
}