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
	private: System::Windows::Forms::TabControl^ otherOffsetsTab;
	private: System::Windows::Forms::TabPage^ tab_PCB;
	private: System::Windows::Forms::TabPage^ tab_IN;
	private: System::Windows::Forms::TabPage^ tab_PoFV;
	private: System::Windows::Forms::TabPage^ tab_UFO;
	private: System::Windows::Forms::TabPage^ tab_TD;
	private: System::Windows::Forms::TabPage^ tab_HSiFS;
	private: System::Windows::Forms::TabPage^ tab_WBaWC;
	private: System::Windows::Forms::NumericUpDown^ wolvesOffset;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::NumericUpDown^ ottersOffset;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::NumericUpDown^ eaglesOffset;
	private: System::Windows::Forms::Button^ defaultButton;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::Button^ cancelButton;











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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(settings::typeid));
			this->generalBox = (gcnew System::Windows::Forms::GroupBox());
			this->bombsOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->missesOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->otherOffsetsTab = (gcnew System::Windows::Forms::TabControl());
			this->tab_PCB = (gcnew System::Windows::Forms::TabPage());
			this->BBOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tab_IN = (gcnew System::Windows::Forms::TabPage());
			this->LSOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tab_PoFV = (gcnew System::Windows::Forms::TabPage());
			this->noChargeCB = (gcnew System::Windows::Forms::CheckBox());
			this->tab_UFO = (gcnew System::Windows::Forms::TabPage());
			this->redOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->rainbowOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->greenOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->blueOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->tab_TD = (gcnew System::Windows::Forms::TabPage());
			this->trancesOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tab_HSiFS = (gcnew System::Windows::Forms::TabPage());
			this->releasesOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tab_WBaWC = (gcnew System::Windows::Forms::TabPage());
			this->wolvesOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->ottersOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->eaglesOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->pointsBox = (gcnew System::Windows::Forms::GroupBox());
			this->showScoringCB = (gcnew System::Windows::Forms::CheckBox());
			this->showSurvivalCB = (gcnew System::Windows::Forms::CheckBox());
			this->defaultButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->generalBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bombsOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->missesOffset))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->otherOffsetsTab->SuspendLayout();
			this->tab_PCB->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BBOffset))->BeginInit();
			this->tab_IN->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LSOffset))->BeginInit();
			this->tab_PoFV->SuspendLayout();
			this->tab_UFO->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rainbowOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueOffset))->BeginInit();
			this->tab_TD->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trancesOffset))->BeginInit();
			this->tab_HSiFS->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->releasesOffset))->BeginInit();
			this->tab_WBaWC->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wolvesOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ottersOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eaglesOffset))->BeginInit();
			this->pointsBox->SuspendLayout();
			this->SuspendLayout();
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
			this->groupBox1->Controls->Add(this->otherOffsetsTab);
			this->groupBox1->Location = System::Drawing::Point(12, 101);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(391, 176);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Other Offsets";
			// 
			// otherOffsetsTab
			// 
			this->otherOffsetsTab->Controls->Add(this->tab_PCB);
			this->otherOffsetsTab->Controls->Add(this->tab_IN);
			this->otherOffsetsTab->Controls->Add(this->tab_PoFV);
			this->otherOffsetsTab->Controls->Add(this->tab_UFO);
			this->otherOffsetsTab->Controls->Add(this->tab_TD);
			this->otherOffsetsTab->Controls->Add(this->tab_HSiFS);
			this->otherOffsetsTab->Controls->Add(this->tab_WBaWC);
			this->otherOffsetsTab->Cursor = System::Windows::Forms::Cursors::Default;
			this->otherOffsetsTab->Location = System::Drawing::Point(6, 21);
			this->otherOffsetsTab->Name = L"otherOffsetsTab";
			this->otherOffsetsTab->SelectedIndex = 0;
			this->otherOffsetsTab->Size = System::Drawing::Size(379, 148);
			this->otherOffsetsTab->TabIndex = 5;
			// 
			// tab_PCB
			// 
			this->tab_PCB->Controls->Add(this->BBOffset);
			this->tab_PCB->Controls->Add(this->label3);
			this->tab_PCB->Location = System::Drawing::Point(4, 25);
			this->tab_PCB->Name = L"tab_PCB";
			this->tab_PCB->Padding = System::Windows::Forms::Padding(3);
			this->tab_PCB->Size = System::Drawing::Size(371, 119);
			this->tab_PCB->TabIndex = 0;
			this->tab_PCB->Text = L"PCB";
			this->tab_PCB->UseVisualStyleBackColor = true;
			// 
			// BBOffset
			// 
			this->BBOffset->Location = System::Drawing::Point(6, 6);
			this->BBOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->BBOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->BBOffset->Name = L"BBOffset";
			this->BBOffset->Size = System::Drawing::Size(54, 22);
			this->BBOffset->TabIndex = 5;
			this->BBOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(66, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Border Breaks";
			// 
			// tab_IN
			// 
			this->tab_IN->Controls->Add(this->LSOffset);
			this->tab_IN->Controls->Add(this->label4);
			this->tab_IN->Location = System::Drawing::Point(4, 25);
			this->tab_IN->Name = L"tab_IN";
			this->tab_IN->Padding = System::Windows::Forms::Padding(3);
			this->tab_IN->Size = System::Drawing::Size(371, 119);
			this->tab_IN->TabIndex = 1;
			this->tab_IN->Text = L"IN";
			this->tab_IN->UseVisualStyleBackColor = true;
			// 
			// LSOffset
			// 
			this->LSOffset->Location = System::Drawing::Point(6, 6);
			this->LSOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->LSOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, System::Int32::MinValue });
			this->LSOffset->Name = L"LSOffset";
			this->LSOffset->Size = System::Drawing::Size(54, 22);
			this->LSOffset->TabIndex = 6;
			this->LSOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(66, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(132, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Last Spells Captured";
			// 
			// tab_PoFV
			// 
			this->tab_PoFV->Controls->Add(this->noChargeCB);
			this->tab_PoFV->Location = System::Drawing::Point(4, 25);
			this->tab_PoFV->Name = L"tab_PoFV";
			this->tab_PoFV->Padding = System::Windows::Forms::Padding(3);
			this->tab_PoFV->Size = System::Drawing::Size(371, 119);
			this->tab_PoFV->TabIndex = 2;
			this->tab_PoFV->Text = L"PoFV";
			this->tab_PoFV->UseVisualStyleBackColor = true;
			// 
			// noChargeCB
			// 
			this->noChargeCB->AutoSize = true;
			this->noChargeCB->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->noChargeCB->Checked = true;
			this->noChargeCB->CheckState = System::Windows::Forms::CheckState::Checked;
			this->noChargeCB->Location = System::Drawing::Point(6, 6);
			this->noChargeCB->Name = L"noChargeCB";
			this->noChargeCB->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->noChargeCB->Size = System::Drawing::Size(139, 20);
			this->noChargeCB->TabIndex = 9;
			this->noChargeCB->Text = L"No Charge Attacks";
			this->noChargeCB->UseVisualStyleBackColor = true;
			// 
			// tab_UFO
			// 
			this->tab_UFO->Controls->Add(this->redOffset);
			this->tab_UFO->Controls->Add(this->label8);
			this->tab_UFO->Controls->Add(this->label5);
			this->tab_UFO->Controls->Add(this->rainbowOffset);
			this->tab_UFO->Controls->Add(this->greenOffset);
			this->tab_UFO->Controls->Add(this->label7);
			this->tab_UFO->Controls->Add(this->label6);
			this->tab_UFO->Controls->Add(this->blueOffset);
			this->tab_UFO->Location = System::Drawing::Point(4, 25);
			this->tab_UFO->Name = L"tab_UFO";
			this->tab_UFO->Padding = System::Windows::Forms::Padding(3);
			this->tab_UFO->Size = System::Drawing::Size(371, 119);
			this->tab_UFO->TabIndex = 3;
			this->tab_UFO->Text = L"UFO";
			this->tab_UFO->UseVisualStyleBackColor = true;
			// 
			// redOffset
			// 
			this->redOffset->Location = System::Drawing::Point(6, 6);
			this->redOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->redOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->redOffset->Name = L"redOffset";
			this->redOffset->Size = System::Drawing::Size(54, 22);
			this->redOffset->TabIndex = 10;
			this->redOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(66, 92);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(99, 16);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Rainbow UFOs";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(66, 8);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Red UFOs";
			// 
			// rainbowOffset
			// 
			this->rainbowOffset->Location = System::Drawing::Point(6, 90);
			this->rainbowOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->rainbowOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->rainbowOffset->Name = L"rainbowOffset";
			this->rainbowOffset->Size = System::Drawing::Size(54, 22);
			this->rainbowOffset->TabIndex = 13;
			this->rainbowOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// greenOffset
			// 
			this->greenOffset->Location = System::Drawing::Point(6, 34);
			this->greenOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->greenOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->greenOffset->Name = L"greenOffset";
			this->greenOffset->Size = System::Drawing::Size(54, 22);
			this->greenOffset->TabIndex = 11;
			this->greenOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(66, 64);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(73, 16);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Blue UFOs";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(66, 36);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Green UFOs";
			// 
			// blueOffset
			// 
			this->blueOffset->Location = System::Drawing::Point(6, 62);
			this->blueOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->blueOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->blueOffset->Name = L"blueOffset";
			this->blueOffset->Size = System::Drawing::Size(54, 22);
			this->blueOffset->TabIndex = 12;
			this->blueOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tab_TD
			// 
			this->tab_TD->Controls->Add(this->trancesOffset);
			this->tab_TD->Controls->Add(this->label9);
			this->tab_TD->Location = System::Drawing::Point(4, 25);
			this->tab_TD->Name = L"tab_TD";
			this->tab_TD->Padding = System::Windows::Forms::Padding(3);
			this->tab_TD->Size = System::Drawing::Size(371, 119);
			this->tab_TD->TabIndex = 4;
			this->tab_TD->Text = L"TD";
			this->tab_TD->UseVisualStyleBackColor = true;
			// 
			// trancesOffset
			// 
			this->trancesOffset->Location = System::Drawing::Point(6, 6);
			this->trancesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->trancesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->trancesOffset->Name = L"trancesOffset";
			this->trancesOffset->Size = System::Drawing::Size(54, 22);
			this->trancesOffset->TabIndex = 7;
			this->trancesOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(66, 8);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(58, 16);
			this->label9->TabIndex = 7;
			this->label9->Text = L"Trances";
			// 
			// tab_HSiFS
			// 
			this->tab_HSiFS->Controls->Add(this->releasesOffset);
			this->tab_HSiFS->Controls->Add(this->label10);
			this->tab_HSiFS->Location = System::Drawing::Point(4, 25);
			this->tab_HSiFS->Name = L"tab_HSiFS";
			this->tab_HSiFS->Padding = System::Windows::Forms::Padding(3);
			this->tab_HSiFS->Size = System::Drawing::Size(371, 119);
			this->tab_HSiFS->TabIndex = 5;
			this->tab_HSiFS->Text = L"HSiFS";
			this->tab_HSiFS->UseVisualStyleBackColor = true;
			// 
			// releasesOffset
			// 
			this->releasesOffset->Location = System::Drawing::Point(6, 6);
			this->releasesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->releasesOffset->Name = L"releasesOffset";
			this->releasesOffset->Size = System::Drawing::Size(54, 22);
			this->releasesOffset->TabIndex = 8;
			this->releasesOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(66, 8);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(67, 16);
			this->label10->TabIndex = 8;
			this->label10->Text = L"Releases";
			// 
			// tab_WBaWC
			// 
			this->tab_WBaWC->Controls->Add(this->wolvesOffset);
			this->tab_WBaWC->Controls->Add(this->label11);
			this->tab_WBaWC->Controls->Add(this->ottersOffset);
			this->tab_WBaWC->Controls->Add(this->label12);
			this->tab_WBaWC->Controls->Add(this->label13);
			this->tab_WBaWC->Controls->Add(this->eaglesOffset);
			this->tab_WBaWC->Location = System::Drawing::Point(4, 25);
			this->tab_WBaWC->Name = L"tab_WBaWC";
			this->tab_WBaWC->Padding = System::Windows::Forms::Padding(3);
			this->tab_WBaWC->Size = System::Drawing::Size(371, 119);
			this->tab_WBaWC->TabIndex = 6;
			this->tab_WBaWC->Text = L"WBaWC";
			this->tab_WBaWC->UseVisualStyleBackColor = true;
			// 
			// wolvesOffset
			// 
			this->wolvesOffset->Location = System::Drawing::Point(6, 6);
			this->wolvesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->wolvesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->wolvesOffset->Name = L"wolvesOffset";
			this->wolvesOffset->Size = System::Drawing::Size(54, 22);
			this->wolvesOffset->TabIndex = 13;
			this->wolvesOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(66, 8);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(54, 16);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Wolves";
			// 
			// ottersOffset
			// 
			this->ottersOffset->Location = System::Drawing::Point(6, 34);
			this->ottersOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->ottersOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->ottersOffset->Name = L"ottersOffset";
			this->ottersOffset->Size = System::Drawing::Size(54, 22);
			this->ottersOffset->TabIndex = 15;
			this->ottersOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(66, 36);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(43, 16);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Otters";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(66, 64);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(51, 16);
			this->label13->TabIndex = 16;
			this->label13->Text = L"Eagles";
			// 
			// eaglesOffset
			// 
			this->eaglesOffset->Location = System::Drawing::Point(6, 62);
			this->eaglesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->eaglesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->eaglesOffset->Name = L"eaglesOffset";
			this->eaglesOffset->Size = System::Drawing::Size(54, 22);
			this->eaglesOffset->TabIndex = 18;
			this->eaglesOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
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
			// defaultButton
			// 
			this->defaultButton->Location = System::Drawing::Point(166, 283);
			this->defaultButton->Name = L"defaultButton";
			this->defaultButton->Size = System::Drawing::Size(75, 23);
			this->defaultButton->TabIndex = 17;
			this->defaultButton->Text = L"Default";
			this->defaultButton->UseVisualStyleBackColor = true;
			this->defaultButton->Click += gcnew System::EventHandler(this, &settings::defaultButton_Click);
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(247, 283);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(75, 23);
			this->saveButton->TabIndex = 18;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &settings::saveButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(328, 283);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 19;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(415, 318);
			this->Controls->Add(this->defaultButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->generalBox);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pointsBox);
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
			this->otherOffsetsTab->ResumeLayout(false);
			this->tab_PCB->ResumeLayout(false);
			this->tab_PCB->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BBOffset))->EndInit();
			this->tab_IN->ResumeLayout(false);
			this->tab_IN->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LSOffset))->EndInit();
			this->tab_PoFV->ResumeLayout(false);
			this->tab_PoFV->PerformLayout();
			this->tab_UFO->ResumeLayout(false);
			this->tab_UFO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->redOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rainbowOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->greenOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blueOffset))->EndInit();
			this->tab_TD->ResumeLayout(false);
			this->tab_TD->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trancesOffset))->EndInit();
			this->tab_HSiFS->ResumeLayout(false);
			this->tab_HSiFS->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->releasesOffset))->EndInit();
			this->tab_WBaWC->ResumeLayout(false);
			this->tab_WBaWC->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wolvesOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ottersOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eaglesOffset))->EndInit();
			this->pointsBox->ResumeLayout(false);
			this->pointsBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void ShowConfig()
	{
		// General offset
		this->missesOffset->Value = config["InitialMisses"].get<int16_t>();
		this->bombsOffset->Value = config["InitialBombs"].get<int16_t>();

		// DRC Points
		this->showSurvivalCB->Checked = config["ShowSurvivalPoint"].get<bool>();
		this->showScoringCB->Checked = config["ShowScoringPoint"].get<bool>();

		// Other offsets
		this->BBOffset->Value = config["InitialBorderBreaks"].get<int16_t>();
		this->LSOffset->Value = config["InitialLastSpellsCaptured"].get<int16_t>();
		this->trancesOffset->Value = config["InitialTrances"].get<int16_t>();
		this->releasesOffset->Value = config["InitialReleases"].get<int16_t>();
		this->noChargeCB->Checked = config["NoChargeAttacks"].get<bool>();
		this->redOffset->Value = config["InitialRedUFOs"].get<int16_t>();
		this->greenOffset->Value = config["InitialGreenUFOs"].get<int16_t>();
		this->blueOffset->Value = config["InitialBlueUFOs"].get<int16_t>();
		this->rainbowOffset->Value = config["InitialRainbowUFOs"].get<int16_t>();
		this->wolvesOffset->Value = config["InitialWolves"].get<int16_t>();
		this->ottersOffset->Value = config["InitialOtters"].get<int16_t>();
		this->eaglesOffset->Value = config["InitialEagles"].get<int16_t>();
	}

	private: System::Void SaveConfig()
	{
		// General offset
		config["InitialMisses"] = Convert::ToInt16(this->missesOffset->Value);
		config["InitialBombs"] = Convert::ToInt16(this->bombsOffset->Value);

		// DRC Points
		config["ShowSurvivalPoint"] = this->showSurvivalCB->Checked;
		config["ShowScoringPoint"] = this->showScoringCB->Checked;

		// Other offsets
		config["InitialBorderBreaks"] = Convert::ToInt16(this->BBOffset->Value);
		config["InitialLastSpellsCaptured"] = Convert::ToInt16(this->LSOffset->Value);
		config["InitialTrances"] = Convert::ToInt16(this->trancesOffset->Value);
		config["InitialReleases"] = Convert::ToInt16(this->releasesOffset->Value);
		config["NoChargeAttacks"] = this->noChargeCB->Checked;
		config["InitialRedUFOs"] = Convert::ToInt16(this->redOffset->Value);
		config["InitialGreenUFOs"] = Convert::ToInt16(this->greenOffset->Value);
		config["InitialBlueUFOs"] = Convert::ToInt16(this->blueOffset->Value);
		config["InitialRainbowUFOs"] = Convert::ToInt16(this->rainbowOffset->Value);
		config["InitialWolves"] = Convert::ToInt16(this->wolvesOffset->Value);
		config["InitialOtters"] = Convert::ToInt16(this->ottersOffset->Value);
		config["InitialEagles"] = Convert::ToInt16(this->eaglesOffset->Value);

		// must be done here
		no_charge = this->noChargeCB->Checked;

		if (!Save_config())	{ MessageBox::Show("Error saving config file!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); }		
		if (!Load_config()) { MessageBox::Show("Error loading config file!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); }

		this->Close();
	}

	private: System::Void defaultButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// General offset
		this->missesOffset->Value = 0;
		this->bombsOffset->Value = 0;

		// DRC Points
		this->showSurvivalCB->Checked = true;
		this->showScoringCB->Checked = true;

		// Other offsets
		this->BBOffset->Value = 0;
		this->LSOffset->Value = 0;
		this->trancesOffset->Value = 0;
		this->releasesOffset->Value = 0;
		this->noChargeCB->Checked = true;
		this->redOffset->Value = 0;
		this->greenOffset->Value = 0;
		this->blueOffset->Value = 0;
		this->rainbowOffset->Value = 0;
		this->wolvesOffset->Value = 0;
		this->ottersOffset->Value = 0;
		this->eaglesOffset->Value = 0;

		this->SaveConfig();
	}

	private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->SaveConfig();
		this->Close();
	}
};
}
