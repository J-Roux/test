#include "Event.h"

char * GetTime()
{
    time_t timev;
    char *buffer = new char[10];
    tm * currentTime = new tm();
    time(&timev);
    localtime_s(currentTime, &timev);
    strftime(buffer, 10, "%H:%M:%S", currentTime);
    return buffer;
}

char * GetDate()
{
    time_t timev;
    char *buffer = new char[10];
    tm * currentTime = new tm();
    time(&timev);
    localtime_s(currentTime, &timev);
    strftime(buffer, 10, "%d/%m/%y", currentTime);
    return buffer;
}

Event CreateCustomEvent()
{
    Event event;
    event.id = CreateGUID();
    event.date = GetDate();
    event.time = GetTime();
    event.p0 = rand();
    event.p1 = rand();
    event.p2 = rand();
    return event;
}

Event::~Event()
{
    delete this->id;
    delete this->date;
    delete this->time;
}


char * CreateGUID()
{
    wchar_t szGuidW[40] = { 0 };
    char * szGuidA = new char[40];
    GUID guid = { 0 };
    CoCreateGuid(&guid);
    StringFromGUID2(guid, szGuidW, 40);
    WideCharToMultiByte(0, 0, szGuidW, -1, szGuidA, 40, NULL, NULL);
    return szGuidA;
}
