#pragma once

#include <windows.h>
#undef GetTempPath

#include "Advanced_options.h"
#include "Preferences.h"
#include "CommandLineHelp.h"
#include <shellapi.h>

namespace FLACfrontend {

	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::IO;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Net;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:
		Form1(void)
		{
			InitializeComponent();
			this->AdvDialog = (gcnew Advanced_options());
			this->PreferencesDialog = gcnew Preferences();
			this->CommandLineHelpDialog = gcnew CommandLineHelp();
			this->programVersion = "2.1 build 20250601";

			comboBoxCommandLine->Validated += gcnew System::EventHandler(this, &Form1::comboBoxCommandLine_Validated);
			comboBoxCommandLine->Leave += gcnew System::EventHandler(this, &Form1::comboBoxCommandLine_Leave);
			comboBoxCommandLine->KeyDown += gcnew KeyEventHandler(this, &Form1::comboBoxCommandLine_KeyDown);
			comboBoxCommandLine->TextChanged += gcnew System::EventHandler(this, &Form1::comboBoxCommandLine_TextChanged);
			PreferencesDialog->numericUpDownCommandLineHistoryLimit->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDownCommandLineHistoryLimit_ValueChanged);
			PreferencesDialog->checkBoxSaveCommandLineHistory->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxSaveCommandLineHistory_CheckedChanged);

			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			//
			//TODO: Add the constructor code here
			//
		}

	private:
		void Form1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			SaveSettings("settings.txt"); // Save settings on close
		}
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListBox^ lstFiles;
	protected:

	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnRemove;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::OpenFileDialog^ dlgAddFile;
	private: System::Windows::Forms::GroupBox^ gbEncoding;

	private: System::Windows::Forms::TextBox^ textLevel;
	private: System::Windows::Forms::Label^ lblLevel;


	private: System::Windows::Forms::TrackBar^ tbLevel;
	private: System::Windows::Forms::CheckBox^ chkReplayGainAlbum;

	private: System::Windows::Forms::CheckBox^ chkReplayGain;
	private: System::Windows::Forms::CheckBox^ chkVerify;
	private: System::Windows::Forms::FolderBrowserDialog^ dlgOutputDirectory;
	private: System::Windows::Forms::GroupBox^ gbOutputDir;



	private: System::Windows::Forms::Button^ btnSelectDirectory;
	private: System::Windows::Forms::TextBox^ txtOutputDirectory;
	private: System::Windows::Forms::Button^ btnOutputDirSameAsInput;



	private: System::Windows::Forms::Button^ btnEncode;
	private: System::Windows::Forms::Button^ btnDecode;
	private: System::Windows::Forms::Button^ btnTest;
	private: System::Windows::Forms::Button^ btnFingerprint;
	private: System::Windows::Forms::Button^ btnExit;



	private: System::Windows::Forms::GroupBox^ gbGeneral;

	private: System::Windows::Forms::CheckBox^ chkOggFlac;

	private: System::Windows::Forms::CheckBox^ chkDeleteInput;
	private: System::Windows::Forms::CheckBox^ chkKeepForeign;
	private: System::Windows::Forms::GroupBox^ gbDecoding;
	private: System::Windows::Forms::CheckBox^ chkDecodeThroughErrors;



	private: System::Windows::Forms::Button^ btnHelp;

	private: System::Windows::Forms::Button^ btnAdvanced;
	private: System::Windows::Forms::Button^ buttonPreferences;

	private: Advanced_options^ AdvDialog;
	private: Preferences^ PreferencesDialog;
	private: CommandLineHelp^ CommandLineHelpDialog;
	private: System::Windows::Forms::ToolTip^ ttHelp;
	private: System::Windows::Forms::Button^ btnAbout;


	private: System::Windows::Forms::GroupBox^ groupBoxAdditionalOptions;
	private: System::Windows::Forms::TextBox^ textBoxR;
	private: System::Windows::Forms::TrackBar^ trackBarR;
	private: System::Windows::Forms::CheckBox^ checkBoxOptionR;
	private: System::Windows::Forms::CheckBox^ checkBoxNoPadding;
	private: System::Windows::Forms::TextBox^ textBoxMT;
	private: System::Windows::Forms::TextBox^ textBoxPrefixUser;
	private: System::Windows::Forms::CheckBox^ checkBoxOptionP;
	private: System::Windows::Forms::CheckBox^ checkBoxAddPrefix;
	private: System::Windows::Forms::CheckBox^ checkBoxOverwrite;
	private: System::Windows::Forms::CheckBox^ checkBoxOptionE;
	private: System::Windows::Forms::CheckBox^ checkBoxOptionMT;
	public: System::Windows::Forms::CheckBox^ chkIgnoreChunkSize;
	private: System::Windows::Forms::GroupBox^ grpbCuesheet;
	public: System::Windows::Forms::TextBox^ txtCuesheet;
	private: System::Windows::Forms::Button^ btnCueSheet;
	private: System::Windows::Forms::GroupBox^ grpbExtraOptions;
