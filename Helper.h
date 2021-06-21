#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include "Location.h"
#include <fstream>

using namespace System;

namespace Helper
{
	std::string getFolderNameFromPath(std::string path, std::string delimiter);
	std::string getFolderPath(std::string path);
	std::string SysStringToStd(System::String^ s);
	std::vector<Location> parseConfig(std::string configPath);
	void writeConfig(Location loc, std::string configFile);
};

