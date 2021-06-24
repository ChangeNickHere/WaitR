#pragma once
#include <fstream>
#include <string>
#include <ctime>
#include "Helper.h"
#include <filesystem>

/*
*	Simple logger class.
*	Static stream sharing with other modules.
*	All logs are stored in one files named dmy_HM_log.txt (day month year _ hour minute)
*/
class Logger
{
private:
	static std::ofstream stream;
	static std::string logFile;
	static int cnt;

public:
	/*
	* Call inti check
	* Each time constructor is called it will increase cnt 
	*/
	Logger();

	/*
	*  Each time destructor is called it will decrease cnt
	*  if cnt is 0 it will close stream
	*/
	~Logger();

	/*
	* 
	* Function for constructor that will check if stream is open
	* If not it will open new file with name styled like dmy_HM (day month year _ hour minute)
	* and set logFile name
	* 
	*/
	void initCheck();

	/*
	* Simple formated write to log file
	*/
	void error(const std::string& text) const;

	/*
	* Simple formated write to log file
	*/
	void debug(const std::string& text) const;
	
	/*
	* Simple formated write to log file
	*/
	void info(const std::string & text) const;

};

