#pragma once
#include "Logger_Interface.h"
class ConsoleLogger :
	public Logger_Interface
{
public:
	ConsoleLogger(LogLevel logLevelconst);
	~ConsoleLogger();
	void Execute(const std::string& message);
};

