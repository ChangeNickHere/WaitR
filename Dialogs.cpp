#include "Dialogs.h"
#include <windows.h>
#include <shlobj.h>
#include <string>


using namespace System::Windows::Forms;


std::string Dialogs::getFileName()
{
	OPENFILENAMEA ofn;
	char szFile[100] = { 0 };
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileNameA(&ofn) == TRUE)
	{
		return ofn.lpstrFile;
	}
    return std::string();
}

System::String^ Dialogs::getFolderName()
{
	System::String^ folder;

	FolderBrowserDialog^ fd;
	fd = gcnew System::Windows::Forms::FolderBrowserDialog;

	// Show the FolderBrowserDialog.
	System::Windows::Forms::DialogResult result = fd->ShowDialog();
	if (result == ::DialogResult::OK)
	{
		folder = fd->SelectedPath;
	}
	return folder;
}

