#pragma once
#include <iostream>
#include <fstream>
#include <vector>
class FileWriter
{
public:
	FileWriter();
	~FileWriter();
	bool WriteToFile(const std::string & fileName, const std::string& msg);
	bool CreateFile(const std::string& filename);
};

