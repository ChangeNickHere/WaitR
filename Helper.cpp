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
std::vector<Helper::Location> Helper::parseConfig()
{
    // init
    std::filesystem::path currPath = std::filesystem::current_path();
    std::string configPath = currPath.u8string()+"\\Config.txt";
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

// Function that writes new server configuration to config file. If configuration exist then it will rewrite it.
void Helper::writeConfig(const Helper::Location & loc)
{
    // init
    Logger log;
    std::string rewrite;
    std::string configFile = "./Config.txt";

    // get all locations from config
    std::vector<Location> locations = Helper::parseConfig();
  
    // find duplicates and delete them
    for (unsigned i = 0; i < locations.size();)
    {
        if (locations[i].serverName == loc.serverName)
        {
            
            // log erased element
            log.info("Duplicate " + loc.serverName + " erased");
            
            // erase same element
            locations.erase(locations.begin() + i);
        }
        else
        {
            i++;
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
//
//void Helper::copyProcessWrapper()
//{
//    // select source folder
//    std::string source = Dialogs::getFolderName();
//
//    // get suffix
//    std::string suffix = Dialogs::getSuffix();
//
//    std::string foldername = Helper::getFolderNameFromPath(source, "\\");
//    
//    if (suffix != "")
//    {
//        foldername += "_" + suffix;
//    }
//
//    // from config get servers properties
//    std::vector<Helper::Location> locations = Helper::parseConfig("C:\\Users\\Filip\\Documents\\JCU\\CPP\\FDS\\config.txt");
//
//    // select servers
//    // TODO
//    locations = Dialogs::selectLocations(locations);
//
//    std::vector<Helper::Location> backupLocations;
//    std::vector<Helper::Location> rewriteLocations;
//
//    // sort locations for rewrite or backup
//    for (const Helper::Location& loc : locations)
//    {
//        if (loc.rewrite)
//        {
//            rewriteLocations.push_back(loc);
//            continue;
//        }
//        backupLocations.push_back(loc);
//    }
//    
//    Rewrite rewrite;
//    rewrite.setSource(source);
//    rewrite.setFolderName(foldername);
//    rewrite.setLocations(rewriteLocations);
//    rewrite.copy();
//
//    Backup backup;
//    backup.setSource(source);
//    backup.setFolderName(foldername);
//    backup.setLocations(backupLocations);
//    backup.copy();
//
//    MessageBox::Show("Completed");
//}

