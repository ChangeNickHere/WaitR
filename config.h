#pragma once

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
	private: System::Windows::Forms::Label^ LName;
	protected:
	private: System::Windows::Forms::Button^ BGenerate;
	private: System::Windows::Forms::TextBox^ TBName;
	private: System::Windows::Forms::Label^ LServerAddr;
	private: System::Windows::Forms::TextBox^ TBServerAddress;
	private: System::Windows::Forms::Label^ LBackupName;
	private: System::Windows::Forms::TextBox^ TBBackupName;
	private: System::Windows::Forms::Label^ LSuffix;
	private: System::Windows::Forms::TextBox^ TBSuffix;



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
			this->LName = (gcnew System::Windows::Forms::Label());
			this->BGenerate = (gcnew System::Windows::Forms::Button());
			this->TBName = (gcnew System::Windows::Forms::TextBox());
			this->LServerAddr = (gcnew System::Windows::Forms::Label());
			this->TBServerAddress = (gcnew System::Windows::Forms::TextBox());
			this->LBackupName = (gcnew System::Windows::Forms::Label());
			this->TBBackupName = (gcnew System::Windows::Forms::TextBox());
			this->LSuffix = (gcnew System::Windows::Forms::Label());
			this->TBSuffix = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// LName
			// 
			this->LName->AutoSize = true;
			this->LName->Location = System::Drawing::Point(23, 26);
			this->LName->Name = L"LName";
			this->LName->Size = System::Drawing::Size(73, 13);
			this->LName->TabIndex = 0;
			this->LName->Text = L"Display name:";
			// 
			// BGenerate
			// 
			this->BGenerate->Location = System::Drawing::Point(89, 155);
			this->BGenerate->Name = L"BGenerate";
			this->BGenerate->Size = System::Drawing::Size(169, 23);
			this->BGenerate->TabIndex = 1;
			this->BGenerate->Text = L"Generate";
			this->BGenerate->UseVisualStyleBackColor = true;
			// 
			// TBName
			// 
			this->TBName->Location = System::Drawing::Point(117, 23);
			this->TBName->Name = L"TBName";
			this->TBName->Size = System::Drawing::Size(211, 20);
			this->TBName->TabIndex = 2;
			// 
			// LServerAddr
			// 
			this->LServerAddr->AutoSize = true;
			this->LServerAddr->Location = System::Drawing::Point(23, 55);
			this->LServerAddr->Name = L"LServerAddr";
			this->LServerAddr->Size = System::Drawing::Size(81, 13);
			this->LServerAddr->TabIndex = 3;
			this->LServerAddr->Text = L"Server address:";
			this->LServerAddr->Click += gcnew System::EventHandler(this, &config::label1_Click);
			// 
			// TBServerAddress
			// 
			this->TBServerAddress->Location = System::Drawing::Point(117, 52);
			this->TBServerAddress->Name = L"TBServerAddress";
			this->TBServerAddress->Size = System::Drawing::Size(211, 20);
			this->TBServerAddress->TabIndex = 4;
			// 
			// LBackupName
			// 
			this->LBackupName->AutoSize = true;
			this->LBackupName->Location = System::Drawing::Point(23, 84);
			this->LBackupName->Name = L"LBackupName";
			this->LBackupName->Size = System::Drawing::Size(76, 13);
			this->LBackupName->TabIndex = 5;
			this->LBackupName->Text = L"Backup name:";
			this->LBackupName->Click += gcnew System::EventHandler(this, &config::label1_Click_1);
			// 
			// TBBackupName
			// 
			this->TBBackupName->Location = System::Drawing::Point(117, 81);
			this->TBBackupName->Name = L"TBBackupName";
			this->TBBackupName->Size = System::Drawing::Size(211, 20);
			this->TBBackupName->TabIndex = 6;
			// 
			// LSuffix
			// 
			this->LSuffix->AutoSize = true;
			this->LSuffix->Location = System::Drawing::Point(23, 113);
			this->LSuffix->Name = L"LSuffix";
			this->LSuffix->Size = System::Drawing::Size(33, 13);
			this->LSuffix->TabIndex = 7;
			this->LSuffix->Text = L"Suffix";
			// 
			// TBSuffix
			// 
			this->TBSuffix->Location = System::Drawing::Point(117, 113);
			this->TBSuffix->Name = L"TBSuffix";
			this->TBSuffix->Size = System::Drawing::Size(211, 20);
			this->TBSuffix->TabIndex = 8;
			// 
			// config
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(373, 199);
			this->Controls->Add(this->TBSuffix);
			this->Controls->Add(this->LSuffix);
			this->Controls->Add(this->TBBackupName);
			this->Controls->Add(this->LBackupName);
			this->Controls->Add(this->TBServerAddress);
			this->Controls->Add(this->LServerAddr);
			this->Controls->Add(this->TBName);
			this->Controls->Add(this->BGenerate);
			this->Controls->Add(this->LName);
			this->Name = L"config";
			this->Text = L"config";
			this->Load += gcnew System::EventHandler(this, &config::config_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void config_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
};

}
