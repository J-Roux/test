#include "eventThread.h"


void GenerateEvent(bool pause, double baseSpeed, HANDLE * hArgv)
{
    if (!pause)
    {
        double speed = baseSpeed + rand() % (int)baseSpeed;
        Event e = CreateCustomEvent();
        WriteFile(hArgv[3], &e, sizeof(e), NULL, NULL);
        Sleep(speed);
    }
}

void ExecuteCommand(CHAR * command, bool &pause, double &baseSpeed)
{
     switch (command[0])
    {
    case 'p': pause = true; break;
    case 'r': pause = false; break;
    case 'f': if (baseSpeed > 0) baseSpeed *= 0.3; break;
    case 's': baseSpeed /= 0.3; break;
    }
}

void GetCommand(HANDLE * hArgv, bool &pause, double &baseSpeed)
{
    if (WaitForSingleObject(hArgv[0], 0) == WAIT_OBJECT_0)
    {
        CHAR command[2] = { '0', '\0' };
        DWORD dwRead;
        SetEvent(hArgv[2]);
        ReadFile(hArgv[1], command, sizeof(command), &dwRead, NULL);
        ExecuteCommand(command, pause, baseSpeed);
        ResetEvent(hArgv[2]);
    }
}

DWORD WINAPI EventThread(LPVOID lpParameter)
{
    HANDLE * hArgv = (HANDLE*)lpParameter;
    double baseSpeed = 1000;
    bool pause = false;
    srand((unsigned)time(NULL));
    for (;;)
    {
        GetCommand(hArgv, pause, baseSpeed);
        GenerateEvent(pause, baseSpeed, hArgv);
    }
    return 0;
}