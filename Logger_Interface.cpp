#include "pch.h"
#include "Logger_Interface.h"
#include <chrono>
#include <string>
#include <cctype>
#include <sstream>

Logger_Interface::Logger_Interface(LogLevel logLevel) : logLevel(logLevel), lineNumber(0)
{
}

Logger_Interface::~Logger_Interface()
{
}

const LogLevel & Logger_Interface::getLogLevel()
{
	return logLevel;
}

// could be substitued with a class just containing const strings

std::string Logger_Interface::IsAlNum(std::string & str) 
{
	std::string formattedString;
	for (const char& c : str)
	{
		if (std::isalnum(c))
		{
			formattedString += c;
		}
	}
	return formattedString;
}

std::string Logger_Interface::GetLogLevelAsString(const LogLevel & logLevel)
{
	std::string toString;
	switch (logLevel)
	{
		case(LogLevel::Debug) :
			toString = "Debug";
			break;
		case(LogLevel::Error) :
			toString = "Error";
			break;
		case(LogLevel::Info) :
			toString = "Info";
			break;
		case(LogLevel::Warning) :
			toString = "Warning";
			break;
	}

	return toString;
}

	std::string Logger_Interface::CreateLogString(const std::vector<std::string>& message)
	{
		std::string msg = " - ";
		msg += GetLogLevelAsString(logLevel);
		msg += " - ";
		msg += GetFormattedTime();


		for (const auto& c : message)
		{
			msg += c;
		}

		msg.append("\n");
		
		std::ostringstream stream;
		stream << std::setw(8) << std::setfill('0') << lineNumber;
		return stream.str() + msg;
	}

std::string Logger_Interface::GetFormattedTime()
{		std::string time = GetCurrentTime();
		time.erase(std::remove(time.begin(), time.end(), '\n'), time.end());
		time.append(" - ");
		return time;
}

// we will be using microsofts built in get time, because it is threadsafe
std::string Logger_Interface::GetCurrentTime()
{
// https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s?view=vs-2019

	struct tm newtime;
	__int64 ltime;
	char buf[26];
	errno_t err;

	_time64(&ltime);

	// Obtain coordinated universal time:
	err = _gmtime64_s(&newtime, &ltime);
	
	if (err)
	{
		printf("Invalid Argument to _gmtime64_s.");
	}

	// Convert to an ASCII representation
	err = asctime_s(buf, 26, &newtime);
	if (err)
	{
		printf("Invalid Argument to asctime_s.");
	}

	return buf;
}
