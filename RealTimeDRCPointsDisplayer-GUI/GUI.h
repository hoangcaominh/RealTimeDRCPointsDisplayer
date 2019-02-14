#pragma once

#include "ProcessJSON.h"
#include "ProcessMemory.h"

DWORD procStatus;
DWORD GetExitCodeReturn;

namespace RealTimeDRCPointsDisplayerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:

		GUI(void)
		{
			// LoadConfig();
			// CheckNewVersion();
			InitializeComponent();
			Update();
			RealTimeDRCPointsDisplayerGUI::GUI::Width = 299;
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  updateInfo;
	private: System::Windows::Forms::ListBox^  infoBox;

	protected:

	private: System::Windows::Forms::Button^  clear;
	private: System::Windows::Forms::Button^  detectGame;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  bombsLabel;
	private: System::Windows::Forms::Label^  missesLabel;
	private: System::Windows::Forms::Label^  shottypeLabel;
	private: System::Windows::Forms::Label^  diffLabel;
	// private: System::Windows::Forms::Label^  gameLabel;
	private: System::Windows::Forms::Label^  scoringLabel;
	private: System::Windows::Forms::Label^  survivalLabel;
	private: System::Windows::Forms::Button^  settings;
	private: System::Windows::Forms::Button^  about;
	// private: System::Windows::Forms::Label^  scoreLabel;

	private: System::ComponentModel::BackgroundWorker^  bkgWorker;
	private: System::Windows::Forms::Label^  extraLabel0;
	private: System::Windows::Forms::Label^  extraLabel1;
	private: System::Windows::Forms::Label^  extraLabel3;
	private: System::Windows::Forms::Label^  extraLabel2;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI::typeid));
			this->updateInfo = (gcnew System::Windows::Forms::Button());
			this->infoBox = (gcnew System::Windows::Forms::ListBox());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->detectGame = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->extraLabel3 = (gcnew System::Windows::Forms::Label());
			this->extraLabel2 = (gcnew System::Windows::Forms::Label());
			this->extraLabel1 = (gcnew System::Windows::Forms::Label());
			this->scoringLabel = (gcnew System::Windows::Forms::Label());
			this->survivalLabel = (gcnew System::Windows::Forms::Label());
			this->bombsLabel = (gcnew System::Windows::Forms::Label());
			this->missesLabel = (gcnew System::Windows::Forms::Label());
			this->shottypeLabel = (gcnew System::Windows::Forms::Label());
			this->diffLabel = (gcnew System::Windows::Forms::Label());
			this->extraLabel0 = (gcnew System::Windows::Forms::Label());
			this->settings = (gcnew System::Windows::Forms::Button());
			this->about = (gcnew System::Windows::Forms::Button());
			this->bkgWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// updateInfo
			// 
			this->updateInfo->Location = System::Drawing::Point(12, 256);
			this->updateInfo->Name = L"updateInfo";
			this->updateInfo->Size = System::Drawing::Size(130, 23);
			this->updateInfo->TabIndex = 1;
			this->updateInfo->Text = L"Update Files";
			this->updateInfo->UseVisualStyleBackColor = true;
			this->updateInfo->Click += gcnew System::EventHandler(this, &GUI::update_Click);
			// 
			// infoBox
			// 
			this->infoBox->FormattingEnabled = true;
			this->infoBox->Location = System::Drawing::Point(12, 12);
			this->infoBox->Name = L"infoBox";
			this->infoBox->Size = System::Drawing::Size(266, 238);
			this->infoBox->TabIndex = 0;
			this->infoBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::listBox1_SelectedIndexChanged);
			// 
			// clear
			// 
			this->clear->Location = System::Drawing::Point(12, 285);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(130, 23);
			this->clear->TabIndex = 2;
			this->clear->Text = L"Clear History";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &GUI::clearHistory_Click);
			// 
			// detectGame
			// 
			this->detectGame->Location = System::Drawing::Point(12, 314);
			this->detectGame->Name = L"detectGame";
			this->detectGame->Size = System::Drawing::Size(266, 23);
			this->detectGame->TabIndex = 3;
			this->detectGame->Text = L"Find Game";
			this->detectGame->UseVisualStyleBackColor = true;
			this->detectGame->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->extraLabel3);
			this->panel1->Controls->Add(this->extraLabel2);
			this->panel1->Controls->Add(this->extraLabel1);
			this->panel1->Controls->Add(this->scoringLabel);
			this->panel1->Controls->Add(this->survivalLabel);
			this->panel1->Controls->Add(this->bombsLabel);
			this->panel1->Controls->Add(this->missesLabel);
			this->panel1->Controls->Add(this->shottypeLabel);
			this->panel1->Controls->Add(this->diffLabel);
			this->panel1->Controls->Add(this->extraLabel0);
			this->panel1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel1->Location = System::Drawing::Point(284, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(348, 324);
			this->panel1->TabIndex = 5;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GUI::panel1_Paint);
			// 
			// extraLabel3
			// 
			this->extraLabel3->BackColor = System::Drawing::Color::Transparent;
			this->extraLabel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->extraLabel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->extraLabel3->ForeColor = System::Drawing::Color::Yellow;
			this->extraLabel3->Location = System::Drawing::Point(261, 162);
			this->extraLabel3->Name = L"extraLabel3";
			this->extraLabel3->Size = System::Drawing::Size(87, 54);
			this->extraLabel3->TabIndex = 10;
			this->extraLabel3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->extraLabel3->Visible = false;
			// 
			// extraLabel2
			// 
			this->extraLabel2->BackColor = System::Drawing::Color::Transparent;
			this->extraLabel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->extraLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->extraLabel2->ForeColor = System::Drawing::Color::Lime;
			this->extraLabel2->Location = System::Drawing::Point(174, 162);
			this->extraLabel2->Name = L"extraLabel2";
			this->extraLabel2->Size = System::Drawing::Size(174, 54);
			this->extraLabel2->TabIndex = 9;
			this->extraLabel2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->extraLabel2->Visible = false;
			// 
			// extraLabel1
			// 
			this->extraLabel1->BackColor = System::Drawing::Color::Transparent;
			this->extraLabel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->extraLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->extraLabel1->ForeColor = System::Drawing::Color::Lime;
			this->extraLabel1->Location = System::Drawing::Point(87, 162);
			this->extraLabel1->Name = L"extraLabel1";
			this->extraLabel1->Size = System::Drawing::Size(87, 54);
			this->extraLabel1->TabIndex = 8;
			this->extraLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->extraLabel1->Visible = false;
			// 
			// scoringLabel
			// 
			this->scoringLabel->BackColor = System::Drawing::Color::Transparent;
			this->scoringLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->scoringLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->scoringLabel->ForeColor = System::Drawing::Color::White;
			this->scoringLabel->Location = System::Drawing::Point(0, 270);
			this->scoringLabel->Name = L"scoringLabel";
			this->scoringLabel->Size = System::Drawing::Size(348, 54);
			this->scoringLabel->TabIndex = 6;
			this->scoringLabel->Text = L"Scoring point";
			this->scoringLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// survivalLabel
			// 
			this->survivalLabel->BackColor = System::Drawing::Color::Transparent;
			this->survivalLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->survivalLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->survivalLabel->ForeColor = System::Drawing::Color::White;
			this->survivalLabel->Location = System::Drawing::Point(0, 216);
			this->survivalLabel->Name = L"survivalLabel";
			this->survivalLabel->Size = System::Drawing::Size(348, 54);
			this->survivalLabel->TabIndex = 5;
			this->survivalLabel->Text = L"Survival point";
			this->survivalLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bombsLabel
			// 
			this->bombsLabel->BackColor = System::Drawing::Color::Transparent;
			this->bombsLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bombsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->bombsLabel->ForeColor = System::Drawing::Color::Lime;
			this->bombsLabel->Location = System::Drawing::Point(174, 108);
			this->bombsLabel->Name = L"bombsLabel";
			this->bombsLabel->Size = System::Drawing::Size(174, 54);
			this->bombsLabel->TabIndex = 3;
			this->bombsLabel->Text = L"Bombs";
			this->bombsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// missesLabel
			// 
			this->missesLabel->BackColor = System::Drawing::Color::Transparent;
			this->missesLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->missesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->missesLabel->ForeColor = System::Drawing::Color::Red;
			this->missesLabel->Location = System::Drawing::Point(0, 108);
			this->missesLabel->Name = L"missesLabel";
			this->missesLabel->Size = System::Drawing::Size(174, 54);
			this->missesLabel->TabIndex = 2;
			this->missesLabel->Text = L"Misses";
			this->missesLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// shottypeLabel
			// 
			this->shottypeLabel->BackColor = System::Drawing::Color::Transparent;
			this->shottypeLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->shottypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->shottypeLabel->ForeColor = System::Drawing::Color::White;
			this->shottypeLabel->Location = System::Drawing::Point(0, 54);
			this->shottypeLabel->Name = L"shottypeLabel";
			this->shottypeLabel->Size = System::Drawing::Size(348, 54);
			this->shottypeLabel->TabIndex = 4;
			this->shottypeLabel->Text = L"Shottype";
			this->shottypeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// diffLabel
			// 
			this->diffLabel->BackColor = System::Drawing::Color::Transparent;
			this->diffLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->diffLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->diffLabel->ForeColor = System::Drawing::Color::White;
			this->diffLabel->Location = System::Drawing::Point(0, 0);
			this->diffLabel->Name = L"diffLabel";
			this->diffLabel->Size = System::Drawing::Size(348, 54);
			this->diffLabel->TabIndex = 1;
			this->diffLabel->Text = L"Difficulty";
			this->diffLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// extraLabel0
			// 
			this->extraLabel0->BackColor = System::Drawing::Color::Transparent;
			this->extraLabel0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->extraLabel0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->extraLabel0->ForeColor = System::Drawing::Color::White;
			this->extraLabel0->Location = System::Drawing::Point(0, 162);
			this->extraLabel0->Name = L"extraLabel0";
			this->extraLabel0->Size = System::Drawing::Size(348, 54);
			this->extraLabel0->TabIndex = 7;
			this->extraLabel0->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// settings
			// 
			this->settings->Location = System::Drawing::Point(148, 256);
			this->settings->Name = L"settings";
			this->settings->Size = System::Drawing::Size(130, 23);
			this->settings->TabIndex = 4;
			this->settings->Text = L"Settings";
			this->settings->UseVisualStyleBackColor = true;
			// 
			// about
			// 
			this->about->Location = System::Drawing::Point(148, 285);
			this->about->Name = L"about";
			this->about->Size = System::Drawing::Size(130, 23);
			this->about->TabIndex = 5;
			this->about->Text = L"About";
			this->about->UseVisualStyleBackColor = true;
			this->about->Click += gcnew System::EventHandler(this, &GUI::about_Click);
			// 
			// bkgWorker
			// 
			this->bkgWorker->WorkerReportsProgress = true;
			this->bkgWorker->WorkerSupportsCancellation = true;
			this->bkgWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::bkgWorker_DoWork);
			this->bkgWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &GUI::bkgWorker_ReportProgress);
			this->bkgWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &GUI::bkgWorker_RunWorkerCompleted);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(645, 349);
			this->Controls->Add(this->about);
			this->Controls->Add(this->settings);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->detectGame);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->infoBox);
			this->Controls->Add(this->updateInfo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GUI";
			this->Text = L"Live DRC Points Calculator";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e)
	{

	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{

	}

	private: System::Void update_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Update();
	}

	private: System::Void clearHistory_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->infoBox->Items->Clear();
	}

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{

	}

	private: System::Void LoadConfig()
	{
		if (!Load_config())
		{
			MessageBox::Show("Error loading config file!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void CheckNewVersion()
	{ 
		json temp_config;

		BOOL fail = Download_config();
		if (fail)
		{
			std::ifstream readNewVersion("_config.json");
			if (!readNewVersion.fail())
			{
				readNewVersion >> temp_config;
				String^ newVersion = convertToStringClass(temp_config["version"].get<std::string>());
				String^ curVersion = convertToStringClass(config["version"].get<std::string>());

				// check if there is a new upadte
				if (curVersion->CompareTo(newVersion) < 0)
				{
					if (MessageBox::Show("New version detected. Do you want to update?", "Update", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
					{
						std::string url = temp_config["url"].get<std::string>();
						// Start updating, do it later :P
					}
				}
			}
		}
	}

	private: System::Void Update()
	{
		SYSTEMTIME sysTime;
		GetLocalTime(&sysTime);

		this->infoBox->Items->Add("[" + sysTime.wHour + ":" + sysTime.wMinute + ":" + sysTime.wSecond + "]");

		this->infoBox->Items->Add(L"Downloading rubric file...");
		BOOL fail = Download_rubrics();
		if (!fail)
		{
			this->infoBox->Items->Add(L"Successfully downloaded rubric file.");
		}
		else
		{
			this->infoBox->Items->Add(L"Failed to download rubric file. ID returned: " + fail);
		}

		this->infoBox->Items->Add(L"Downloading world record file...");
		fail = Download_wrs();
		if (!fail)
		{
			this->infoBox->Items->Add(L"Successfully downloaded world record file.");
		}
		else
		{
			this->infoBox->Items->Add(L"Failed to download world record file. ID returned: " + fail);
		}

		bool flag = true;

		this->infoBox->Items->Add(L"Parsing rubric file...");
		fail = Load_rubrics();
		if (!fail)
		{
			this->infoBox->Items->Add(L"Successfully parsed rubric file.");
		}
		else
		{
			this->infoBox->Items->Add(L"Failed to parse rubric file.");
			flag = false;
		}

		this->infoBox->Items->Add(L"Parsing world record file...");
		fail = Load_wrs();
		if (!fail)
		{
			this->infoBox->Items->Add(L"Successfully parsed world record file.");
		}
		else
		{
			this->infoBox->Items->Add(L"Failed to parse world record file.");
			flag = false;
		}

		this->detectGame->Enabled = flag;
		infoBox->SelectedIndex = infoBox->Items->Count - 1;
	}

	// convert to String from const char*
	private: String^ convertToStringClass(const char* &str)
	{
		String^ newString = gcnew String(str);
		return newString;
	}

	// convert to String from std::string
	private: String^ convertToStringClass(std::string &str)
	{
		String^ newString = gcnew String(str.c_str());
		return newString;
	}

	// IN stage final andl ast spells captured
	private: System::Void printFinalStage()
	{
		if (strcmp(idx_difficulty[difficulty], "Extra") == 0)
		{
			this->extraLabel0->Text = (L"Last Spells: " + ls_capped + L"/1");
		}
		else
		{
			switch (stage)
			{
			case 6: // 6A
			{
				char maxLastSpells = Rubrics["MAX_LAST_SPELLS"][idx_difficulty[difficulty]]["FinalA"].get<char>();
				this->extraLabel0->Text = (L"LS: " + ls_capped + L"/" + maxLastSpells);
				this->extraLabel2->Text = L"Final: A";
				break;
			}
			case 7:	// 6B
			{
				char maxLastSpells = Rubrics["MAX_LAST_SPELLS"][idx_difficulty[difficulty]]["FinalB"].get<char>();
				this->extraLabel0->Text = (L"LS: " + ls_capped + L"/" + maxLastSpells);
				this->extraLabel2->Text = L"Final: B";
				break; 
			}
			default:
				this->extraLabel0->Text = (L"LS: " + ls_capped + L"/?");
				this->extraLabel2->Text = L"Final: ?";
				break;
			}
		}
	}

	private: System::Void initLabel()
	{
		switch (game)
		{
		case 6:		// PCB
			this->extraLabel0->Width = 348;
			this->extraLabel0->ForeColor = System::Drawing::Color::Magenta;
			this->extraLabel1->Visible = false;
			this->extraLabel2->Visible = false;
			this->extraLabel3->Visible = false;
			break;
		case 7:		// IN
			if (strcmp(idx_difficulty[difficulty], "Extra") == 0)
			{
				this->extraLabel0->Width = 348;
				this->extraLabel0->ForeColor = System::Drawing::Color::White;
				this->extraLabel1->Visible = false;
				this->extraLabel2->Visible = false;
				this->extraLabel3->Visible = false;
			}
			else
			{
				this->extraLabel0->Width = 174;
				this->extraLabel0->ForeColor = System::Drawing::Color::White;
				this->extraLabel1->Visible = false;
				this->extraLabel2->Visible = true;
				this->extraLabel2->Width = 174;
				this->extraLabel2->ForeColor = System::Drawing::Color::White;
				this->extraLabel3->Visible = false;
			}
			break;
		case 11:	// UFO
			this->extraLabel0->Width = 87;
			this->extraLabel0->ForeColor = System::Drawing::Color::Red;
			this->extraLabel1->Visible = true;
			this->extraLabel2->Visible = true;
			this->extraLabel2->Width = 87;
			this->extraLabel2->ForeColor = System::Drawing::Color::Blue;
			this->extraLabel3->Visible = true;
			break;
		case 13:	// TD
			this->extraLabel0->Width = 348;
			this->extraLabel0->ForeColor = System::Drawing::Color::Silver;
			this->extraLabel1->Visible = false;
			this->extraLabel2->Visible = false;
			this->extraLabel3->Visible = false;
			break;
		case 16:	// HSiFS
			this->extraLabel0->Width = 348;
			this->extraLabel0->ForeColor = System::Drawing::Color::Yellow;
			this->extraLabel1->Visible = false;
			this->extraLabel2->Visible = false;
			this->extraLabel3->Visible = false;
			break;
		default:
			this->extraLabel0->Width = 348;
			this->extraLabel0->Text = L"";
			this->extraLabel1->Visible = false;
			this->extraLabel2->Visible = false;
			this->extraLabel3->Visible = false;
			break;
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SYSTEMTIME sysTime;
		GetLocalTime(&sysTime);

		this->infoBox->Items->Add("[" + sysTime.wHour + ":" + sysTime.wMinute + ":" + sysTime.wSecond + "]");

		BOOL fail = GetProcess();
		// Successfully get the process
		if (!fail)
		{
			this->infoBox->Items->Add(L"Found " + convertToStringClass(idx_game[game]));
			// this->gameLabel->Text = (L"Game: " + convertToStringClass(idx_game[game]));

			// Disable Find Game button
			detectGame->Enabled = false;
			
			// Expand window
			RealTimeDRCPointsDisplayerGUI::GUI::Width = 661;

			if (!GetExitCodeProcess(gameProc, &procStatus))
			{
				this->infoBox->Items->Add(L"Get Exit Code Failed. Error: " + GetLastError());
			}

			// Inititalize UI
			ReadMemory();
			initLabel();

			bkgWorker->RunWorkerAsync();
		}
		else
		{
			this->infoBox->Items->Add(L"Game not found. ID Returned: " + fail);
		}

		infoBox->SelectedIndex = infoBox->Items->Count - 1;
	}

	private: System::Void bkgWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		while (procStatus == STILL_ACTIVE)
		{
			GetExitCodeReturn = GetExitCodeProcess(gameProc, &procStatus);

			if (GetExitCodeReturn)
			{
				if (procStatus == STILL_ACTIVE)
				{
					ReadMemory();
					calculateDRCPoints();
				}
			}

			bkgWorker->ReportProgress(100);
		}
		bkgWorker->CancelAsync();
	}

	private: System::Void bkgWorker_ReportProgress(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e)
	{
		if (!GetExitCodeReturn)
		{
			this->infoBox->Items->Add(L"Get Exit Code Failed. Error: " + GetLastError());
		}

		if (procStatus == STILL_ACTIVE)
		{
			this->diffLabel->Text = (L"Difficulty: " + convertToStringClass(idx_difficulty[difficulty]));

			switch (game)
			{
			case 12:	// GFW
				this->shottypeLabel->Text = (L"Route: " + convertToStringClass(shottype));
				break;
			case 16:	// HSiFS
				this->shottypeLabel->Text = (L"Shot: " + convertToStringClass(shottype));	// Shottype is too long!
				break;
			default:
				this->shottypeLabel->Text = (L"Shottype: " + convertToStringClass(shottype));
				break;
			}

			this->missesLabel->Text = (L"Misses: " + misses);
			if (strcmp(idx_game[game], "PoDD") == 0 || strcmp(idx_game[game], "PoFV") == 0)	// Phantasmagoria
			{
				if (noCharge)
				{
					this->bombsLabel->ForeColor = System::Drawing::Color::Lime;
					this->bombsLabel->Text = L"NoCharge";
				}
				else
				{
					this->bombsLabel->ForeColor = System::Drawing::Color::Red;
					this->bombsLabel->Text = L"Charged";
				}
			}
			else
			{
				this->bombsLabel->ForeColor = System::Drawing::Color::Lime;
				this->bombsLabel->Text = (L"Bombs: " + bombs);
			}
			// this->scoreLabel->Text = (L"Score: " + score);

			switch (game)
			{
			case 6:		// PCB
				this->extraLabel0->Text = (L"Border Breaks: " + borderBreaks);
				break;
			case 7:		// IN
				printFinalStage();
				break;
			case 11:	// UFO
				this->extraLabel0->Text = (L"" + ufos_red);
				this->extraLabel1->Text = (L"" + ufos_green);
				this->extraLabel2->Text = (L"" + ufos_blue);
				this->extraLabel3->Text = (L"" + ufos_rainbow);
				break;
			case 13:	// TD
				this->extraLabel0->Text = (L"Trances: " + trances);
				break;
			case 16:	// HSiFS
				this->extraLabel0->Text = (L"Releases: " + releases);
				break;
			default:
				this->extraLabel0->Text = (L"");
				break;
			}

			this->survivalLabel->Text = (L"Survival Points: " + roundf(drcpoints_survival));
			this->scoringLabel->Text = (L"Scoring Points: " + roundf(drcpoints_scoring));
		}
		else
		{
			// Set the window to default
			RealTimeDRCPointsDisplayerGUI::GUI::Width = 299;
			this->infoBox->Items->Add(L"Game not found, stopped reading");

			// Enable Find Game button
			detectGame->Enabled = true;
		}
	}

	private: System::Void bkgWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
	{

	}

	private: System::Void about_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MessageBox::Show(
			"Live DRC Points Calculator\n" +
			"(formerly Real-time DRC Points Displayer)\n\n" +
			"A small tool that helps players with in-game information such as misses, bombs, etc..\n\n" +
			"Author: Cao Minh\n" + 
			"Version: 1.0",
			"About",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);
	}

	};
}
