#include "loggerThread.h"

char * fileName = "log.txt";

void ReadEvent(HANDLE * hArgv, Logger * logger, int &eventCount)
{
    Event e;
    ReadFile(hArgv[1], &e, sizeof(e), NULL, NULL);
    logger->Write(e);
    eventCount++;      
}

Logger * ExecuteCommand(CHAR * command, Logger * logger, int eventCount, Logger* lvl0, Logger* lvl1, Logger* lvl2)
{
    switch (command[0])
    {
    case '0': logger = lvl0; break;
    case '1': logger = lvl1; break;
    case '2': logger = lvl2; break;
    case 's': cout << endl << "Number of events:  " << eventCount << endl;
        break;
    }     return logger;
}

Logger * GetCommand(HANDLE * hArgv, Logger * logger, int eventCount, Logger* lvl0, Logger* lvl1, Logger* lvl2)
{
    if (WaitForSingleObject(hArgv[0], 0) == WAIT_OBJECT_0)
    {
        CHAR command[2] = { '0', '\0' };
        DWORD dwRead;
        SetEvent(hArgv[2]);
        ReadFile(hArgv[3], command, sizeof(command), &dwRead, NULL);
        logger = ExecuteCommand(command, logger, eventCount, lvl0, lvl1, lvl2);
        ResetEvent(hArgv[2]);
    }        return logger;
}

DWORD WINAPI LoggerThread(LPVOID lpParameter)
{
    HANDLE * hArgv = (HANDLE*)lpParameter;
    Logger * logger = Logger::GetLogger(2, fileName);
    Logger * lvl0 = Logger::GetLogger(0, fileName);
    Logger * lvl1 = Logger::GetLogger(1, fileName);
    Logger * lvl2 = Logger::GetLogger(2, fileName);
    int eventCount = 0;
    for (;;)
    {
        logger = GetCommand(hArgv, logger, eventCount, lvl0 , lvl1, lvl2);
        ReadEvent(hArgv, logger, eventCount);
    }
    return 0;
}

