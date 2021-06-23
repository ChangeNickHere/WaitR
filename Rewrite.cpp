#include "Rewrite.h"

using namespace std;
namespace fs = std::filesystem;

void Rewrite::copy()
{
    //init
    Logger log;
    string source = this->getSource();
    vector<Helper::Location> locations = this->getLocations();
    string fullpath = source + "\\App\\";
    string filename;
    string programFile;

    // Create and set progress bar
    System::Windows::Forms::ProgressBar^ progBar = gcnew System::Windows::Forms::ProgressBar();
    progBar->Name = L"Copying...";
    progBar->Text = L"Copying...";
    progBar->Minimum = 1;
    progBar->Maximum = locations.size();
    progBar->Step = 1;
    progBar->Show();

    // Create form for progress bar
    Form^ frm = gcnew Form();
    frm->Controls->Add(progBar);
    frm->StartPosition = FormStartPosition::CenterScreen;
    frm->Name = L"Copy and backup";
    frm->Show();

    //iterate through locations
    for (const Helper::Location& location : locations)
    {
        progBar->Text = gcnew String(location.serverName.c_str());
        frm->Text = gcnew String(location.serverName.c_str());
        // iterate throught files in folder
        for (const auto& file : std::filesystem::directory_iterator(fullpath))
        {
            // filter only files
            if (fs::is_directory(file.path()))
            {
                continue;
            }
            // get file paths
            filename = file.path().filename().string();
            programFile = location.programFolder + "\\" + filename;

            //overwrite existing files in program folder
            try
            {
                fs::copy_file(file.path(), programFile, fs::copy_options::overwrite_existing);
            }
            catch (std::filesystem::filesystem_error const& ex)
            {
                log.error("On server: " + location.serverName + " during file overwriting.");
                log.error(ex.what());
                log.error(ex.path1().string());
                log.error(ex.path2().string());
            }
            catch (std::exception const& ex)
            {
                log.error(ex.what());
            }
        }

    }
    frm->Close();
}
