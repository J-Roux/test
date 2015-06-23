#include "actionMap.h"
#include "commands.h"
ActionMap commands = { { "date", &date_func },
{ "time", &time_func },
{ "exit", &exit_func },
{ "faster", &faster_func },
{ "slower", &slower_func },
{ "pause", &pause_func },
{ "resume", &resume_func },
{ "stat", &stat_func },
{ "level0", &level_zero_func },
{ "level1", &level_one_func },
{ "level2", &level_two_func } };

bool exit_programm = false;
