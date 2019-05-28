#include "pch.h"
#include "ConsoleLogger.h"
#include <thread>


ConsoleLogger::ConsoleLogger(LogLevel loglevel) : Logger_Interface(loglevel)
{
	std::string currentTime = GetCurrentTime();
	IsAlNum(currentTime);
	std::string str = "Started App On: " + currentTime + "\n";
	Execute(str);
}

ConsoleLogger::~ConsoleLogger()
{
}

void ConsoleLogger::Execute(const std::string & message)
{
	std::printf("%s\n", message.c_str());
}
