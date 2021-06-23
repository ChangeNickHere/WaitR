#pragma once
#include "CopyFiles.h"
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <filesystem>

class Backup :
    public CopyFiles
{
public:
    void copy() override;
    Backup() = default;
    ~Backup() = default;
};

