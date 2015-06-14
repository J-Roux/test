#include <map>
#include <string>
#include <iostream>

using namespace std;

typedef void(*Function)();
typedef map<string, Function> action_map;