#pragma once
#include <string>
#include "Helper.h"
#include <vector>
#include <string>
#include <typeinfo>

/*
* Name space for manualy created dialog forms
*/
namespace Dialogs
{
	/*
	* Form that will return path to user selected foldere
	*/
	std::string getFolderName();

	/*
	* Selecting servers dialog returns selected servers or empty vector
	* 
	* 1) Dymicaly create chceck boxes for each location
	* 2) On OK click add all chced locations to vector
	* 3) Return vector of user selected locations
	* 
	*/
	std::vector<Helper::Location> selectLocations(std::vector<Helper::Location> locations);

	/*
	* Dialog that returs suffix(string) for folder can be empty
	* Pop up that will ask user if he wants to add some suffix to folder name
	*/ 
	std::string getSuffix();
};

