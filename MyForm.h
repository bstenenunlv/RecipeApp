#ifndef MyForm
#define MyForn

#pragma once

#include <String>
#include "Records.h"
#include "AddRecipeForm.h"

namespace Project_Recipe {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  ingredients;
	private: System::Windows::Forms::DataGridView^  procedures;
	protected:

	protected:

	private: System::Windows::Forms::DataGridView^  recipes;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label1;




	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Procedure;



	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Recipe;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Ingredient;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Type;
	private: System::Windows::Forms::Button^  button1;



	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ingredients = (gcnew System::Windows::Forms::DataGridView());
			this->Ingredient = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->procedures = (gcnew System::Windows::Forms::DataGridView());
			this->Procedure = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->recipes = (gcnew System::Windows::Forms::DataGridView());
			this->Recipe = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ingredients))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->procedures))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recipes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// ingredients
			// 
			this->ingredients->AllowUserToAddRows = false;
			this->ingredients->AllowUserToDeleteRows = false;
			this->ingredients->AllowUserToResizeColumns = false;
			this->ingredients->AllowUserToResizeRows = false;
			this->ingredients->BackgroundColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ingredients->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ingredients->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->ingredients->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
			this->ingredients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ingredients->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Ingredient,
					this->Amount, this->Type
			});
			this->ingredients->Location = System::Drawing::Point(337, 12);
			this->ingredients->Name = L"ingredients";
			this->ingredients->ReadOnly = true;
			this->ingredients->RowHeadersWidth = 10;
			this->ingredients->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->ingredients->Size = System::Drawing::Size(343, 427);
			this->ingredients->TabIndex = 0;
			this->ingredients->TabStop = false;
			this->ingredients->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::ingredients_CellContentClick);
			// 
			// Ingredient
			// 
			this->Ingredient->HeaderText = L"Ingredient";
			this->Ingredient->Name = L"Ingredient";
			this->Ingredient->ReadOnly = true;
			this->Ingredient->Width = 200;
			// 
			// Amount
			// 
			this->Amount->HeaderText = L"Qty";
			this->Amount->Name = L"Amount";
			this->Amount->ReadOnly = true;
			this->Amount->Width = 35;
			// 
			// Type
			// 
			this->Type->HeaderText = L"Type";
			this->Type->MinimumWidth = 100;
			this->Type->Name = L"Type";
			this->Type->ReadOnly = true;
			// 
			// procedures
			// 
			this->procedures->AllowUserToAddRows = false;
			this->procedures->AllowUserToDeleteRows = false;
			this->procedures->AllowUserToResizeColumns = false;
			this->procedures->AllowUserToResizeRows = false;
			this->procedures->BackgroundColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->procedures->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->procedures->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->procedures->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->procedures->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Procedure });
			this->procedures->Location = System::Drawing::Point(709, 12);
			this->procedures->Name = L"procedures";
			this->procedures->ReadOnly = true;
			this->procedures->RowHeadersWidth = 10;
			this->procedures->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->procedures->Size = System::Drawing::Size(361, 427);
			this->procedures->TabIndex = 1;
			this->procedures->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::procedures_CellContentClick);
			// 
			// Procedure
			// 
			this->Procedure->HeaderText = L"Procedure";
			this->Procedure->MinimumWidth = 350;
			this->Procedure->Name = L"Procedure";
			this->Procedure->ReadOnly = true;
			this->Procedure->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Procedure->Width = 350;
			// 
			// recipes
			// 
			this->recipes->AccessibleName = L"recipeList";
			this->recipes->AllowUserToAddRows = false;
			this->recipes->AllowUserToDeleteRows = false;
			this->recipes->AllowUserToResizeColumns = false;
			this->recipes->AllowUserToResizeRows = false;
			this->recipes->BackgroundColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->recipes->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->recipes->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->recipes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->recipes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Recipe });
			this->recipes->Location = System::Drawing::Point(13, 105);
			this->recipes->Name = L"recipes";
			this->recipes->ReadOnly = true;
			this->recipes->RowHeadersWidth = 10;
			this->recipes->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->recipes->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->recipes->Size = System::Drawing::Size(262, 144);
			this->recipes->TabIndex = 2;
			this->recipes->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::recipes_CellContentClick);
			this->recipes->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::recipes_CellContentClick);
			this->recipes->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MyForm::recipes_CellMouseClick);
			this->recipes->Validated += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			// 
			// Recipe
			// 
			this->Recipe->HeaderText = L"                 Recipes";
			this->Recipe->Name = L"Recipe";
			this->Recipe->ReadOnly = true;
			this->Recipe->Width = 250;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(12, 12);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(68, 26);
			this->numericUpDown1->TabIndex = 3;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(86, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 18);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Servings";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(263, 26);
			this->textBox1->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(97, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 18);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Recipe";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(13, 268);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(290, 171);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click_2);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(187, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 37);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Add Recipe";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1082, 451);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->recipes);
			this->Controls->Add(this->procedures);
			this->Controls->Add(this->ingredients);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"                                                                                 "
				L"                                                                                "
				L"       Group Recipes";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ingredients))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->procedures))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recipes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void pictureBox1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{ // This is how I tested the linked list items.  *Bromley*

		this->recipes->Rows->Add(6);
		this->ingredients->Rows->Add(19);
		this->procedures->Rows->Add(19);	//build emply lists
		// show recipe list
		for (int x = 0; x < recipeQuantity; ++x) this->recipes->Rows[x]->Cells[0]->Value = recipeName(x);			
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	}

