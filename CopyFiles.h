#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include "Helper.h"

class CopyFiles
{
protected:
    std::vector<Helper::Location> locations;
    std::string source;
    std::string folderName;

public:
    std::string getSource() const;
    std::string getFolderName() const;
    std::vector<Helper::Location> getLocations() const;
    void setSource(const std::string & source);
    void setFolderName(const std::string & folderName);
    void setLocations(const std::vector<Helper::Location> & locations);

    virtual void copy() = 0;
    CopyFiles() = default;
    ~CopyFiles() = default;
};

