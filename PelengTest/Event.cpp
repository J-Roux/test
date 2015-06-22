#include "Event.h"

Event CreateCustomEvent()
{
	Event event;
	srand((unsigned int)time(NULL));
	event.id = CreateGUID();
	event.date = __DATE__;
	event.time = __TIME__;
	event.p0 = rand();
	event.p1 = rand();
	event.p2 = rand();
	return event;
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
