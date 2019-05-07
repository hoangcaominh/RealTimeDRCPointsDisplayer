#pragma once

#include "ProcessJSON.h"

namespace RealTimeDRCPointsDisplayerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for settings
	/// </summary>
	public ref class settings : public System::Windows::Forms::Form
	{
	public:
		settings(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			ShowConfig();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~settings()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::Button^  saveButton;
	private: System::Windows::Forms::Button^  defaultButton;


	private: System::Windows::Forms::GroupBox^  generalBox;
	private: System::Windows::Forms::NumericUpDown^  bombsOffset;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  missesOffset;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::NumericUpDown^  releasesOffset;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::NumericUpDown^  trancesOffset;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  rainbowOffset;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::NumericUpDown^  blueOffset;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  greenOffset;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  redOffset;
	private: System::Windows::Forms::CheckBox^  noChargeCB;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  LSOffset;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  BBOffset;
	private: System::Windows::Forms::GroupBox^  pointsBox;
	private: System::Windows::Forms::CheckBox^  showScoringCB;
	private: System::Windows::Forms::CheckBox^  showSurvivalCB;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(settings::typeid));
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->defaultButton = (gcnew System::Windows::Forms::Button());
			this->generalBox = (gcnew System::Windows::Forms::GroupBox());
			this->bombsOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->missesOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->releasesOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->trancesOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->rainbowOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->blueOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->greenOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->redOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->noChargeCB = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->LSOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->BBOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->pointsBox = (gcnew System::Windows::Forms::GroupBox());
			this->showScoringCB = (gcnew System::Windows::Forms::CheckBox());
			this->showSurvivalCB = (gcnew System::Windows::Forms::CheckBox());
			this->generalBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bombsOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->missesOffset))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->releasesOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trancesOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rainbowOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LSOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BBOffset))->BeginInit();
			this->pointsBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(328, 265);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 16;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(247, 265);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(75, 23);
			this->saveButton->TabIndex = 15;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &settings::saveButton_Click);
			// 
			// defaultButton
			// 
			this->defaultButton->Location = System::Drawing::Point(166, 265);
			this->defaultButton->Name = L"defaultButton";
			this->defaultButton->Size = System::Drawing::Size(75, 23);
			this->defaultButton->TabIndex = 14;
			this->defaultButton->Text = L"Default";
			this->defaultButton->UseVisualStyleBackColor = true;
			this->defaultButton->Click += gcnew System::EventHandler(this, &settings::defaultButton_Click);
			// 
			// generalBox
			// 
			this->generalBox->Controls->Add(this->bombsOffset);
			this->generalBox->Controls->Add(this->label2);
			this->generalBox->Controls->Add(this->label1);
			this->generalBox->Controls->Add(this->missesOffset);
			this->generalBox->Location = System::Drawing::Point(12, 12);
			this->generalBox->Name = L"generalBox";
			this->generalBox->Size = System::Drawing::Size(176, 83);
			this->generalBox->TabIndex = 1;
			this->generalBox->TabStop = false;
			this->generalBox->Text = L"General Offset";
			// 
			// bombsOffset
			// 
			this->bombsOffset->Location = System::Drawing::Point(6, 49);
			this->bombsOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->bombsOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->bombsOffset->Name = L"bombsOffset";
			this->bombsOffset->Size = System::Drawing::Size(54, 22);
			this->bombsOffset->TabIndex = 2;
			this->bombsOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(66, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Bombs";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(66, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Misses";
			// 
			// missesOffset
			// 
			this->missesOffset->Location = System::Drawing::Point(6, 21);
			this->missesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->missesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->missesOffset->Name = L"missesOffset";
			this->missesOffset->Size = System::Drawing::Size(54, 22);
			this->missesOffset->TabIndex = 1;
			this->missesOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->releasesOffset);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->trancesOffset);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->rainbowOffset);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->blueOffset);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->greenOffset);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->redOffset);
			this->groupBox1->Controls->Add(this->noChargeCB);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->LSOffset);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->BBOffset);
			this->groupBox1->Location = System::Drawing::Point(12, 101);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(391, 158);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Other Offsets";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(66, 107);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(67, 16);
			this->label10->TabIndex = 8;
			this->label10->Text = L"Releases";
			// 
			// releasesOffset
			// 
			this->releasesOffset->Location = System::Drawing::Point(6, 105);
			this->releasesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->releasesOffset->Name = L"releasesOffset";
			this->releasesOffset->Size = System::Drawing::Size(54, 22);
			this->releasesOffset->TabIndex = 8;
			this->releasesOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(66, 79);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(58, 16);
			this->label9->TabIndex = 7;
			this->label9->Text = L"Trances";
			// 
			// trancesOffset
			// 
			this->trancesOffset->Location = System::Drawing::Point(6, 77);
			this->trancesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->trancesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->trancesOffset->Name = L"trancesOffset";
			this->trancesOffset->Size = System::Drawing::Size(54, 22);
			this->trancesOffset->TabIndex = 7;
			this->trancesOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(276, 107);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(99, 16);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Rainbow UFOs";
			// 
			// rainbowOffset
			// 
			this->rainbowOffset->Location = System::Drawing::Point(216, 105);
			this->rainbowOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->rainbowOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->rainbowOffset->Name = L"rainbowOffset";
			this->rainbowOffset->Size = System::Drawing::Size(54, 22);
			this->rainbowOffset->TabIndex = 13;
			this->rainbowOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(276, 79);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(73, 16);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Blue UFOs";
			// 
			// blueOffset
			// 
			this->blueOffset->Location = System::Drawing::Point(216, 77);
			this->blueOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->blueOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->blueOffset->Name = L"blueOffset";
			this->blueOffset->Size = System::Drawing::Size(54, 22);
			this->blueOffset->TabIndex = 12;
			this->blueOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(276, 51);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Green UFOs";
			// 
			// greenOffset
			// 
			this->greenOffset->Location = System::Drawing::Point(216, 49);
			this->greenOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->greenOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->greenOffset->Name = L"greenOffset";
			this->greenOffset->Size = System::Drawing::Size(54, 22);
			this->greenOffset->TabIndex = 11;
			this->greenOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(276, 23);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Red UFOs";
			// 
			// redOffset
			// 
			this->redOffset->Location = System::Drawing::Point(216, 21);
			this->redOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->redOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->redOffset->Name = L"redOffset";
			this->redOffset->Size = System::Drawing::Size(54, 22);
			this->redOffset->TabIndex = 10;
			this->redOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// noChargeCB
			// 
			this->noChargeCB->AutoSize = true;
			this->noChargeCB->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->noChargeCB->Checked = true;
			this->noChargeCB->CheckState = System::Windows::Forms::CheckState::Checked;
			this->noChargeCB->Location = System::Drawing::Point(6, 133);
			this->noChargeCB->Name = L"noChargeCB";
			this->noChargeCB->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->noChargeCB->Size = System::Drawing::Size(139, 20);
			this->noChargeCB->TabIndex = 9;
			this->noChargeCB->Text = L"No Charge Attacks";
			this->noChargeCB->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(66, 51);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(132, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Last Spells Captured";
			// 
			// LSOffset
			// 
			this->LSOffset->Location = System::Drawing::Point(6, 49);
			this->LSOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->LSOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, System::Int32::MinValue });
			this->LSOffset->Name = L"LSOffset";
			this->LSOffset->Size = System::Drawing::Size(54, 22);
			this->LSOffset->TabIndex = 6;
			this->LSOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(66, 23);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Border Breaks";
			// 
			// BBOffset
			// 
			this->BBOffset->Location = System::Drawing::Point(6, 21);
			this->BBOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->BBOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->BBOffset->Name = L"BBOffset";
			this->BBOffset->Size = System::Drawing::Size(54, 22);
			this->BBOffset->TabIndex = 5;
			this->BBOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// pointsBox
			// 
			this->pointsBox->Controls->Add(this->showScoringCB);
			this->pointsBox->Controls->Add(this->showSurvivalCB);
			this->pointsBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->pointsBox->Location = System::Drawing::Point(203, 12);
			this->pointsBox->Margin = System::Windows::Forms::Padding(4);
			this->pointsBox->Name = L"pointsBox";
			this->pointsBox->Padding = System::Windows::Forms::Padding(4);
			this->pointsBox->Size = System::Drawing::Size(200, 83);
			this->pointsBox->TabIndex = 0;
			this->pointsBox->TabStop = false;
			this->pointsBox->Text = L"DRC Points";
			// 
			// showScoringCB
			// 
			this->showScoringCB->AutoSize = true;
			this->showScoringCB->Checked = true;
			this->showScoringCB->CheckState = System::Windows::Forms::CheckState::Checked;
			this->showScoringCB->Location = System::Drawing::Point(7, 50);
			this->showScoringCB->Name = L"showScoringCB";
			this->showScoringCB->Size = System::Drawing::Size(155, 20);
			this->showScoringCB->TabIndex = 4;
			this->showScoringCB->Text = L"Display Scoring Point";
			this->showScoringCB->UseVisualStyleBackColor = true;
			// 
			// showSurvivalCB
			// 
			this->showSurvivalCB->AutoSize = true;
			this->showSurvivalCB->Checked = true;
			this->showSurvivalCB->CheckState = System::Windows::Forms::CheckState::Checked;
			this->showSurvivalCB->Location = System::Drawing::Point(7, 22);
			this->showSurvivalCB->Name = L"showSurvivalCB";
			this->showSurvivalCB->Size = System::Drawing::Size(157, 20);
			this->showSurvivalCB->TabIndex = 3;
			this->showSurvivalCB->Text = L"Display Survival Point";
			this->showSurvivalCB->UseVisualStyleBackColor = true;
			// 
			// settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(415, 300);
			this->Controls->Add(this->generalBox);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pointsBox);
			this->Controls->Add(this->defaultButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->cancelButton);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"settings";
			this->ShowIcon = false;
			this->Text = L"Settings";
			this->generalBox->ResumeLayout(false);
			this->generalBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bombsOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->missesOffset))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->releasesOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trancesOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rainbowOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LSOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BBOffset))->EndInit();
			this->pointsBox->ResumeLayout(false);
			this->pointsBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void ShowConfig()
	{
		// General offset
		missesOffset->Value = config["InitialMisses"].get<int16_t>();
		bombsOffset->Value = config["InitialBombs"].get<int16_t>();

		// DRC Points
		showSurvivalCB->Checked = config["ShowSurvivalPoint"].get<bool>();
		showScoringCB->Checked = config["ShowScoringPoint"].get<bool>();

		// Other offsets
		BBOffset->Value = config["InitialBorderBreaks"].get<int16_t>();
		LSOffset->Value = config["InitialLastSpellsCaptured"].get<int16_t>();
		trancesOffset->Value = config["InitialTrances"].get<int16_t>();
		releasesOffset->Value = config["InitialReleases"].get<int16_t>();
		noChargeCB->Checked = config["NoChargeAttacks"].get<bool>();
		redOffset->Value = config["InitialRedUFOs"].get<int16_t>();
		greenOffset->Value = config["InitialGreenUFOs"].get<int16_t>();
		blueOffset->Value = config["InitialBlueUFOs"].get<int16_t>();
		rainbowOffset->Value = config["InitialRainbowUFOs"].get<int16_t>();
	}

	private: System::Void SaveConfig()
	{
		// General offset
		config["InitialMisses"] = Convert::ToInt16(missesOffset->Value);
		config["InitialBombs"] = Convert::ToInt16(bombsOffset->Value);

		// DRC Points
		config["ShowSurvivalPoint"] = showSurvivalCB->Checked;
		config["ShowScoringPoint"] = showScoringCB->Checked;

		// Other offsets
		config["InitialBorderBreaks"] = Convert::ToInt16(BBOffset->Value);
		config["InitialLastSpellsCaptured"] = Convert::ToInt16(LSOffset->Value);
		config["InitialTrances"] = Convert::ToInt16(trancesOffset->Value);
		config["InitialReleases"] = Convert::ToInt16(releasesOffset->Value);
		config["NoChargeAttacks"] = noChargeCB->Checked;
		config["InitialRedUFOs"] = Convert::ToInt16(redOffset->Value);
		config["InitialGreenUFOs"] = Convert::ToInt16(greenOffset->Value);
		config["InitialBlueUFOs"] = Convert::ToInt16(blueOffset->Value);
		config["InitialRainbowUFOs"] = Convert::ToInt16(rainbowOffset->Value);

		// must be done here
		no_charge = noChargeCB->Checked;

		if (!Save_config())	{ MessageBox::Show("Error saving config file!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); }		
		if (!Load_config()) { MessageBox::Show("Error loading config file!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); }

		this->Close();
	}

	private: System::Void defaultButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// General offset
		missesOffset->Value = 0;
		bombsOffset->Value = 0;

		// DRC Points
		showSurvivalCB->Checked = true;
		showScoringCB->Checked = true;

		// Other offsets
		BBOffset->Value = 0;
		LSOffset->Value = 0;
		trancesOffset->Value = 0;
		releasesOffset->Value = 0;
		noChargeCB->Checked = true;
		redOffset->Value = 0;
		greenOffset->Value = 0;
		blueOffset->Value = 0;
		rainbowOffset->Value = 0;

		this->SaveConfig();
	}

	private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->SaveConfig();
		this->Close();
	}

	};
}
