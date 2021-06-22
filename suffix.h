#pragma once

namespace WaitR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for suffix
	/// </summary>
	public ref class suffix : public System::Windows::Forms::Form
	{
	public:
		suffix(void)
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
		~suffix()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ suffixLabel;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ buttonContinue;
	protected:

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
			this->suffixLabel = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonContinue = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// suffixLabel
			// 
			this->suffixLabel->AutoSize = true;
			this->suffixLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->suffixLabel->Location = System::Drawing::Point(100, 33);
			this->suffixLabel->Name = L"suffixLabel";
			this->suffixLabel->Size = System::Drawing::Size(209, 29);
			this->suffixLabel->TabIndex = 0;
			this->suffixLabel->Text = L"Please enter suffix";
			this->suffixLabel->Click += gcnew System::EventHandler(this, &suffix::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(105, 85);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(204, 20);
			this->textBox1->TabIndex = 1;
			// 
			// buttonContinue
			// 
			this->buttonContinue->Location = System::Drawing::Point(172, 134);
			this->buttonContinue->Name = L"buttonContinue";
			this->buttonContinue->Size = System::Drawing::Size(75, 23);
			this->buttonContinue->TabIndex = 2;
			this->buttonContinue->Text = L"continue";
			this->buttonContinue->UseVisualStyleBackColor = true;
			// 
			// suffix
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(416, 188);
			this->Controls->Add(this->buttonContinue);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->suffixLabel);
			this->Name = L"suffix";
			this->Text = L"suffix";
			this->Load += gcnew System::EventHandler(this, &suffix::suffix_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void suffix_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
