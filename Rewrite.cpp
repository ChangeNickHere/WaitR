#include "Rewrite.h"

using namespace std;
namespace fs = std::filesystem;

void Rewrite::copy()
{
    //init
    Logger log;
    string source = this->getSource();
    vector<Helper::Location> locations = this->getLocations();
    string fullpath = source + "\\App\\";
    string filename;
    string programFile;

    //iterate through locations
    for (const Helper::Location& location : locations)
    {
        // iterate throught files in folder
        for (const auto& file : std::filesystem::directory_iterator(fullpath))
        {
            // filter only files
            if (fs::is_directory(file.path()))
            {
                continue;
            }
            // get file paths
            filename = file.path().filename().string();
            programFile = location.programFolder + "\\" + filename;

            //overwrite existing files in program folder
            try
            {
                fs::copy_file(file.path(), programFile, fs::copy_options::overwrite_existing);
            }
            catch (std::filesystem::filesystem_error const& ex)
            {
                log.error("On server: " + location.serverName + " during file overwriting.");
                log.error(ex.what());
                log.error(ex.path1().string());
                log.error(ex.path2().string());
            }
        }

    }
}
