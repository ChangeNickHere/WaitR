#pragma once
#include <fstream>
#include <string>
#include <ctime>
#include "Helper.h"
#include <filesystem>

class Logger
{
private:
	static std::ofstream stream;
	static std::string logFile;
	static int cnt;

public:
	void initCheck();
	void error(const std::string& text);
	void debug(const std::string& text);
	void info(const std::string & text);

	Logger();
	~Logger();
};

