#include "Event.h"

Event createEvent()
{
	Event event;
	srand((unsigned int)time(NULL));	
	event.id = createGUID();
	event.date = __DATE__;
	event.time = __TIME__;
	event.p0 = rand();
	event.p1 = rand();
	event.p2 = rand();
	return event;
}


char * createGUID()
{
	wchar_t szGuidW[40] = { 0 };
	char szGuidA[40] = { 0 };
	GUID guid = { 0 };
	CoCreateGuid(&guid);
	StringFromGUID2(guid, szGuidW, 40);
	WideCharToMultiByte(0, 0, szGuidW, -1, szGuidA, 40, NULL, NULL);
	return szGuidA;
}
