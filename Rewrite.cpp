#include "Rewrite.h"

using namespace std;
namespace fs = std::filesystem;

void Rewrite::copy()
{
    //init
    string source = this->getSource();
    vector<Location> locations = this->getLocations();
    string fullpath = source + "\\App\\";
    
    //
    for (const Location& location : locations)
    {
        for (const auto& file : std::filesystem::directory_iterator(fullpath))
        {
            if (fs::is_directory(file.path()))
            {
                continue;
            }
            string filename = file.path().filename().string();
            string programFile = location.programFolder + "\\" + filename;
            //rewrite
            fs::copy_file(file.path(), programFile, fs::copy_options::overwrite_existing);
        }

    }
}
