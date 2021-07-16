#include "Log.h"
#include <iostream> // C++ standard library do  not have extension (C have)

void Log(const char* messege)
{
	std::cout << messege << std::endl;
}

void InitLog()
{
	Log("Initialized");
}


