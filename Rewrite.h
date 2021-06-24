#pragma once
#include "CopyFiles.h"
#include <vector>
#include <string>
#include "Helper.h"

/*==============================================================
* 
* Class that inherits from copy files
* Purpose is to rewrite existing files in folder
*
*==============================================================*/
class Rewrite :
    public CopyFiles
{  
public:
    Rewrite() = default;
    ~Rewrite() = default;

    /*
    * Copy function inherited from Copy files virtual copy
    *
    *   For all locations:
    *   1) Copy and overwrite existing file in program folder
    *   2) Continue to other location
    *   3) Showing locations progres on progress bar
    *
    *   Function will log followings:
    *   1) On how many servers will try to copy files
    *   2) Exception given by copy files or other std exception that can occur during copying
    *
    */
    void copy() override;
};

