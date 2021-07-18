#include <iostream>

/*
 * Writing a log class (lecture first on the class)
 * class for messeges (ususally used for Degubbing)
 * Maintain 3 log levels (Error, Warning, Message)
 * depending on what level is set, different messeges 
 * are shown.
 * 
 * This is a horrible example of a class, but it 
 * can be imporoved in very many ways which 
 * will be discussed in the following lectures
 * 
 */ 

// #define LOG(x) std::cout << x << std::endl;


class Log
{
public:
    int LogLevelError = 0;
	int LogLevelWarning = 1;
	int LogLevelInfo = 2;
	
private:
	int m_loglevel = LogLevelInfo;
	
public:
	void SetLogLevel(int level)
	{
		m_loglevel = level;
	}
	
	void Error(const char* messege)
	{
		if (m_loglevel >= LogLevelError)
			std::cout << "[Error] " << messege << std::endl;
	}
	
	void Warning(const char* messege)
	{
		if (m_loglevel >= LogLevelWarning)
			std::cout << "[Warning] " << messege << std::endl;
	}
	
	void Info(const char* messege)
	{
		if (m_loglevel >= LogLevelInfo)
			std::cout << "[Info] " << messege << std::endl;
	}
};

int main(int argc, char **argv)
{
	
	Log log;
	log.SetLogLevel(log.LogLevelWarning);
	log.Error("Shit!");
	log.Warning("Thisis bad");
	log.Info("I want a cinnabonn");
	
	
	return 0;
}
