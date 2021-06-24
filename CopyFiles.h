#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include "Helper.h"

/*
* Class for copy files with virtual method
*/
class CopyFiles
{
protected:
    std::vector<Helper::Location> locations;
    std::string source;
    std::string folderName;

public:
    CopyFiles() = default;
    ~CopyFiles() = default;

    /*
    * Getters
    */
    std::string getSource() const;
    std::string getFolderName() const;
    std::vector<Helper::Location> getLocations() const;

    /*
    * Setters
    */
    void setSource(const std::string & source);
    void setFolderName(const std::string & folderName);
    void setLocations(const std::vector<Helper::Location> & locations);

    /*
    * Virtual method for copiing files
    */
    virtual void copy() = 0;
};

