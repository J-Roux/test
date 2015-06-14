#include "Logger.h"
#include "main.h"

void prepare()
{
	commands.insert(make_pair("date", &date_func));
	commands.insert(make_pair("time", &time_func));
	commands.insert(make_pair("exit", &exit_func));
	commands.insert(make_pair("faster", &faster_func));
	commands.insert(make_pair("slower", &slower_func));
	commands.insert(make_pair("pause", &pause_func));
	commands.insert(make_pair("resume", &resume_func));
	commands.insert(make_pair("stat", &stat_func));
	commands.insert(make_pair("level 0", &level_zero_func));
	commands.insert(make_pair("level 1", &level_one_func));
	commands.insert(make_pair("level 2", &level_two_func));
}

void main()
{
	prepare();
	My_Event * e = new My_Event();
	My_Event * e1 = new My_Event();
	delete e;
	delete e1;
	std::string input;
	while (true)
	{
		std::cin >> input;
		action_map::iterator iter = commands.find(input);
		if (iter != commands.end())
		{
			(*iter->second)();
			if (exit_programm == true) break;
		}
		else
		{
			cerr << "Invalid argument" << endl;
		}
	}
}

