#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>

using namespace System;

namespace Helper
{
	std::string getFolderNameFromPath(std::string path, std::string delimiter);
	std::string getFolderPath(std::string path);
	std::string SysStringToStd(System::String^ s);
};

