#include "loggerThread.h"

DWORD WINAPI LoggerThread(LPVOID lpParameter)
{
    HANDLE * hArgv = (HANDLE*)lpParameter;
   
    for (;;)
    {
        Event e;
        ReadFile(hArgv[1], &e, sizeof(e), NULL, NULL);
        cout << e.id << endl;
        if (WaitForSingleObject(hArgv[0], 0) == WAIT_OBJECT_0)
        {
            CHAR command[2] = { '0', '\0' };
            DWORD dwRead;
            SetEvent(hArgv[2]);
            ReadFile(hArgv[5], command, sizeof(command), &dwRead, NULL);
            cout << "get message" << endl;
            cout << endl << "message is :  "<< command << endl;
            /* switch (command[0])
            {
            case '0':  break;
            case '1': break;
            case '2': break;
            case 's':
            break;
            }*/
            ResetEvent(hArgv[2]);
        }
    }
    return 0;
}

