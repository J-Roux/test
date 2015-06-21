#pragma once
#include "actionMap.h"
#include <Windows.h>


extern ActionMap commands;
extern bool exit_programm;

void date_func(HANDLE hInput);
void time_func(HANDLE hInput);
void exit_func(HANDLE hInput);
void faster_func(HANDLE hInput);
void slower_func(HANDLE hInput);
void pause_func(HANDLE hInput);
void resume_func(HANDLE hInput);
void stat_func(HANDLE hInput);
void level_zero_func(HANDLE hInput);
void level_one_func(HANDLE hInput);
void level_two_func(HANDLE hInput);


