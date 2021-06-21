#pragma once

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
			//
			//TODO: Add the constructor code here
			//
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
	protected:
	private: System::Windows::Forms::Button^ button1;
	public:
	private: System::Windows::Forms::Button^ button2;

	protected:

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
			this->pictureBoxLogo = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLogo))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxLogo
			// 
			this->pictureBoxLogo->Location = System::Drawing::Point(158, 37);
			this->pictureBoxLogo->Name = L"pictureBoxLogo";
			this->pictureBoxLogo->Size = System::Drawing::Size(483, 206);
			this->pictureBoxLogo->TabIndex = 0;
			this->pictureBoxLogo->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(158, 311);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(476, 311);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(165, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// WaitRMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(803, 398);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBoxLogo);
			this->Name = L"WaitRMenu";
			this->Text = L"WaitRMenu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLogo))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
