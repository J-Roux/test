#include "Event.h"

My_Event::My_Event()
{
	GUID guid;
	HRESULT hr = CoCreateGuid(&guid);
	RPC_CSTR  guidStr;
	UuidToStringA(&guid, &guidStr);
	std::cout << guidStr;
}