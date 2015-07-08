#ifndef LOGGER_H
#define LOGGER_H

#include "Event.h"
#include <fstream>

using namespace std;


class Logger
{
protected:
    ofstream log;

    Logger(char* fileName);
    ~Logger();
public:

    static Logger* GetLogger(int level, char* fileName);
    virtual Logger* Write(const Event &e) abstract;
};

class LoggerLevelZero : public Logger
{
public:
    LoggerLevelZero(char* fileName) : Logger(fileName) {}
    virtual LoggerLevelZero* Write(const Event &e) override;
};

class LoggerLevelOne : public Logger
{
public:
    LoggerLevelOne(char* fileName) : Logger(fileName) {}
    virtual LoggerLevelOne* Write(const Event &e) override;

};

class LoggerLevelTwo : public Logger
{
public:
    LoggerLevelTwo(char* fileName) : Logger(fileName) {}
    virtual LoggerLevelTwo* Write(const Event &e) override;
};


#endif  /*LOGGER_H*/