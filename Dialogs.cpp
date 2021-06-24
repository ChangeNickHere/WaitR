#include "Dialogs.h"

std::string Dialogs::getFolderName()
{
	System::String^ folder;
	System::Windows::Forms::FolderBrowserDialog^ fd;
	fd = gcnew System::Windows::Forms::FolderBrowserDialog;

	// Show the FolderBrowserDialog.
	System::Windows::Forms::DialogResult result = fd->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		folder = fd->SelectedPath;
	}
	std::string source = Helper::SysStringToStd(folder);
	return source;
}

// Dialog form for selecting locations
std::vector<Helper::Location> Dialogs::selectLocations(std::vector<Helper::Location> locations)
{
	// Init
	Logger log;
	System::Windows::Forms::Form^ frm = gcnew  System::Windows::Forms::Form();
	System::Windows::Forms::CheckBox^ box = gcnew System::Windows::Forms::CheckBox();
	int cnt = 0;
	std::vector<Helper::Location> outLocations;

	// positions
	int initOffset = 20;
	int xDistance = 80;
	int yDistance = 50;

	// Through all locations
	for (const Helper::Location loc : locations)
	{
		// for each location create checkbox
		box = gcnew System::Windows::Forms::CheckBox();
		box->Name = gcnew System::String(loc.serverName.c_str());
		box->Text = gcnew System::String(loc.serverName.c_str());
		box->AutoSize = true;
		box->Location = System::Drawing::Point(initOffset + cnt % 2 * xDistance, initOffset + cnt / 2 * yDistance);

		// Add checkbox to form
		frm->Controls->Add(box);
		cnt++;
	}

	// Create ok button
	System::Windows::Forms::Button^ okButton = gcnew  System::Windows::Forms::Button();
	okButton->Name = L"OK";	
	okButton->Text = L"OK";
	okButton->Location = System::Drawing::Point(initOffset + cnt % 2 * xDistance, initOffset + cnt / 2 * yDistance);
	okButton->UseVisualStyleBackColor = true;
	okButton->DialogResult = System::Windows::Forms::DialogResult::OK;
	cnt++;

	// Create cancel button
	System::Windows::Forms::Button^ cancelButton = gcnew  System::Windows::Forms::Button();
	cancelButton->Name = L"Cancel";
	cancelButton->Text = L"Cancel";
	cancelButton->Location = System::Drawing::Point(initOffset + cnt % 2 * xDistance, initOffset + cnt / 2 * yDistance);
	cancelButton->UseVisualStyleBackColor = true;
	cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	cnt++;
	
	// form settings
	frm->Name = L"Select servers";
	frm->Text = L"Select servers";
	frm->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	frm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	frm->Icon = gcnew System::Drawing::Icon("pics\\icon.ico");

	// set form size
	frm->Height = 80 + (initOffset + cnt / 2 * yDistance);

	// Add buttons to form
	frm->AcceptButton = okButton;
	frm->CancelButton = cancelButton;
	frm->Controls->Add(okButton);
	frm->Controls->Add(cancelButton);

	// on OK or Cancel button click;
	if (frm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		//find all selected loctaions
		for (int i = 0; i < frm->Controls->Count; i++)
		{
			if (frm->Controls[i]->GetType() == System::Windows::Forms::CheckBox::typeid && static_cast<System::Windows::Forms::CheckBox^>(frm->Controls[i])->Checked)
			{
				for (const Helper::Location & loc : locations)
				{
					if (loc.serverName == Helper::SysStringToStd(static_cast<System::Windows::Forms::CheckBox^>(frm->Controls[i])->Name))
					{
						outLocations.push_back(loc);
					}
				}
				
			}
		}
		log.info("Count of servers that will be updated is: " + std::to_string(outLocations.size()));
		return outLocations;
	}
	else
	{
		// return empty vector
		log.info("Server selections was cancelled");
		return outLocations;
	}
	return outLocations;
}

std::string Dialogs::getSuffix()
{
	System::Windows::Forms::Form^ frm = gcnew  System::Windows::Forms::Form();

	// create suffixLabel
	System::Windows::Forms::Label^ suffixLabel = gcnew System::Windows::Forms::Label();
	suffixLabel->AutoSize = true;
	suffixLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(238)));
	suffixLabel->Location = System::Drawing::Point(73, 32);
	suffixLabel->Name = L"suffixLabel";
	suffixLabel->Size = System::Drawing::Size(277, 29);
	suffixLabel->TabIndex = 0;
	suffixLabel->Text = L"Please enter folder suffix";
	
	// create textBox1 
	System::Windows::Forms::TextBox^ textBox1 = (gcnew System::Windows::Forms::TextBox());
	textBox1->Location = System::Drawing::Point(105, 85);
	textBox1->Name = L"textBox1";
	textBox1->Size = System::Drawing::Size(204, 20);
	textBox1->TabIndex = 1;
	
	// buttonContinue
	System::Windows::Forms::Button^ buttonContinue = (gcnew System::Windows::Forms::Button());
	buttonContinue->Location = System::Drawing::Point(172, 134);
	buttonContinue->Name = L"buttonContinue";
	buttonContinue->Size = System::Drawing::Size(75, 23);
	buttonContinue->TabIndex = 2;
	buttonContinue->Text = L"continue";
	buttonContinue->UseVisualStyleBackColor = true;
	buttonContinue->DialogResult = System::Windows::Forms::DialogResult::OK;
	
	// set form properties
	frm->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	frm->Icon = gcnew System::Drawing::Icon("pics\\icon.ico");
	frm->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	frm->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	frm->ClientSize = System::Drawing::Size(416, 188);
	frm->AcceptButton = buttonContinue;
	frm->Controls->Add(buttonContinue);
	frm->Controls->Add(textBox1);
	frm->Controls->Add(suffixLabel);
	frm->Name = L"suffix";
	frm->Text = L"suffix";

	if (frm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (System::String::IsNullOrEmpty(textBox1->Text))
		{
			return std::string();
		}
		return Helper::SysStringToStd(textBox1->Text);
	}
	else
	{
		return std::string();
	}

	return std::string();
}

