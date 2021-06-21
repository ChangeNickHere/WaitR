#include "Helper.h"

std::string Helper::getFolderNameFromPath(std::string path, std::string delimiter)
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

std::string Helper::getFolderPath(std::string path)
{
    size_t pos;
    pos = path.find_last_of("/\\");
    std::string folderName = path.substr(0, pos);

    return folderName;
}

std::string Helper::SysStringToStd(System::String^ s)
{
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    std::string out = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return out;
}

std::vector<Location> Helper::parseConfig(std::string configPath)
{
    std::string line = "";
    std::ifstream config(configPath);
    Location loc;
    std::vector<Location> locations;    
    while (std::getline(config, line))
    {
        if (line.empty() || line[0] == '#')
        {
            continue;
        }
        if (line[0] == '=')
        {
            locations.push_back(loc);
        }
        std::size_t delimiter = line.find("=");
        std::string name = line.substr(0, delimiter);
        std::string value = line.substr(delimiter + 1);
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
    config.close();
    return locations;
}

void Helper::writeConfig(Location loc, std::string configFile)
{
    std::fstream config(configFile, config.in | config.out);
    std::string line;
    int cnt = 0;
    //erase existing config for same location
    while (std::getline(config, line))
    {
        if (line.find(loc.serverName) != std::string::npos || (cnt > 0 && cnt <= 5))
        {
            line.replace(line.find(line),line.length(), "");
            cnt++;
        }
    }
    config.close();
    //
    std::ofstream config(configFile, std::ios::out | std::ios::app);
    std::string rewrite;
    if (loc.rewrite)
        rewrite = "true";
    else
        rewrite = "false";
    //write out new config
    config << "servername=" << loc.serverName << std::endl;
    config << "programfolder=" << loc.programFolder << std::endl;
    config << "xmlfilepath=" << loc.xlmPath << std::endl;
    config << "backup=" << loc.backupPath << std::endl;
    config << "rewrite=" << rewrite << std::endl;
    config << std::string(loc.backupPath.length(), '=') << std::endl;
    config.close();
}

