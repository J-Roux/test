#include "Logger.h"
#include "main.h"


DWORD WINAPI EventThread(LPVOID lpParameter)
{
    HANDLE * hArgv = (HANDLE*) lpParameter;
    CHAR command[2] = {'0', '\0'};
    DWORD dwRead;
    srand((unsigned int)time(NULL));
    int baseSpeed = 1000;
    bool pause = false;
    for (;;)
    {
        if (!pause)
        {
            int speed = baseSpeed + rand() % baseSpeed;
           // Event e = createEvent();
            cout << speed << "  " << pause << endl;
           // DWORD bytes_written = 1;
           // WriteFile(hArgv[3], &e, sizeof(e), NULL, NULL);
            Sleep(speed);
        }
        if (WaitForSingleObject(hArgv[0], 0) == WAIT_OBJECT_0)
        {
   
            SetEvent(hArgv[2]);
            ReadFile(hArgv[1], command, sizeof(command), &dwRead, NULL);
            switch (command[0])
            {
                case 'p': pause = true; break;
                case 'r': pause = false; break;
                case 'f': if( baseSpeed > 0) baseSpeed -= 100; break;
                case 's': baseSpeed += 100; break;
            }
            ResetEvent(hArgv[2]);
        }
    }
	return 0;
}

DWORD WINAPI loggerThread(LPVOID lpParameter)
{
    HANDLE * hArgv = (HANDLE*)lpParameter;
    CHAR command[2] = { '0', '\0' };
    DWORD dwRead;
    for (;;)
    {
        SetEvent(hArgv[2]);
        ReadFile(hArgv[1], command, sizeof(command), &dwRead, NULL);
        cout << endl << command << endl;
        switch (command[0])
        {
            case '0': break;
            case '1': break;
            case '2': break;
            case 's':
                break;
        }
        ResetEvent(hArgv[2]);
    }
    return 0;
}


void Prepare()
{
	commands.insert(make_pair("date", &date_func));
	commands.insert(make_pair("time", &time_func));
	commands.insert(make_pair("exit", &exit_func));
	commands.insert(make_pair("faster", &faster_func));
	commands.insert(make_pair("slower", &slower_func));
	commands.insert(make_pair("pause", &pause_func));
	commands.insert(make_pair("resume", &resume_func));
	commands.insert(make_pair("stat", &stat_func));
	commands.insert(make_pair("level 0", &level_zero_func));
	commands.insert(make_pair("level 1", &level_one_func));
	commands.insert(make_pair("level 2", &level_two_func));
}

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
    HANDLE hLoggerThread = CreateThread(0, 0, loggerThread, argv, 0, &myThreadID);
    if (hLoggerThread == NULL)
        cerr << "Create event thread";
    return hLoggerThread;
}

void main()
{
    HANDLE hEventThreadRead;
    HANDLE hEventThreadWrite;
    HANDLE hLogThreadWrite;
    HANDLE hLogThreadRead;
    HANDLE hMainThreadRead;
    HANDLE hMainThreadWrite;
    Prepare();
    CreateAnonPipe(hEventThreadRead, hEventThreadWrite);
    CreateAnonPipe(hLogThreadRead, hLogThreadWrite);
    CreateAnonPipe(hMainThreadRead, hMainThreadWrite);
    HANDLE hWaitCommand = CreateEventA(NULL, false, false, CreateGUID());
    HANDLE hReadCommandEventThread = CreateEventA(NULL, false, false, CreateGUID());
    HANDLE hEventArgs[] = { hReadCommandEventThread, hEventThreadRead, hWaitCommand, hLogThreadWrite };
    HANDLE hLoggerArgs[] = { hWaitCommand , hLogThreadRead, hMainThreadWrite };
    HANDLE hFuncArgs[] = { hEventThreadWrite, hReadCommandEventThread, hWaitCommand };
    HANDLE hEventThread = CreateEventThread(hEventArgs);
    HANDLE hLoggerThread = CreateLoggerThread(hLoggerArgs);
    std::string input;
	while (true)
	{
		std::cin >> input;
		ActionMap::iterator iter = commands.find(input);
		if (iter != commands.end())
		{
            (*iter->second)(hFuncArgs);
            if (exit_programm == true) break;
		}
		else
		{
			cerr << "Invalid argument" << endl;
		}
	}
	CloseHandle(hEventThread);
    CloseHandle(hLoggerThread);
}

