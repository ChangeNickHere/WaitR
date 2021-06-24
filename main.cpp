#include "WaitRMenu.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() 
{ 
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create menu form and run it as app window
    WaitR::WaitRMenu form;
    Application::Run(% form);
}