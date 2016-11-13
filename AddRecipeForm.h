#pragma once
#include <string>
#include <vector>
#include "Records.h"

namespace Project_Recipe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddRecipeForm
	/// </summary>
	public ref class AddRecipeForm : public System::Windows::Forms::Form
	{
	public:



		void AddRecipe(void)
		{


			std::string name = systemStrToStdStr(recipeName->Text);
			std::vector<ingredients> ingList;
			std::vector<std::string> procList;
			int ingCount = dataGridView1->RowCount;

			for (int i = 0; i < ingCount; ++i)
			{
				// need error checking
				if (dataGridView1->Rows[i]->Cells[0]->Value == nullptr) continue;
				ingredients thisIng;

				thisIng.ingredient = systemStrToStdStr(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
				thisIng.amount = atof(systemStrToStdStr(dataGridView1->Rows[i]->Cells[1]->Value->ToString()).c_str());
				thisIng.type = systemStrToStdStr(dataGridView1->Rows[i]->Cells[2]->Value->ToString());
				ingList.push_back(thisIng);
			}
			int rowCount = dataGridView2->RowCount;
			for (int i = 0; i < rowCount; ++i)
			{
				if (dataGridView2->Rows[i]->Cells[0]->Value == nullptr) continue;
				std::string proc = systemStrToStdStr(dataGridView1->Rows[i]->Cells[0]->Value->ToString());
				procList.push_back(proc);
			}
			AddNewRecipe(name, 1, ingList, procList);

			
		}


		AddRecipeForm(void)
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
		~AddRecipeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  recipeName;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Unit;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Step;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;








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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->recipeName = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Unit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Step = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(127, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Ingredients";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(465, 58);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Instructions";
			// 
			// recipeName
			// 
			this->recipeName->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->recipeName->Location = System::Drawing::Point(53, 12);
			this->recipeName->Name = L"recipeName";
			this->recipeName->Size = System::Drawing::Size(263, 20);
			this->recipeName->TabIndex = 4;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Name, this->Amount,
					this->Unit
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 74);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(304, 376);
			this->dataGridView1->TabIndex = 5;
			// 
			// Name
			// 
			this->Name->HeaderText = L"Name";
			this->Name->Name = L"Name";
			// 
			// Amount
			// 
			this->Amount->HeaderText = L"Amount";
			this->Amount->Name = L"Amount";
			// 
			// Unit
			// 
			this->Unit->HeaderText = L"Unit";
			this->Unit->Name = L"Unit";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Step });
			this->dataGridView2->Location = System::Drawing::Point(322, 74);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->Size = System::Drawing::Size(332, 376);
			this->dataGridView2->TabIndex = 6;
			// 
			// Step
			// 
			this->Step->HeaderText = L"Step";
			this->Step->Name = L"Step";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(498, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 43);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddRecipeForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(579, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 43);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddRecipeForm::button2_Click);
			// 
			// AddRecipeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(666, 462);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->recipeName);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Text = L"AddRecipeForm";
			this->Leave += gcnew System::EventHandler(this, &AddRecipeForm::Reset);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		AddRecipe();
		Close();

	}
private: System::Void Reset(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}
};



}
