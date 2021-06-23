//#include "config.h"
// my
#include "Dialogs.h"
#include "Helper.h"
#include "Backup.h"
#include "Rewrite.h"
#include "CopyFiles.h"
#include "Logger.h"

// forms
#include "WaitRMenu.h"

// libs
#include <filesystem>
//#include <windows.h>
#include <string>
#include <iostream>

//#include <boost/log/trivial.hpp>
// 
// Gobal Variables and declarations.
// 
 

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

namespace fs = std::filesystem;

[STAThreadAttribute]
void main() 
{
    //Helper::Location loc;
    //loc.backupPath = "C:\\Users\\Filip\\Desktop\\testfilesys\\FDSFiles\\Backup\\";
    //loc.xlmPath = "C:\\Users\\Filip\\Desktop\\testfilesys\\xmlfile.txt";
    //loc.programFolder = "C:\\Users\\Filip\\Desktop\\testfilesys\\program\\";
    //loc.rewrite = true;
    //loc.serverName = "Server1";
    
 //   String^ folder = gcnew System::String("");
 ///*   folder = "asdasdas";Dialogs::getFolderName();*/

 //   //str = FileDialogs::BrowseFolder("");
	//// Now simpley display the file name 
 //   //MessageBox::Show(str2);
 //   //MessageBox::Show(str3);

 //   if (String::IsNullOrEmpty(folder))
 //   {
 //       MessageBox::Show("Empty filepath!");
 //       return;
 //   }

    //Helper::writeConfig(loc, "C:\\Users\\Filip\\Documents\\JCU\\CPP\\FDS\\config.txt");
    //
    //vector<Helper::Location> locations = Helper::parseConfig("C:\\Users\\Filip\\Documents\\JCU\\CPP\\FDS\\config.txt");
    //locations.push_back(loc);
    //vector<Helper::Location> locationsOUT = Dialogs::selectLocations(locations);
    
    //string s = Dialogs::getSuffix();

    //String^ str3 = gcnew String(locations[1].serverName.c_str());
    //String^ str4 = gcnew String(locations[1].backupPath.c_str());
    //String^ str5 = gcnew String(locations[1].programFolder.c_str());
    //String^ str6 = gcnew String(locations[1].xlmPath.c_str());

    //MessageBox::Show(str3);
    //MessageBox::Show(str4);
    //MessageBox::Show(str5);
    //MessageBox::Show(str6);

    //string source = Helper::SysStringToStd(folder);
    //string delimiter = "\\";
    //string folderName = Helper::getFolderNameFromPath(source, delimiter);

   //; fs::copy_file("C:\\Users\\Filip\\Desktop\\testfilesys\\FDSFiles\\Backup\\V.VPR.35.2021.0526.5\\App\\text123.txt", loc.programFolder+"text123.txt", fs::copy_options::overwrite_existing);

    //std::string source = Dialogs::getFolderName();
    //std::string folderName = Helper::getFolderNameFromPath(source, "\\");

    //Backup bcp;
    //bcp.setSource(source);
    //bcp.setFolderName(folderName);
    //bcp.setLocations(locations);

    //bcp.copy();

  /*  Rewrite rwt;
    rwt.setSource(source);
    rwt.setFolderName(folderName);
    rwt.setLocations(locations);

    rwt.copy();*/

    //MessageBox::Show(folder);
    //delete folder;

    

    //String^ str3 = gcnew String(folderName.c_str());
    //MessageBox::Show(str3);
    //
    //const auto copyOptions = fs::copy_options::overwrite_existing |
    //    fs::copy_options::update_existing |
    //    fs::copy_options::recursive;

    //string backup = "C:\\Users\\Filip\\Desktop\\FDSFiles\\Backup\\" + folderName + "\\";

    //fs::copy(source, backup, copyOptions);

    
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    //WinformCDemo is your project name
    WaitR::WaitRMenu form;
    Application::Run(% form);
}