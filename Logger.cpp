#include "Logger.h"

std::ofstream Logger::stream;
std::string Logger::logFile;
int Logger::cnt;

Logger::Logger()
{
	initCheck();
	cnt++;
}

Logger::~Logger()
{
	cnt--;
	if (cnt == 0)
	{
		stream.close();
	}
}

void Logger::initCheck()
{
	if (!stream.is_open())
	{
		char buffer[12];
		std::filesystem::path currPath = std::filesystem::current_path() ;
		std::time_t result = std::time(nullptr);
		struct tm* timeinfo;
		timeinfo = localtime(&result);
		strftime(buffer, 12,"%d%m%y_%H%M", timeinfo);
		std::string tim = Helper::SysStringToStd(result.ToString());
		logFile = currPath.u8string() + "\\" + buffer + "_log.txt";
		stream.open(logFile, std::ios::out);
	}
}

void Logger::error(const std::string& text) const
{
	stream << "Error: " << text << std::endl;
}

void Logger::debug(const std::string& text) const
{
	stream << "Debug: " << text << std::endl;
}

void Logger::info(const std::string& text) const
{
	stream << "Info: " << text << std::endl;
}