#include "pch.h"
#include "FileLogger.h"
#include <fstream>
#include <iostream>
#include <string>
//#include <cctype>
//#include <ios>
//#include <iomanip>
#include <thread>	


FileLogger::FileLogger(LogLevel logLevel, std::string logPrefix) : Logger_Interface(logLevel)
{
	filewriter = new FileWriter();
	CreateFile(logPrefix);
}

void FileLogger::CreateFile(const std::string& logPrefix)
{
	std::string currentTime = GetCurrentTime();
	fileName = logPrefix + IsAlNum(currentTime) + ".txt";
	std::string str = "Started App On: " + currentTime;
	Execute(str);
}

void FileLogger::Execute(const std::string& message)
{
	filewriter->WriteToFile(fileName, message);
}

FileLogger::~FileLogger()
{
	delete filewriter;
}

const std::string& FileLogger::getFileName()
{
	return fileName;
}


