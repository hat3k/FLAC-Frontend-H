#pragma once

namespace FLACfrontend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CommandLineHelp
	/// </summary>
	public ref class CommandLineHelp : public System::Windows::Forms::Form
	{
	public:
		CommandLineHelp(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void SetText(String^ text) {
			textBoxCommandLineHelp->Text = text;
			textBoxCommandLineHelp->Select(0, 0);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CommandLineHelp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxCommandLineHelp;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CommandLineHelp::typeid));
			this->textBoxCommandLineHelp = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBoxCommandLineHelp
			// 
			this->textBoxCommandLineHelp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBoxCommandLineHelp->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxCommandLineHelp->HideSelection = false;
			this->textBoxCommandLineHelp->Location = System::Drawing::Point(0, 0);
			this->textBoxCommandLineHelp->Multiline = true;
			this->textBoxCommandLineHelp->Name = L"textBoxCommandLineHelp";
			this->textBoxCommandLineHelp->ReadOnly = true;
			this->textBoxCommandLineHelp->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxCommandLineHelp->Size = System::Drawing::Size(624, 441);
			this->textBoxCommandLineHelp->TabIndex = 0;
			// 
			// CommandLineHelp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->textBoxCommandLineHelp);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CommandLineHelp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"CommandLineHelp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
