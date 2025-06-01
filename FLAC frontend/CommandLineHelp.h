#pragma once

namespace FLACfrontend {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

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
			this->Shown += gcnew System::EventHandler(this, &CommandLineHelp::CommandLineHelp_Shown);
			textBoxCommandLineHelpSearch->KeyDown += gcnew KeyEventHandler(this, &CommandLineHelp::textBoxCommandLineHelpSearch_KeyDown);
			this->AcceptButton = buttonCommandLineHelpFind;
			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &CommandLineHelp::Form_KeyDown);
		}

		void SetText(String^ text) {
			richTextBoxCommandLineHelp->Text = text;
			richTextBoxCommandLineHelp->Select(0, 0);
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
	private: System::Windows::Forms::RichTextBox^ richTextBoxCommandLineHelp;

	private: System::Windows::Forms::TextBox^ textBoxCommandLineHelpSearch;
	private: System::Windows::Forms::Button^ buttonCommandLineHelpFind;

	private: System::Void CommandLineHelp_Shown(System::Object^ sender, System::EventArgs^ e)
	{
		this->ActiveControl = textBoxCommandLineHelpSearch;
		textBoxCommandLineHelpSearch->Select(0, 0);
	}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CommandLineHelp::typeid));
			this->richTextBoxCommandLineHelp = (gcnew System::Windows::Forms::RichTextBox());
			this->textBoxCommandLineHelpSearch = (gcnew System::Windows::Forms::TextBox());
			this->buttonCommandLineHelpFind = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBoxCommandLineHelp
			// 
			this->richTextBoxCommandLineHelp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxCommandLineHelp->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBoxCommandLineHelp->HideSelection = false;
			this->richTextBoxCommandLineHelp->Location = System::Drawing::Point(0, 46);
			this->richTextBoxCommandLineHelp->Name = L"richTextBoxCommandLineHelp";
			this->richTextBoxCommandLineHelp->ReadOnly = true;
			this->richTextBoxCommandLineHelp->Size = System::Drawing::Size(624, 394);
			this->richTextBoxCommandLineHelp->TabIndex = 2;
			this->richTextBoxCommandLineHelp->Text = L"";
			// 
			// textBoxCommandLineHelpSearch
			// 
			this->textBoxCommandLineHelpSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxCommandLineHelpSearch->Location = System::Drawing::Point(12, 13);
			this->textBoxCommandLineHelpSearch->Name = L"textBoxCommandLineHelpSearch";
			this->textBoxCommandLineHelpSearch->Size = System::Drawing::Size(519, 20);
			this->textBoxCommandLineHelpSearch->TabIndex = 0;
			// 
			// buttonCommandLineHelpFind
			// 
			this->buttonCommandLineHelpFind->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonCommandLineHelpFind->Location = System::Drawing::Point(537, 12);
			this->buttonCommandLineHelpFind->Name = L"buttonCommandLineHelpFind";
			this->buttonCommandLineHelpFind->Size = System::Drawing::Size(75, 22);
			this->buttonCommandLineHelpFind->TabIndex = 1;
			this->buttonCommandLineHelpFind->Text = L"Find/Next";
			this->buttonCommandLineHelpFind->UseVisualStyleBackColor = true;
			this->buttonCommandLineHelpFind->Click += gcnew System::EventHandler(this, &CommandLineHelp::buttonCommandLineHelpFind_Click);
			// 
			// CommandLineHelp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->buttonCommandLineHelpFind);
			this->Controls->Add(this->textBoxCommandLineHelpSearch);
			this->Controls->Add(this->richTextBoxCommandLineHelp);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CommandLineHelp";
			this->Text = L"Command-line help";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		int lastSearchPos;
		String^ lastSearchText;

		private: void FindTextInHelp(bool forward)
		{
			String^ searchText = textBoxCommandLineHelpSearch->Text;
			if (String::IsNullOrEmpty(searchText))
				return;

			RichTextBox^ rtb = richTextBoxCommandLineHelp;
			int startPos = lastSearchPos;

			if (searchText != lastSearchText)
			{
				startPos = 0;
				lastSearchText = searchText;
			}

			int foundIndex = rtb->Find(searchText, startPos, rtb->Text->Length, RichTextBoxFinds::None);

			if (foundIndex >= 0)
			{
				rtb->SelectionStart = foundIndex;
				rtb->SelectionLength = searchText->Length;
				rtb->Focus();
				lastSearchPos = foundIndex + searchText->Length;
			}
			else
			{
				if (startPos > 0)
				{
					MessageBox::Show("Reached end of file. Searching from the beginning.", "Find", MessageBoxButtons::OK, MessageBoxIcon::Information);
					lastSearchPos = 0;
					FindTextInHelp(forward);
				}
				else
				{
					MessageBox::Show("Text not found.", "Find", MessageBoxButtons::OK, MessageBoxIcon::Information);
					lastSearchPos = 0;
				}
			}
		}
		private: System::Void buttonCommandLineHelpFind_Click(System::Object^ sender, System::EventArgs^ e)
		{
			FindTextInHelp(true);
		}
		private: System::Void textBoxCommandLineHelpSearch_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode == Keys::Enter)
			{
				FindTextInHelp(true);
				e->Handled = true;
				e->SuppressKeyPress = true;
			}
		}
		private: System::Void Form_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode == Keys::F3)
			{
				FindTextInHelp(true);
				e->Handled = true;
				e->SuppressKeyPress = true;
			}
			else if (e->Control && e->KeyCode == Keys::F)
			{
				textBoxCommandLineHelpSearch->Focus();
				textBoxCommandLineHelpSearch->SelectAll();

				e->Handled = true;
				e->SuppressKeyPress = true;
			}
		}
	};
}
