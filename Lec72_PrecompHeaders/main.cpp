#include "pch.h"

/*
 * Precompiled header -- 
 * allows to convert header files, like 
 * standard libraries -- into binaries
 * 
 * PCH
 * 
 * They allow to speed up the compilation
 * PCH are usually used for static stuff, 
 * that does not change. Like logging library
 * Or for external stuff. 
 * Like standard teplate library (std::)
 * This is a great amount of code that 
 * can be precompiled.
 * 
 * Notably, PCH can hide what is going on 
 * 
 * 
 * The setup is to create a header .h file
 * with required includes and .cpp file 
 * with just one pch.h included
 * 
 * In the settings set up for this file 
 * "precompuled headers -- create"
 * in the project properties set up 
 * "precompiled headers -- use"
 * 
 * It is different in visual studio, but I 
 * think it is also set up here.
 * or
 * 
 * g++ -std=c++11 pch.h # create a precompiled header -> pch.h.gch File
 * time g++ -std=c++11 Main.cpp # run the probram with the header
 * 
 * 
 * 
 */ 

int main(int argc, char **argv)
{
	//pass
}
