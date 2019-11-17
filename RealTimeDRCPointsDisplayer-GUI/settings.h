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
private: System::Windows::Forms::GroupBox^ langBox;
private: System::Windows::Forms::RadioButton^ lang_jaRB;
private: System::Windows::Forms::RadioButton^ lang_enRB;
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
			this->langBox = (gcnew System::Windows::Forms::GroupBox());
			this->lang_jaRB = (gcnew System::Windows::Forms::RadioButton());
			this->lang_enRB = (gcnew System::Windows::Forms::RadioButton());
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
			this->langBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// generalBox
			// 
			this->generalBox->Controls->Add(this->bombsOffset);
			this->generalBox->Controls->Add(this->label2);
			this->generalBox->Controls->Add(this->label1);
			this->generalBox->Controls->Add(this->missesOffset);
			resources->ApplyResources(this->generalBox, L"generalBox");
			this->generalBox->Name = L"generalBox";
			this->generalBox->TabStop = false;
			// 
			// bombsOffset
			// 
			resources->ApplyResources(this->bombsOffset, L"bombsOffset");
			this->bombsOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 127, 0, 0, 0 });
			this->bombsOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, System::Int32::MinValue });
			this->bombsOffset->Name = L"bombsOffset";
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// missesOffset
			// 
			resources->ApplyResources(this->missesOffset, L"missesOffset");
			this->missesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 127, 0, 0, 0 });
			this->missesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, System::Int32::MinValue });
			this->missesOffset->Name = L"missesOffset";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->otherOffsetsTab);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
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
			resources->ApplyResources(this->otherOffsetsTab, L"otherOffsetsTab");
			this->otherOffsetsTab->Multiline = true;
			this->otherOffsetsTab->Name = L"otherOffsetsTab";
			this->otherOffsetsTab->SelectedIndex = 0;
			// 
			// tab_PCB
			// 
			this->tab_PCB->Controls->Add(this->BBOffset);
			this->tab_PCB->Controls->Add(this->label3);
			resources->ApplyResources(this->tab_PCB, L"tab_PCB");
			this->tab_PCB->Name = L"tab_PCB";
			this->tab_PCB->UseVisualStyleBackColor = true;
			// 
			// BBOffset
			// 
			resources->ApplyResources(this->BBOffset, L"BBOffset");
			this->BBOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 127, 0, 0, 0 });
			this->BBOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, System::Int32::MinValue });
			this->BBOffset->Name = L"BBOffset";
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// tab_IN
			// 
			this->tab_IN->Controls->Add(this->LSOffset);
			this->tab_IN->Controls->Add(this->label4);
			resources->ApplyResources(this->tab_IN, L"tab_IN");
			this->tab_IN->Name = L"tab_IN";
			this->tab_IN->UseVisualStyleBackColor = true;
			// 
			// LSOffset
			// 
			resources->ApplyResources(this->LSOffset, L"LSOffset");
			this->LSOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->LSOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, System::Int32::MinValue });
			this->LSOffset->Name = L"LSOffset";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// tab_PoFV
			// 
			this->tab_PoFV->Controls->Add(this->noChargeCB);
			resources->ApplyResources(this->tab_PoFV, L"tab_PoFV");
			this->tab_PoFV->Name = L"tab_PoFV";
			this->tab_PoFV->UseVisualStyleBackColor = true;
			// 
			// noChargeCB
			// 
			resources->ApplyResources(this->noChargeCB, L"noChargeCB");
			this->noChargeCB->Checked = true;
			this->noChargeCB->CheckState = System::Windows::Forms::CheckState::Checked;
			this->noChargeCB->Name = L"noChargeCB";
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
			resources->ApplyResources(this->tab_UFO, L"tab_UFO");
			this->tab_UFO->Name = L"tab_UFO";
			this->tab_UFO->UseVisualStyleBackColor = true;
			// 
			// redOffset
			// 
			resources->ApplyResources(this->redOffset, L"redOffset");
			this->redOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 127, 0, 0, 0 });
			this->redOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, System::Int32::MinValue });
			this->redOffset->Name = L"redOffset";
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->Name = L"label8";
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->Name = L"label5";
			// 
			// rainbowOffset
			// 
			resources->ApplyResources(this->rainbowOffset, L"rainbowOffset");
			this->rainbowOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 127, 0, 0, 0 });
			this->rainbowOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, System::Int32::MinValue });
			this->rainbowOffset->Name = L"rainbowOffset";
			// 
			// greenOffset
			// 
			resources->ApplyResources(this->greenOffset, L"greenOffset");
			this->greenOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 127, 0, 0, 0 });
			this->greenOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, System::Int32::MinValue });
			this->greenOffset->Name = L"greenOffset";
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->Name = L"label6";
			// 
			// blueOffset
			// 
			resources->ApplyResources(this->blueOffset, L"blueOffset");
			this->blueOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 127, 0, 0, 0 });
			this->blueOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, System::Int32::MinValue });
			this->blueOffset->Name = L"blueOffset";
			// 
			// tab_TD
			// 
			this->tab_TD->Controls->Add(this->trancesOffset);
			this->tab_TD->Controls->Add(this->label9);
			resources->ApplyResources(this->tab_TD, L"tab_TD");
			this->tab_TD->Name = L"tab_TD";
			this->tab_TD->UseVisualStyleBackColor = true;
			// 
			// trancesOffset
			// 
			resources->ApplyResources(this->trancesOffset, L"trancesOffset");
			this->trancesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 127, 0, 0, 0 });
			this->trancesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 128, 0, 0, System::Int32::MinValue });
			this->trancesOffset->Name = L"trancesOffset";
			// 
			// label9
			// 
			resources->ApplyResources(this->label9, L"label9");
			this->label9->Name = L"label9";
			// 
			// tab_HSiFS
			// 
			this->tab_HSiFS->Controls->Add(this->releasesOffset);
			this->tab_HSiFS->Controls->Add(this->label10);
			resources->ApplyResources(this->tab_HSiFS, L"tab_HSiFS");
			this->tab_HSiFS->Name = L"tab_HSiFS";
			this->tab_HSiFS->UseVisualStyleBackColor = true;
			// 
			// releasesOffset
			// 
			resources->ApplyResources(this->releasesOffset, L"releasesOffset");
			this->releasesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->releasesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, System::Int32::MinValue });
			this->releasesOffset->Name = L"releasesOffset";
			// 
			// label10
			// 
			resources->ApplyResources(this->label10, L"label10");
			this->label10->Name = L"label10";
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
			resources->ApplyResources(this->tab_WBaWC, L"tab_WBaWC");
			this->tab_WBaWC->Name = L"tab_WBaWC";
			this->tab_WBaWC->UseVisualStyleBackColor = true;
			// 
			// label14
			// 
			resources->ApplyResources(this->label14, L"label14");
			this->label14->Name = L"label14";
			// 
			// RBOffset
			// 
			resources->ApplyResources(this->RBOffset, L"RBOffset");
			this->RBOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->RBOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, System::Int32::MinValue });
			this->RBOffset->Name = L"RBOffset";
			// 
			// wolvesOffset
			// 
			resources->ApplyResources(this->wolvesOffset, L"wolvesOffset");
			this->wolvesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->wolvesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, System::Int32::MinValue });
			this->wolvesOffset->Name = L"wolvesOffset";
			// 
			// label11
			// 
			resources->ApplyResources(this->label11, L"label11");
			this->label11->Name = L"label11";
			// 
			// ottersOffset
			// 
			resources->ApplyResources(this->ottersOffset, L"ottersOffset");
			this->ottersOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->ottersOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, System::Int32::MinValue });
			this->ottersOffset->Name = L"ottersOffset";
			// 
			// label12
			// 
			resources->ApplyResources(this->label12, L"label12");
			this->label12->Name = L"label12";
			// 
			// label13
			// 
			resources->ApplyResources(this->label13, L"label13");
			this->label13->Name = L"label13";
			// 
			// eaglesOffset
			// 
			resources->ApplyResources(this->eaglesOffset, L"eaglesOffset");
			this->eaglesOffset->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->eaglesOffset->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, System::Int32::MinValue });
			this->eaglesOffset->Name = L"eaglesOffset";
			// 
			// defaultButton
			// 
			resources->ApplyResources(this->defaultButton, L"defaultButton");
			this->defaultButton->Name = L"defaultButton";
			this->defaultButton->UseVisualStyleBackColor = true;
			this->defaultButton->Click += gcnew System::EventHandler(this, &settings::defaultButton_Click);
			// 
			// saveButton
			// 
			resources->ApplyResources(this->saveButton, L"saveButton");
			this->saveButton->Name = L"saveButton";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &settings::saveButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			resources->ApplyResources(this->cancelButton, L"cancelButton");
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// optinalBox
			// 
			this->optinalBox->Controls->Add(this->optionalOffsetsTab);
			resources->ApplyResources(this->optinalBox, L"optinalBox");
			this->optinalBox->Name = L"optinalBox";
			this->optinalBox->TabStop = false;
			// 
			// optionalOffsetsTab
			// 
			this->optionalOffsetsTab->Controls->Add(this->tab_Box1);
			this->optionalOffsetsTab->Controls->Add(this->tab_Box2);
			resources->ApplyResources(this->optionalOffsetsTab, L"optionalOffsetsTab");
			this->optionalOffsetsTab->Name = L"optionalOffsetsTab";
			this->optionalOffsetsTab->SelectedIndex = 0;
			// 
			// tab_Box1
			// 
			this->tab_Box1->Controls->Add(this->noneRB1);
			this->tab_Box1->Controls->Add(this->scoringRB1);
			this->tab_Box1->Controls->Add(this->survivalRB1);
			this->tab_Box1->Controls->Add(this->wrRB1);
			this->tab_Box1->Controls->Add(this->scoreRB1);
			resources->ApplyResources(this->tab_Box1, L"tab_Box1");
			this->tab_Box1->Name = L"tab_Box1";
			this->tab_Box1->UseVisualStyleBackColor = true;
			// 
			// noneRB1
			// 
			resources->ApplyResources(this->noneRB1, L"noneRB1");
			this->noneRB1->Name = L"noneRB1";
			this->noneRB1->TabStop = true;
			this->noneRB1->UseVisualStyleBackColor = true;
			// 
			// scoringRB1
			// 
			resources->ApplyResources(this->scoringRB1, L"scoringRB1");
			this->scoringRB1->Name = L"scoringRB1";
			this->scoringRB1->UseVisualStyleBackColor = true;
			// 
			// survivalRB1
			// 
			resources->ApplyResources(this->survivalRB1, L"survivalRB1");
			this->survivalRB1->Checked = true;
			this->survivalRB1->Name = L"survivalRB1";
			this->survivalRB1->TabStop = true;
			this->survivalRB1->UseVisualStyleBackColor = true;
			// 
			// wrRB1
			// 
			resources->ApplyResources(this->wrRB1, L"wrRB1");
			this->wrRB1->Name = L"wrRB1";
			this->wrRB1->UseVisualStyleBackColor = true;
			// 
			// scoreRB1
			// 
			resources->ApplyResources(this->scoreRB1, L"scoreRB1");
			this->scoreRB1->Name = L"scoreRB1";
			this->scoreRB1->UseVisualStyleBackColor = true;
			// 
			// tab_Box2
			// 
			this->tab_Box2->Controls->Add(this->noneRB2);
			this->tab_Box2->Controls->Add(this->scoringRB2);
			this->tab_Box2->Controls->Add(this->survivalRB2);
			this->tab_Box2->Controls->Add(this->wrRB2);
			this->tab_Box2->Controls->Add(this->scoreRB2);
			resources->ApplyResources(this->tab_Box2, L"tab_Box2");
			this->tab_Box2->Name = L"tab_Box2";
			this->tab_Box2->UseVisualStyleBackColor = true;
			// 
			// noneRB2
			// 
			resources->ApplyResources(this->noneRB2, L"noneRB2");
			this->noneRB2->Name = L"noneRB2";
			this->noneRB2->TabStop = true;
			this->noneRB2->UseVisualStyleBackColor = true;
			// 
			// scoringRB2
			// 
			resources->ApplyResources(this->scoringRB2, L"scoringRB2");
			this->scoringRB2->Checked = true;
			this->scoringRB2->Name = L"scoringRB2";
			this->scoringRB2->TabStop = true;
			this->scoringRB2->UseVisualStyleBackColor = true;
			// 
			// survivalRB2
			// 
			resources->ApplyResources(this->survivalRB2, L"survivalRB2");
			this->survivalRB2->Name = L"survivalRB2";
			this->survivalRB2->UseVisualStyleBackColor = true;
			// 
			// wrRB2
			// 
			resources->ApplyResources(this->wrRB2, L"wrRB2");
			this->wrRB2->Name = L"wrRB2";
			this->wrRB2->UseVisualStyleBackColor = true;
			// 
			// scoreRB2
			// 
			resources->ApplyResources(this->scoreRB2, L"scoreRB2");
			this->scoreRB2->Name = L"scoreRB2";
			this->scoreRB2->UseVisualStyleBackColor = true;
			// 
			// langBox
			// 
			this->langBox->Controls->Add(this->lang_jaRB);
			this->langBox->Controls->Add(this->lang_enRB);
			resources->ApplyResources(this->langBox, L"langBox");
			this->langBox->Name = L"langBox";
			this->langBox->TabStop = false;
			// 
			// lang_jaRB
			// 
			resources->ApplyResources(this->lang_jaRB, L"lang_jaRB");
			this->lang_jaRB->Name = L"lang_jaRB";
			this->lang_jaRB->UseVisualStyleBackColor = true;
			// 
			// lang_enRB
			// 
			resources->ApplyResources(this->lang_enRB, L"lang_enRB");
			this->lang_enRB->Checked = true;
			this->lang_enRB->Name = L"lang_enRB";
			this->lang_enRB->TabStop = true;
			this->lang_enRB->UseVisualStyleBackColor = true;
			// 
			// settings
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->Controls->Add(this->langBox);
			this->Controls->Add(this->optinalBox);
			this->Controls->Add(this->defaultButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->generalBox);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"settings";
			this->ShowIcon = false;
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
			this->langBox->ResumeLayout(false);
			this->langBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void ShowConfig()
	{
		// Language
		this->lang_enRB->Checked = config["lang"] == "en";
		this->lang_jaRB->Checked = config["lang"] == "ja";

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
		// Language
		config["lang"] = (this->lang_enRB->Checked) ? "en" : "ja";

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
