#pragma once
#include "CopyFiles.h"
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <filesystem>

/*==============================================================
* Class that inherits from copy files
* Purpose is to copy files and back up existing files in folder
* 
*==============================================================*/

class Backup :
    public CopyFiles
{
public:
    Backup() = default;
    ~Backup() = default;

    /*
    * Copy function inherited from Copy files virtual copy
    * 
    *   For all locations:
    *   1) Copy source folder under the source folder name and suffix to "backup" folder on server
    *   2) In copied folder app subfolder it will create backup folder
    *   3) If some file from app subfolder exists it will be backed up into previously created folder
    *   4) Delete XML file given by config
    *   5) Continue to other location
    *   6) Showing locations progres on progress bar 
    * 
    *   Function will log followings:
    *   1) On how many servers will try to copy files
    *   2) Exception given by copy files or other std exception that can occur during copying
    *   3) If XML file was deleted
    * 
    */
    void copy() override;
};

