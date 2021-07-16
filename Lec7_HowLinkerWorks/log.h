// void Log(const char* message); // declare the function for compiler

#pragma once // ???

static void Log(const char* message) // stastic will include it only to WITHIN the scope of ONE file
                                     // INTERNAL LINKING
									 // or inline -- take and replace in every place
									 // Move Log() into a separate transaltion unit or into log.cpp
{
	std::cout << message << std::endl;
}
