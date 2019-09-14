#pragma once

#include "ProcessJSON.h"
#include "ProcessMemory.h"
#include "settings.h"

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
			if (!Load_config()) { MessageBox::Show("Error loading config file!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); }
			CheckNewVersion();
			InitializeComponent();
			// InitWAV();
			UpdateRubrics();
			checkOffsetsOn->RunWorkerAsync();
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
	private: System::DateTime^ sysTime = gcnew System::DateTime();

	private: System::Windows::Forms::Button^  updateRubrics;
	protected:

	private: System::Windows::Forms::ListBox^  infoBox;

	private: System::Windows::Forms::Button^  clear;
	private: System::Windows::Forms::Button^  findGame;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  bombsLabel;
	private: System::Windows::Forms::Label^  missesLabel;
	private: System::Windows::Forms::Label^  shottypeLabel;
	private: System::Windows::Forms::Label^  diffLabel;
	private: System::Windows::Forms::Label^ optionalLabel1;
	private: System::Windows::Forms::Label^ optionalLabel2;


	private: System::Windows::Forms::Button^  settings;
	private: System::Windows::Forms::Button^  about;

	private: System::ComponentModel::BackgroundWorker^  bkgWorker;
	private: System::Windows::Forms::Label^  extraLabel0;
	private: System::Windows::Forms::Label^  extraLabel1;
	private: System::Windows::Forms::Label^  extraLabel3;
	private: System::Windows::Forms::Label^  extraLabel2;
	private: System::ComponentModel::BackgroundWorker^  UpdateNewVersion;
	private: System::Windows::Forms::Label^  warningLabel;
	private: System::ComponentModel::BackgroundWorker^  checkOffsetsOn;
	private: System::ComponentModel::BackgroundWorker^ findGameThread;

	private: System::Collections::Generic::List<System::Drawing::Brush^>^ IndexedColor = gcnew System::Collections::Generic::List<System::Drawing::Brush^>();

	private: Resources::ResourceManager^ globalStrings = gcnew Resources::ResourceManager(L"RealTimeDRCPointsDisplayerGUI.GlobalStrings", this->GetType()->Assembly);
			 // private: System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GUI::typeid));
			this->updateRubrics = (gcnew System::Windows::Forms::Button());
			this->infoBox = (gcnew System::Windows::Forms::ListBox());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->findGame = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->extraLabel3 = (gcnew System::Windows::Forms::Label());
			this->extraLabel2 = (gcnew System::Windows::Forms::Label());
			this->extraLabel1 = (gcnew System::Windows::Forms::Label());
			this->optionalLabel2 = (gcnew System::Windows::Forms::Label());
			this->optionalLabel1 = (gcnew System::Windows::Forms::Label());
			this->bombsLabel = (gcnew System::Windows::Forms::Label());
			this->missesLabel = (gcnew System::Windows::Forms::Label());
			this->shottypeLabel = (gcnew System::Windows::Forms::Label());
			this->diffLabel = (gcnew System::Windows::Forms::Label());
			this->extraLabel0 = (gcnew System::Windows::Forms::Label());
			this->settings = (gcnew System::Windows::Forms::Button());
			this->about = (gcnew System::Windows::Forms::Button());
			this->bkgWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->UpdateNewVersion = (gcnew System::ComponentModel::BackgroundWorker());
			this->warningLabel = (gcnew System::Windows::Forms::Label());
			this->checkOffsetsOn = (gcnew System::ComponentModel::BackgroundWorker());
			this->findGameThread = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// updateRubrics
			// 
			resources->ApplyResources(this->updateRubrics, L"updateRubrics");
			this->updateRubrics->Name = L"updateRubrics";
			this->updateRubrics->UseVisualStyleBackColor = true;
			this->updateRubrics->Click += gcnew System::EventHandler(this, &GUI::update_Click);
			// 
			// infoBox
			// 
			resources->ApplyResources(this->infoBox, L"infoBox");
			this->infoBox->BackColor = System::Drawing::Color::Black;
			this->infoBox->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->infoBox->ForeColor = System::Drawing::Color::White;
			this->infoBox->FormattingEnabled = true;
			this->infoBox->Name = L"infoBox";
			this->infoBox->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &GUI::DrawItem);
			this->infoBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::listBox1_SelectedIndexChanged);
			// 
			// clear
			// 
			resources->ApplyResources(this->clear, L"clear");
			this->clear->Name = L"clear";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &GUI::clearHistory_Click);
			// 
			// findGame
			// 
			resources->ApplyResources(this->findGame, L"findGame");
			this->findGame->Name = L"findGame";
			this->findGame->UseVisualStyleBackColor = true;
			this->findGame->Click += gcnew System::EventHandler(this, &GUI::findGame_Click);
			// 
			// panel1
			// 
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->extraLabel3);
			this->panel1->Controls->Add(this->extraLabel2);
			this->panel1->Controls->Add(this->extraLabel1);
			this->panel1->Controls->Add(this->optionalLabel2);
			this->panel1->Controls->Add(this->optionalLabel1);
			this->panel1->Controls->Add(this->bombsLabel);
			this->panel1->Controls->Add(this->missesLabel);
			this->panel1->Controls->Add(this->shottypeLabel);
			this->panel1->Controls->Add(this->diffLabel);
			this->panel1->Controls->Add(this->extraLabel0);
			this->panel1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel1->Name = L"panel1";
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GUI::panel1_Paint);
			// 
			// extraLabel3
			// 
			resources->ApplyResources(this->extraLabel3, L"extraLabel3");
			this->extraLabel3->BackColor = System::Drawing::Color::Transparent;
			this->extraLabel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->extraLabel3->ForeColor = System::Drawing::Color::Yellow;
			this->extraLabel3->Name = L"extraLabel3";
			// 
			// extraLabel2
			// 
			resources->ApplyResources(this->extraLabel2, L"extraLabel2");
			this->extraLabel2->BackColor = System::Drawing::Color::Transparent;
			this->extraLabel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->extraLabel2->ForeColor = System::Drawing::Color::Lime;
			this->extraLabel2->Name = L"extraLabel2";
			// 
			// extraLabel1
			// 
			resources->ApplyResources(this->extraLabel1, L"extraLabel1");
			this->extraLabel1->BackColor = System::Drawing::Color::Transparent;
			this->extraLabel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->extraLabel1->ForeColor = System::Drawing::Color::Lime;
			this->extraLabel1->Name = L"extraLabel1";
			// 
			// optionalLabel2
			// 
			resources->ApplyResources(this->optionalLabel2, L"optionalLabel2");
			this->optionalLabel2->BackColor = System::Drawing::Color::Transparent;
			this->optionalLabel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->optionalLabel2->ForeColor = System::Drawing::Color::White;
			this->optionalLabel2->Name = L"optionalLabel2";
			// 
			// optionalLabel1
			// 
			resources->ApplyResources(this->optionalLabel1, L"optionalLabel1");
			this->optionalLabel1->BackColor = System::Drawing::Color::Transparent;
			this->optionalLabel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->optionalLabel1->ForeColor = System::Drawing::Color::White;
			this->optionalLabel1->Name = L"optionalLabel1";
			// 
			// bombsLabel
			// 
			resources->ApplyResources(this->bombsLabel, L"bombsLabel");
			this->bombsLabel->BackColor = System::Drawing::Color::Transparent;
			this->bombsLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bombsLabel->ForeColor = System::Drawing::Color::Lime;
			this->bombsLabel->Name = L"bombsLabel";
			// 
			// missesLabel
			// 
			resources->ApplyResources(this->missesLabel, L"missesLabel");
			this->missesLabel->BackColor = System::Drawing::Color::Transparent;
			this->missesLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->missesLabel->ForeColor = System::Drawing::Color::Red;
			this->missesLabel->Name = L"missesLabel";
			// 
			// shottypeLabel
			// 
			resources->ApplyResources(this->shottypeLabel, L"shottypeLabel");
			this->shottypeLabel->BackColor = System::Drawing::Color::Transparent;
			this->shottypeLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->shottypeLabel->ForeColor = System::Drawing::Color::White;
			this->shottypeLabel->Name = L"shottypeLabel";
			// 
			// diffLabel
			// 
			resources->ApplyResources(this->diffLabel, L"diffLabel");
			this->diffLabel->BackColor = System::Drawing::Color::Transparent;
			this->diffLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->diffLabel->ForeColor = System::Drawing::Color::White;
			this->diffLabel->Name = L"diffLabel";
			// 
			// extraLabel0
			// 
			resources->ApplyResources(this->extraLabel0, L"extraLabel0");
			this->extraLabel0->BackColor = System::Drawing::Color::Transparent;
			this->extraLabel0->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->extraLabel0->ForeColor = System::Drawing::Color::White;
			this->extraLabel0->Name = L"extraLabel0";
			// 
			// settings
			// 
			resources->ApplyResources(this->settings, L"settings");
			this->settings->Name = L"settings";
			this->settings->UseVisualStyleBackColor = true;
			this->settings->Click += gcnew System::EventHandler(this, &GUI::settings_Click);
			// 
			// about
			// 
			resources->ApplyResources(this->about, L"about");
			this->about->Name = L"about";
			this->about->UseVisualStyleBackColor = true;
			this->about->Click += gcnew System::EventHandler(this, &GUI::about_Click);
			// 
			// bkgWorker
			// 
			this->bkgWorker->WorkerReportsProgress = true;
			this->bkgWorker->WorkerSupportsCancellation = true;
			this->bkgWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::bkgWorker_DoWork);
			this->bkgWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &GUI::bkgWorker_ReportProgress);
			// 
			// UpdateNewVersion
			// 
			this->UpdateNewVersion->WorkerReportsProgress = true;
			this->UpdateNewVersion->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::UpdateNewVersion_DoWork);
			this->UpdateNewVersion->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &GUI::UpdateNewVersion_ProgressChanged);
			this->UpdateNewVersion->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &GUI::UpdateNewVersion_RunWorkerCompleted);
			// 
			// warningLabel
			// 
			resources->ApplyResources(this->warningLabel, L"warningLabel");
			this->warningLabel->BackColor = System::Drawing::Color::Transparent;
			this->warningLabel->ForeColor = System::Drawing::Color::Red;
			this->warningLabel->Name = L"warningLabel";
			// 
			// checkOffsetsOn
			// 
			this->checkOffsetsOn->WorkerReportsProgress = true;
			this->checkOffsetsOn->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::checkOffsetsOn_DoWork);
			this->checkOffsetsOn->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &GUI::checkOffsetsOn_ProgressChanged);
			// 
			// findGameThread
			// 
			this->findGameThread->WorkerSupportsCancellation = true;
			this->findGameThread->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::findGameThread_DoWork);
			this->findGameThread->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &GUI::findGameThread_RunWorkerCompleted);
			// 
			// GUI
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->Controls->Add(this->warningLabel);
			this->Controls->Add(this->about);
			this->Controls->Add(this->settings);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->findGame);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->infoBox);
			this->Controls->Add(this->updateRubrics);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"GUI";
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

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{

	}

	// convert to String from const char*
	private: String^ convertToStringClass(const char* &str)
	{
		return gcnew String(str);
	}

	// convert to String from std::string
	private: String^ convertToStringClass(std::string &str)
	{
		return gcnew String(str.c_str());
	}

	 // IN stage final andl ast spells captured
	private: System::Void printFinalStage()
	{
		initLabel();
		if (strcmp(idx_difficulty[difficulty], "Extra") == 0)
		{
			this->extraLabel0->Text = (globalStrings->GetString(L"LastSpells") + L": " + last_spells_captured + L"/1");
		}
		else
		{
			switch (stage)
			{
			case 6: // 6A
			{
				char maxLastSpells = Rubrics["MAX_LAST_SPELLS"][idx_difficulty[difficulty]]["FinalA"].get<char>();
				this->extraLabel0->Text = (L"LS: " + last_spells_captured + L"/" + maxLastSpells);
				this->extraLabel2->Text = globalStrings->GetString(L"Final") + L": A";
				break;
			}
			case 7:	// 6B
			{
				char maxLastSpells = Rubrics["MAX_LAST_SPELLS"][idx_difficulty[difficulty]]["FinalB"].get<char>();
				this->extraLabel0->Text = (L"LS: " + last_spells_captured + L"/" + maxLastSpells);
				this->extraLabel2->Text = globalStrings->GetString(L"Final") + L": B";
				break;
			}
			default:
				this->extraLabel0->Text = (L"LS: " + last_spells_captured + L"/?");
				this->extraLabel2->Text = globalStrings->GetString(L"Final") + L": ?";
				break;
			}
		}
	}

	//
	// Buttons
	//

	private: System::Void about_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// player->PlayLooping();

		MessageBox::Show(
			"Live DRC Points Calculator\n" +
			"(formerly Real-time DRC Points Displayer)\n\n" +
			"A tool that tracks in-game data such as misses, bombs, etc, " +
			"thus calculating DRC points for both survival and scoring during a Touhou run.\n\n" +
			"Author: Cao Minh\n" +
			"Version: " + convertToStringClass(config["version"].get<std::string>()) + "\n" + 
			"GitHub reository name: RealTimeDRCPointsDisplayer",
			"About",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);
		// player->Stop();
	}

	private: System::Void update_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->UpdateRubrics();
	}

	private: System::Void clearHistory_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->infoBox->Items->Clear();
		this->IndexedColor->Clear();
	}

	private: System::Void settings_Click(System::Object^  sender, System::EventArgs^  e)
	{
		RealTimeDRCPointsDisplayerGUI::settings^ settingsForm = gcnew RealTimeDRCPointsDisplayerGUI::settings();
		settingsForm->ShowDialog();		
	}

	private: System::Void findGame_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->infoBox->Items->Add(this->sysTime->Now.ToString("[h:mm:ss]"));
		this->IndexedColor->Add(System::Drawing::Brushes::White);

		// Cancellation
		if (this->findGameThread->IsBusy)
		{
			this->findGameThread->CancelAsync();
		}
		else
		{
			this->infoBox->Items->Add("Finding game, please wait warmly...");
			this->IndexedColor->Add(System::Drawing::Brushes::White);
			this->infoBox->SelectedIndex = this->infoBox->Items->Count - 1;
			this->findGame->Text = L"Stop Finding Game";

			this->findGameThread->RunWorkerAsync();
		}
	}
	
	//
	// Background functions
	//

	private: System::Void CheckNewVersion()
	{
		json temp_config;

		BOOL fail = Download_config();
		if (!fail)
		{
			std::ifstream readNewVersion("_config.json");
			if (!readNewVersion.fail())
			{
				readNewVersion >> temp_config;
				readNewVersion.close();
				String^ newVersion = convertToStringClass(temp_config["version"].get<std::string>());
				String^ curVersion = convertToStringClass(config["version"].get<std::string>());

				// check if there is a new upadte
				if (curVersion->CompareTo(newVersion) < 0)
				{
					if (MessageBox::Show("Version " + newVersion + " is available. Proceed to download page?", "Update", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes)
					{
						Diagnostics::Process::Start("https://github.com/hoangcaominh/RealTimeDRCPointsDisplayer/releases/latest");
					}
				}
			}
		}
		IO::File::Delete("_config.json");
	}

	private: System::Void UpdateRubrics()
	{
		this->infoBox->Items->Add(this->sysTime->Now.ToString("[h:mm:ss]"));
		this->IndexedColor->Add(System::Drawing::Brushes::White);

		this->infoBox->Items->Add(L"Downloading rubric file...");
		this->IndexedColor->Add(System::Drawing::Brushes::White);
		BOOL fail = Download_rubrics();
		if (!fail)
		{
			this->infoBox->Items->Add(L"Successfully downloaded rubric file.");
			this->IndexedColor->Add(System::Drawing::Brushes::White);
		}
		else
		{
			this->infoBox->Items->Add(L"Failed to download rubric file. Returned: " + fail);
			this->IndexedColor->Add(System::Drawing::Brushes::Red);
		}

		this->infoBox->Items->Add(L"Downloading world record file...");
		this->IndexedColor->Add(System::Drawing::Brushes::White);
		fail = Download_wrs();
		if (!fail)
		{
			this->infoBox->Items->Add(L"Successfully downloaded world record file.");
			this->IndexedColor->Add(System::Drawing::Brushes::White);
		}
		else
		{
			this->infoBox->Items->Add(L"Failed to download world record file. Returned: " + fail);
			this->IndexedColor->Add(System::Drawing::Brushes::Red);
		}

		bool flag = true;

		this->infoBox->Items->Add(L"Parsing rubric file...");
		this->IndexedColor->Add(System::Drawing::Brushes::White);
		fail = Load_rubrics();
		if (!fail)
		{
			this->infoBox->Items->Add(L"Successfully parsed rubric file.");
			this->IndexedColor->Add(System::Drawing::Brushes::White);
		}
		else
		{
			this->infoBox->Items->Add(L"Failed to parse rubric file.");
			this->IndexedColor->Add(System::Drawing::Brushes::Red);
			flag = false;
		}

		this->infoBox->Items->Add(L"Parsing world record file...");
		this->IndexedColor->Add(System::Drawing::Brushes::White);
		fail = Load_wrs();
		if (!fail)
		{
			this->infoBox->Items->Add(L"Successfully parsed world record file.");
			this->IndexedColor->Add(System::Drawing::Brushes::White);
		}
		else
		{
			this->infoBox->Items->Add(L"Failed to parse world record file.");
			this->IndexedColor->Add(System::Drawing::Brushes::Red);
			flag = false;
		}

		this->findGame->Enabled = flag;
		this->infoBox->SelectedIndex = this->infoBox->Items->Count - 1;
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
		case 17:	// WBaWC
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

	// Apply offsets from config file
	private: System::Void ApplyOffsets()
	{
		// General offset
		misses += config["InitialMisses"].get<int8_t>();
		bombs += config["InitialBombs"].get<int8_t>();

		// Other offsets
		border_breaks += config["InitialBorderBreaks"].get<int8_t>();
		last_spells_captured += config["InitialLastSpellsCaptured"].get<int8_t>();
		trances += config["InitialTrances"].get<int8_t>();
		releases += config["InitialReleases"].get<int16_t>();
		ufos_red += config["InitialRedUFOs"].get<int8_t>();
		ufos_green += config["InitialGreenUFOs"].get<int8_t>();
		ufos_blue += config["InitialBlueUFOs"].get<int8_t>();
		ufos_rainbow += config["InitialRainbowUFOs"].get<int8_t>();
		wolves += config["InitialWolves"].get<int16_t>();
		otters += config["InitialOtters"].get<int16_t>();
		eagles += config["InitialEagles"].get<int16_t>();
		roar_breaks += config["InitialRoarBreaks"].get<int16_t>();
	}

	// Remove offsets before applying offsets again
	private: System::Void RemoveOffsets()
	{
		// General offset
		misses -= config["InitialMisses"].get<int8_t>();
		bombs -= config["InitialBombs"].get<int8_t>();

		// Other offsets
		border_breaks -= config["InitialBorderBreaks"].get<int8_t>();
		last_spells_captured -= config["InitialLastSpellsCaptured"].get<int8_t>();
		trances -= config["InitialTrances"].get<int8_t>();
		releases -= config["InitialReleases"].get<int16_t>();
		ufos_red -= config["InitialRedUFOs"].get<int8_t>();
		ufos_green -= config["InitialGreenUFOs"].get<int8_t>();
		ufos_blue -= config["InitialBlueUFOs"].get<int8_t>();
		ufos_rainbow -= config["InitialRainbowUFOs"].get<int8_t>();
		wolves -= config["InitialWolves"].get<int16_t>();
		otters -= config["InitialOtters"].get<int16_t>();
		eagles -= config["InitialEagles"].get<int16_t>();
		roar_breaks -= config["InitialRoarBreaks"].get<int16_t>();
	}

	// Display warning when there are offsets applied
	private: System::Void ToggleWarning()
	{
		if (
			config["InitialMisses"] == 0 &&
			config["InitialBombs"] == 0 &&
			config["InitialBorderBreaks"] == 0 &&
			config["InitialLastSpellsCaptured"] == 0 &&
			config["InitialTrances"] == 0 &&
			config["InitialReleases"] == 0 &&
			config["InitialRedUFOs"] == 0 &&
			config["InitialGreenUFOs"] == 0 &&
			config["InitialBlueUFOs"] == 0 &&
			config["InitialRainbowUFOs"] == 0 &&
			config["InitialWolves"] == 0 &&
			config["InitialOtters"] == 0 &&
			config["InitialEagles"] == 0 &&
			config["InitialRoarBreaks"] == 0// &&
			// config["NoChargeAttacks"]
			)
		{
			this->warningLabel->Text = L"";
			this->Height = 388;
		}
		else
		{
			this->warningLabel->Text = L"Warning: Offsets on!";
			this->Height = 399;
		}
	}

	//
	// Background Worker
	//

	private: System::Void findGameThread_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e)
	{
		BOOL find = GetProcess();
		while (find)
		{
			if (this->findGameThread->CancellationPending)
			{
				e->Cancel = true;
				break;
			}

			find = GetProcess();
			System::Threading::Thread::Sleep(100);
		}
	}

	private: System::Void findGameThread_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e)
	{
		if (e->Error != nullptr)
		{
			MessageBox::Show(e->Error->Message);
		}
		else if (e->Cancelled)
		{
			this->infoBox->Items->Add(L"Stopped finding game");
			this->IndexedColor->Add(System::Drawing::Brushes::White);
			this->infoBox->SelectedIndex = this->infoBox->Items->Count - 1;
			this->findGame->Text = L"Find Game";
		}
		else
		{
			this->infoBox->Items->Add(L"Found " + globalStrings->GetString(convertToStringClass(idx_game[game])));
			this->IndexedColor->Add(System::Drawing::Brushes::Lime);

			// Disable buttons
			this->updateRubrics->Enabled = false;
			this->findGame->Text = L"Find Game";
			this->findGame->Enabled = false;

			// Expand window
			RealTimeDRCPointsDisplayerGUI::GUI::Width = 661;

			if (!GetExitCodeProcess(gameProc, &procStatus))
			{
				this->infoBox->Items->Add(L"Get Exit Code Failed. Error: " + GetLastError());
				this->IndexedColor->Add(System::Drawing::Brushes::Red);
			}
			this->infoBox->SelectedIndex = this->infoBox->Items->Count - 1;

			// Inititalize UI
			ReadMemory();
			this->initLabel();

			this->bkgWorker->RunWorkerAsync();
		}
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
				}
			}

			this->bkgWorker->ReportProgress(100);
			System::Threading::Thread::Sleep(10);
		}
		this->bkgWorker->CancelAsync();
	}

	private: System::Void bkgWorker_ReportProgress(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e)
	{
		if (!GetExitCodeReturn)
		{
			this->infoBox->Items->Add(this->sysTime->Now.ToString("[h:mm:ss]"));
			this->IndexedColor->Add(System::Drawing::Brushes::White);
			this->infoBox->Items->Add(L"Get Exit Code Failed. Error: " + GetLastError());
			this->IndexedColor->Add(System::Drawing::Brushes::Red);
			this->infoBox->SelectedIndex = this->infoBox->Items->Count - 1;
		}

		if (procStatus == STILL_ACTIVE)
		{
			this->ApplyOffsets();
			
			calculateDRCPoints();

			this->diffLabel->Text = (globalStrings->GetString(L"Difficulty") + L": " + convertToStringClass(idx_difficulty[difficulty]));

			switch (game)
			{
			case 12:	// GFW
				this->shottypeLabel->Text = (globalStrings->GetString(L"Route") + L": " + globalStrings->GetString(convertToStringClass(shottype)));
				break;
			case 16:	// HSiFS
				this->shottypeLabel->Text = (globalStrings->GetString(L"HSiFS_Shottype") + L": " + globalStrings->GetString(convertToStringClass(shottype)));	// Shottype is too long!
				break;
			default:
				this->shottypeLabel->Text = (globalStrings->GetString(L"Shottype") + L": " + globalStrings->GetString(convertToStringClass(shottype)));
				break;
			}

			this->missesLabel->Text = (globalStrings->GetString(L"Misses") + L": " + misses);
			if (strcmp(idx_game[game], "PoDD") == 0 || strcmp(idx_game[game], "PoFV") == 0)	// Phantasmagoria
			{
				if (no_charge)
				{
					this->bombsLabel->ForeColor = Drawing::Color::Lime;
					this->bombsLabel->Text = L"NoCharge";
				}
				else
				{
					this->bombsLabel->ForeColor = Drawing::Color::Red;
					this->bombsLabel->Text = L"Charged";
				}
			}
			else
			{
				this->bombsLabel->ForeColor = Drawing::Color::Lime;
				this->bombsLabel->Text = (globalStrings->GetString(L"Bombs") + L": " + bombs);
			}

			switch (game)
			{
			case 6:		// PCB
				this->extraLabel0->Text = (globalStrings->GetString(L"BorderBreaks") + L": " + border_breaks);
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
				this->extraLabel0->Text = (globalStrings->GetString(L"Trances") + L": " + trances);
				break;
			case 16:	// HSiFS
				this->extraLabel0->Text = (globalStrings->GetString(L"Releases") + L": " + releases);
				break;
			case 17:	// WBaWC
				this->extraLabel0->Text = (L"" + wolves);
				this->extraLabel1->Text = (L"" + otters);
				this->extraLabel2->Text = (L"" + eagles);
				this->extraLabel3->Text = (L"" + roar_breaks);
				break;
			default:
				this->extraLabel0->Text = (L"");
				break;
			}

			ShowOptionalBox(optionalLabel1, config["OptionalBox1"].get<uint8_t>());
			ShowOptionalBox(optionalLabel2, config["OptionalBox2"].get<uint8_t>());

			RemoveOffsets();
			/*
			if (misses == 0 && bombs == 0 && ls_capped == 10 && timer == 0)
			{
				player->PlayLooping();
			}
			*/
		}
		else
		{
			// Set the window to default
			RealTimeDRCPointsDisplayerGUI::GUI::Width = 299;
			this->infoBox->Items->Add(this->sysTime->Now.ToString("[h:mm:ss]"));
			this->IndexedColor->Add(System::Drawing::Brushes::White);
			this->infoBox->Items->Add(L"Game not found, stopped reading");
			this->IndexedColor->Add(System::Drawing::Brushes::White);
			this->infoBox->SelectedIndex = this->infoBox->Items->Count - 1;

			// Enable buttons
			this->updateRubrics->Enabled = true;
			this->findGame->Enabled = true;
		}
	}

	private: void ShowOptionalBox(System::Windows::Forms::Label^% optionalLabel, uint8_t value)
	{
		switch (value)
		{
		case 0:
			optionalLabel->Text = L"";
			break;
		case 1:
			optionalLabel->Text = System::String::Format("{0:n0}", score);
			break;
		case 2:
			optionalLabel->Text = System::String::Format("{0:n0}", getWR());
			break;
		case 3:
			optionalLabel->Text = globalStrings->GetString(L"SurvivalPoints") + L": " + roundf(drcpoints_survival);
			break;
		case 4:
			optionalLabel->Text = globalStrings->GetString(L"ScoringPoints") + L": " + roundf(drcpoints_scoring);
			break;
		default:
			break;
		}
	}

	/*
	private: System::Void InitWAV()
	{
		String^ path = convertToStringClass(config["WAV"].get<std::string>());
		player->SoundLocation = path;
	}
	*/

	// coloring log text
	private: System::Void DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e)
	{
		e->DrawBackground();
		e->Graphics->DrawString(this->infoBox->Items[e->Index]->ToString(), this->infoBox->Font, IndexedColor[e->Index], e->Bounds);
	}

	private: System::Void checkOffsetsOn_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		while (true)
		{
			this->checkOffsetsOn->ReportProgress(100);
			System::Threading::Thread::Sleep(100);
		}
	}

	private: System::Void checkOffsetsOn_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e)
	{
		this->ToggleWarning();
	}

	// updateNewVersion: not done yet
	private: System::Void UpdateNewVersion_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e)
	{

	}

	private: System::Void UpdateNewVersion_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e)
	{

	}

	private: System::Void UpdateNewVersion_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e)
	{

	}
};
}