//	public: System::Windows::Forms::TextBox^ txtCommandLine;
	public: System::Windows::Forms::ComboBox^ comboBoxCommandLine;
	private: System::Windows::Forms::Button^ btnCommandHelp;
	private: System::Windows::Forms::CheckBox^ checkCuesheet;
	private: System::Windows::Forms::Button^ buttonClearCuesheet;
	private: System::Windows::Forms::CheckBox^ checkCommandLine;
	private: System::Windows::Forms::Button^ buttonClearCommandLine;
	private: System::Windows::Forms::OpenFileDialog^ openCueSheet;
	private: System::Windows::Forms::CheckBox^ checkBoxExactRice;
	private: System::Windows::Forms::CheckBox^ checkBoxRiceParameterSearch;


	private: System::ComponentModel::IContainer^ components;

	private: void SaveSettings(String^ path) {
		StreamWriter^ writer = gcnew StreamWriter(path);
		writer->WriteLine("CompressionLevel: " + tbLevel->Value.ToString());
		writer->WriteLine("VerifyAfterEncoding: " + chkVerify->Checked.ToString());
		writer->WriteLine("ReplayGainEnabled: " + chkReplayGain->Checked.ToString());
		writer->WriteLine("OptionP: " + checkBoxOptionP->Checked.ToString());
		writer->WriteLine("OptionE: " + checkBoxOptionE->Checked.ToString());
		writer->WriteLine("OptionMT: " + checkBoxOptionMT->Checked.ToString());
		writer->WriteLine("MTThreads: " + textBoxMT->Text);
		writer->WriteLine("AddPrefix: " + checkBoxAddPrefix->Checked.ToString());
		writer->WriteLine("PrefixUser: " + textBoxPrefixUser->Text);
		writer->WriteLine("OptionR: " + checkBoxOptionR->Checked.ToString());
		writer->WriteLine("RLevel: " + trackBarR->Value.ToString());
		writer->WriteLine("NoPadding: " + checkBoxNoPadding->Checked.ToString());
//		writer->WriteLine("ExactRice: " + checkBoxExactRice->Checked.ToString());
//		writer->WriteLine("RiceParameterSearch: " + checkBoxRiceParameterSearch->Checked.ToString());
		writer->WriteLine("Overwrite: " + checkBoxOverwrite->Checked.ToString());
		writer->WriteLine("CheckForUpdatesOnStartup: " + this->PreferencesDialog->checkBoxCheckForUpdatesOnStartup->Checked.ToString());
		writer->WriteLine("IgnoredVersion: " + ignoredVersion);
		writer->WriteLine("DontPreserveTimestampsPermissions: " + this->PreferencesDialog->checkBoxDontPreserveTimestampsPermissions->Checked.ToString());
//		writer->WriteLine("IgnoreReadOnly: " + this->PreferencesDialog->checkBoxIgnoreReadOnly->Checked.ToString());
		writer->WriteLine("EnableCommandLine: " + checkCommandLine->Checked.ToString());
		writer->WriteLine("SaveCommandLineHistory: " + this->PreferencesDialog->checkBoxSaveCommandLineHistory->Checked.ToString());
		writer->WriteLine("CommandLineHistoryLimit: " + this->PreferencesDialog->numericUpDownCommandLineHistoryLimit->Value.ToString());
//		writer->WriteLine("CommandLineOptions: " + txtCommandLine->Text);
		writer->WriteLine("CommandLineOptions: " + comboBoxCommandLine->Text);
		if (PreferencesDialog->checkBoxSaveCommandLineHistory->Checked) {
			for each (String ^ cmd in comboBoxCommandLine->Items) {
				writer->WriteLine("CommandLineHistory: " + cmd);
			}
		}
		writer->Close();
	}

	private: void LoadSettings(String^ path) {
		if (File::Exists(path)) {
			StreamReader^ reader = gcnew StreamReader(path);

			while (!reader->EndOfStream) {
				String^ line = reader->ReadLine();
				array<String^>^ parts = line->Split(':');
				if (parts->Length == 2) {
					String^ key = parts[0]->Trim();
					String^ value = parts[1]->Trim();

					if (key == "CompressionLevel") {
						tbLevel->Value = Int32::Parse(value);
					}
					else if (key == "VerifyAfterEncoding") {
						chkVerify->Checked = Boolean::Parse(value);
					}
					else if (key == "ReplayGainEnabled") {
						chkReplayGain->Checked = Boolean::Parse(value);
					}
					else if (key == "OptionP") {
						checkBoxOptionP->Checked = Boolean::Parse(value);
					}
					else if (key == "OptionE") {
						checkBoxOptionE->Checked = Boolean::Parse(value);
					}
					else if (key == "OptionMT") {
						checkBoxOptionMT->Checked = Boolean::Parse(value);
					}
					else if (key == "MTThreads") {
						textBoxMT->Text = value;
					}
					else if (key == "AddPrefix") {
						checkBoxAddPrefix->Checked = Boolean::Parse(value);
					}
					else if (key == "PrefixUser") {
						textBoxPrefixUser->Text = value;
					}
					else if (key == "OptionR") {
						checkBoxOptionR->Checked = Boolean::Parse(value);
					}
					else if (key == "RLevel") {
						trackBarR->Value = Int32::Parse(value);
					}
					else if (key == "NoPadding") {
						checkBoxNoPadding->Checked = Boolean::Parse(value);
					}
//					else if (key == "ExactRice") {
//						checkBoxExactRice->Checked = Boolean::Parse(value);
//					}
//					else if (key == "RiceParameterSearch") {
//						checkBoxRiceParameterSearch->Checked = Boolean::Parse(value);
//					}
					else if (key == "Overwrite") {
						checkBoxOverwrite->Checked = Boolean::Parse(value);
					}
					else if (key == "CheckForUpdatesOnStartup") {
						this->PreferencesDialog->checkBoxCheckForUpdatesOnStartup->Checked = Boolean::Parse(value);
					}
					else if (key == "IgnoredVersion") {
						ignoredVersion = value;
					}
					else if (key == "DontPreserveTimestampsPermissions") {
						this->PreferencesDialog->checkBoxDontPreserveTimestampsPermissions->Checked = Boolean::Parse(value);
					}
//					else if (key == "IgnoreReadOnly") {
//						this->PreferencesDialog->checkBoxIgnoreReadOnly->Checked = Boolean::Parse(value);
//					}
					else if (key == "EnableCommandLine") {
						checkCommandLine->Checked = Boolean::Parse(value);
					}
					else if (key == "SaveCommandLineHistory") {
						this->PreferencesDialog->checkBoxSaveCommandLineHistory->Checked = Boolean::Parse(value);
					}
					else if (key == "CommandLineHistoryLimit") {
						this->PreferencesDialog->numericUpDownCommandLineHistoryLimit->Value = Int32::Parse(value);
					}
//					else if (key == "CommandLineOptions") {
//						txtCommandLine->Text = value;
//					}
					else if (key == "CommandLineOptions") {
						comboBoxCommandLine->Text = value;
					}
					else if (key == "CommandLineHistory" && PreferencesDialog->checkBoxSaveCommandLineHistory->Checked) {
						comboBoxCommandLine->Items->Add(value);
					}
				}
			}
			reader->Close();
		}
	}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->lstFiles = (gcnew System::Windows::Forms::ListBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnRemove = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->dlgAddFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->gbEncoding = (gcnew System::Windows::Forms::GroupBox());
			this->chkReplayGainAlbum = (gcnew System::Windows::Forms::CheckBox());
			this->chkReplayGain = (gcnew System::Windows::Forms::CheckBox());
			this->chkVerify = (gcnew System::Windows::Forms::CheckBox());
			this->textLevel = (gcnew System::Windows::Forms::TextBox());
			this->lblLevel = (gcnew System::Windows::Forms::Label());
			this->tbLevel = (gcnew System::Windows::Forms::TrackBar());
			this->dlgOutputDirectory = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->gbOutputDir = (gcnew System::Windows::Forms::GroupBox());
			this->btnOutputDirSameAsInput = (gcnew System::Windows::Forms::Button());
			this->btnSelectDirectory = (gcnew System::Windows::Forms::Button());
			this->txtOutputDirectory = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxOverwrite = (gcnew System::Windows::Forms::CheckBox());
			this->btnEncode = (gcnew System::Windows::Forms::Button());
			this->btnDecode = (gcnew System::Windows::Forms::Button());
			this->btnTest = (gcnew System::Windows::Forms::Button());
			this->btnFingerprint = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->gbGeneral = (gcnew System::Windows::Forms::GroupBox());
			this->chkKeepForeign = (gcnew System::Windows::Forms::CheckBox());
			this->chkOggFlac = (gcnew System::Windows::Forms::CheckBox());
			this->chkDeleteInput = (gcnew System::Windows::Forms::CheckBox());
			this->gbDecoding = (gcnew System::Windows::Forms::GroupBox());
			this->chkDecodeThroughErrors = (gcnew System::Windows::Forms::CheckBox());
			this->btnHelp = (gcnew System::Windows::Forms::Button());
			this->btnAdvanced = (gcnew System::Windows::Forms::Button());
			this->buttonPreferences = (gcnew System::Windows::Forms::Button());
			this->ttHelp = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->btnAbout = (gcnew System::Windows::Forms::Button());
			this->checkBoxNoPadding = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxMT = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPrefixUser = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxOptionP = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxAddPrefix = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxOptionE = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxOptionMT = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxOptionR = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxR = (gcnew System::Windows::Forms::TextBox());
			this->trackBarR = (gcnew System::Windows::Forms::TrackBar());
			this->chkIgnoreChunkSize = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxExactRice = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxRiceParameterSearch = (gcnew System::Windows::Forms::CheckBox());
			this->groupBoxAdditionalOptions = (gcnew System::Windows::Forms::GroupBox());
			this->grpbCuesheet = (gcnew System::Windows::Forms::GroupBox());
			this->buttonClearCuesheet = (gcnew System::Windows::Forms::Button());
			this->checkCuesheet = (gcnew System::Windows::Forms::CheckBox());
			this->txtCuesheet = (gcnew System::Windows::Forms::TextBox());
			this->btnCueSheet = (gcnew System::Windows::Forms::Button());
			this->grpbExtraOptions = (gcnew System::Windows::Forms::GroupBox());
			this->buttonClearCommandLine = (gcnew System::Windows::Forms::Button());
			this->checkCommandLine = (gcnew System::Windows::Forms::CheckBox());
//			this->txtCommandLine = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxCommandLine = (gcnew System::Windows::Forms::ComboBox());
			this->btnCommandHelp = (gcnew System::Windows::Forms::Button());
			this->openCueSheet = (gcnew System::Windows::Forms::OpenFileDialog());
			this->gbEncoding->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbLevel))->BeginInit();
			this->gbOutputDir->SuspendLayout();
			this->gbGeneral->SuspendLayout();
			this->gbDecoding->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarR))->BeginInit();
			this->groupBoxAdditionalOptions->SuspendLayout();
			this->grpbCuesheet->SuspendLayout();
			this->grpbExtraOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// lstFiles
			// 
			this->lstFiles->FormattingEnabled = true;
			this->lstFiles->HorizontalScrollbar = true;
			this->lstFiles->Location = System::Drawing::Point(12, 12);
			this->lstFiles->Name = L"lstFiles";
			this->lstFiles->Size = System::Drawing::Size(393, 134);
			this->lstFiles->TabIndex = 0;
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(412, 12);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 1;
			this->btnAdd->Text = L"&Add files";
			this->ttHelp->SetToolTip(this->btnAdd, L"Add files to be encoded/decoded/checked etc.");
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Form1::btnAdd_Click);
			// 
			// btnRemove
			// 
			this->btnRemove->Location = System::Drawing::Point(412, 42);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(75, 23);
			this->btnRemove->TabIndex = 2;
			this->btnRemove->Text = L"&Remove file";
			this->ttHelp->SetToolTip(this->btnRemove, L"Remove one file from the list");
			this->btnRemove->UseVisualStyleBackColor = true;
			this->btnRemove->Click += gcnew System::EventHandler(this, &Form1::btnRemove_Click);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(412, 124);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(75, 23);
			this->btnClear->TabIndex = 3;
			this->btnClear->Text = L"&Clear filelist";
			this->ttHelp->SetToolTip(this->btnClear, L"Clear the list of files to be encoded/decoded/checked etc.");
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &Form1::btnClear_Click);
			// 
			// dlgAddFile
			// 
			this->dlgAddFile->Filter = L"Supported Files|*.wav;*.flac;*.ogg;*.oga;*.aiff;*.w64;*.raw|FLAC files|*.flac|Unc"
				L"ompressed files|*.wav;*.w64;*.aiff;*.raw|OGG Files|*.ogg;*.oga";
			this->dlgAddFile->Multiselect = true;
			this->dlgAddFile->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::dlgAddFile_FileOk);
			// 
			// gbEncoding
			// 
			this->gbEncoding->Controls->Add(this->chkReplayGainAlbum);
			this->gbEncoding->Controls->Add(this->chkReplayGain);
			this->gbEncoding->Controls->Add(this->chkVerify);
			this->gbEncoding->Controls->Add(this->textLevel);
			this->gbEncoding->Controls->Add(this->lblLevel);
			this->gbEncoding->Controls->Add(this->tbLevel);
			this->gbEncoding->Location = System::Drawing::Point(12, 152);
			this->gbEncoding->Name = L"gbEncoding";
			this->gbEncoding->Size = System::Drawing::Size(200, 134);
			this->gbEncoding->TabIndex = 4;
			this->gbEncoding->TabStop = false;
			this->gbEncoding->Text = L"Encoding options";
			// 
			// chkReplayGainAlbum
			// 
			this->chkReplayGainAlbum->AutoSize = true;
			this->chkReplayGainAlbum->Enabled = false;
			this->chkReplayGainAlbum->Location = System::Drawing::Point(30, 108);
			this->chkReplayGainAlbum->Name = L"chkReplayGainAlbum";
			this->chkReplayGainAlbum->Size = System::Drawing::Size(164, 17);
			this->chkReplayGainAlbum->TabIndex = 5;
			this->chkReplayGainAlbum->Text = L"Treat input files as one album";
			this->ttHelp->SetToolTip(this->chkReplayGainAlbum, L"If set, all input files will be treated as one album");
			this->chkReplayGainAlbum->UseVisualStyleBackColor = true;
			// 
			// chkReplayGain
			// 
			this->chkReplayGain->AutoSize = true;
			this->chkReplayGain->Location = System::Drawing::Point(13, 85);
			this->chkReplayGain->Name = L"chkReplayGain";
			this->chkReplayGain->Size = System::Drawing::Size(128, 17);
			this->chkReplayGain->TabIndex = 4;
			this->chkReplayGain->Text = L"Calculate ReplayGain";
			this->ttHelp->SetToolTip(this->chkReplayGain, L"If set, ReplayGain tags are added");
			this->chkReplayGain->UseVisualStyleBackColor = true;
			this->chkReplayGain->CheckStateChanged += gcnew System::EventHandler(this, &Form1::chkReplayGain_CheckStateChanged);
			// 
			// chkVerify
			// 
			this->chkVerify->AutoSize = true;
			this->chkVerify->Checked = true;
			this->chkVerify->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkVerify->Location = System::Drawing::Point(13, 61);
			this->chkVerify->Name = L"chkVerify";
			this->chkVerify->Size = System::Drawing::Size(123, 17);
			this->chkVerify->TabIndex = 3;
			this->chkVerify->Text = L"Verify after encoding";
			this->ttHelp->SetToolTip(this->chkVerify, L"If set, the resulting file is checked for integrity");
			this->chkVerify->UseVisualStyleBackColor = true;
			// 
			// textLevel
			// 
			this->textLevel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textLevel->Location = System::Drawing::Point(48, 27);
			this->textLevel->Name = L"textLevel";
			this->textLevel->ReadOnly = true;
			this->textLevel->Size = System::Drawing::Size(21, 20);
			this->textLevel->TabIndex = 2;
			this->textLevel->Text = L"8";
			this->textLevel->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->ttHelp->SetToolTip(this->textLevel, L"The compression level, a higher level makes smaller files, but takes longer to en"
				L"code");
			// 
			// lblLevel
			// 
			this->lblLevel->AutoSize = true;
			this->lblLevel->Location = System::Drawing::Point(10, 30);
			this->lblLevel->Name = L"lblLevel";
			this->lblLevel->Size = System::Drawing::Size(36, 13);
			this->lblLevel->TabIndex = 1;
			this->lblLevel->Text = L"Level:";
			// 
			// tbLevel
			// 
			this->tbLevel->LargeChange = 1;
			this->tbLevel->Location = System::Drawing::Point(75, 23);
			this->tbLevel->Maximum = 8;
			this->tbLevel->Name = L"tbLevel";
			this->tbLevel->Size = System::Drawing::Size(119, 45);
			this->tbLevel->TabIndex = 0;
			this->ttHelp->SetToolTip(this->tbLevel, L"Set the compression level, a higher level makes smaller files, but takes longer t"
				L"o encode");
			this->tbLevel->Value = 8;
			this->tbLevel->ValueChanged += gcnew System::EventHandler(this, &Form1::tbLevel_ValueChanged);
			// 
			// gbOutputDir
			// 
			this->gbOutputDir->Controls->Add(this->btnOutputDirSameAsInput);
			this->gbOutputDir->Controls->Add(this->btnSelectDirectory);
			this->gbOutputDir->Controls->Add(this->txtOutputDirectory);
			this->gbOutputDir->Controls->Add(this->checkBoxOverwrite);
			this->gbOutputDir->Location = System::Drawing::Point(12, 556);
			this->gbOutputDir->Name = L"gbOutputDir";
			this->gbOutputDir->Size = System::Drawing::Size(469, 71);
			this->gbOutputDir->TabIndex = 10;
			this->gbOutputDir->TabStop = false;
			this->gbOutputDir->Text = L"Output directory (only for encoding and decoding)";
			// 
			// btnOutputDirSameAsInput
			// 
			this->btnOutputDirSameAsInput->Location = System::Drawing::Point(375, 21);
			this->btnOutputDirSameAsInput->Name = L"btnOutputDirSameAsInput";
			this->btnOutputDirSameAsInput->Size = System::Drawing::Size(85, 22);
			this->btnOutputDirSameAsInput->TabIndex = 2;
			this->btnOutputDirSameAsInput->Text = L"Same as input";
			this->ttHelp->SetToolTip(this->btnOutputDirSameAsInput, L"Set output directory the same as input directory");
			this->btnOutputDirSameAsInput->UseVisualStyleBackColor = true;
			this->btnOutputDirSameAsInput->Click += gcnew System::EventHandler(this, &Form1::btnOutputDirSameAsInput_Click);
			// 
			// btnSelectDirectory
			// 
			this->btnSelectDirectory->Location = System::Drawing::Point(346, 21);
			this->btnSelectDirectory->Name = L"btnSelectDirectory";
			this->btnSelectDirectory->Size = System::Drawing::Size(26, 22);
			this->btnSelectDirectory->TabIndex = 1;
			this->btnSelectDirectory->Text = L"...";
			this->ttHelp->SetToolTip(this->btnSelectDirectory, L"Select an output directory");
			this->btnSelectDirectory->UseVisualStyleBackColor = true;
			this->btnSelectDirectory->Click += gcnew System::EventHandler(this, &Form1::btnSelectDirectory_Click);
			// 
			// txtOutputDirectory
			// 
			this->txtOutputDirectory->Enabled = false;
			this->txtOutputDirectory->Location = System::Drawing::Point(13, 22);
			this->txtOutputDirectory->Name = L"txtOutputDirectory";
			this->txtOutputDirectory->Size = System::Drawing::Size(327, 20);
			this->txtOutputDirectory->TabIndex = 0;
			this->txtOutputDirectory->Text = L"<< Same as input directory >>";
			// 
			// checkBoxOverwrite
			// 
			this->checkBoxOverwrite->AutoSize = true;
			this->checkBoxOverwrite->Location = System::Drawing::Point(13, 48);
			this->checkBoxOverwrite->Name = L"checkBoxOverwrite";
			this->checkBoxOverwrite->Size = System::Drawing::Size(163, 17);
			this->checkBoxOverwrite->TabIndex = 3;
			this->checkBoxOverwrite->Text = L"Overwrite existing output files";
			this->ttHelp->SetToolTip(this->checkBoxOverwrite, L"-f, --force\r\nForce overwriting of output files.\r\nWarning! No confirmation!");
			this->checkBoxOverwrite->UseVisualStyleBackColor = true;
			this->checkBoxOverwrite->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxOverwrite_CheckedChanged);
			// 
			// btnEncode
			// 
			this->btnEncode->Location = System::Drawing::Point(12, 633);
			this->btnEncode->Name = L"btnEncode";
			this->btnEncode->Size = System::Drawing::Size(75, 23);
			this->btnEncode->TabIndex = 15;
			this->btnEncode->Text = L"&Encode";
			this->ttHelp->SetToolTip(this->btnEncode, L"Encode WAV files or re-encode FLAC files to FLAC");
			this->btnEncode->UseVisualStyleBackColor = true;
			this->btnEncode->Click += gcnew System::EventHandler(this, &Form1::btnEncode_Click);
			// 
			// btnDecode
			// 
			this->btnDecode->Location = System::Drawing::Point(107, 633);
			this->btnDecode->Name = L"btnDecode";
			this->btnDecode->Size = System::Drawing::Size(75, 23);
			this->btnDecode->TabIndex = 16;
			this->btnDecode->Text = L"&Decode";
			this->ttHelp->SetToolTip(this->btnDecode, L"Decode FLAC-files to WAV-files");
			this->btnDecode->UseVisualStyleBackColor = true;
			this->btnDecode->Click += gcnew System::EventHandler(this, &Form1::btnDecode_Click);
			// 
			// btnTest
			// 
			this->btnTest->Location = System::Drawing::Point(201, 633);
			this->btnTest->Name = L"btnTest";
			this->btnTest->Size = System::Drawing::Size(90, 23);
			this->btnTest->TabIndex = 17;
			this->btnTest->Text = L"&Test for errors";
			this->ttHelp->SetToolTip(this->btnTest, L"Test whether FLAC-file is not corrupt");
			this->btnTest->UseVisualStyleBackColor = true;
			this->btnTest->Click += gcnew System::EventHandler(this, &Form1::btnTest_Click);
			// 
			// btnFingerprint
			// 
			this->btnFingerprint->Location = System::Drawing::Point(311, 633);
			this->btnFingerprint->Name = L"btnFingerprint";
			this->btnFingerprint->Size = System::Drawing::Size(75, 23);
			this->btnFingerprint->TabIndex = 18;
			this->btnFingerprint->Text = L"&Fingerprint";
			this->ttHelp->SetToolTip(this->btnFingerprint, L"Show MD5 sums of FLAC-files");
			this->btnFingerprint->UseVisualStyleBackColor = true;
			this->btnFingerprint->Click += gcnew System::EventHandler(this, &Form1::btnFingerprint_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(406, 633);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 19;
			this->btnExit->Text = L"E&xit";
			this->ttHelp->SetToolTip(this->btnExit, L"Exit FLAC frontend-H");
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Form1::btnExit_Click);
			// 
			// gbGeneral
			// 
			this->gbGeneral->Controls->Add(this->chkKeepForeign);
			this->gbGeneral->Controls->Add(this->chkOggFlac);
			this->gbGeneral->Controls->Add(this->chkDeleteInput);
			this->gbGeneral->Location = System::Drawing::Point(220, 152);
			this->gbGeneral->Name = L"gbGeneral";
			this->gbGeneral->Size = System::Drawing::Size(185, 88);
			this->gbGeneral->TabIndex = 5;
			this->gbGeneral->TabStop = false;
			this->gbGeneral->Text = L"General options";
			// 
			// chkKeepForeign
			// 
			this->chkKeepForeign->AutoSize = true;
			this->chkKeepForeign->Location = System::Drawing::Point(13, 66);
			this->chkKeepForeign->Name = L"chkKeepForeign";
			this->chkKeepForeign->Size = System::Drawing::Size(133, 17);
			this->chkKeepForeign->TabIndex = 2;
			this->chkKeepForeign->Text = L"Keep foreign metadata";
			this->ttHelp->SetToolTip(this->chkKeepForeign, L"Keep foreign metadata (like BWF-chunks), see the flac website for more informatio"
				L"n");
			this->chkKeepForeign->UseVisualStyleBackColor = true;
			// 
			// chkOggFlac
			// 
			this->chkOggFlac->AutoSize = true;
			this->chkOggFlac->Location = System::Drawing::Point(13, 43);
			this->chkOggFlac->Name = L"chkOggFlac";
			this->chkOggFlac->Size = System::Drawing::Size(153, 17);
			this->chkOggFlac->TabIndex = 1;
			this->chkOggFlac->Text = L"Create/read as OGG-FLAC";
			this->ttHelp->SetToolTip(this->chkOggFlac, L"Create a FLAC-file in the OGG container or force the input file to be read as OGG"
				L"");
			this->chkOggFlac->UseVisualStyleBackColor = true;
			// 
			// chkDeleteInput
			// 
			this->chkDeleteInput->AutoSize = true;
			this->chkDeleteInput->Location = System::Drawing::Point(13, 20);
			this->chkDeleteInput->Name = L"chkDeleteInput";
			this->chkDeleteInput->Size = System::Drawing::Size(104, 17);
			this->chkDeleteInput->TabIndex = 0;
			this->chkDeleteInput->Text = L"Delete input files";
			this->ttHelp->SetToolTip(this->chkDeleteInput, L"Delete the input files after a successful encode or decode operation");
			this->chkDeleteInput->UseVisualStyleBackColor = true;
			// 
			// gbDecoding
			// 
			this->gbDecoding->Controls->Add(this->chkDecodeThroughErrors);
			this->gbDecoding->Location = System::Drawing::Point(220, 243);
			this->gbDecoding->Name = L"gbDecoding";
			this->gbDecoding->Size = System::Drawing::Size(185, 43);
			this->gbDecoding->TabIndex = 6;
			this->gbDecoding->TabStop = false;
			this->gbDecoding->Text = L"Decoding/testing options";
			// 
			// chkDecodeThroughErrors
			// 
			this->chkDecodeThroughErrors->AutoSize = true;
			this->chkDecodeThroughErrors->Location = System::Drawing::Point(13, 19);
			this->chkDecodeThroughErrors->Name = L"chkDecodeThroughErrors";
			this->chkDecodeThroughErrors->Size = System::Drawing::Size(154, 17);
			this->chkDecodeThroughErrors->TabIndex = 0;
			this->chkDecodeThroughErrors->Text = L"Decode/test through errors";
			this->ttHelp->SetToolTip(this->chkDecodeThroughErrors, L"When errors are found during decoding, do not stop");
			this->chkDecodeThroughErrors->UseVisualStyleBackColor = true;
			// 
			// btnHelp
			// 
			this->btnHelp->Location = System::Drawing::Point(412, 234);
			this->btnHelp->Name = L"btnHelp";
			this->btnHelp->Size = System::Drawing::Size(75, 23);
			this->btnHelp->TabIndex = 13;
			this->btnHelp->Text = L"&Help";
			this->ttHelp->SetToolTip(this->btnHelp, L"Place your mouse pointer over an option to get more information");
			this->btnHelp->UseVisualStyleBackColor = true;
			this->btnHelp->Click += gcnew System::EventHandler(this, &Form1::btnHelp_Click);
			// 
			// btnAdvanced
			// 
			this->btnAdvanced->Enabled = false;
			this->btnAdvanced->Location = System::Drawing::Point(412, 167);
			this->btnAdvanced->Name = L"btnAdvanced";
			this->btnAdvanced->Size = System::Drawing::Size(75, 23);
			this->btnAdvanced->TabIndex = 11;
			this->btnAdvanced->Text = L"Ad&vanced";
			this->ttHelp->SetToolTip(this->btnAdvanced, L"See advanced options");
			this->btnAdvanced->UseVisualStyleBackColor = true;
			this->btnAdvanced->Visible = false;
			this->btnAdvanced->Click += gcnew System::EventHandler(this, &Form1::btnAdvanced_Click);
			// 
			// buttonPreferences
			// 
			this->buttonPreferences->Location = System::Drawing::Point(412, 205);
			this->buttonPreferences->Name = L"buttonPreferences";
			this->buttonPreferences->Size = System::Drawing::Size(75, 23);
			this->buttonPreferences->TabIndex = 12;
			this->buttonPreferences->Text = L"&Preferences";
			this->ttHelp->SetToolTip(this->buttonPreferences, L"App\'s preferences");
			this->buttonPreferences->UseVisualStyleBackColor = true;
			this->buttonPreferences->Click += gcnew System::EventHandler(this, &Form1::buttonPreferences_Click);
			// 
			// btnAbout
			// 
			this->btnAbout->Location = System::Drawing::Point(412, 263);
			this->btnAbout->Name = L"btnAbout";
			this->btnAbout->Size = System::Drawing::Size(75, 23);
			this->btnAbout->TabIndex = 14;
			this->btnAbout->Text = L"A&bout";
			this->ttHelp->SetToolTip(this->btnAbout, L"Get version number of FLAC Frontend-H");
			this->btnAbout->UseVisualStyleBackColor = true;
			this->btnAbout->Click += gcnew System::EventHandler(this, &Form1::btnAbout_Click);
			// 
			// checkBoxNoPadding
			// 
			this->checkBoxNoPadding->AutoSize = true;
			this->checkBoxNoPadding->Checked = true;
			this->checkBoxNoPadding->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxNoPadding->Location = System::Drawing::Point(221, 42);
			this->checkBoxNoPadding->Name = L"checkBoxNoPadding";
			this->checkBoxNoPadding->Size = System::Drawing::Size(108, 17);
			this->checkBoxNoPadding->TabIndex = 10;
			this->checkBoxNoPadding->Text = L"Remove Padding";
			this->ttHelp->SetToolTip(this->checkBoxNoPadding, L"--no-padding");
			this->checkBoxNoPadding->UseVisualStyleBackColor = true;
			this->checkBoxNoPadding->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxNoPadding_CheckedChanged);
			// 
			// textBoxMT
			// 
			this->textBoxMT->Enabled = false;
			this->textBoxMT->Location = System::Drawing::Point(151, 63);
			this->textBoxMT->Name = L"textBoxMT";
			this->textBoxMT->Size = System::Drawing::Size(25, 20);
			this->textBoxMT->TabIndex = 3;
			this->textBoxMT->Text = L"1";
			this->textBoxMT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->ttHelp->SetToolTip(this->textBoxMT, L"-j##, --threads=##\r\nUse ## threads for encoding.\r\nNote!\r\nOnly compatible with FLA"
				L"C version 1.5.0 or higher.");
			this->textBoxMT->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxMT_TextChanged);
			// 
			// textBoxPrefixUser
			// 
			this->textBoxPrefixUser->Enabled = false;
			this->textBoxPrefixUser->Location = System::Drawing::Point(183, 109);
			this->textBoxPrefixUser->Name = L"textBoxPrefixUser";
			this->textBoxPrefixUser->Size = System::Drawing::Size(277, 20);
			this->textBoxPrefixUser->TabIndex = 6;
			this->ttHelp->SetToolTip(this->textBoxPrefixUser, resources->GetString(L"textBoxPrefixUser.ToolTip"));
			this->textBoxPrefixUser->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxPrefixUser_TextChanged);
			// 
			// checkBoxOptionP
			// 
			this->checkBoxOptionP->AutoSize = true;
			this->checkBoxOptionP->Checked = true;
			this->checkBoxOptionP->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxOptionP->Location = System::Drawing::Point(13, 19);
			this->checkBoxOptionP->Name = L"checkBoxOptionP";
			this->checkBoxOptionP->Size = System::Drawing::Size(79, 17);
			this->checkBoxOptionP->TabIndex = 0;
			this->checkBoxOptionP->Text = L"Option \"-p\"";
			this->ttHelp->SetToolTip(this->checkBoxOptionP, L"-p, --qlp-coeff-precision-search\r\n\r\nDo exhaustive search of LP coefficient quanti"
				L"zation (expensive!);\r\noverrides -q;\r\ndoes nothing if using -l 0");
			this->checkBoxOptionP->UseVisualStyleBackColor = true;
			this->checkBoxOptionP->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxOptionP_CheckedChanged);
			// 
			// checkBoxAddPrefix
			// 
			this->checkBoxAddPrefix->AutoSize = true;
			this->checkBoxAddPrefix->Location = System::Drawing::Point(13, 111);
			this->checkBoxAddPrefix->Name = L"checkBoxAddPrefix";
			this->checkBoxAddPrefix->Size = System::Drawing::Size(172, 17);
			this->checkBoxAddPrefix->TabIndex = 5;
			this->checkBoxAddPrefix->Text = L"Add a prefix to output filename:";
			this->ttHelp->SetToolTip(this->checkBoxAddPrefix, resources->GetString(L"checkBoxAddPrefix.ToolTip"));
			this->checkBoxAddPrefix->UseVisualStyleBackColor = true;
			this->checkBoxAddPrefix->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxAddPrefix_CheckedChanged);
			// 
			// checkBoxOptionE
			// 
			this->checkBoxOptionE->AutoSize = true;
			this->checkBoxOptionE->Checked = true;
			this->checkBoxOptionE->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxOptionE->Location = System::Drawing::Point(13, 42);
			this->checkBoxOptionE->Name = L"checkBoxOptionE";
			this->checkBoxOptionE->Size = System::Drawing::Size(79, 17);
			this->checkBoxOptionE->TabIndex = 1;
			this->checkBoxOptionE->Text = L"Option \"-e\"";
			this->ttHelp->SetToolTip(this->checkBoxOptionE, L"-e, --exhaustive-model-search\r\n\r\nDo exhaustive model search (expensive!)");
			this->checkBoxOptionE->UseVisualStyleBackColor = true;
			this->checkBoxOptionE->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxOptionE_CheckedChanged);
			// 
			// checkBoxOptionMT
			// 
			this->checkBoxOptionMT->AutoSize = true;
			this->checkBoxOptionMT->Location = System::Drawing::Point(13, 65);
			this->checkBoxOptionMT->Name = L"checkBoxOptionMT";
			this->checkBoxOptionMT->Size = System::Drawing::Size(140, 17);
			this->checkBoxOptionMT->TabIndex = 2;
			this->checkBoxOptionMT->Text = L"Multithreading. Threads:";
			this->ttHelp->SetToolTip(this->checkBoxOptionMT, L"-j##, --threads=##\r\n\r\nUse ## threads for encoding.\r\nNote!\r\nOnly compatible with F"
				L"LAC version 1.5.0 or higher.");
			this->checkBoxOptionMT->UseVisualStyleBackColor = true;
			this->checkBoxOptionMT->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxOptionMT_CheckedChanged);
			// 
			// checkBoxOptionR
			// 
			this->checkBoxOptionR->AutoSize = true;
			this->checkBoxOptionR->Checked = true;
			this->checkBoxOptionR->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxOptionR->Location = System::Drawing::Point(221, 19);
			this->checkBoxOptionR->Name = L"checkBoxOptionR";
			this->checkBoxOptionR->Size = System::Drawing::Size(79, 17);
			this->checkBoxOptionR->TabIndex = 7;
			this->checkBoxOptionR->Text = L"Option \"-r\":";
			this->ttHelp->SetToolTip(this->checkBoxOptionR, resources->GetString(L"checkBoxOptionR.ToolTip"));
			this->checkBoxOptionR->UseVisualStyleBackColor = true;
			this->checkBoxOptionR->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxOptionR_CheckedChanged);
			// 
			// textBoxR
			// 
			this->textBoxR->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBoxR->Location = System::Drawing::Point(299, 17);
			this->textBoxR->Name = L"textBoxR";
			this->textBoxR->ReadOnly = true;
			this->textBoxR->Size = System::Drawing::Size(21, 20);
			this->textBoxR->TabIndex = 8;
			this->textBoxR->Text = L"8";
			this->textBoxR->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->ttHelp->SetToolTip(this->textBoxR, resources->GetString(L"textBoxR.ToolTip"));
			// 
			// trackBarR
			// 
			this->trackBarR->LargeChange = 1;
			this->trackBarR->Location = System::Drawing::Point(326, 13);
			this->trackBarR->Maximum = 8;
			this->trackBarR->Name = L"trackBarR";
			this->trackBarR->Size = System::Drawing::Size(119, 45);
			this->trackBarR->TabIndex = 9;
			this->ttHelp->SetToolTip(this->trackBarR, resources->GetString(L"trackBarR.ToolTip"));
			this->trackBarR->Value = 8;
			this->trackBarR->ValueChanged += gcnew System::EventHandler(this, &Form1::trackBarR_ValueChanged);
			// 
			// chkIgnoreChunkSize
			// 
			this->chkIgnoreChunkSize->AutoSize = true;
			this->chkIgnoreChunkSize->Location = System::Drawing::Point(13, 88);
			this->chkIgnoreChunkSize->Name = L"chkIgnoreChunkSize";
			this->chkIgnoreChunkSize->Size = System::Drawing::Size(125, 17);
			this->chkIgnoreChunkSize->TabIndex = 4;
			this->chkIgnoreChunkSize->Text = L"Ignore WAVE filesize";
			this->ttHelp->SetToolTip(this->chkIgnoreChunkSize, L"For files > 4GB, use with caution!");
			this->chkIgnoreChunkSize->UseVisualStyleBackColor = true;
			// 
			// checkBoxExactRice
			// 
			this->checkBoxExactRice->AutoSize = true;
			this->checkBoxExactRice->Enabled = false;
			this->checkBoxExactRice->Location = System::Drawing::Point(221, 65);
			this->checkBoxExactRice->Name = L"checkBoxExactRice";
			this->checkBoxExactRice->Size = System::Drawing::Size(78, 17);
			this->checkBoxExactRice->TabIndex = 11;
			this->checkBoxExactRice->Text = L"Exact Rice";
			this->ttHelp->SetToolTip(this->checkBoxExactRice, L"--exact-rice\r\n\r\nExact Rice codeword length calculation.");
			this->checkBoxExactRice->UseVisualStyleBackColor = true;
			this->checkBoxExactRice->Visible = false;
			this->checkBoxExactRice->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxExactRice_CheckedChanged);
			// 
			// checkBoxRiceParameterSearch
			// 
			this->checkBoxRiceParameterSearch->AutoSize = true;
			this->checkBoxRiceParameterSearch->Enabled = false;
			this->checkBoxRiceParameterSearch->Location = System::Drawing::Point(221, 88);
			this->checkBoxRiceParameterSearch->Name = L"checkBoxRiceParameterSearch";
			this->checkBoxRiceParameterSearch->Size = System::Drawing::Size(133, 17);
			this->checkBoxRiceParameterSearch->TabIndex = 12;
			this->checkBoxRiceParameterSearch->Text = L"Rice parameter search";
			this->ttHelp->SetToolTip(this->checkBoxRiceParameterSearch, L"--rice-parameter-search");
			this->checkBoxRiceParameterSearch->UseVisualStyleBackColor = true;
			this->checkBoxRiceParameterSearch->Visible = false;
			this->checkBoxRiceParameterSearch->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxRiceParameterSearch_CheckedChanged);
			// 
			// buttonClearCommandLine
			// 
			this->buttonClearCommandLine->Location = System::Drawing::Point(346, 19);
			this->buttonClearCommandLine->Name = L"buttonClearCommandLine";
			this->buttonClearCommandLine->Size = System::Drawing::Size(48, 22);
			this->buttonClearCommandLine->TabIndex = 2;
			this->buttonClearCommandLine->Text = L"Clear";
			this->ttHelp->SetToolTip(this->buttonClearCommandLine, L"\'Click\" clears current line.\r\n\r\n\'Shift+Click\' clears the whole history.");
			this->buttonClearCommandLine->UseVisualStyleBackColor = true;
			this->buttonClearCommandLine->Click += gcnew System::EventHandler(this, &Form1::buttonClearCommandLine_Click);
			// 
			// groupBoxAdditionalOptions
			// 
			this->groupBoxAdditionalOptions->Controls->Add(this->checkBoxRiceParameterSearch);
			this->groupBoxAdditionalOptions->Controls->Add(this->checkBoxExactRice);
			this->groupBoxAdditionalOptions->Controls->Add(this->chkIgnoreChunkSize);
			this->groupBoxAdditionalOptions->Controls->Add(this->textBoxR);
			this->groupBoxAdditionalOptions->Controls->Add(this->trackBarR);
			this->groupBoxAdditionalOptions->Controls->Add(this->checkBoxOptionR);
			this->groupBoxAdditionalOptions->Controls->Add(this->checkBoxNoPadding);
			this->groupBoxAdditionalOptions->Controls->Add(this->textBoxMT);
			this->groupBoxAdditionalOptions->Controls->Add(this->textBoxPrefixUser);
			this->groupBoxAdditionalOptions->Controls->Add(this->checkBoxOptionP);
			this->groupBoxAdditionalOptions->Controls->Add(this->checkBoxAddPrefix);
			this->groupBoxAdditionalOptions->Controls->Add(this->checkBoxOptionE);
			this->groupBoxAdditionalOptions->Controls->Add(this->checkBoxOptionMT);
			this->groupBoxAdditionalOptions->Location = System::Drawing::Point(12, 292);
			this->groupBoxAdditionalOptions->Name = L"groupBoxAdditionalOptions";
			this->groupBoxAdditionalOptions->Size = System::Drawing::Size(469, 138);
			this->groupBoxAdditionalOptions->TabIndex = 7;
			this->groupBoxAdditionalOptions->TabStop = false;
			this->groupBoxAdditionalOptions->Text = L"Additional options";
			// 
			// grpbCuesheet
			// 
			this->grpbCuesheet->Controls->Add(this->buttonClearCuesheet);
			this->grpbCuesheet->Controls->Add(this->checkCuesheet);
			this->grpbCuesheet->Controls->Add(this->txtCuesheet);
			this->grpbCuesheet->Controls->Add(this->btnCueSheet);
			this->grpbCuesheet->Location = System::Drawing::Point(12, 496);
			this->grpbCuesheet->Name = L"grpbCuesheet";
			this->grpbCuesheet->Size = System::Drawing::Size(469, 54);
			this->grpbCuesheet->TabIndex = 9;
			this->grpbCuesheet->TabStop = false;
			this->grpbCuesheet->Text = L"Embed cuesheet (only for encoding)";
			// 
			// buttonClearCuesheet
			// 
			this->buttonClearCuesheet->Location = System::Drawing::Point(346, 19);
			this->buttonClearCuesheet->Name = L"buttonClearCuesheet";
			this->buttonClearCuesheet->Size = System::Drawing::Size(48, 22);
			this->buttonClearCuesheet->TabIndex = 2;
			this->buttonClearCuesheet->Text = L"Clear";
			this->buttonClearCuesheet->UseVisualStyleBackColor = true;
			this->buttonClearCuesheet->Click += gcnew System::EventHandler(this, &Form1::buttonClearCuesheet_Click);
			// 
			// checkCuesheet
			// 
			this->checkCuesheet->AutoSize = true;
			this->checkCuesheet->Location = System::Drawing::Point(13, 22);
			this->checkCuesheet->Name = L"checkCuesheet";
			this->checkCuesheet->Size = System::Drawing::Size(59, 17);
			this->checkCuesheet->TabIndex = 0;
			this->checkCuesheet->Text = L"Enable";
			this->checkCuesheet->UseVisualStyleBackColor = true;
			this->checkCuesheet->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkCuesheet_CheckedChanged);
			// 
			// txtCuesheet
			// 
			this->txtCuesheet->Location = System::Drawing::Point(78, 20);
			this->txtCuesheet->Name = L"txtCuesheet";
			this->txtCuesheet->Size = System::Drawing::Size(262, 20);
			this->txtCuesheet->TabIndex = 1;
			// 
			// btnCueSheet
			// 
			this->btnCueSheet->Location = System::Drawing::Point(400, 19);
			this->btnCueSheet->Name = L"btnCueSheet";
			this->btnCueSheet->Size = System::Drawing::Size(60, 22);
			this->btnCueSheet->TabIndex = 3;
			this->btnCueSheet->Text = L"Select";
			this->btnCueSheet->UseVisualStyleBackColor = true;
			this->btnCueSheet->Click += gcnew System::EventHandler(this, &Form1::btnCueSheet_Click);
			// 
			// grpbExtraOptions
			// 
			this->grpbExtraOptions->Controls->Add(this->buttonClearCommandLine);
			this->grpbExtraOptions->Controls->Add(this->checkCommandLine);
