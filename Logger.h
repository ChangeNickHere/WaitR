#pragma once
#include <fstream>
#include <string>
#include <ctime>
#include "Helper.h"
#include <filesystem>

/*
	Simple logger class.
	Static stream sharing with other modules.
	All logs are stored in one files named mdy_HM_log.txt
*/
class Logger
{
private:
	static std::ofstream stream;
	static std::string logFile;
	static int cnt;

public:
	void initCheck();
	void error(const std::string& text) const;
	void debug(const std::string& text) const;
	void info(const std::string & text) const;

	Logger();
	~Logger();
};

