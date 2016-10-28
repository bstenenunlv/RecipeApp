
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
#ifndef records
#define records

#include <string>
#include <iostream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//********************************************************************************************
//									global variables
//********************************************************************************************
extern int	recipeQuantity;
extern int	totalIngredients;
extern int	totalprocedures;
//*****************************************************************************
//								Declarations
//*****************************************************************************
bool loadRecipes(void); //global function
void returnMemory(void); //delete all linked lists
String^ recipeName(int);
String^ recipeProcedure(int, int);
String^ recipeIngredient(int, int);
int		IngredientQty(int);			//recipe number
int		procedureQty(int);
int		servings(int);
double  recipeIngredientQuantity(int, int);
String^ recipeIngredientTyp(int, int);

//*****************************************************************************
//								ingredients
//*****************************************************************************
struct ingredients
{
	int				recipeNumber;		// The recipe this ingredient belongs
	std::string		ingredient;			// Food item
	double			amount;				// Items in the natural number 
										// category should be 
										// printed with (int) conversion.

	std::string		type;				// Type of measure 1: quantity
										// 2:cups, 3:tablespoons 4: teaspoons
										// 5:sticks

	ingredients		*nextIngredient;	// Pointer to next ingredient
};
//*****************************************************************************
//							preceedures or steps
//*****************************************************************************
struct procedures
{
	int				recipeNumber;		// The recipe this proceedure belongs
	std::string		procedure;		// Next cooking proceedure.
	double			time;				// Estimated time for proceedure.
	procedures		*nextProcedure;	// Pointer to next proceedure.
};
//*****************************************************************************
//								Recipes
//*****************************************************************************
struct recipe
{
	int	recipeNumber;		// Index number for recipe
	std::string title;			// Recipe title
	int servings;			// Number of people it serves.
	int ingredientCount;	// Number of ingredients.
	int ProcedureCount;		// Number of steps to cook recipe
	recipe *nextRecipe;	// Pointer tp the next recipe in the data stream
};
//*****************************************************************************
#endif

