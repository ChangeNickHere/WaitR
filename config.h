#pragma once
#include "Helper.h"

namespace WaitR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for config
	/// </summary>
	public ref class config : public System::Windows::Forms::Form
	{
	public:
		config(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~config()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LServerName;
	protected:

	protected:
	private: System::Windows::Forms::Button^ BGenerate;
	private: System::Windows::Forms::TextBox^ TBServerName;


	private: System::Windows::Forms::Label^ LProgramFolder;
	private: System::Windows::Forms::TextBox^ TBProgramFolder;


	private: System::Windows::Forms::Label^ LBackupAddress;
	private: System::Windows::Forms::TextBox^ TBBackupAddress;


	private: System::Windows::Forms::Label^ LXmlFilePath;
	private: System::Windows::Forms::TextBox^ TBXmlFilePath;
	private: System::Windows::Forms::CheckBox^ CBRewrite;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->LServerName = (gcnew System::Windows::Forms::Label());
			this->BGenerate = (gcnew System::Windows::Forms::Button());
			this->TBServerName = (gcnew System::Windows::Forms::TextBox());
			this->LProgramFolder = (gcnew System::Windows::Forms::Label());
			this->TBProgramFolder = (gcnew System::Windows::Forms::TextBox());
			this->LBackupAddress = (gcnew System::Windows::Forms::Label());
			this->TBBackupAddress = (gcnew System::Windows::Forms::TextBox());
			this->LXmlFilePath = (gcnew System::Windows::Forms::Label());
			this->TBXmlFilePath = (gcnew System::Windows::Forms::TextBox());
			this->CBRewrite = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// LServerName
			// 
			this->LServerName->AutoSize = true;
			this->LServerName->Location = System::Drawing::Point(23, 26);
			this->LServerName->Name = L"LServerName";
			this->LServerName->Size = System::Drawing::Size(70, 13);
			this->LServerName->TabIndex = 0;
			this->LServerName->Text = L"Server name:";
			// 
			// BGenerate
			// 
			this->BGenerate->Location = System::Drawing::Point(84, 164);
			this->BGenerate->Name = L"BGenerate";
			this->BGenerate->Size = System::Drawing::Size(169, 23);
			this->BGenerate->TabIndex = 1;
			this->BGenerate->Text = L"Generate";
			this->BGenerate->UseVisualStyleBackColor = true;
			this->BGenerate->Click += gcnew System::EventHandler(this, &config::BGenerate_Click);
			// 
			// TBServerName
			// 
			this->TBServerName->Location = System::Drawing::Point(117, 23);
			this->TBServerName->Name = L"TBServerName";
			this->TBServerName->Size = System::Drawing::Size(211, 20);
			this->TBServerName->TabIndex = 2;
			// 
			// LProgramFolder
			// 
			this->LProgramFolder->AutoSize = true;
			this->LProgramFolder->Location = System::Drawing::Point(23, 55);
			this->LProgramFolder->Name = L"LProgramFolder";
			this->LProgramFolder->Size = System::Drawing::Size(78, 13);
			this->LProgramFolder->TabIndex = 3;
			this->LProgramFolder->Text = L"Program folder:";
			// 
			// TBProgramFolder
			// 
			this->TBProgramFolder->Location = System::Drawing::Point(117, 52);
			this->TBProgramFolder->Name = L"TBProgramFolder";
			this->TBProgramFolder->Size = System::Drawing::Size(211, 20);
			this->TBProgramFolder->TabIndex = 4;
			// 
			// LBackupAddress
			// 
			this->LBackupAddress->AutoSize = true;
			this->LBackupAddress->Location = System::Drawing::Point(23, 84);
			this->LBackupAddress->Name = L"LBackupAddress";
			this->LBackupAddress->Size = System::Drawing::Size(87, 13);
			this->LBackupAddress->TabIndex = 5;
			this->LBackupAddress->Text = L"Backup address:";
			// 
			// TBBackupAddress
			// 
			this->TBBackupAddress->Location = System::Drawing::Point(117, 81);
			this->TBBackupAddress->Name = L"TBBackupAddress";
			this->TBBackupAddress->Size = System::Drawing::Size(211, 20);
			this->TBBackupAddress->TabIndex = 6;
			// 
			// LXmlFilePath
			// 
			this->LXmlFilePath->AutoSize = true;
			this->LXmlFilePath->Location = System::Drawing::Point(23, 113);
			this->LXmlFilePath->Name = L"LXmlFilePath";
			this->LXmlFilePath->Size = System::Drawing::Size(67, 13);
			this->LXmlFilePath->TabIndex = 7;
			this->LXmlFilePath->Text = L"Xml file path:";
			// 
			// TBXmlFilePath
			// 
			this->TBXmlFilePath->Location = System::Drawing::Point(117, 113);
			this->TBXmlFilePath->Name = L"TBXmlFilePath";
			this->TBXmlFilePath->Size = System::Drawing::Size(211, 20);
			this->TBXmlFilePath->TabIndex = 8;
			// 
			// CBRewrite
			// 
			this->CBRewrite->AutoSize = true;
			this->CBRewrite->Location = System::Drawing::Point(117, 140);
			this->CBRewrite->Name = L"CBRewrite";
			this->CBRewrite->Size = System::Drawing::Size(62, 17);
			this->CBRewrite->TabIndex = 9;
			this->CBRewrite->Text = L"Rewrite";
			this->CBRewrite->UseVisualStyleBackColor = true;
			// 
			// config
			// 
			this->Icon = gcnew System::Drawing::Icon("pics\\icon.ico");
			this->StartPosition = FormStartPosition::CenterScreen;
			this->AcceptButton = this->BGenerate;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(373, 199);
			this->Controls->Add(this->CBRewrite);
			this->Controls->Add(this->TBXmlFilePath);
			this->Controls->Add(this->LXmlFilePath);
			this->Controls->Add(this->TBBackupAddress);
			this->Controls->Add(this->LBackupAddress);
			this->Controls->Add(this->TBProgramFolder);
			this->Controls->Add(this->LProgramFolder);
			this->Controls->Add(this->TBServerName);
			this->Controls->Add(this->BGenerate);
			this->Controls->Add(this->LServerName);
			this->Name = L"config";
			this->Text = L"config";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

/*
* Button click that will check if relevant fields are filled
* If not it will show modal message box
* If they are then it will write in config file
*/
private: System::Void BGenerate_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Helper::Location loc;

	// Check if rewrite is wanted
	if (CBRewrite->Checked)
	{
		// Program need to have correct config file so this must chceck if relevant fields are filled
		if (String::IsNullOrEmpty(TBProgramFolder->Text) || String::IsNullOrEmpty(TBServerName->Text))
		{
			MessageBox::Show("Server name or program folder is empty!");
		}
		else
		{
			// Add server properties to locastion structure
			loc.backupPath = "Dont need for rewrite";
			loc.programFolder  = Helper::SysStringToStd(TBProgramFolder->Text);
			loc.rewrite = CBRewrite->Checked;
			loc.serverName = Helper::SysStringToStd(TBServerName->Text);
			loc.xlmPath = "Dont need for rewrite";
			Helper::writeConfig(loc);
			MessageBox::Show("Confing updated!");

			// Form manipulation 
			this->BGenerate->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();

		}
	}
	else
	{
		// Program need to have correct config file so this must chceck if relevant fields are filled
		if (String::IsNullOrEmpty(TBProgramFolder->Text) || String::IsNullOrEmpty(TBServerName->Text) || String::IsNullOrEmpty(TBXmlFilePath->Text) || String::IsNullOrEmpty(TBBackupAddress->Text))
		{
			MessageBox::Show("You must fill all fields!");
		}
		else
		{
			// Add server properties to locastion structure
			loc.backupPath = Helper::SysStringToStd(TBBackupAddress->Text);
			loc.programFolder = Helper::SysStringToStd(TBProgramFolder->Text);
			loc.rewrite = CBRewrite->Checked;
			loc.serverName = Helper::SysStringToStd(TBServerName->Text);
			loc.xlmPath = Helper::SysStringToStd(TBXmlFilePath->Text);
			Helper::writeConfig(loc);
			MessageBox::Show("Confing updated!");

			// Form manipulation
			this->BGenerate->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}
}
};

}
