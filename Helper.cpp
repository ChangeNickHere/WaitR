#include "Helper.h"

std::string Helper::getFolderNameFromPath(std::string path, std::string delimiter)
{
    size_t pos = 0;
    std::string folder;
    while ((pos = path.find(delimiter)) != std::string::npos) 
    {
        folder = path.substr(pos+1, path.length());
        path.erase(0, pos + delimiter.length());
    }
	return folder;
}

std::string Helper::getFolderPath(std::string path)
{
    size_t pos;
    pos = path.find_last_of("/\\");
    std::string folderName = path.substr(0, pos);

    return folderName;
}

std::string Helper::SysStringToStd(System::String^ s)
{
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    std::string out = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return out;
}

