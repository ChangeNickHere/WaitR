#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>

#include "Logger.h"


using namespace System;
using namespace System::Windows::Forms;

/*
	Namespace to keep things organised
*/
namespace Helper
{
	// Structure that keeps server properties in one place
	struct Location
	{
		std::string programFolder;
		std::string xlmPath;
		std::string backupPath;
		std::string serverName;
		bool rewrite;
	};

	// Function that returns Folder name from path
	std::string getFolderNameFromPath(std::string path, const std::string & delimiter);

	// Function returns folder path if file path obtained
	std::string getFolderPath(const std::string & path);
	
	// Helper function for converting System::String ^ to std::string
	std::string SysStringToStd(System::String^ s);
	
	// Function for parsing config that returns vector of locations properties
	std::vector<Location> parseConfig();
	
	// Function that writes new server configuration to config file. If configuration exist then it will rewrite it.
	void writeConfig(const Location & loc);


	/*=================================================
	*	Function to wrap all segments of copy process:
	*		1) Get source
	*		2) Get suffix
	*		3) Combine folder name 
	*		4) Get config
	*		5) Select copy locations
	*		6) Copy backup
	*		7) Copy rewrite
	===================================================*/
	void copyProcessWrapper();
};

