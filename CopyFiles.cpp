#include "CopyFiles.h"



std::string CopyFiles::getSource() const
{
    return this->source;
}

std::string CopyFiles::getFolderName() const
{
    return this->folderName;
}

void CopyFiles::setSource(const std::string & source)
{
    this->source = source;
}

void CopyFiles::setFolderName(const std::string & folderName)
{
    this->folderName = folderName;
}

void CopyFiles::setLocations(const std::vector<Helper::Location> & locations)
{
    this->locations = std::move(locations);
}

std::vector<Helper::Location> CopyFiles::getLocations() const
{
    return this->locations;
}