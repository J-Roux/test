#include "eventThread.h"


DWORD WINAPI EventThread(LPVOID lpParameter)
{
    HANDLE * hArgv = (HANDLE*)lpParameter;
    CHAR command[2] = { '0', '\0' };
    DWORD dwRead;
    double baseSpeed = 1000;
    bool pause = false;
    srand((unsigned)time(NULL));
    for (;;)
    {
        if (!pause)
        {
            double speed = baseSpeed + rand() % (int)baseSpeed;
            Event e = CreateCustomEvent();
            cout << speed << "  " << e.id << endl;
            WriteFile(hArgv[3], &e, sizeof(e), NULL, NULL);
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
            case 'f': if (baseSpeed > 0) baseSpeed *= 0.3; break;
            case 's': baseSpeed *= 1.3; break;
            }
            ResetEvent(hArgv[2]);
        }
    }
    return 0;
}