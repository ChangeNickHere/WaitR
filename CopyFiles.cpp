#include "CopyFiles.h"



std::string CopyFiles::getSource()
{
    return this->source;
}

std::string CopyFiles::getFolderName()
{
    return this->folderName;
}

void CopyFiles::setSource(std::string source)
{
    this->source = source;
}

void CopyFiles::setFolderName(std::string folderName)
{
    this->folderName = folderName;
}

void CopyFiles::setLocations(std::vector<Location> locations)
{
    this->locations = std::move(locations);
}

std::vector<Location> CopyFiles::getLocations()
{
    return this->locations;
}