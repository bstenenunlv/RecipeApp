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




	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Recipe;

	private: System::Windows::Forms::PictureBox^  pictureBox1;




	private: System::Windows::Forms::Label^  currentRecipe;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addRecipeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Ingredient;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Procedure;








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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ingredients = (gcnew System::Windows::Forms::DataGridView());
			this->Ingredient = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->procedures = (gcnew System::Windows::Forms::DataGridView());
			this->recipes = (gcnew System::Windows::Forms::DataGridView());
			this->Recipe = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->currentRecipe = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addRecipeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Procedure = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ingredients))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->procedures))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recipes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
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
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ingredients->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->ingredients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ingredients->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Ingredient,
					this->Amount, this->Type
			});
			this->ingredients->Location = System::Drawing::Point(346, 96);
			this->ingredients->Name = L"ingredients";
			this->ingredients->ReadOnly = true;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->ingredients->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->ingredients->RowHeadersWidth = 10;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ingredients->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->ingredients->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->ingredients->Size = System::Drawing::Size(340, 391);
			this->ingredients->TabIndex = 0;
			this->ingredients->TabStop = false;
			this->ingredients->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::ingredients_CellContentClick);
			// 
			// Ingredient
			// 
			this->Ingredient->Name = L"Ingredient";
			this->Ingredient->ReadOnly = true;
			this->Ingredient->Width = 160;
			// 
			// Amount
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopRight;
			this->Amount->DefaultCellStyle = dataGridViewCellStyle2;
			this->Amount->HeaderText = L"Qty";
			this->Amount->Name = L"Amount";
			this->Amount->ReadOnly = true;
			this->Amount->Width = 75;
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
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->procedures->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle5;
			this->procedures->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->procedures->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Procedure });
			this->procedures->Location = System::Drawing::Point(709, 96);
			this->procedures->Name = L"procedures";
			this->procedures->ReadOnly = true;
			this->procedures->RowHeadersWidth = 10;
			this->procedures->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->procedures->Size = System::Drawing::Size(361, 391);
			this->procedures->TabIndex = 1;
			this->procedures->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::procedures_CellContentClick);
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
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->recipes->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->recipes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->recipes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Recipe });
			this->recipes->Location = System::Drawing::Point(15, 83);
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
			this->numericUpDown1->Location = System::Drawing::Point(178, 17);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(92, 26);
			this->numericUpDown1->TabIndex = 3;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(103, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 18);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Servings";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(88, 51);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(189, 26);
			this->textBox1->TabIndex = 6;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(13, 316);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(290, 171);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click_2);
			// 
			// currentRecipe
			// 
			this->currentRecipe->AutoSize = true;
			this->currentRecipe->Location = System::Drawing::Point(478, 24);
			this->currentRecipe->Name = L"currentRecipe";
			this->currentRecipe->Size = System::Drawing::Size(158, 18);
			this->currentRecipe->TabIndex = 10;
			this->currentRecipe->Text = L"Current Recipe: None";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 18);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Search";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1082, 24);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addRecipeToolStripMenuItem,
					this->saveToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// addRecipeToolStripMenuItem
			// 
			this->addRecipeToolStripMenuItem->Name = L"addRecipeToolStripMenuItem";
			this->addRecipeToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->addRecipeToolStripMenuItem->Text = L"Add Recipe";
			this->addRecipeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addRecipeToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->recipes);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(0, 43);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(303, 245);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->numericUpDown1);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(337, 43);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(754, 464);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1082, 499);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->procedures);
			this->Controls->Add(this->currentRecipe);
			this->Controls->Add(this->ingredients);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"                                                                                 "
				L"                                                                                "
				L"       Just Cook";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ingredients))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->procedures))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->recipes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
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
		repopulateRecipeList();
//		for (int x = 0; x < recipeQuantity; ++x) this->recipes->Rows[x]->Cells[0]->Value = recipeName(x);			
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

