#include "Helper.h"

// Function that returns Folder name from path
std::string Helper::getFolderNameFromPath(std::string path, const std::string & delimiter)
{
    size_t pos = 0;
    std::string folder;
    while ((pos = path.find(delimiter)) != std::string::npos) 
    {
        folder = path.substr(pos+1, path.length());
        path.erase(0, pos + delimiter.length());
    }
	return folder;
}

// Function returns folder path if file path obtained
std::string Helper::getFolderPath(const std::string & path)
{
    size_t pos;
    pos = path.find_last_of("/\\");
    std::string folderName = path.substr(0, pos);
    
    return folderName;
}

// Helper function for converting System::String ^ to std::string
std::string Helper::SysStringToStd(System::String^ s)
{
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    std::string out = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return out;
}

// Function for parsing config that returns vector of locations properties
std::vector<Helper::Location> Helper::parseConfig(const std::string & configPath)
{
    // init
    std::string line = "";
    std::ifstream config(configPath);
    Helper::Location loc;
    std::vector<Helper::Location> locations;

    // Read config by line
    while (std::getline(config, line))
    {
        if (line.empty() || line[0] == '#')
        {
            continue;
        }
        if (line[0] == '=')
        {
            // End of location's properties push and continue for a new location
            locations.push_back(loc);
            continue;
        }

        // parse line with delimiter
        std::size_t delimiter = line.find("=");
        std::string name = line.substr(0, delimiter);
        std::string value = line.substr(delimiter + 1);

        // Assign property
        if (name == "servername")
            loc.serverName = value;
        else if (name == "programfolder")
            loc.programFolder = value;
        else if (name == "backup")
            loc.backupPath = value;
        else if (name == "xmlfilepath")
            loc.xlmPath = value;
        else if (name == "rewrite")
        {
            bool b = (value == "true");
            loc.rewrite = b;
        }
    }

    // close stream and return vector
    config.close();
    return locations;
}

void Helper::writeConfig(const Helper::Location & loc, const std::string & configFile)
{
    // init
    Logger log;
    std::string rewrite;

    // get all locations from config
    std::vector<Location> locations = Helper::parseConfig(configFile);
  
    // find duplicates elements and delete them
    for (unsigned i = 0; i < locations.size(); i++)
    {
        if (locations[i].serverName == loc.serverName)
        {
            // erase same element
            locations.erase(locations.begin() + i);
            i--;
            log.info("Duplicate " + locations[i].serverName + " erased");
        }
    }
    // push new element
    locations.push_back(loc);
    log.info("New server: " + loc.serverName + " added.");
    // init stream
    std::fstream config;
    if (config.is_open())
    {
        log.error("Config is open! In write config function.");
        MessageBox::Show("Config is open! Could not write. All actions reverted!");
        return;
    }
    // open file for read and write with append mode
    config.open(configFile, std::ios::in | std::ios::out);

    // write out all locations
    for (const Location& location : locations)
    {
        if (location.rewrite)
            rewrite = "true";
        else
            rewrite = "false";
        //write out new config
        config << "servername=" << location.serverName << std::endl;
        config << "programfolder=" << location.programFolder << std::endl;
        config << "xmlfilepath=" << location.xlmPath << std::endl;
        config << "backup=" << location.backupPath << std::endl;
        config << "rewrite=" << rewrite << std::endl;
        config << std::string(location.backupPath.length()+15, '=') << std::endl;
    }

    config.close();
}

