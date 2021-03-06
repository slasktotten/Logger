// Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "FileLogger.h"
#include "ConsoleLogger.h"
#include "FileWriter.h"

int main()
{
	Logger_Interface* logger = new FileLogger(LogLevel::Debug);
	Logger_Interface* _logger = new ConsoleLogger(LogLevel::Debug);
	std::string msg = "hello world ";

	for (int i = 0; i < 3000; i++)
	{
		logger->Log(LogLevel::Debug, msg, i);
		_logger->Log(LogLevel::Debug, msg, i);
	}

	logger->Log(LogLevel::Debug, 1, " ", 1.5, " address of logger is: ", logger);
	_logger->Log(LogLevel::Debug, 1, " ", 1.5, " address of logger is: ", logger);


	// we have just put this to naively display output of console program
	system("PAUSE");
}

