#include "Backup.h"

using namespace std;
namespace fs = std::filesystem;

void Backup::copy() 
{
    //init
    Logger log;
    string source = this->getSource();
    string folderName = this->getFolderName();
    vector<Helper::Location> locations = this->getLocations();
    string fullpath = "";

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

    log.info("Backing up on " + std::to_string(locations.size()) + " server(s).");

    // set copy options
    const auto copyOptions = fs::copy_options::overwrite_existing |
        fs::copy_options::update_existing |
        fs::copy_options::recursive;
    
    // Iterate throught locations
    for (const auto& location : locations)
    {
        fullpath = location.backupPath + folderName + "\\";
        progBar->Text = gcnew String(location.serverName.c_str());
        frm->Text = gcnew String(location.serverName.c_str());
        //copy folder struct
        try
        {
            fs::copy(source, fullpath, copyOptions);
        }
        catch (std::filesystem::filesystem_error const& ex)
        {
            log.error("On server: " + location.serverName + " during copy folder structure.");
            log.error(ex.what());
            log.error(ex.path1().string());
            log.error(ex.path2().string());
        }

        fullpath += "App\\";
        string backup = fullpath + "Backup\\";

        try
        {
            // create backup dir
            fs::create_directory(backup);
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
            if (fs::is_directory(file.path()))
            {
                continue;
            }

            string filename = file.path().filename().string();
            fs::file_status s = fs::file_status{};
            string programFile = location.programFolder + "\\" + filename;

            if (fs::status_known(s) ? fs::exists(s) : fs::exists(programFile))
            {
                //backup files from program folder
                try
                {
                    fs::copy_file(programFile, backup + filename);
                }
                catch (std::filesystem::filesystem_error const& ex)
                {
                    log.error("On server: " + location.serverName + " during file backup.");
                    log.error(ex.what());
                    log.error(ex.path1().string());
                    log.error(ex.path2().string());
                }
                catch (std::exception const& ex)
                {
                    log.error(ex.what());
                }
            }
            try
            {
                //rewrite
                fs::copy_file(file.path(), programFile, fs::copy_options::overwrite_existing);
            }
            catch (std::filesystem::filesystem_error const& ex)
            {
                log.error("On server: " + location.serverName + " during rewriting files in program folder.");
                log.error(ex.what());
                log.error(ex.path1().string());
                log.error(ex.path2().string());
            }
            catch (std::exception const& ex)
            {
                log.error(ex.what());
            }
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
    frm->Close();
}
