#pragma once
#include <map>
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

typedef void(*Function)(HANDLE);
typedef map<string, Function> ActionMap;