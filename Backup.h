#pragma once
#include "CopyFiles.h"
#include <vector>
#include <string>
#include <cstdio>

class Backup :
    public CopyFiles
{
public:
    void copy() override;
    Backup() = default;
    ~Backup() = default;
};

