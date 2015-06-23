#ifndef EVENT_H
#define EVENT_H

#include <Objbase.h>
#include <string>
#include <time.h>
#include <iostream>
#include <stdlib.h>    
#include <time.h> 

struct Event
{
    char * date;
    char * time;
    int p0;
    int p1;
    int p2;
    char * id;
};

Event CreateCustomEvent();
char * CreateGUID();

#endif /*EVENT_H*/