#include "commands.h"


void faster_func(HANDLE hInput)
{
    char * message = "f";
    DWORD bytes_written = 1;
    WriteFile(hInput, message, strlen(message), &bytes_written, NULL);
}

void slower_func(HANDLE hInput)
{
    char * message = "s";
    DWORD bytes_written = 1;
    WriteFile(hInput, message, strlen(message), &bytes_written, NULL);
}

void pause_func(HANDLE hInput)
{
    char * message = "p";
    DWORD bytes_written = 1;
    WriteFile(hInput, message, strlen(message), &bytes_written, NULL);
}

void resume_func(HANDLE hInput)
{
    char * message = "r";
    DWORD bytes_written = 1;
    WriteFile(hInput, message, strlen(message), &bytes_written, NULL);
}

void stat_func(HANDLE hInput)
{

}

void level_zero_func(HANDLE hInput)
{

}

void level_one_func(HANDLE hInput)
{

}

void level_two_func(HANDLE hInput)
{

}

void date_func(HANDLE hInput)
{
	cout << endl << __DATE__ << endl;
}

void time_func(HANDLE hInput)
{
	cout << endl << __TIME__ << endl;
}

void exit_func(HANDLE hInput)
{
	exit_programm = true;
}