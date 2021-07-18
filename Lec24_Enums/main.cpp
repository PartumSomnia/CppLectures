#include <iostream>

/*
 * Enum -- name of the value
 * allows to define set of values
 * name values
 * 
 * Usefull to name variables
 * Consider 3 values 
 * A = 0
 * B = 1
 * C = 2
 * 
 * value = A
 * 
 * somewhere 
 * check if it is value = B
 * 
 * We want a type that can be only {0,1,2}
 * 
 * For the set of values to represent numerically
 * 
 */ 
 
/* --- example of enum -- */

enum Example : char // for specify type of integer
{
	// if only first number is set, the other ar +1
	A = 5, B, C
};

/* --- example from log glass -- */

class Log
{
public:
	// new public type that can be one of the three specific raviables
    enum Levels
	{
		LevelError=0, LevelWarning, LevelInfo
	};
	
private:
	int m_loglevel = LevelInfo; // internal varaible for keeping track on what is the 
	// user defined log level
	
public:
	// set the level for the code Takes the enum variable -- from Log name space
	// Log::LevelWarning for example! 
	void SetLogLevel(Levels level)
	{
		m_loglevel = level;
	}
	
	void Error(const char* messege)
	{
		if (m_loglevel >= LevelError)
			std::cout << "[Error] " << messege << std::endl;
	}
	
	void Warning(const char* messege)
	{
		if (m_loglevel >= LevelWarning)
			std::cout << "[Warning] " << messege << std::endl;
	}
	
	void Info(const char* messege)
	{
		if (m_loglevel >= LevelInfo)
			std::cout << "[Info] " << messege << std::endl;
	}
};



int main(int argc, char **argv)
{
	// enum is an actual type that can be A, B, C ONLY!
    Example value = B;
	
	std::cout << value << std::endl;

	Log log;
	log.SetLogLevel(Log::LevelWarning);
	log.Error("Shit!");
	log.Warning("Thisis bad");
	log.Info("I want a cinnabonn");

	return 0;
}

