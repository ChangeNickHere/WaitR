#pragma once
#include <string>
#include "Helper.h"
#include <vector>
#include <string>
#include <typeinfo>

namespace Dialogs
{
	//static std::string getFileName();
	std::string getFolderName();

	// Selecting servers dialog returns selected servers or empty vector;
	std::vector<Helper::Location> selectLocations(std::vector<Helper::Location> locations);

	// Dialog that returs suffix (string) for folder can be empty
	std::string getSuffix();
};

