#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <utility> // to make the tuple
#include <functional> // tuple

/*
 * Using pre-processor in C++ to .. help>?
 * Pre-precossor -- is a text editing stage
 * there, the 'text replacment' can be done
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */ 

// exmaple of a STUPID macro
#define OPEN_CURLY {

// example of a usefull Macro
#define LOG(x) std::cout << x << std::endl;

// Example of a LOG for Debug/Release modes
// In Debug -- everyting; In Release -- Only Errors
// Logging also takes time 
// Remove the Logg from the Release Code
// Define in pre-process 
// Find Preprocessor definitions and add for debbut TST_DEBUG
// and in Release add TST_RELEASE

/*
#ifdef TST_DEBUG
#define LOGDEBUG(x) std::cout << x << std::endl;
#else
#define LOGDEBUG(x) // replace it with nothing :) 
#endif
*/

// I could not make it work... Something with Debug
// Release modes settings in Codelite. Fuck it.

// anyways, here instead of 'ifdef' it is better to use 

// now you can control it here, instead of ... somewhere
#if TST_DEBUG = 0
#define LOGDEBUG(x) std::cout << x << std::endl
#elif defined(TST_RELEASE)
#define LOGDEBUG(x) // replace it with nothing :) 
#endif

// still does not work for some reason


// multiline Macro are done with \ slash at every line
// don't put any ' ' after the \


int main(int argc, char **argv)
OPEN_CURLY
	
	
	LOG("HI!");
	LOGDEBUG("DEBUGGING HAHAHA!");
	return 0;
}
