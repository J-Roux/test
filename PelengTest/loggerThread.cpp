#include "loggerThread.h"

const char * fileName = "log.txt";

int ReadEvent(HANDLE * hArgv, Logger * logger, int eventCount)
{
    Event e;
    ReadFile(hArgv[1], &e, sizeof(e), NULL, NULL);
    cout << e.id << endl;
    logger->Write(e);
    eventCount++;        return eventCount;
}

Logger * ExecuteCommand(CHAR * command, Logger * logger, int eventCount)
{
    switch (command[0])
    {
    case '0': logger = Logger::GetLogger(0, fileName); break;
    case '1': logger = Logger::GetLogger(1, fileName); break;
    case '2': logger = Logger::GetLogger(2, fileName); break;
    case 's': cout << endl << "Number of events:  " << eventCount << endl;
        break;
    }     return logger;
}

Logger * GetCommand(HANDLE * hArgv, Logger * logger, int eventCount)
{
    if (WaitForSingleObject(hArgv[0], 0) == WAIT_OBJECT_0)
    {
        CHAR command[2] = { '0', '\0' };
        DWORD dwRead;
        SetEvent(hArgv[2]);
        ReadFile(hArgv[4], command, sizeof(command), &dwRead, NULL);
        logger = ExecuteCommand(command, logger, eventCount);
        ResetEvent(hArgv[2]);
    }        return logger;
}

DWORD WINAPI LoggerThread(LPVOID lpParameter)
{
    HANDLE * hArgv = (HANDLE*)lpParameter;
    Logger * logger = Logger::GetLogger(2, fileName);
    int eventCount = 0;
    for (;;)
    {
        logger = GetCommand(hArgv, logger, eventCount);
        eventCount = ReadEvent(hArgv, logger, eventCount);
    }
    return 0;
}

