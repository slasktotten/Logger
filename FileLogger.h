#pragma once
#include "Logger_Interface.h"
#include <mutex>
#include "FileWriter.h"

class FileLogger :
	public Logger_Interface
{
private:
	void CreateFile(const std::string& logPrefix);
	std::string fileName;
	std::mutex mutex;
	FileWriter* filewriter;
public:
	FileLogger(LogLevel logLevel, std::string logPrefix = "log_");
	void Execute(const std::string& message);
	~FileLogger();
	const std::string& getFileName();
};

