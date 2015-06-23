#include "Logger.h"

Logger::Logger(const char* fileName)
{
    log.open(fileName);
    eventCount = 0;
}

Logger::~Logger()
{
    log.close();
}


Logger * Logger::GetLogger(int level, const char* fileName)
{
    switch (level)
    {
    case 0: return new LoggerLevelZero(fileName);
    case 1: return new LoggerLevelOne(fileName);
    case 2: return new LoggerLevelTwo(fileName);
    default: return NULL;
    }
}


LoggerLevelZero* LoggerLevelZero::Write(const Event &e)
{
    log << typeid(LoggerLevelZero).name() << endl;
    log << e.time << endl;
    log << e.id << endl;
    log << endl;
    eventCount++;
    return this;
}

LoggerLevelOne* LoggerLevelOne::Write(const Event &e)
{
    log << typeid(LoggerLevelOne).name() << endl;
    log << e.date << endl;
    log << e.time << endl;
    log << e.id << endl;
    log << e.p0 << endl;
    log << endl;
    eventCount++;
    return this;
}

LoggerLevelTwo* LoggerLevelTwo::Write(const Event &e)
{
    log << typeid(LoggerLevelTwo).name() << endl;
    log << e.date << endl;
    log << e.time << endl;
    log << e.id << endl;
    log << e.p0 << endl;
    log << e.p1 << endl;
    log << e.p2 << endl;
    log << endl;
    eventCount++;
    return this;
}