private: void setActiveRecipe(recipe* r)
{
	repopulateRecipeList();
	previousActiveRecipe = activeRecipe;
	activeRecipe = r;


	if (previousActiveRecipe != NULL) // there was a last
	{

		for (int x = 0; x < previousActiveRecipe->ingredientCount; ++x)
		{
			this->ingredients->Rows[x]->Cells[0]->Value = "";
			this->ingredients->Rows[x]->Cells[1]->Value = "";
			this->ingredients->Rows[x]->Cells[2]->Value = "";
		}
		for (int i = 0; i < previousActiveRecipe->ProcedureCount; ++i)
		{
			this->procedures->Rows[i]->Cells[0]->Value = "";
		}
	}
	if (activeRecipe != NULL)	// there is a current recipe
	{
		for (int x = 0; x < activeRecipe->ingredientCount; ++x)
		{
			this->ingredients->Rows[x]->Cells[0]->Value = recipeIngredient(activeRecipe->recipeNumber, x);
			double decimalQuantity = recipeIngredientQuantity(activeRecipe->recipeNumber, x);
			std::string fractionalQuantity = getNearestCommonFraction(decimalQuantity);
			this->ingredients->Rows[x]->Cells[1]->Value = gcnew String(fractionalQuantity.c_str());
			this->ingredients->Rows[x]->Cells[2]->Value = recipeIngredientTyp(activeRecipe->recipeNumber, x);
		}
		for (int x = 0; x < activeRecipe->ProcedureCount; ++x)
			this->procedures->Rows[x]->Cells[0]->Value = recipeProcedure(activeRecipe->recipeNumber, x);

		this->numericUpDown1->Value = activeRecipe->servings;
		serves = (float)activeRecipe->servings;
		for (int x = 0; x < 30; x++) amount[x] = 0;

		
	}
	else
	{
		this->numericUpDown1->Value = 0;
		serves = 0;
		for (int x = 0; x < 30; x++) amount[x] = 0;
	}
}

private: System::Void recipes_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
{
 //********************************************************************************************
 //							Clear the grids of data
 //********************************************************************************************
	int row = e->RowIndex;

	if (row >= lastSearchedRecipeContainer.size()) // empty row
	{
		setActiveRecipe(NULL);
		currentRecipe->Text = "Current Recipe: None";
	}
	else 
	{
		setActiveRecipe(lastSearchedRecipeContainer[row]);
		std::string text = "Current Recipe: " + activeRecipe->title;
		currentRecipe->Text = gcnew System::String(text.c_str());
	}

	if (previousActiveRecipe != activeRecipe) // new recipe
	{
		procedures->ClearSelection();
		ingredients->ClearSelection();
	}

	
}
private: System::Void recipes_CellMouseClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {

}
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	
	if (this->numericUpDown1->Value < 1)
		this->numericUpDown1->Value = 1;	//lock to >=1

	if (activeRecipe != NULL) // there is a current active recipe
	{
		double ratio;
		int newserve = 0;
		int x = 0;
		if (serves > 0)
		{
			ratio = (float) this->numericUpDown1->Value / serves;
			for (int x = 0; x < activeRecipe->ingredientCount; x++)
			{
				if (this->ingredients->Rows[x]->Cells[1]->Value == "") continue;
				if (amount[x] == 0)
				{
					std::string val = systemStrToStdStr(Convert::ToString(this->ingredients->Rows[x]->Cells[1]->Value));
					amount[x] = fractionalStringToDouble(val);
				}
					
				amount[x] = amount[x] * ratio;
				this->ingredients->Rows[x]->Cells[1]->Value = gcnew String(getNearestCommonFraction(amount[x]).c_str());

			}
			serves = (int) this->numericUpDown1->Value;
		}
	}
}
private: System::Void Reset(System::Object^  sender, System::EventArgs^  e) {
	repopulateRecipeList();
}

private: void repopulateRecipeList()
{
	std::string searchStr = systemStrToStdStr(textBox1->Text);	//convert

	std::vector<recipe*> relevantRecipes = findRecipesContaining(searchStr);


	if (oldSearchString != searchStr) // altered string
		recipes->ClearSelection();

	oldSearchString = searchStr;




	for (int x = 0; x < recipeQuantity; ++x)
	{
		recipes->Rows[x]->Cells[0]->Value = "";
	}
	int count = 0;
	for (std::vector<recipe*>::iterator i = relevantRecipes.begin(); i != relevantRecipes.end(); ++i)
	{
		recipes->Rows[count++]->Cells[0]->Value = recipeName((*i)->recipeNumber);
	}
}

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	repopulateRecipeList();



}
private: System::Void addRecipeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	AddRecipeForm^ form = gcnew AddRecipeForm();
	form->Show();
}
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	saveRecipes();
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	saveRecipes();
	this->Close();
}
};

};

#endif