#include "Logger.h"
#include "main.h"


DWORD WINAPI eventThread(LPVOID lpParameter)
{
    HANDLE * hArgv = (HANDLE*) lpParameter;
    CHAR command[2] = {'0', '\0'};
    DWORD dwRead;
    int speed = 1000;
    bool pause = false;
    for (;;)
    {
        if (!pause)
        {
            Event e = createEvent();
            cout << speed << "  " << pause << endl;
            DWORD bytes_written = 1;
            WriteFile(hArgv[3], &e, sizeof(e), NULL, NULL);
            Sleep(speed);
        }
        if (WaitForSingleObject(hArgv[0], 0) == WAIT_OBJECT_0)
        {
            SetEvent(hArgv[2]);
            ReadFile(hArgv[1], command, sizeof(command), &dwRead, NULL);
            cout << command << endl;
            switch (command[0])
            {
                case 'p': pause = true; break;
                case 'r': pause = false; break;
                case 'f': if(speed > 0) speed -= 100; break;
                case 's': speed += 100; break;
            }
            ResetEvent(hArgv[2]);
        }
    }
	return 0;
}

DWORD WINAPI loggerThread(LPVOID lpParameter)
{

    return 0;
}


void prepare()
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

void createAnonPipe(HANDLE &child_input_read, HANDLE &child_input_write)
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
    HANDLE hEventThread = CreateThread(0, 0, eventThread, argv, 0, &myThreadID);
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
    prepare();
    createAnonPipe(hEventThreadRead, hEventThreadWrite);
    HANDLE hWaitCommand = CreateEventA(NULL, false, false, createGUID());
    createAnonPipe(hLogThreadRead, hLogThreadWrite);
    HANDLE hReadCommand = CreateEventA(NULL, false, false, createGUID());
    HANDLE hEventArgs[] = { hReadCommand, hEventThreadRead, hWaitCommand, hLogThreadWrite };
    HANDLE hLoggerArgs[] = { hReadCommand, hLogThreadRead };
    HANDLE hEventThread = CreateEventThread(hEventArgs);
    HANDLE hLoggerThread = CreateLoggerThread(hLoggerArgs);
    std::string input;
	while (true)
	{
		std::cin >> input;
		ActionMap::iterator iter = commands.find(input);
		if (iter != commands.end())
		{
            SetEvent(hReadCommand);
            cout << hWaitCommand << endl;
            WaitForSingleObject(hWaitCommand, INFINITE);
            (*iter->second)(hEventThreadWrite);
            ResetEvent(hReadCommand);
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

