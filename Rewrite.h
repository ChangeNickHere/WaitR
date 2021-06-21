#pragma once
#include "CopyFiles.h"
#include <vector>
#include <string>
#include "Location.h"

class Rewrite :
    public CopyFiles
{  
public:
    void copy() override;
    Rewrite() = default;
    ~Rewrite() = default;
};

