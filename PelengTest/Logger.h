#include "Event.h"

class Logger
{
protected:
	Logger(char* fileName);
	~Logger();
public:
	static Logger* GetLogger(int level);
	virtual Logger* Write(My_Event event);
};
