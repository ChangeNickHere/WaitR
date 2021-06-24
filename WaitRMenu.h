#pragma once
#include "config.h"
#include "Helper.h"
#include "Dialogs.h"
#include "Backup.h"
#include "Rewrite.h"
#include "Logger.h"

namespace WaitR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for WaitRMenu
	/// </summary>
	public ref class WaitRMenu : public System::Windows::Forms::Form
	{
	public:
		WaitRMenu(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WaitRMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ pictureBoxLogo;
	private: System::Windows::Forms::Button^ btnCreateConfig;
	private: System::Windows::Forms::Button^ btnCopy;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WaitRMenu::typeid));
			this->pictureBoxLogo = (gcnew System::Windows::Forms::PictureBox());
			this->btnCreateConfig = (gcnew System::Windows::Forms::Button());
			this->btnCopy = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLogo))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxLogo
			// 
			this->pictureBoxLogo->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->pictureBoxLogo->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxLogo.InitialImage")));
			this->pictureBoxLogo->Image = System::Drawing::Image::FromFile("pics\\menu.png");
			this->pictureBoxLogo->Location = System::Drawing::Point(127, 35);
			this->pictureBoxLogo->Name = L"pictureBoxLogo";
			this->pictureBoxLogo->Size = System::Drawing::Size(526, 223);
			this->pictureBoxLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBoxLogo->TabIndex = 0;
			this->pictureBoxLogo->TabStop = false;
			this->pictureBoxLogo->WaitOnLoad = true;
			// 
			// btnCreateConfig
			// 
			this->btnCreateConfig->Location = System::Drawing::Point(158, 311);
			this->btnCreateConfig->Name = L"btnCreateConfig";
			this->btnCreateConfig->Size = System::Drawing::Size(159, 23);
			this->btnCreateConfig->TabIndex = 1;
			this->btnCreateConfig->Text = L"Create config";
			this->btnCreateConfig->UseVisualStyleBackColor = true;
			this->btnCreateConfig->Click += gcnew System::EventHandler(this, &WaitRMenu::btnCreateConfig_Click);
			// 
			// btnCopy
			// 
			this->btnCopy->Location = System::Drawing::Point(476, 311);
			this->btnCopy->Name = L"btnCopy";
			this->btnCopy->Size = System::Drawing::Size(165, 23);
			this->btnCopy->TabIndex = 2;
			this->btnCopy->Text = L"Copy files";
			this->btnCopy->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnCopy->UseVisualStyleBackColor = true;
			this->btnCopy->Click += gcnew System::EventHandler(this, &WaitRMenu::btnCopy_Click);
			// 
			// WaitRMenu
			// 
			this->Icon = gcnew System::Drawing::Icon("pics\\icon.ico");
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->ClientSize = System::Drawing::Size(803, 398);
			this->Controls->Add(this->btnCopy);
			this->Controls->Add(this->btnCreateConfig);
			this->Controls->Add(this->pictureBoxLogo);
			this->Name = L"WaitR Menu";
			this->Text = L"WaitR Menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLogo))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCreateConfig_Click(System::Object^ sender, System::EventArgs^ e) {
		WaitR::config configForm;
		configForm.ShowDialog();
	}

	   /*=================================================
	   *	Function to wrap all segments of copy process:
	   *		1) Get source
	   *		2) Get suffix
	   *		3) Combine folder name
	   *		4) Get config
	   *		5) Select copy locations
	   *		6) Copy backup
	   *		7) Copy rewrite
	   ===================================================*/
	private: System::Void btnCopy_Click(System::Object^ sender, System::EventArgs^ e) {
		
		// Create logger for logging events
		Logger log;

		// Select folder which will be used as source for copy
		std::string source = Dialogs::getFolderName();
		log.info("Source set to: " + source);

		// Get suffix
		// Can be an empty string if no suffix is wanted
		std::string suffix = Dialogs::getSuffix();
		log.info("Suffix set to: " + suffix);

		// Newly copied folder will have same and as source folder
		std::string foldername = Helper::getFolderNameFromPath(source, "\\");

		// If suffix is not enmpty add suffix to folder name
		if (suffix != "")
		{
			foldername += "_" + suffix;
		}
		log.info("Backup folder name set to: " + foldername);

		// Get all servers properties from config file
		std::vector<Helper::Location> locations = Helper::parseConfig();
		log.info("Config parsed");
		if (locations.empty())
		{
			log.info("Config is empty! Nothing was parsed.");
			return;
		}
		// Select servers that we want to use for copy
		locations = Dialogs::selectLocations(locations);

		if (locations.empty())
		{
			log.info("No server selected!");
			return;
		}

		// Init vectors for rewwrite and backup
		std::vector<Helper::Location> backupLocations;
		std::vector<Helper::Location> rewriteLocations;

		// Sort locations for rewrite or backup
		for (const Helper::Location& loc : locations)
		{
			if (loc.rewrite)
			{
				rewriteLocations.push_back(loc);
				continue;
			}
			backupLocations.push_back(loc);
		}

		// Init rewrite class
		Rewrite rewrite;
		rewrite.setSource(source);
		rewrite.setFolderName(foldername);
		rewrite.setLocations(rewriteLocations);
		
		// Rewrite files in program folder
		rewrite.copy();

		// Init backup class
		Backup backup;
		backup.setSource(source);
		backup.setFolderName(foldername);
		backup.setLocations(backupLocations);

		// Copy and backup files
		backup.copy();

		MessageBox::Show("     Completed! \nCheck log if anything missing.");
	}
};
}