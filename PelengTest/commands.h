#ifndef COMMANDS_H
#define COMMANDS_H
#include "actionMap.h"
#include <Windows.h>
#include <ctime>

extern ActionMap commands;
extern bool exit_programm;

void date_func(FuncArgs args);

void time_func(FuncArgs args);

void exit_func(FuncArgs args);

void faster_func(FuncArgs args);

void slower_func(FuncArgs args);

void pause_func(FuncArgs args);

void resume_func(FuncArgs args);

void stat_func(FuncArgs args);

void level_zero_func(FuncArgs args);

void level_one_func(FuncArgs args);

void level_two_func(FuncArgs args);

#endif /*COMMANDS_H*/
