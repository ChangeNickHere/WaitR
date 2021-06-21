#pragma once
#include "fileBrowser.cpp"
#include <string>


static int CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);

std::string BrowseFolder(std::string saved_path)