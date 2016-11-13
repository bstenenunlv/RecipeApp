
//*****************************************************************************
//          Richard Bromley 5001075854 
//          CS420 Assignment
//
// Purpose: This discription header is designed to construct
//			a recipe record for our group adjustable recipes
//			program.
//
// Input: 
// 		       
//
// Output:   
//*****************************************************************************
#pragma once
#ifndef records
#define records

#include <string>
#include <iostream>
#include <vector>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//forward declaration
struct recipe;


//********************************************************************************************
//									global variables
//********************************************************************************************
extern int	recipeQuantity;
extern int	totalIngredients;
extern int	totalprocedures;
extern double serves;
extern double amount[30];
extern std::vector<recipe*> lastSearchedRecipeContainer;
extern recipe* activeRecipe;

//*****************************************************************************
//								Declarations
//*****************************************************************************
bool loadRecipes(void); //global function
bool saveRecipes(void);
void returnMemory(void); //delete all linked lists
String^ recipeName(int);
String^ recipeProcedure(int, int);
String^ recipeIngredient(int, int);
int		IngredientQty(int);			//recipe number
int		procedureQty(int);
int		servings(int);
double  recipeIngredientQuantity(int, int);
String^ recipeIngredientTyp(int, int);
std::vector<recipe*> findRecipesContaining(std::string);	// find recipes containing string in title
std::string systemStrToStdStr(System::String^);				// convert system str -> std str


//*****************************************************************************
//								ingredients
//*****************************************************************************
struct ingredients
{
	int				recipeNumber = 0;		// The recipe this ingredient belongs
	std::string		ingredient = "";		// Food item
	double			amount = 0;				// Items in the natural number 
											// category should be 
											// printed with (int) conversion.

	std::string		type = "";				// Type of measure 1: quantity
											// 2:cups, 3:tablespoons 4: teaspoons
											// 5:sticks

	ingredients		*nextIngredient = NULL;	// Pointer to next ingredient
};
//*****************************************************************************
//							preceedures or steps
//*****************************************************************************
struct procedures
{
	int				recipeNumber = 0;		// The recipe this proceedure belongs
	std::string		procedure = "";			// Next cooking proceedure.
	double			time = 0.0;				// Estimated time for proceedure.
	procedures		*nextProcedure = NULL;	// Pointer to next proceedure.
};
//*****************************************************************************
//								Recipes
//*****************************************************************************
struct recipe
{
	int	recipeNumber = 0;		// Index number for recipe
	std::string title = "";		// Recipe title
	int servings = 0;			// Number of people it serves.
	int ingredientCount = 0;	// Number of ingredients.
	int ProcedureCount = 0;		// Number of steps to cook recipe
	recipe *nextRecipe = NULL;	// Pointer tp the next recipe in the data stream
};
//*****************************************************************************



void AddNewRecipe(std::string name, int servings, std::vector<ingredients> ingredientList, std::vector<std::string> procedureList);

#endif

