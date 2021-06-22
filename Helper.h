#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>

#include "Logger.h"

using namespace System;
using namespace System::Windows::Forms;


namespace Helper
{
	struct Location
	{
		std::string programFolder;
		std::string xlmPath;
		std::string backupPath;
		std::string serverName;
		bool rewrite;
	};
	std::string getFolderNameFromPath(std::string path, const std::string & delimiter);
	std::string getFolderPath(const std::string & path);
	std::string SysStringToStd(System::String^ s);
	std::vector<Location> parseConfig(const std::string & configPath);
	void writeConfig(const Location & loc, const std::string & configFile);
};