private: System::Void ingredients_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
}

private: System::Void procedures_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
}

private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) 
{
}

private: System::Void pictureBox1_Click_2(System::Object^  sender, System::EventArgs^  e) 
{
}

private: System::Void recipes_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
 //********************************************************************************************
 //							Clear the grids of data
 //********************************************************************************************
	int row = e->RowIndex;
	if (e->RowIndex > recipeQuantity - 1) row = recipeQuantity - 1;
	textBox1->Text = recipeName(row);
	this->numericUpDown1->Value = 0;
	for (int x = 0; x < recipeQuantity; ++x) this->recipes->Rows[x]->Cells[0]->Value = "";
	for (int x = 0; x < 10; ++x)
	{
		this->ingredients->Rows[x]->Cells[0]->Value = "";
		this->ingredients->Rows[x]->Cells[1]->Value = "";
		this->ingredients->Rows[x]->Cells[2]->Value = "";
	}
	for (int x = 0; x < 10; ++x) this->procedures->Rows[x]->Cells[0]->Value = "";
	//********************************************************************************************
	//							load data
	//********************************************************************************************
	for (int x = 0; x < recipeQuantity; ++x) this->recipes->Rows[x]->Cells[0]->Value = recipeName(x);


	for (int x = 0; x < IngredientQty(row); ++x)
	{
		this->ingredients->Rows[x]->Cells[0]->Value = recipeIngredient(row, x);
		this->ingredients->Rows[x]->Cells[1]->Value = recipeIngredientQuantity(row, x);
		this->ingredients->Rows[x]->Cells[2]->Value = recipeIngredientTyp(row, x);
	}
	for (int x = 0; x < procedureQty(row); ++x) this->procedures->Rows[x]->Cells[0]->Value = recipeProcedure(row, x);
	this->numericUpDown1->Value = servings(row);
}
private: System::Void recipes_CellMouseClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) 
{

}
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	AddRecipeForm^ form = gcnew AddRecipeForm();
	form->Show();
	saveRecipes();

}
private: System::Void Reset(System::Object^  sender, System::EventArgs^  e) {
	for (int x = 0; x < recipeQuantity; ++x) this->recipes->Rows[x]->Cells[0]->Value = recipeName(x);
}

};


};

#endif