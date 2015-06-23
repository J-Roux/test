#include "loggerThread.h"

const char * fileName = "log.txt";

DWORD WINAPI LoggerThread(LPVOID lpParameter)
{
    HANDLE * hArgv = (HANDLE*)lpParameter;
    Logger * logger = Logger::GetLogger(2, fileName);
    for (;;)
    {
        Event e;
        ReadFile(hArgv[1], &e, sizeof(e), NULL, NULL);
        cout << e.id << endl;
        logger->Write(e);
        if (WaitForSingleObject(hArgv[0], 0) == WAIT_OBJECT_0)
        {
            CHAR command[2] = { '0', '\0' };
            DWORD dwRead;
            SetEvent(hArgv[2]);
            ReadFile(hArgv[4], command, sizeof(command), &dwRead, NULL);
            cout << endl << "message is :  " << command << endl;
            switch (command[0])
            {
            case '0': logger = Logger::GetLogger(0, fileName); break;
            case '1': logger = Logger::GetLogger(1, fileName); break;
            case '2': logger = Logger::GetLogger(2, fileName); break;
            case 's':
                break;
            }
            ResetEvent(hArgv[2]);
        }
    }
    return 0;
}