//			this->grpbExtraOptions->Controls->Add(this->txtCommandLine);
			this->grpbExtraOptions->Controls->Add(this->comboBoxCommandLine);
			this->grpbExtraOptions->Controls->Add(this->btnCommandHelp);
			this->grpbExtraOptions->Location = System::Drawing::Point(12, 436);
			this->grpbExtraOptions->Name = L"grpbExtraOptions";
			this->grpbExtraOptions->Size = System::Drawing::Size(469, 54);
			this->grpbExtraOptions->TabIndex = 8;
			this->grpbExtraOptions->TabStop = false;
			this->grpbExtraOptions->Text = L"Extra command line options";
			// 
			// checkCommandLine
			// 
			this->checkCommandLine->AutoSize = true;
			this->checkCommandLine->Location = System::Drawing::Point(13, 22);
			this->checkCommandLine->Name = L"checkCommandLine";
			this->checkCommandLine->Size = System::Drawing::Size(59, 17);
			this->checkCommandLine->TabIndex = 0;
			this->checkCommandLine->Text = L"Enable";
			this->checkCommandLine->UseVisualStyleBackColor = true;
			this->checkCommandLine->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkCommandLine_CheckedChanged);
			// 
			// txtCommandLine
			// 
//			this->txtCommandLine->Location = System::Drawing::Point(78, 20);
//			this->txtCommandLine->Name = L"txtCommandLine";
//			this->txtCommandLine->Size = System::Drawing::Size(84, 20);
//			this->txtCommandLine->TabIndex = 1;
//			this->txtCommandLine->Visible = false;
			// 
			// comboBoxCommandLine
			// 
			this->comboBoxCommandLine->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboBoxCommandLine->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBoxCommandLine->FormattingEnabled = true;
			this->comboBoxCommandLine->Location = System::Drawing::Point(78, 20);
			this->comboBoxCommandLine->Name = L"comboBoxCommandLine";
			this->comboBoxCommandLine->Size = System::Drawing::Size(262, 21);
			this->comboBoxCommandLine->TabIndex = 1;
			// 
			// btnCommandHelp
			// 
			this->btnCommandHelp->Location = System::Drawing::Point(400, 19);
			this->btnCommandHelp->Name = L"btnCommandHelp";
			this->btnCommandHelp->Size = System::Drawing::Size(60, 22);
			this->btnCommandHelp->TabIndex = 3;
			this->btnCommandHelp->Text = L"See help";
			this->btnCommandHelp->UseVisualStyleBackColor = true;
			this->btnCommandHelp->Click += gcnew System::EventHandler(this, &Form1::btnCommandHelp_Click);
			// 
			// openCueSheet
			// 
			this->openCueSheet->Filter = L"Cuesheet|*.cue";
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(493, 666);
			this->Controls->Add(this->grpbCuesheet);
			this->Controls->Add(this->grpbExtraOptions);
			this->Controls->Add(this->groupBoxAdditionalOptions);
			this->Controls->Add(this->btnAbout);
			this->Controls->Add(this->btnAdvanced);
			this->Controls->Add(this->buttonPreferences);
			this->Controls->Add(this->btnHelp);
			this->Controls->Add(this->gbDecoding);
			this->Controls->Add(this->gbGeneral);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnFingerprint);
			this->Controls->Add(this->btnTest);
			this->Controls->Add(this->btnDecode);
			this->Controls->Add(this->btnEncode);
			this->Controls->Add(this->gbOutputDir);
			this->Controls->Add(this->gbEncoding);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->btnRemove);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->lstFiles);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"FLAC Frontend-H";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::lstFiles_DragDrop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::lstFiles_DragEnter);
			this->gbEncoding->ResumeLayout(false);
			this->gbEncoding->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbLevel))->EndInit();
			this->gbOutputDir->ResumeLayout(false);
			this->gbOutputDir->PerformLayout();
			this->gbGeneral->ResumeLayout(false);
			this->gbGeneral->PerformLayout();
			this->gbDecoding->ResumeLayout(false);
			this->gbDecoding->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarR))->EndInit();
			this->groupBoxAdditionalOptions->ResumeLayout(false);
			this->groupBoxAdditionalOptions->PerformLayout();
			this->grpbCuesheet->ResumeLayout(false);
			this->grpbCuesheet->PerformLayout();
			this->grpbExtraOptions->ResumeLayout(false);
			this->grpbExtraOptions->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: String^ programVersion;
	private: String^ ignoredVersion;
	private: System::String^ GetFlacVersion() {
		Process^ p = gcnew Process();
		p->StartInfo->FileName = "tools/flac.exe";
		p->StartInfo->Arguments = "--version";
		p->StartInfo->UseShellExecute = false;
		p->StartInfo->RedirectStandardOutput = true;
		p->StartInfo->CreateNoWindow = true;
		p->Start();
		String^ output = p->StandardOutput->ReadToEnd();
		p->WaitForExit();
		return output->Trim();
	}
	private: System::Void checkCommandLine_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
