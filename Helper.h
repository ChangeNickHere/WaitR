#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>

#include "Logger.h"

/*
*	Namespace to keep things organised
*/
namespace Helper
{
	/*
	* Key structure for server properties
	*/
	struct Location
	{
		std::string programFolder;
		std::string xlmPath;
		std::string backupPath;
		std::string serverName;
		bool rewrite;
	};

	/*
	* Function that returns Folder name from path 
	*/ 
	std::string getFolderNameFromPath(std::string path, const std::string & delimiter);

	/*
	* Function returns folder path if file path obtained
	*/
	std::string getFolderPath(const std::string & path);
	
	/*
	* Helper function for converting System::String ^ to std::string
	*/
	std::string SysStringToStd(System::String^ s);
	
	/*
	* Function for parsing config that returns vector of locations properties
	* 1) Read config file
	* 2) Iterate through lines
	* 3) if line starts '#' or is empty skip it
	* 4) Split line with delimiter
	* 5) Check parameter and fill relevant location property
	* 6) if line starts '=' push location into vector
	* 7) After all lines close file stream and return vector of locations
	*/
	std::vector<Location> parseConfig();
	
	/*
	* Function that writes new server configuration to config file. If configuration exist then it will rewrite it.
	* 1) Load all locations from config file
	* 2) Check for duplicates
	* 3) Delete duplicates 
	*		If some one wants to reconfigure existiong server location it will use server name as key
	*		Finds old server location and deletes it
	* 4) Insert new location
	* 5) Write in config file
	* 6) Close file
	*/
	void writeConfig(const Location & loc);

};

