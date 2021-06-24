#include "Backup.h"

void Backup::copy() 
{
    // Init
    Logger log;
    std::string source = this->getSource();
    std::string folderName = this->getFolderName();
    std::vector<Helper::Location> locations = this->getLocations();
    std::string fullpath = "";

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

    log.info("Backing up on " + std::to_string(locations.size()) + " server(s).");

    // set copy options
    const auto copyOptions = std::filesystem::copy_options::overwrite_existing |
        std::filesystem::copy_options::update_existing |
        std::filesystem::copy_options::recursive;
    
    // Iterate throught locations
    for (const auto& location : locations)
    {
        // Show working server
        progBar->Text = gcnew System::String(location.serverName.c_str());
        frm->Text = gcnew System::String(location.serverName.c_str());

        fullpath = location.backupPath + folderName + "\\";

        //copy folder struct
        try
        {
            std::filesystem::copy(source, fullpath, copyOptions);
        }
        catch (std::filesystem::filesystem_error const& ex)
        {
            log.error("On server: " + location.serverName + " during copy folder structure.");
            log.error(ex.what());
            log.error("From path: " + ex.path1().string());
            log.error("To path: "+ ex.path2().string());
        }

        fullpath += "App\\";
        std::string backup = fullpath + "Backup\\";

        try
        {
            // create backup dir
            std::filesystem::create_directory(backup);
        }
        catch (std::filesystem::filesystem_error const& ex)
        {
            log.error("On server: " + location.serverName + " during creation of backup folder.");
            log.error(ex.what());
        }
        catch (std::exception const& ex)
        {
            log.error(ex.what());
        }

        // iterate throught files in directory
        for (const auto& file : std::filesystem::directory_iterator(fullpath))
        {
            // filter only files
            if (std::filesystem::is_directory(file.path()))
            {
                continue;
            }

            std::string filename = file.path().filename().string();
            std::filesystem::file_status s = std::filesystem::file_status{};
            std::string programFile = location.programFolder + "\\" + filename;

            if (std::filesystem::status_known(s) ? std::filesystem::exists(s) : std::filesystem::exists(programFile))
            {
                //backup files from program folder
                try
                {
                    std::filesystem::copy_file(programFile, backup + filename);
                }
                catch (std::filesystem::filesystem_error const& ex)
                {
                    log.error("On server: " + location.serverName + " during file backup.");
                    log.error(ex.what());
                    log.error("From path: " + ex.path1().string());
                    log.error("To path: " + ex.path2().string());
                }
                catch (std::exception const& ex)
                {
                    log.error(ex.what());
                }
            }
            try
            {
                //rewrite
                std::filesystem::copy_file(file.path(), programFile, std::filesystem::copy_options::overwrite_existing);
            }
            catch (std::filesystem::filesystem_error const& ex)
            {
                log.error("On server: " + location.serverName + " during rewriting files in program folder.");
                log.error(ex.what());
                log.error("From path: " + ex.path1().string());
                log.error("To path: " + ex.path2().string());
            }
            catch (std::exception const& ex)
            {
                log.error(ex.what());
            }
            // Update progress bar
            progBar->PerformStep();
        }

        //delete XML file
        if (remove(location.xlmPath.c_str()) != 0)
        {
            log.error("Error deleting file on server " + location.serverName);
        }
        else
        {
            log.info("XML file successfully deleted on server " + location.serverName);
        }
    }

    // Close progress bar form
    frm->Close();
}
