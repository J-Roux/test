#pragma once
#include <Objbase.h>
#include <string>
#include <time.h>
#include <iostream>
#include <stdlib.h>    
#include <time.h> 

struct My_Event
{
	char * date;
	char * time;
	int p0;
	int p1;
	int p2;
	char * id;
};

My_Event createEvent();
char * createGUID();