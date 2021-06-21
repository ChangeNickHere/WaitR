#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include "Location.h"

class CopyFiles
{
protected:
    std::vector<Location> locations;
    std::string source;
    std::string folderName;

public:
    std::string getSource();
    std::string getFolderName();
    std::vector<Location> getLocations();
    void setSource(std::string source);
    void setFolderName(std::string folderName);
    void setLocations(std::vector<Location>);

    virtual void copy() = 0;
    CopyFiles() = default;
    ~CopyFiles() = default;
};