//		txtCommandLine->Enabled = checkCommandLine->Checked;
		comboBoxCommandLine->Enabled = checkCommandLine->Checked;
		buttonClearCommandLine->Enabled = checkCommandLine->Checked;
		btnCommandHelp->Enabled = checkCommandLine->Checked;
	}
	private: System::Void buttonClearCommandLine_Click(System::Object^ sender, System::EventArgs^ e) {
//		txtCommandLine->Clear();
		if (Control::ModifierKeys == Keys::Shift) {
			comboBoxCommandLine->Items->Clear();
			comboBoxCommandLine->Text = "";
		}
		else {
			comboBoxCommandLine->Text = "";
		}
		if (comboBoxCommandLine->Enabled) {
			comboBoxCommandLine->Focus();
		}
	}
//	private: System::Void btnCommandHelp_Click(System::Object^ sender, System::EventArgs^ e) {
//		COORD c;
//
//		FreeConsole();
//		AllocConsole();
//		c.X = 80; c.Y = 600;
//		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
//
//		Process^ p = gcnew Process();
//		p->StartInfo->FileName = "tools/flac.exe";
//		p->StartInfo->UseShellExecute = false;
//		p->StartInfo->Arguments = "-h";
//		p->Start();
//		p->WaitForExit();
//		   
//		// Add pause to let console window stay
//		p->StartInfo->FileName = "cmd";
//		p->StartInfo->Arguments = "/c PAUSE";
//		p->Start();
//		p->WaitForExit();
//
//		FreeConsole();
//	}
	private: System::Void btnCommandHelp_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
		Process^ p = gcnew Process();
		p->StartInfo->FileName = "tools/flac.exe";
		p->StartInfo->Arguments = "-h";
		p->StartInfo->UseShellExecute = false;
		p->StartInfo->RedirectStandardOutput = true;
		p->StartInfo->RedirectStandardError = true;
		p->StartInfo->CreateNoWindow = true;
		
		p->Start();

		String^ output = p->StandardOutput->ReadToEnd();
		String^ error = p->StandardError->ReadToEnd();
		p->WaitForExit();

		if (!String::IsNullOrEmpty(error)) {
			MessageBox::Show("Error launching flac.exe:\n" + error, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Create and configure the help form
		CommandLineHelp^ helpForm = gcnew CommandLineHelp();
		helpForm->SetText(output);
		
		// Position the help form to the right of the main window
		helpForm->StartPosition = FormStartPosition::Manual;
		helpForm->Location = Point(this->Location.X + this->Width, this->Location.Y);
		
		// Set height equal to the main window's height
		helpForm->Size = System::Drawing::Size(helpForm->Width, this->Height);

		// Show the help form non-modally (user can interact with both forms)
		helpForm->Show(this);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Failed to open help: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void checkCuesheet_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		txtCuesheet->Enabled = checkCuesheet->Checked;
		buttonClearCuesheet->Enabled = checkCuesheet->Checked;
		btnCueSheet->Enabled = checkCuesheet->Checked;
	}
	private: System::Void buttonClearCuesheet_Click(System::Object^ sender, System::EventArgs^ e) {
		txtCuesheet->Clear();
	}
	private: System::Void btnCueSheet_Click(System::Object^ sender, System::EventArgs^ e) {
		openCueSheet->ShowDialog();
		txtCuesheet->Text = openCueSheet->FileName;
	}

		   // -------------------------------//
		   // --- Right column of buttons --- //
		   // -------------------------------//

	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		dlgAddFile->ShowDialog();
	}

	private: System::Void dlgAddFile_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		lstFiles->Items->AddRange(dlgAddFile->FileNames);
	}

	private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
		lstFiles->Items->Clear();
	}

	private: System::Void btnRemove_Click(System::Object^ sender, System::EventArgs^ e) {
		lstFiles->Items->Remove(lstFiles->SelectedItem);
	}

	private: System::Void btnAdvanced_Click(System::Object^ sender, System::EventArgs^ e) {
		AdvDialog->ShowDialog();
	}

	private: System::Void buttonPreferences_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PreferencesDialog->ShowDialog() == ::DialogResult::OK)
		{
			SaveSettings("settings.txt");
		}
	}

	private: System::Void btnHelp_Click(System::Object^ sender, System::EventArgs^ e) {
		ttHelp->Show("Place your mouse pointer over a specific option to get more information", btnHelp);
	}

	private: System::Void btnAbout_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ flacVersion = GetFlacVersion();
		String^ message = "FLAC Frontend-H v" + this->programVersion + "\n"
			"Using FLAC version: " + flacVersion + "\n\n"
			"Do you want to visit project's homepage?\n"
			"https://github.com/hat3k/FLAC-Frontend-H";

		System::Windows::Forms::DialogResult result = MessageBox::Show(
			message,
			"About",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Information,
			MessageBoxDefaultButton::Button1);

		if (result == ::DialogResult::Yes) {
			Process::Start("https://github.com/hat3k/FLAC-Frontend-H");
		}
	}

		   // ----------------------------------//
		   // --- Setting fields interaction --- //
		   // ----------------------------------//

	private: System::Void tbLevel_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		textLevel->Text = tbLevel->Value.ToString();
	}

	private: System::Void trackBarR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		textBoxR->Text = trackBarR->Value.ToString();
	}

	private: System::Void chkReplayGain_CheckStateChanged(System::Object^ sender, System::EventArgs^ e) {
		if (chkReplayGain->Checked == true) {
			chkReplayGainAlbum->Enabled = true;
		}
		else {
			chkReplayGainAlbum->Checked = false;
			chkReplayGainAlbum->Enabled = false;
		}

	}

		   // ---------------------------------//
		   // --- Output directory buttons --- //
		   // ---------------------------------//

	private: System::Void btnSelectDirectory_Click(System::Object^ sender, System::EventArgs^ e) {
		dlgOutputDirectory->ShowDialog();
		if (!String::IsNullOrEmpty(dlgOutputDirectory->SelectedPath))
			txtOutputDirectory->Text = dlgOutputDirectory->SelectedPath;
	}

	private: System::Void btnOutputDirSameAsInput_Click(System::Object^ sender, System::EventArgs^ e) {
		txtOutputDirectory->Text = "<< Same as input directory >>";
	}


		   // ---------------------------//
		   // --- Last row of buttons --- //
		   // ---------------------------//

	private: System::Void btnEncode_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fileargs = "";
		String^ command = "tools/flac.exe";
		String^ args = "";
		String^ fileTemp = "";
		String^ ext = ".flac";
		COORD c;
		int numberOfFiles = lstFiles->Items->Count;
		int i;

		// Check whether possible
		if (chkReplayGain->Checked == true && chkReplayGainAlbum->Checked == true && numberOfFiles > 50) {
			MessageBox::Show("Adding Album ReplayGain for more than 50 files is not possible", "Too many files", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (chkReplayGain->Checked == true && chkOggFlac->Checked == true) {
			MessageBox::Show("Adding ReplayGain to OGG-FLAC files is currently not supported", "No ReplayGain with Ogg", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Retrieve settings and transform to command-line options
		args += "-" + tbLevel->Value.ToString() + " ";
		if (chkVerify->Checked == true) args += "-V ";
		if (checkBoxOptionE->Checked == true) args += "-e ";
		if (checkBoxOptionP->Checked == true) args += "-p ";
		if (checkBoxNoPadding->Checked == true) args += "--no-padding ";
		if (checkBoxOverwrite->Checked == true) args += "-f ";
		if (checkBoxOptionMT->Checked == true) args += "-j" + textBoxMT->Text + " ";
		if (checkBoxOptionR->Checked == true) args += "-r" + textBoxR->Text + " ";
//		if (checkBoxExactRice->Checked == true) args += "--exact-rice ";
//		if (checkBoxRiceParameterSearch->Checked == true) args += "--rice-parameter-search ";
		if (checkBoxAddPrefix->Checked == true) args += "--output-prefix=" + textBoxPrefixUser->Text + " ";
		if (chkDeleteInput->Checked == true) args += "--delete-input-file ";
		if (chkKeepForeign->Checked == true) args += "--keep-foreign-metadata ";
		if (chkOggFlac->Checked == true) { args += "--ogg "; ext = ".oga"; }
		if (chkIgnoreChunkSize->Checked == true) args += "--ignore-chunk-sizes ";
		if (chkReplayGain->Checked == true && chkReplayGainAlbum->Checked == false) args += "--replay-gain ";
		if (checkCuesheet->Checked == true && !String::IsNullOrEmpty(txtCuesheet->Text)) args += "--cuesheet \"" + txtCuesheet->Text + "\" ";
		if (this->PreferencesDialog->checkBoxDontPreserveTimestampsPermissions->Checked == true) args += "--no-preserve-modtime ";
//		if (this->PreferencesDialog->checkBoxIgnoreReadOnly->Checked == true) args += "--ignore-read-only ";
//		if (checkCommandLine->Checked == true && !String::IsNullOrEmpty(txtCommandLine->Text)) args += txtCommandLine->Text + " ";
		if (checkCommandLine->Checked == true && !String::IsNullOrEmpty(comboBoxCommandLine->Text)) args += comboBoxCommandLine->Text + " ";

		// Get console ready and populate process
		FreeConsole();
		AllocConsole();
		c.X = 80; c.Y = 8000;
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
		Process^ p = gcnew Process();
		p->StartInfo->FileName = command;
		p->StartInfo->UseShellExecute = false;

		if (txtOutputDirectory->Text != "<< Same as input directory >>") {
			// Process each file separately if output directory is specified
			for (i = 0; i < numberOfFiles; i++) {
				fileTemp = "" + lstFiles->Items[i];
				fileTemp = txtOutputDirectory->Text + "\\" + fileTemp->Substring(fileTemp->LastIndexOf("\\"));
				fileTemp = fileTemp->Substring(0, fileTemp->LastIndexOf(".")) + ext;
				p->StartInfo->Arguments = args + "-o " + "\"" + fileTemp + "\" \"" + lstFiles->Items[i] + "\"";
				p->Start();
				p->WaitForExit();
			}
		}
		else if (chkReplayGain->Checked == true && chkReplayGainAlbum->Checked == false) {
			// Process files in batches of 50 if output directory is same as input
			// and (not-album) ReplayGain processing is required
			for (i = 0; i < numberOfFiles; i++) {
				if (i % 50 == 49) {
					p->StartInfo->Arguments = args + fileargs;
					p->Start();
					p->WaitForExit();
					fileargs = "";
				}
				fileargs += "\"" + lstFiles->Items[i] + "\" ";
			}
			// Run remainder
			p->StartInfo->Arguments = args + fileargs;
			p->Start();
			p->WaitForExit();
		}
		else {
			// Process files in batches of 50 if output directory is same as input
			// and ReplayGain processing is not required or Album gain has to be calculated separately
			for (i = 0; i < numberOfFiles; i++) {
				if (i % 50 == 49) {
					p->StartInfo->Arguments = args + fileargs;
					p->Start();
					p->WaitForExit();
					fileargs = "";
				}
				fileargs += "\"" + lstFiles->Items[i] + "\" ";
			}
			// Run remainder
			p->StartInfo->Arguments = args + fileargs;
			p->Start();
			p->WaitForExit();
		}

		// Add ReplayGain tags if album-tags have to be added
		if (chkReplayGain->Checked == true && chkReplayGainAlbum->Checked == true) {
			fileargs = "";
			Console::WriteLine("");
			Console::WriteLine("Now adding ReplayGain, this can take a while... ");
			p->StartInfo->FileName = "tools/metaflac.exe";
			args = "--add-replay-gain ";
			for (i = 0; i < numberOfFiles; i++) {
				if (txtOutputDirectory->Text != "<< Same as input directory >>") {
					fileTemp = "" + lstFiles->Items[i];
					fileTemp = txtOutputDirectory->Text + "\\" + fileTemp->Substring(fileTemp->LastIndexOf("\\"));
					fileTemp = fileTemp->Substring(0, fileTemp->LastIndexOf(".")) + ext;
					fileargs += "\"" + fileTemp + "\" ";
				}
				else {
					fileTemp = "" + lstFiles->Items[i];
					fileTemp = fileTemp->Substring(0, fileTemp->LastIndexOf(".")) + ext;
					fileargs += "\"" + fileTemp + "\" ";
				}
			}
			p->StartInfo->Arguments = args + fileargs;
			p->Start();
			p->WaitForExit();
		}

		// Add pause to let console window stay
		p->StartInfo->FileName = "cmd";
		p->StartInfo->Arguments = "/c PAUSE";
		p->Start();
		p->WaitForExit();
		FreeConsole();
	}

	private: System::Void btnDecode_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fileargs = "";
		String^ command = "tools/flac.exe";
		String^ args = "-d ";
		String^ fileTemp = "";
		COORD c;
		int numberOfFiles = lstFiles->Items->Count;
		int i;

		// Retrieve settings
		if (chkDeleteInput->Checked == true) args += "--delete-input-file ";
		if (chkKeepForeign->Checked == true) args += "--keep-foreign-metadata ";
		if (chkOggFlac->Checked == true) args += "--ogg ";
		if (chkDecodeThroughErrors->Checked == true) args += "-F ";

		if (checkBoxOverwrite->Checked == true) args += "-f ";
		if (this->PreferencesDialog->checkBoxDontPreserveTimestampsPermissions->Checked == true) args += "--no-preserve-modtime ";
//		if (this->PreferencesDialog->checkBoxIgnoreReadOnly->Checked == true) args += "--ignore-read-only ";
//		if (checkCommandLine->Checked == true && !String::IsNullOrEmpty(txtCommandLine->Text)) args += txtCommandLine->Text + " ";
		if (checkCommandLine->Checked == true && !String::IsNullOrEmpty(comboBoxCommandLine->Text)) args += comboBoxCommandLine->Text + " ";

		// Get console ready and populate process
		FreeConsole();
		AllocConsole();
		c.X = 80; c.Y = 8000;
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
		Process^ p = gcnew Process();
		p->StartInfo->FileName = command;
		p->StartInfo->UseShellExecute = false;


		if (txtOutputDirectory->Text != "<< Same as input directory >>") {
			// Process each file separately if output directory is specified
			for (i = 0; i < numberOfFiles; i++) {
				fileTemp = "" + lstFiles->Items[i];
				fileTemp = txtOutputDirectory->Text + "\\" + fileTemp->Substring(fileTemp->LastIndexOf("\\"));
				fileTemp = fileTemp->Substring(0, fileTemp->LastIndexOf(".")) + ".wav";
				p->StartInfo->Arguments = args + "-o " + "\"" + fileTemp + "\" \"" + lstFiles->Items[i] + "\"";
				p->Start();
				p->WaitForExit();
			}
		}
		else {
			// Process in batches of 50 if file is processed in same directory
			for (i = 0; i < numberOfFiles; i++) {
				if (i % 50 == 49) {
					p->StartInfo->Arguments = args + fileargs;
					p->Start();
					p->WaitForExit();
					fileargs = "";
				}
				fileargs += "\"" + lstFiles->Items[i] + "\" ";
			}
			// Run remainder
			p->StartInfo->Arguments = args + fileargs;
			p->Start();
			p->WaitForExit();
		}

		// Add pause to let console window stay
		p->StartInfo->FileName = "cmd";
		p->StartInfo->Arguments = "/c PAUSE";
		p->Start();
		p->WaitForExit();
		FreeConsole();
	}

	private: System::Void btnTest_Click(System::Object^ sender, System::EventArgs^ e) {
		// Let's first create some kind of BAT-file
		String^ fileargs = "";
		String^ command = "tools/flac.exe";
		String^ args = "-t ";
		COORD c;
		int numberOfFiles = lstFiles->Items->Count;
		int i;

		if (chkDecodeThroughErrors->Checked == true)	args += "-F ";

		// Get console ready and populate process
		FreeConsole();
		AllocConsole();
		c.X = 80; c.Y = 8000;
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
		Process^ p = gcnew Process();
		p->StartInfo->FileName = command;
		p->StartInfo->UseShellExecute = false;


		// Process in batches of 50
		for (i = 0; i < numberOfFiles; i++) {
			if (i % 50 == 49) {
				p->StartInfo->Arguments = args + fileargs;
				p->Start();
				p->WaitForExit();
				fileargs = "";
			}
			fileargs += "\"" + lstFiles->Items[i] + "\" ";
		}

		// Run remainder
		p->StartInfo->Arguments = args + fileargs;
		p->Start();
		p->WaitForExit();

		// Add pause to let console window stay
		p->StartInfo->FileName = "cmd";
		p->StartInfo->Arguments = "/c PAUSE";
		p->Start();
		p->WaitForExit();
		FreeConsole();

	}

	private: System::Void btnFingerprint_Click(System::Object^ sender, System::EventArgs^ e) {
		// Let's first create some kind of BAT-file
		String^ fileargs = "";
		String^ command = "tools/metaflac.exe";
		String^ args = "--show-md5sum ";
		COORD c;
		int numberOfFiles = lstFiles->Items->Count;
		int i;

		// Get console ready and populate process
		FreeConsole();
		AllocConsole();
		c.X = 80; c.Y = 8000;
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
		Process^ p = gcnew Process();
		p->StartInfo->FileName = command;
		p->StartInfo->UseShellExecute = false;

		// Process files in batches of 50
		for (i = 0; i < numberOfFiles; i++) {
			if (i % 50 == 49) {
				p->StartInfo->Arguments = args + fileargs;
				p->Start();
				p->WaitForExit();
				fileargs = "";
			}
			fileargs += "\"" + lstFiles->Items[i] + "\" ";
		}

		// Run remainder
		p->StartInfo->Arguments = args + fileargs;
		p->Start();
		p->WaitForExit();

		// Add pause to let console window stay
		p->StartInfo->FileName = "cmd";
		p->StartInfo->Arguments = "/c PAUSE";
		p->Start();
		p->WaitForExit();
		FreeConsole();
	}

	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveSettings("settings.txt");
		this->Close();
	}

		   // ---------------------------//
		   // --- Drag and drop stuff --- //
		   // ---------------------------//

	private: System::Void lstFiles_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		// Show user that dragdrop is possible
		if (e->Data->GetDataPresent(DataFormats::FileDrop))
			e->Effect = DragDropEffects::Link;
		else
			e->Effect = DragDropEffects::None;
	}
	private: System::Void lstFiles_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		// Get filedrop into array of strings
		array<String^>^ FileDropList = (array<String^>^)e->Data->GetData(DataFormats::FileDrop);
		String^ extension = "";
		String^ FileDropDirItem = "";
		String^ FileDropItem = "";

		// First process each item that has been dropped
		for each(String ^ FileDropItem in FileDropList) {
			if (Directory::Exists(FileDropItem)) {
				// Check whether dropped item is directory and find all files in that directory
				for each(String ^ FileDropDirItem in Directory::GetFiles(FileDropItem, "*.*", SearchOption::AllDirectories)) {
					extension = FileDropDirItem->Substring(FileDropDirItem->LastIndexOf(".") + 1);
					if ((extension == "flac") || (extension == "oga") || (extension == "ogg") || (extension == "wav")) {
						// In directory search, only add relevant files
						lstFiles->Items->Add(FileDropDirItem);
					}
				}
			}
			else {
				// If not a directory, just add the dropped item
				lstFiles->Items->Add(FileDropItem);
			}
		}
	}

