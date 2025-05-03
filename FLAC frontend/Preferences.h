#pragma once

#include <windows.h>

using namespace System::Windows::Forms;

namespace FLACfrontend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Preferences
	/// </summary>
	public ref class Preferences : public System::Windows::Forms::Form
	{
	public:
		Preferences(void)
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
		~Preferences()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonOkPreferences;
	public: System::Windows::Forms::CheckBox^ checkBoxCheckForUpdatesOnStartup;

	private: System::Windows::Forms::ToolTip^ toolTipPreferences;

	private: System::ComponentModel::IContainer^ components;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Preferences::typeid));
			this->buttonOkPreferences = (gcnew System::Windows::Forms::Button());
			this->checkBoxCheckForUpdatesOnStartup = (gcnew System::Windows::Forms::CheckBox());
			this->toolTipPreferences = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// buttonOkPreferences
			// 
			this->buttonOkPreferences->Location = System::Drawing::Point(105, 226);
			this->buttonOkPreferences->Name = L"buttonOkPreferences";
			this->buttonOkPreferences->Size = System::Drawing::Size(75, 23);
			this->buttonOkPreferences->TabIndex = 0;
			this->buttonOkPreferences->Text = L"OK";
			this->buttonOkPreferences->UseVisualStyleBackColor = true;
			this->buttonOkPreferences->Click += gcnew System::EventHandler(this, &Preferences::buttonOkPreferences_Click);
			// 
			// checkBoxCheckForUpdatesOnStartup
			// 
			this->checkBoxCheckForUpdatesOnStartup->AutoSize = true;
			this->checkBoxCheckForUpdatesOnStartup->Location = System::Drawing::Point(12, 12);
			this->checkBoxCheckForUpdatesOnStartup->Name = L"checkBoxCheckForUpdatesOnStartup";
			this->checkBoxCheckForUpdatesOnStartup->Size = System::Drawing::Size(163, 17);
			this->checkBoxCheckForUpdatesOnStartup->TabIndex = 1;
			this->checkBoxCheckForUpdatesOnStartup->Text = L"Check for updates on startup";
			this->toolTipPreferences->SetToolTip(this->checkBoxCheckForUpdatesOnStartup, L"Automatically check if a new version is available when the program starts");
			this->checkBoxCheckForUpdatesOnStartup->UseVisualStyleBackColor = true;
			// 
			// Preferences
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->checkBoxCheckForUpdatesOnStartup);
			this->Controls->Add(this->buttonOkPreferences);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Preferences";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Preferences";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonOkPreferences_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = ::DialogResult::OK;
		this->Close();
	}
	};
}
