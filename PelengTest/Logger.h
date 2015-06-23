#ifndef LOGGER_H
#define LOGGER_H

#include "Event.h"
#include <fstream>

using namespace std;


class Logger
{
protected:
    ofstream log;
    int eventCount;

    Logger(const char* fileName);
    ~Logger();
public:
    static Logger* GetLogger(int level, const char* fileName);
    virtual Logger* Write(const Event &e) abstract;
};

class LoggerLevelZero : public Logger
{
public:
    LoggerLevelZero(const char* fileName) : Logger(fileName) {}
    virtual LoggerLevelZero* Write(const Event &e) override;
};

class LoggerLevelOne : public Logger
{
public:
    LoggerLevelOne(const char* fileName) : Logger(fileName) {}
    virtual LoggerLevelOne* Write(const Event &e) override;

};

class LoggerLevelTwo : public Logger
{
public:
    LoggerLevelTwo(const char* fileName) : Logger(fileName) {}
    virtual LoggerLevelTwo* Write(const Event &e) override;
};

#endif  /*LOGGER_H*/