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

	private: System::Windows::Forms::GroupBox^ optinalBox;
	private: System::Windows::Forms::TabControl^ optionalOffsetsTab;
	private: System::Windows::Forms::TabPage^ tab_Box1;
	private: System::Windows::Forms::RadioButton^ scoringRB1;
	private: System::Windows::Forms::RadioButton^ survivalRB1;
	private: System::Windows::Forms::RadioButton^ wrRB1;
	private: System::Windows::Forms::RadioButton^ scoreRB1;
	private: System::Windows::Forms::TabPage^ tab_Box2;
	private: System::Windows::Forms::RadioButton^ scoringRB2;
	private: System::Windows::Forms::RadioButton^ survivalRB2;
	private: System::Windows::Forms::RadioButton^ wrRB2;
	private: System::Windows::Forms::RadioButton^ scoreRB2;











	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::RadioButton^ noneRB1;
private: System::Windows::Forms::RadioButton^ noneRB2;
private: System::Windows::Forms::NumericUpDown^ RBOffset;





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
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->RBOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->wolvesOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->ottersOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->eaglesOffset = (gcnew System::Windows::Forms::NumericUpDown());
			this->defaultButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->optinalBox = (gcnew System::Windows::Forms::GroupBox());
			this->optionalOffsetsTab = (gcnew System::Windows::Forms::TabControl());
			this->tab_Box1 = (gcnew System::Windows::Forms::TabPage());
			this->noneRB1 = (gcnew System::Windows::Forms::RadioButton());
			this->scoringRB1 = (gcnew System::Windows::Forms::RadioButton());
			this->survivalRB1 = (gcnew System::Windows::Forms::RadioButton());
			this->wrRB1 = (gcnew System::Windows::Forms::RadioButton());
			this->scoreRB1 = (gcnew System::Windows::Forms::RadioButton());
			this->tab_Box2 = (gcnew System::Windows::Forms::TabPage());
			this->noneRB2 = (gcnew System::Windows::Forms::RadioButton());
			this->scoringRB2 = (gcnew System::Windows::Forms::RadioButton());
			this->survivalRB2 = (gcnew System::Windows::Forms::RadioButton());
			this->wrRB2 = (gcnew System::Windows::Forms::RadioButton());
			this->scoreRB2 = (gcnew System::Windows::Forms::RadioButton());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RBOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wolvesOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ottersOffset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eaglesOffset))->BeginInit();
			this->optinalBox->SuspendLayout();
			this->optionalOffsetsTab->SuspendLayout();
			this->tab_Box1->SuspendLayout();
			this->tab_Box2->SuspendLayout();
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
			this->generalBox->Size = System::Drawing::Size(176, 195);
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
			this->groupBox1->Location = System::Drawing::Point(12, 214);
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
			this->otherOffsetsTab->Multiline = true;
			this->otherOffsetsTab->Name = L"otherOffsetsTab";
			this->otherOffsetsTab->SelectedIndex = 0;
			this->otherOffsetsTab->Size = System::Drawing::Size(379, 149);
			this->otherOffsetsTab->TabIndex = 5;
			// 
			// tab_PCB
			// 
			this->tab_PCB->Controls->Add(this->BBOffset);
			this->tab_PCB->Controls->Add(this->label3);
			this->tab_PCB->Location = System::Drawing::Point(4, 25);
			this->tab_PCB->Name = L"tab_PCB";
			this->tab_PCB->Padding = System::Windows::Forms::Padding(3);
			this->tab_PCB->Size = System::Drawing::Size(371, 120);
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
			this->tab_IN->Size = System::Drawing::Size(371, 120);
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
			this->tab_PoFV->Size = System::Drawing::Size(371, 120);
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
			this->tab_UFO->Size = System::Drawing::Size(371, 120);
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
			this->tab_TD->Size = System::Drawing::Size(371, 120);
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
			this->tab_HSiFS->Size = System::Drawing::Size(371, 120);
			this->tab_HSiFS->TabIndex = 5;
			this->tab_HSiFS->Text = L"HSiFS";
			this->tab_HSiFS->UseVisualStyleBackColor = true;
			// 
			// releasesOffset
			// 
			this->releasesOffset->Location = System::Drawing::Point(6, 6);
			this->releasesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->releasesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, System::Int32::MinValue });
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
			this->tab_WBaWC->Controls->Add(this->label14);
			this->tab_WBaWC->Controls->Add(this->RBOffset);
			this->tab_WBaWC->Controls->Add(this->wolvesOffset);
			this->tab_WBaWC->Controls->Add(this->label11);
			this->tab_WBaWC->Controls->Add(this->ottersOffset);
			this->tab_WBaWC->Controls->Add(this->label12);
			this->tab_WBaWC->Controls->Add(this->label13);
			this->tab_WBaWC->Controls->Add(this->eaglesOffset);
			this->tab_WBaWC->Location = System::Drawing::Point(4, 25);
			this->tab_WBaWC->Name = L"tab_WBaWC";
			this->tab_WBaWC->Padding = System::Windows::Forms::Padding(3);
			this->tab_WBaWC->Size = System::Drawing::Size(371, 120);
			this->tab_WBaWC->TabIndex = 6;
			this->tab_WBaWC->Text = L"WBaWC";
			this->tab_WBaWC->UseVisualStyleBackColor = true;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(66, 92);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(84, 16);
			this->label14->TabIndex = 19;
			this->label14->Text = L"Roar Breaks";
			// 
			// RBOffset
			// 
			this->RBOffset->Location = System::Drawing::Point(6, 90);
			this->RBOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->RBOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, System::Int32::MinValue });
			this->RBOffset->Name = L"RBOffset";
			this->RBOffset->Size = System::Drawing::Size(54, 22);
			this->RBOffset->TabIndex = 20;
			this->RBOffset->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
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
			// defaultButton
			// 
			this->defaultButton->Location = System::Drawing::Point(166, 396);
			this->defaultButton->Name = L"defaultButton";
			this->defaultButton->Size = System::Drawing::Size(75, 23);
			this->defaultButton->TabIndex = 17;
			this->defaultButton->Text = L"Default";
			this->defaultButton->UseVisualStyleBackColor = true;
			this->defaultButton->Click += gcnew System::EventHandler(this, &settings::defaultButton_Click);
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(247, 396);
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
			this->cancelButton->Location = System::Drawing::Point(328, 396);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 19;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// optinalBox
			// 
			this->optinalBox->Controls->Add(this->optionalOffsetsTab);
			this->optinalBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->optinalBox->Location = System::Drawing::Point(195, 13);
			this->optinalBox->Margin = System::Windows::Forms::Padding(4);
			this->optinalBox->Name = L"optinalBox";
			this->optinalBox->Padding = System::Windows::Forms::Padding(4);
			this->optinalBox->Size = System::Drawing::Size(208, 194);
			this->optinalBox->TabIndex = 20;
			this->optinalBox->TabStop = false;
			this->optinalBox->Text = L"Optional Display";
			// 
			// optionalOffsetsTab
			// 
			this->optionalOffsetsTab->Controls->Add(this->tab_Box1);
			this->optionalOffsetsTab->Controls->Add(this->tab_Box2);
			this->optionalOffsetsTab->Location = System::Drawing::Point(7, 22);
			this->optionalOffsetsTab->Name = L"optionalOffsetsTab";
			this->optionalOffsetsTab->SelectedIndex = 0;
			this->optionalOffsetsTab->Size = System::Drawing::Size(194, 165);
			this->optionalOffsetsTab->TabIndex = 5;
			// 
			// tab_Box1
			// 
			this->tab_Box1->Controls->Add(this->noneRB1);
			this->tab_Box1->Controls->Add(this->scoringRB1);
			this->tab_Box1->Controls->Add(this->survivalRB1);
			this->tab_Box1->Controls->Add(this->wrRB1);
			this->tab_Box1->Controls->Add(this->scoreRB1);
			this->tab_Box1->Location = System::Drawing::Point(4, 25);
			this->tab_Box1->Name = L"tab_Box1";
			this->tab_Box1->Padding = System::Windows::Forms::Padding(3);
			this->tab_Box1->Size = System::Drawing::Size(186, 136);
			this->tab_Box1->TabIndex = 0;
			this->tab_Box1->Text = L"Box 1";
			this->tab_Box1->UseVisualStyleBackColor = true;
			// 
			// noneRB1
			// 
			this->noneRB1->AutoSize = true;
			this->noneRB1->Location = System::Drawing::Point(6, 6);
			this->noneRB1->Name = L"noneRB1";
			this->noneRB1->Size = System::Drawing::Size(59, 20);
			this->noneRB1->TabIndex = 12;
			this->noneRB1->TabStop = true;
			this->noneRB1->Text = L"None";
			this->noneRB1->UseVisualStyleBackColor = true;
			// 
			// scoringRB1
			// 
			this->scoringRB1->AutoSize = true;
			this->scoringRB1->Location = System::Drawing::Point(6, 110);
			this->scoringRB1->Name = L"scoringRB1";
			this->scoringRB1->Size = System::Drawing::Size(112, 20);
			this->scoringRB1->TabIndex = 11;
			this->scoringRB1->Text = L"Scoring Points";
			this->scoringRB1->UseVisualStyleBackColor = true;
			// 
			// survivalRB1
			// 
			this->survivalRB1->AutoSize = true;
			this->survivalRB1->Checked = true;
			this->survivalRB1->Location = System::Drawing::Point(6, 84);
			this->survivalRB1->Name = L"survivalRB1";
			this->survivalRB1->Size = System::Drawing::Size(114, 20);
			this->survivalRB1->TabIndex = 10;
			this->survivalRB1->TabStop = true;
			this->survivalRB1->Text = L"Survival Points";
			this->survivalRB1->UseVisualStyleBackColor = true;
			// 
			// wrRB1
			// 
			this->wrRB1->AutoSize = true;
			this->wrRB1->Location = System::Drawing::Point(6, 58);
			this->wrRB1->Name = L"wrRB1";
			this->wrRB1->Size = System::Drawing::Size(110, 20);
			this->wrRB1->TabIndex = 9;
			this->wrRB1->Text = L"World Record";
			this->wrRB1->UseVisualStyleBackColor = true;
			// 
			// scoreRB1
			// 
			this->scoreRB1->AutoSize = true;
			this->scoreRB1->Location = System::Drawing::Point(6, 32);
			this->scoreRB1->Name = L"scoreRB1";
			this->scoreRB1->Size = System::Drawing::Size(62, 20);
			this->scoreRB1->TabIndex = 8;
			this->scoreRB1->Text = L"Score";
			this->scoreRB1->UseVisualStyleBackColor = true;
			// 
			// tab_Box2
			// 
			this->tab_Box2->Controls->Add(this->noneRB2);
			this->tab_Box2->Controls->Add(this->scoringRB2);
			this->tab_Box2->Controls->Add(this->survivalRB2);
			this->tab_Box2->Controls->Add(this->wrRB2);
			this->tab_Box2->Controls->Add(this->scoreRB2);
			this->tab_Box2->Location = System::Drawing::Point(4, 25);
			this->tab_Box2->Name = L"tab_Box2";
			this->tab_Box2->Padding = System::Windows::Forms::Padding(3);
			this->tab_Box2->Size = System::Drawing::Size(186, 136);
			this->tab_Box2->TabIndex = 1;
			this->tab_Box2->Text = L"Box 2";
			this->tab_Box2->UseVisualStyleBackColor = true;
			// 
			// noneRB2
			// 
			this->noneRB2->AutoSize = true;
			this->noneRB2->Location = System::Drawing::Point(6, 6);
			this->noneRB2->Name = L"noneRB2";
			this->noneRB2->Size = System::Drawing::Size(59, 20);
			this->noneRB2->TabIndex = 13;
			this->noneRB2->TabStop = true;
			this->noneRB2->Text = L"None";
			this->noneRB2->UseVisualStyleBackColor = true;
			// 
			// scoringRB2
			// 
			this->scoringRB2->AutoSize = true;
			this->scoringRB2->Checked = true;
			this->scoringRB2->Location = System::Drawing::Point(6, 110);
			this->scoringRB2->Name = L"scoringRB2";
			this->scoringRB2->Size = System::Drawing::Size(112, 20);
			this->scoringRB2->TabIndex = 11;
			this->scoringRB2->TabStop = true;
			this->scoringRB2->Text = L"Scoring Points";
			this->scoringRB2->UseVisualStyleBackColor = true;
			// 
			// survivalRB2
			// 
			this->survivalRB2->AutoSize = true;
			this->survivalRB2->Location = System::Drawing::Point(6, 84);
			this->survivalRB2->Name = L"survivalRB2";
			this->survivalRB2->Size = System::Drawing::Size(114, 20);
			this->survivalRB2->TabIndex = 10;
			this->survivalRB2->Text = L"Survival Points";
			this->survivalRB2->UseVisualStyleBackColor = true;
			// 
			// wrRB2
			// 
			this->wrRB2->AutoSize = true;
			this->wrRB2->Location = System::Drawing::Point(6, 58);
			this->wrRB2->Name = L"wrRB2";
			this->wrRB2->Size = System::Drawing::Size(110, 20);
			this->wrRB2->TabIndex = 9;
			this->wrRB2->Text = L"World Record";
			this->wrRB2->UseVisualStyleBackColor = true;
			// 
			// scoreRB2
			// 
			this->scoreRB2->AutoSize = true;
			this->scoreRB2->Location = System::Drawing::Point(6, 32);
			this->scoreRB2->Name = L"scoreRB2";
			this->scoreRB2->Size = System::Drawing::Size(62, 20);
			this->scoreRB2->TabIndex = 8;
			this->scoreRB2->Text = L"Score";
			this->scoreRB2->UseVisualStyleBackColor = true;
			// 
			// settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(415, 431);
			this->Controls->Add(this->optinalBox);
			this->Controls->Add(this->defaultButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->generalBox);
			this->Controls->Add(this->groupBox1);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RBOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wolvesOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ottersOffset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eaglesOffset))->EndInit();
			this->optinalBox->ResumeLayout(false);
			this->optionalOffsetsTab->ResumeLayout(false);
			this->tab_Box1->ResumeLayout(false);
			this->tab_Box1->PerformLayout();
			this->tab_Box2->ResumeLayout(false);
			this->tab_Box2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void ShowConfig()
	{
		// General offset
		this->missesOffset->Value = config["InitialMisses"].get<int8_t>();
		this->bombsOffset->Value = config["InitialBombs"].get<int8_t>();

		// Optional offsets
		SetOptionalBoxValue(config["OptionalBox1"].get<uint8_t>(), this->noneRB1, this->scoreRB1, this->wrRB1, this->survivalRB1, this->scoringRB1);
		SetOptionalBoxValue(config["OptionalBox2"].get<uint8_t>(), this->noneRB2, this->scoreRB2, this->wrRB2, this->survivalRB2, this->scoringRB2);

		// Other offsets
		this->BBOffset->Value = config["InitialBorderBreaks"].get<int8_t>();
		this->LSOffset->Value = config["InitialLastSpellsCaptured"].get<int8_t>();
		this->trancesOffset->Value = config["InitialTrances"].get<int8_t>();
		this->releasesOffset->Value = config["InitialReleases"].get<int16_t>();
		this->noChargeCB->Checked = config["NoChargeAttacks"].get<bool>();
		this->redOffset->Value = config["InitialRedUFOs"].get<int8_t>();
		this->greenOffset->Value = config["InitialGreenUFOs"].get<int8_t>();
		this->blueOffset->Value = config["InitialBlueUFOs"].get<int8_t>();
		this->rainbowOffset->Value = config["InitialRainbowUFOs"].get<int8_t>();
		this->wolvesOffset->Value = config["InitialWolves"].get<int16_t>();
		this->ottersOffset->Value = config["InitialOtters"].get<int16_t>();
		this->eaglesOffset->Value = config["InitialEagles"].get<int16_t>();
		this->RBOffset->Value = config["InitialRoarBreaks"].get<int16_t>();
	}

	private: System::Void SaveConfig()
	{
		// General offset
		config["InitialMisses"] = Convert::ToSByte(this->missesOffset->Value);
		config["InitialBombs"] = Convert::ToSByte(this->bombsOffset->Value);

		// Optional offsets
		config["OptionalBox1"] = Convert::ToByte(GetOptionalBoxValue(this->noneRB1->Checked, this->scoreRB1->Checked, this->wrRB1->Checked, this->survivalRB1->Checked, this->scoringRB1->Checked));
		config["OptionalBox2"] = Convert::ToByte(GetOptionalBoxValue(this->noneRB2->Checked, this->scoreRB2->Checked, this->wrRB2->Checked, this->survivalRB2->Checked, this->scoringRB2->Checked));

		// Other offsets
		config["InitialBorderBreaks"] = Convert::ToSByte(this->BBOffset->Value);
		config["InitialLastSpellsCaptured"] = Convert::ToSByte(this->LSOffset->Value);
		config["InitialTrances"] = Convert::ToSByte(this->trancesOffset->Value);
		config["InitialReleases"] = Convert::ToInt16(this->releasesOffset->Value);
		config["NoChargeAttacks"] = this->noChargeCB->Checked;
		config["InitialRedUFOs"] = Convert::ToSByte(this->redOffset->Value);
		config["InitialGreenUFOs"] = Convert::ToSByte(this->greenOffset->Value);
		config["InitialBlueUFOs"] = Convert::ToSByte(this->blueOffset->Value);
		config["InitialRainbowUFOs"] = Convert::ToSByte(this->rainbowOffset->Value);
		config["InitialWolves"] = Convert::ToInt16(this->wolvesOffset->Value);
		config["InitialOtters"] = Convert::ToInt16(this->ottersOffset->Value);
		config["InitialEagles"] = Convert::ToInt16(this->eaglesOffset->Value);
		config["InitialRoarBreaks"] = Convert::ToInt16(this->RBOffset->Value);

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

		// Optional offsets
		SetOptionalBoxValue(3, this->noneRB1, this->scoreRB1, this->wrRB1, this->survivalRB1, this->scoringRB1);
		SetOptionalBoxValue(4, this->noneRB2, this->scoreRB2, this->wrRB2, this->survivalRB2, this->scoringRB2);

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
		this->RBOffset->Value = 0;

		this->SaveConfig();
	}

	private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->SaveConfig();
		this->Close();
	}

	private: uint8_t GetOptionalBoxValue(bool a, bool b, bool c, bool d, bool e)
	{
		if (a)
			return 0;
		else if (b)
			return 1;
		else if (c)
			return 2;
		else if (d)
			return 3;
		else if (e)
			return 4;
		else
			return -1;
	}

	private: void SetOptionalBoxValue(uint8_t value, 
		System::Windows::Forms::RadioButton^% a, 
		System::Windows::Forms::RadioButton^% b, 
		System::Windows::Forms::RadioButton^% c, 
		System::Windows::Forms::RadioButton^% d, 
		System::Windows::Forms::RadioButton^% e)
	{
		switch (value)
		{
		case 0:
			a->Checked = true;
			break;
		case 1:
			b->Checked = true;
			break;
		case 2:
			c->Checked = true;
			break;
		case 3:
			d->Checked = true;
			break;
		case 4:
			e->Checked = true;
			break;
		default:
			break;
		}
	}
	
	};
}
