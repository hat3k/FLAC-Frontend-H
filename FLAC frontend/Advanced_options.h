#pragma once

#include <windows.h>

using namespace System;
using namespace System::Diagnostics;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Diagnostics;
using namespace System::Drawing;


namespace FLACfrontend {

	/// <summary>
	/// Summary for Advanced_options
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Advanced_options : public System::Windows::Forms::Form
	{
	public:
		Advanced_options(void)
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
		~Advanced_options()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnCommandHelp;
	private: System::Windows::Forms::GroupBox^  grpbExtraOptions;

	public: System::Windows::Forms::TextBox^  txtCommandLine;
	private: System::Windows::Forms::Button^  btnOK;
	private: System::Windows::Forms::GroupBox^  grpbCuesheet;
	public: 



	public: System::Windows::Forms::TextBox^  txtCuesheet;

	private: System::Windows::Forms::Button^  btnCueSheet;
	private: System::Windows::Forms::OpenFileDialog^  openCueSheet;
	public: System::Windows::Forms::CheckBox^  chkIgnoreChunkSize;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Advanced_options::typeid));
			this->btnCommandHelp = (gcnew System::Windows::Forms::Button());
			this->grpbExtraOptions = (gcnew System::Windows::Forms::GroupBox());
			this->txtCommandLine = (gcnew System::Windows::Forms::TextBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->grpbCuesheet = (gcnew System::Windows::Forms::GroupBox());
			this->txtCuesheet = (gcnew System::Windows::Forms::TextBox());
			this->btnCueSheet = (gcnew System::Windows::Forms::Button());
			this->openCueSheet = (gcnew System::Windows::Forms::OpenFileDialog());
			this->chkIgnoreChunkSize = (gcnew System::Windows::Forms::CheckBox());
			this->grpbExtraOptions->SuspendLayout();
			this->grpbCuesheet->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnCommandHelp
			// 
			this->btnCommandHelp->Location = System::Drawing::Point(214, 19);
			this->btnCommandHelp->Name = L"btnCommandHelp";
			this->btnCommandHelp->Size = System::Drawing::Size(107, 23);
			this->btnCommandHelp->TabIndex = 0;
			this->btnCommandHelp->Text = L"See complete help";
			this->btnCommandHelp->UseVisualStyleBackColor = true;
			this->btnCommandHelp->Click += gcnew System::EventHandler(this, &Advanced_options::btnCommandHelp_Click);
			// 
			// grpbExtraOptions
			// 
			this->grpbExtraOptions->Controls->Add(this->txtCommandLine);
			this->grpbExtraOptions->Controls->Add(this->btnCommandHelp);
			this->grpbExtraOptions->Location = System::Drawing::Point(13, 12);
			this->grpbExtraOptions->Name = L"grpbExtraOptions";
			this->grpbExtraOptions->Size = System::Drawing::Size(327, 56);
			this->grpbExtraOptions->TabIndex = 1;
			this->grpbExtraOptions->TabStop = false;
			this->grpbExtraOptions->Text = L"Extra command line options";
			// 
			// txtCommandLine
			// 
			this->txtCommandLine->Location = System::Drawing::Point(7, 21);
			this->txtCommandLine->Name = L"txtCommandLine";
			this->txtCommandLine->Size = System::Drawing::Size(201, 20);
			this->txtCommandLine->TabIndex = 1;
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(146, 158);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(75, 23);
			this->btnOK->TabIndex = 2;
			this->btnOK->Text = L"OK";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &Advanced_options::btnOK_Click);
			// 
			// grpbCuesheet
			// 
			this->grpbCuesheet->Controls->Add(this->txtCuesheet);
			this->grpbCuesheet->Controls->Add(this->btnCueSheet);
			this->grpbCuesheet->Location = System::Drawing::Point(13, 74);
			this->grpbCuesheet->Name = L"grpbCuesheet";
			this->grpbCuesheet->Size = System::Drawing::Size(327, 54);
			this->grpbCuesheet->TabIndex = 3;
			this->grpbCuesheet->TabStop = false;
			this->grpbCuesheet->Text = L"Embed cuesheet (only for encoding)";
			// 
			// txtCuesheet
			// 
			this->txtCuesheet->Location = System::Drawing::Point(7, 20);
			this->txtCuesheet->Name = L"txtCuesheet";
			this->txtCuesheet->Size = System::Drawing::Size(201, 20);
			this->txtCuesheet->TabIndex = 1;
			// 
			// btnCueSheet
			// 
			this->btnCueSheet->Location = System::Drawing::Point(214, 18);
			this->btnCueSheet->Name = L"btnCueSheet";
			this->btnCueSheet->Size = System::Drawing::Size(107, 23);
			this->btnCueSheet->TabIndex = 0;
			this->btnCueSheet->Text = L"Select cuesheet";
			this->btnCueSheet->UseVisualStyleBackColor = true;
			this->btnCueSheet->Click += gcnew System::EventHandler(this, &Advanced_options::btnCueSheet_Click);
			// 
			// openCueSheet
			// 
			this->openCueSheet->Filter = L"Cuesheet|*.cue";
			// 
			// chkIgnoreChunkSize
			// 
			this->chkIgnoreChunkSize->AutoSize = true;
			this->chkIgnoreChunkSize->Location = System::Drawing::Point(30, 134);
			this->chkIgnoreChunkSize->Name = L"chkIgnoreChunkSize";
			this->chkIgnoreChunkSize->Size = System::Drawing::Size(286, 17);
			this->chkIgnoreChunkSize->TabIndex = 7;
			this->chkIgnoreChunkSize->Text = L"Ignore WAVE filesize (for files > 4GB, use with caution!)";
			this->chkIgnoreChunkSize->UseVisualStyleBackColor = true;
			// 
			// Advanced_options
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(352, 193);
			this->ControlBox = false;
			this->Controls->Add(this->chkIgnoreChunkSize);
			this->Controls->Add(this->grpbCuesheet);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->grpbExtraOptions);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Advanced_options";
			this->Text = L"Advanced options";
			this->grpbExtraOptions->ResumeLayout(false);
			this->grpbExtraOptions->PerformLayout();
			this->grpbCuesheet->ResumeLayout(false);
			this->grpbCuesheet->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void btnCommandHelp_Click(System::Object^  sender, System::EventArgs^  e) {
			 COORD c;

			 FreeConsole();
			 AllocConsole();
			 c.X = 80; c.Y = 600;
			 SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),c);

			 Process^ p = gcnew Process();
			 p->StartInfo->FileName = "tools/flac.exe";
			 p->StartInfo->UseShellExecute = false;
			 p->StartInfo->Arguments = "-h";
			 p->Start();
			 p->WaitForExit();

			 // Add pause to let console window stay 
			 p->StartInfo->FileName = "cmd";
			 p->StartInfo->Arguments = "/c PAUSE";
			 p->Start();
			 p->WaitForExit();

			 FreeConsole();
		 }
private: System::Void btnCueSheet_Click(System::Object^  sender, System::EventArgs^  e) {
			 openCueSheet->ShowDialog();
			 txtCuesheet->Text = openCueSheet->FileName;
		 }
private: System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Visible = false;
		 }
};
}
