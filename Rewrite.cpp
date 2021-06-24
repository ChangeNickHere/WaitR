#include "Rewrite.h"



void Rewrite::copy()
{
    // Init
    Logger log;
    std::string source = this->getSource();
    std::vector<Helper::Location> locations = this->getLocations();
    std::string fullpath = source + "\\App\\";
    std::string filename;
    std::string programFile;

    // Create and set progress bar
    System::Windows::Forms::ProgressBar^ progBar = gcnew System::Windows::Forms::ProgressBar();
    progBar->Name = L"Copying...";
    progBar->Text = L"Copying...";
    progBar->Minimum = 1;
    progBar->Maximum = locations.size();
    progBar->Step = 1;
    progBar->Show();

    // Create form for progress bar
    System::Windows::Forms::Form^ frm = gcnew  System::Windows::Forms::Form();
    frm->Controls->Add(progBar);
    frm->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    frm->Name = L"Copy and backup";
    frm->Show();

    //iterate through locations
    for (const Helper::Location& location : locations)
    {
        // Show working server
        progBar->Text = gcnew System::String(location.serverName.c_str());
        frm->Text = gcnew System::String(location.serverName.c_str());

        // Iterate throught files in folder
        for (const auto& file : std::filesystem::directory_iterator(fullpath))
        {
            // filter only files
            if (std::filesystem::is_directory(file.path()))
            {
                continue;
            }
            // get file paths
            filename = file.path().filename().string();
            programFile = location.programFolder + "\\" + filename;

            //overwrite existing files in program folder
            try
            {
                std::filesystem::copy_file(file.path(), programFile, std::filesystem::copy_options::overwrite_existing);
            }
            catch (std::filesystem::filesystem_error const& ex)
            {
                log.error("On server: " + location.serverName + " during file overwriting.");
                log.error(ex.what());
                log.error("From path: " + ex.path1().string());
                log.error("To path: " + ex.path2().string());
            }
            catch (std::exception const& ex)
            {
                log.error(ex.what());
            }
        }

        // Update progress bar
        progBar->PerformStep();
    }

    // Close progress bar form
    frm->Close();
}
