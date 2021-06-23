//#include "config.h"
//// my
//#include "Dialogs.h"
//#include "Helper.h"
//#include "Backup.h"
//#include "Rewrite.h"
//#include "CopyFiles.h"
//#include "Logger.h"

// forms
#include "WaitRMenu.h"

//// libs
//#include <filesystem>
////#include <windows.h>
//#include <string>
//#include <iostream>

//#include <boost/log/trivial.hpp>
// 
// Gobal Variables and declarations.
// 
 

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() 
{ 
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    


    WaitR::WaitRMenu form;
    Application::Run(% form);
}