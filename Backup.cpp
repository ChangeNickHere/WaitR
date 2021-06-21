#include "Backup.h"
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

void Backup::copy() 
{
    //init
    string source = this->getSource();
    string folderName = this->getFolderName();
    vector<Location> locations = this->getLocations();
    string fullpath = "";

    const auto copyOptions = fs::copy_options::overwrite_existing |
        fs::copy_options::update_existing |
        fs::copy_options::recursive;
    cout << "hey" << endl;
    for (const auto & location : locations)
    {
        fullpath = location.backupPath + folderName + "\\";
        // log this later
        //copy folder struct
        fs::copy(source, fullpath, copyOptions);
        cout << "hey2" << endl;

        fullpath += "App\\";
        std::vector<std::filesystem::path> files;
        string backup = fullpath + "Backup\\";
        fs::create_directory(backup);
        for (const auto& file : std::filesystem::directory_iterator(fullpath))
        {
            if (fs::is_directory(file.path()))
            {
                continue;
            }
            string filename = file.path().filename().string();
            fs::file_status s = fs::file_status{};
            string programFile = location.programFolder + "\\" + filename;
            if (fs::status_known(s) ? fs::exists(s) : fs::exists(programFile))
            {
                //backup
                fs::copy_file(programFile, backup+filename);
            }
            //rewrite
            fs::copy_file(file.path(), programFile, fs::copy_options::overwrite_existing);
        }

        //delete XML file
        if (remove(location.xlmPath.c_str()) != 0)
            //perror("Error deleting file");
            //log this
            return;
        else
            //puts("File successfully deleted");
            //log this
            return;
        return;
    }
    
}
