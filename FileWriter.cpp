#include "pch.h"
#include "FileWriter.h"
#include <vector>
#include <iomanip>
#include <ios>
#include <cctype>
#include <string>


FileWriter::FileWriter()
{
}

FileWriter::~FileWriter()
{
}

bool FileWriter::WriteToFile(const std::string & fileName, const std::string& msg)
{
	std::ofstream file;
	std::string _msg = msg;
	file.open(fileName, std::ios::app);
	if (file.is_open())
	{
		file << _msg;
		file.close();
		return true;
	}
	return false;
}

bool FileWriter::CreateFile(const std::string & filename)
{
	std::ofstream file;
	file.open(filename);
	if (file.is_open())
	{
		file.close();
		return true;
	}
	return false;
}

