#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <thread>
#include <mutex>
enum LogLevel{ Debug, Warning, Info, Error};
class Logger_Interface
{
private:
	// each child will itself define how it wants to implement execute
	virtual void Execute(const std::string& msg) = 0;
	unsigned lineNumber;

	LogLevel logLevel;

	std::mutex mutex;

	// return a string representation of a loglevel enum
	// we might want to customize what's logged so it's in it's own function
	std::string GetLogLevelAsString(const LogLevel& logLevel);

	// takes a generic type T and converts it to a string
	template<typename T>
	std::string to_string_converter(const T& t)
	{
		std::stringstream ss;
		ss << t;
		return ss.str();
	}


protected:
	// format output GetCurrentTime. Currently only strips it of a newline character ands " - " at the end
	std::string GetFormattedTime();

	// get current time
	std::string GetCurrentTime();

public:
	Logger_Interface(LogLevel logLevel);
	virtual ~Logger_Interface();

	template< typename... Param>
	bool Log(const LogLevel& loglevel, const Param&... param)
	{
		if (loglevel != this->logLevel)
		{
			return false;
		}
		const auto output = { to_string_converter(param)... };
		std::string msg = CreateLogString(output);
		mutex.lock();
		std::thread _thread(&Logger_Interface::Execute, this, msg);
		_thread.join();
		lineNumber++;
		mutex.unlock();
		return true;
	}

	const LogLevel& getLogLevel();

	// strip string of any non alphanumeric characters
	// this is useful when generating a valid filename for example
	std::string IsAlNum(std::string& str);

	std::string CreateLogString(const std::vector<std::string>& message);
};

