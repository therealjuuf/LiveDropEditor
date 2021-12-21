#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "ReadDrops.h"


namespace LiveDropEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LiveDropEditorGUI
	/// </summary>
	public ref class LiveDropEditorGUI : public System::Windows::Forms::Form
	{
	public:
		LiveDropEditorGUI(void)
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
		~LiveDropEditorGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ItemOrder;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Grade;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  DropRate;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LiveDropEditorGUI::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ItemOrder = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Grade = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DropRate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ItemOrder,
					this->Grade, this->DropRate
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 53);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(345, 222);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &LiveDropEditorGUI::dataGridView1_CellContentClick);
			// 
			// ItemOrder
			// 
			this->ItemOrder->HeaderText = L"ItemOrder";
			this->ItemOrder->Name = L"ItemOrder";
			this->ItemOrder->ReadOnly = true;
			// 
			// Grade
			// 
			this->Grade->HeaderText = L"Grade";
			this->Grade->Name = L"Grade";
			// 
			// DropRate
			// 
			this->DropRate->HeaderText = L"DropRate";
			this->DropRate->Name = L"DropRate";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"MobID";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(118, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(68, 20);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LiveDropEditorGUI::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(192, 27);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 20);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Update";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LiveDropEditorGUI::button2_Click);
			// 
			// LiveDropEditorGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(369, 289);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"LiveDropEditorGUI";
			this->Text = L"LiveDropEditor";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	this->dataGridView1->Rows->Clear();

	if (textBox1->Text->Length == 0 || !(System::Text::RegularExpressions::Regex::IsMatch(textBox1->Text,"^[-0-9]*$"))) {
		MessageBox::Show("Write a valid MobID!");
		return;
	}

	
	if (!ReadDrops(int::Parse(textBox1->Text))) {
		MessageBox::Show("Mob doesn't exist!");
		return;
	}

	//this->dataGridView1->Rows->Add(int::Parse(textBox1->Text), int::Parse(textBox1->Text), int::Parse(textBox1->Text));
	for (int i = 0; i < 9; i++) {
		this->dataGridView1->Rows->Add(i+1, drops[i].Grade, drops[i].DropRate);
	}

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	for (int i = 0; i < 9; i++) {
		drops[i].Grade= int::Parse(this->dataGridView1->Rows[i]->Cells[1]->Value->ToString());
		drops[i].DropRate = int::Parse(this->dataGridView1->Rows[i]->Cells[2]->Value->ToString());
	}


	UpdateDrops(int::Parse(textBox1->Text));
}
};
}