private: void CheckForUpdate()
{
	try {
		// Enable modern TLS protocols for secure connection
		ServicePointManager::SecurityProtocol = static_cast<SecurityProtocolType>(3072 | 768 | 192); // TLS 1.0, 1.1 and 1.2

		// Download latest version string from GitHub
		WebClient^ client = gcnew WebClient();
		String^ latestFullVersion = client->DownloadString("https://raw.githubusercontent.com/hat3k/FLAC-Frontend-H/master/version.txt")->Trim();

		// Get current version from programVersion field
		String^ currentFullVersion = this->programVersion;
		Version^ current = ParseVersion(currentFullVersion);
		Version^ latest = ParseVersion(latestFullVersion);

		// Compare versions
		if (latest != nullptr && current != nullptr && latest > current)
		{
			// Check if this version was already ignored
			if (ignoredVersion != nullptr && ignoredVersion == latestFullVersion)
			{
				return; // Skip showing dialog
			}

			// Show update dialog with "Cancel = Ignore" option
			System::Windows::Forms::DialogResult result = MessageBox::Show(
				"A new version is available!\n\nCurrent version:\t" + currentFullVersion + "\nLatest version:\t" + latestFullVersion + "\n\nNote: Click 'Cancel' to ignore this version." + "\n\nDo you want to open the releases page?",
				"Update",
				MessageBoxButtons::YesNoCancel,
				MessageBoxIcon::Information
			);

			if (result == ::DialogResult::Yes) {
				// Open releases page
				Process::Start("https://github.com/hat3k/FLAC-Frontend-H/releases");
			}
			else if (result == ::DialogResult::Cancel) {
				// User clicked "Cancel = Ignore this version"
				ignoredVersion = latestFullVersion;
				SaveSettings("settings.txt"); // Save ignored version
			}
		}
	}
	catch (Exception^ ex) {
		// Show error message if network or protocol issues occur
		MessageBox::Show("Error checking for updates:\n" + ex->Message, "Network Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: Version^ ParseVersion(String^ versionStr)
{
	array<String^>^ parts = versionStr->Split(' ');
	if (parts->Length >= 3 && parts[1] == "build")
	{
		int buildNumber;
		if (Int32::TryParse(parts[2], buildNumber))
		{
			return gcnew Version(parts[0] + "." + buildNumber);
		}
	}
	return nullptr;
}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		Environment::CurrentDirectory = Application::StartupPath;
		LoadSettings("settings.txt");
		
		checkBoxOptionMT_CheckedChanged(checkBoxOptionMT, nullptr);
		checkBoxAddPrefix_CheckedChanged(checkBoxAddPrefix, nullptr);
		checkBoxOptionR_CheckedChanged(checkBoxOptionR, nullptr);
		checkCommandLine_CheckedChanged(checkCommandLine, nullptr);
		checkCuesheet_CheckedChanged(checkCuesheet, nullptr);

		if (!(File::Exists("tools/flac.exe"))) {
			MessageBox::Show("flac.exe is not found, FLAC frontend-H can't be used without it. Please reinstall FLAC frontend", "FLAC not found", MessageBoxButtons::OK, MessageBoxIcon::Error);
			// exit(1);
		}
		if (!(File::Exists("tools/metaflac.exe"))) {
			MessageBox::Show("metaflac.exe is not found, FLAC frontend-H can't be used without it. Please reinstall FLAC frontend", "metaflac not found", MessageBoxButtons::OK, MessageBoxIcon::Error);
			// exit(1);
		}
	}
	private: System::Void Form1_Shown(System::Object^ sender, System::EventArgs^ e) {
		if (this->PreferencesDialog->checkBoxCheckForUpdatesOnStartup->Checked) {
			CheckForUpdate();
		}
	}
	private: System::Void checkBoxOptionP_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBoxOptionE_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBoxOptionMT_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBoxOptionMT->Checked)
		{
			textBoxMT->Enabled = true;
		}
		else
		{
			textBoxMT->Enabled = false;
		}
	}
	private: System::Void textBoxMT_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBoxAddPrefix_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBoxAddPrefix->Checked)
		{
			textBoxPrefixUser->Enabled = true;
		}
		else
		{
			textBoxPrefixUser->Enabled = false;
		}
	}
	private: System::Void textBoxPrefixUser_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBoxOverwrite_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBoxOptionR_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (checkBoxOptionR->Checked)
		{
			textBoxR->Enabled = true;
			trackBarR->Enabled = true;
		}
		else
		{
			textBoxR->Enabled = false;
			trackBarR->Enabled = false;
		}
	}
	private: System::Void checkBoxNoPadding_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBoxExactRice_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBoxRiceParameterSearch_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBoxCommandLine_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (PreferencesDialog->checkBoxSaveCommandLineHistory->Checked && String::IsNullOrWhiteSpace(comboBoxCommandLine->Text)) {
			if (comboBoxCommandLine->Items->Contains("")) {
				comboBoxCommandLine->Items->Remove("");
			}
		}
	}
	private: System::Void numericUpDownCommandLineHistoryLimit_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		if (PreferencesDialog->checkBoxSaveCommandLineHistory->Checked) {
			while (comboBoxCommandLine->Items->Count > PreferencesDialog->numericUpDownCommandLineHistoryLimit->Value) {
				comboBoxCommandLine->Items->RemoveAt(comboBoxCommandLine->Items->Count - 1);
			}
		}
	}
	private: System::Void checkBoxSaveCommandLineHistory_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!PreferencesDialog->checkBoxSaveCommandLineHistory->Checked) {
			comboBoxCommandLine->Items->Clear();
		}
	}
	private: System::Void comboBoxCommandLine_Validated(System::Object^ sender, System::EventArgs^ e) {
		comboBoxCommandLine->SelectionStart = comboBoxCommandLine->Text->Length;
		comboBoxCommandLine->SelectionLength = 0;
	}
	private: System::Void comboBoxCommandLine_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (PreferencesDialog->checkBoxSaveCommandLineHistory->Checked &&
			!String::IsNullOrWhiteSpace(comboBoxCommandLine->Text)) {

			if (!comboBoxCommandLine->Items->Contains(comboBoxCommandLine->Text)) {
				comboBoxCommandLine->Items->Insert(0, comboBoxCommandLine->Text);
			}
			while (comboBoxCommandLine->Items->Count > PreferencesDialog->numericUpDownCommandLineHistoryLimit->Value) {
				comboBoxCommandLine->Items->RemoveAt(comboBoxCommandLine->Items->Count - 1);
			}
		}
	}
	private: System::Void comboBoxCommandLine_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			comboBoxCommandLine_Leave(sender, e);
			e->Handled = true;
			e->SuppressKeyPress = true;
		}
	}
};

	public ref class Settings {
	public:
		//Encoding options
		int compressionLevel;
		bool verify;
		bool replayGain;

		//Additional options
		bool optionP;
		bool optionE;
		bool optionMT;
		int optionMTValue;
		bool addPrefix;
		String^ prefixUser;
		bool optionR;
		int optionRValue;
		bool noPadding;
		bool overwrite;
		bool enableCommandLine;
		String^ commandLineOptions;
//		bool exactRice;
//		bool riceParameterSearch;

		// Preferences
		bool checkForUpdatesOnStartup;
		bool dontPreserveTimestampsPermissions;
		bool saveCommandLineHistory;
		int commandLineHistoryLimit;
//		bool ignoreReadOnly;
	};
}

