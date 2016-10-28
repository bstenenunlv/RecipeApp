#include "Records.h"

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace System;
using namespace System::Windows::Forms;

//********************************************************************************************
//									global variables
//********************************************************************************************
typedef enum { quantity = 1, cups = 2, tablespoons = 3, teaspoons = 4, sticks = 5 } measures;

int	recipeQuantity;		//number of recipes
int	totalIngredients;	//number of total ingredients of all recipes
int	totalprocedures;	//number of total procedures of all recipes

recipe *recipes, *firstRecipe, *lastRecipe;  //I use only the first two each
ingredients *item, *firstItem, *lastItem;	 //  don't move first of any item
procedures *task, *firstTask, *lastTask;
//********************************************************************************************
//							 Pass Recipe Name (a system string is returned--not std lib) 
//********************************************************************************************
String^ recipeName(int index)  //passes recipe name string when given index
{
	recipes = firstRecipe;
	for (int x = 0; x < index; ++x) recipes = recipes->nextRecipe;
	return gcnew String(recipes->title.c_str());
}
//********************************************************************************************
//							 Pass proceedure Name  (very little error handling)
//********************************************************************************************
String^ recipeProcedure(int recipeNumber, int procedureNumber)  //procedure string
{
	task = firstTask;
	while (task->recipeNumber < recipeNumber) task = task->nextProcedure;
	for (int y = 0; y < procedureNumber; ++y) task = task->nextProcedure;
	if(recipeNumber == task->recipeNumber) return gcnew String(task->procedure.c_str());
	else return " ";
}
//********************************************************************************************
//							 Pass Ingredient Name
//********************************************************************************************
String^ recipeIngredient(int recipeNumber, int IngredientNumber) //ingredient string
{
	item = firstItem;
	while (item->recipeNumber < recipeNumber)  item = item->nextIngredient;
	for (int y = 0; y < IngredientNumber; ++y) item = item->nextIngredient;

	if (recipeNumber == item->recipeNumber) return gcnew String(item->ingredient.c_str());
	else return " ";
}
//********************************************************************************************
//							 Pass servings
//********************************************************************************************
int servings(int recipeNumber)  //number of procedures for indexed recipe
{
	recipes = firstRecipe;
	while (recipes->recipeNumber < recipeNumber)  recipes = recipes->nextRecipe;

	if (recipeNumber == recipes->recipeNumber) return recipes->servings;
	else return 0;
}
//********************************************************************************************
//							 Pass preceedure quantity
//********************************************************************************************
int procedureQty(int recipeNumber)  //number of procedures for indexed recipe
{
	recipes = firstRecipe;
	while (recipes->recipeNumber < recipeNumber)  recipes = recipes->nextRecipe;

	if (recipeNumber == recipes->recipeNumber) return recipes->ProcedureCount;
	else return 0;
}
//********************************************************************************************
//							 Pass number of Ingredients
//********************************************************************************************
int IngredientQty(int recipeNumber) //number of ingredients for specific recipe
{
	recipes = firstRecipe;
	while (recipes->recipeNumber < recipeNumber)  recipes = recipes->nextRecipe;

	if (recipeNumber == recipes->recipeNumber) return recipes->ingredientCount;
	else return 0;
}
//********************************************************************************************
//							 Pass Ingredient aount				//single ingredient amount
//********************************************************************************************
double recipeIngredientQuantity(int recipeNumber, int IngredientNumber)
{
	item = firstItem;
	while (item->recipeNumber < recipeNumber)  item = item->nextIngredient;
	for (int y = 0; y < IngredientNumber; ++y) item = item->nextIngredient;

	if (recipeNumber == item->recipeNumber) return item->amount;
	else return 0;
}
//********************************************************************************************
//							 Pass Ingredient Name
//********************************************************************************************
String^ recipeIngredientTyp(int recipeNumber, int IngredientNumber) //name string
{
	item = firstItem;
	while (item->recipeNumber < recipeNumber)  item = item->nextIngredient;
	for (int y = 0; y < IngredientNumber; ++y) item = item->nextIngredient;

	if (recipeNumber == item->recipeNumber) return gcnew String(item->type.c_str());
	else return " ";
}
//********************************************************************************************
//							 Delete all linked lists from memory
//********************************************************************************************
void returnMemory(void)
{
	for (int x = 0; x < totalprocedures; ++x)
	{
		task = firstTask->nextProcedure;
		delete firstTask;
		firstTask = task;
	}
	for (int x = 0; x < totalIngredients; ++x)
	{
		item = firstItem->nextIngredient;
		delete firstItem;
		firstItem = item;
	}
	for (int x = 0; x < recipeQuantity; ++x)
	{
		recipes = firstRecipe->nextRecipe;
		delete firstRecipe;
		firstRecipe = recipes;
	}
}
//********************************************************************************************
//									   File loader
//********************************************************************************************
bool loadRecipes(void)
{
	int count = 0;				//count is used to count ingredients and procedures
	std::ifstream infile;
	std::string entry;			// entry is a file buffer

	infile.open("recipes.txt");

	getline(infile, entry);
	if (entry == "Group Recipes") infile >> recipeQuantity;
	else return false;	//file is corrupt

	getline(infile, entry);
	//********************************************************************************************
	//						  load start positions of linked lists
	//********************************************************************************************
	recipes = new recipe;
    firstRecipe = recipes;	// set header of linked list

	item = new ingredients;
	firstItem = item;		//mark front of ingredients linked list

	task = new procedures;
	firstTask = task;		//set header
	//********************************************************************************************
	//									File loader
	//********************************************************************************************
	for (int x = 0; x < recipeQuantity; x++) // load recipes
	{		
		getline(infile, recipes->title);
		infile >> entry;
		if (entry == "serves") infile >> recipes->servings; // load number of servings 
		else return false;									// else corrupt

		count = 0;
		recipes->recipeNumber = x;
		infile >> entry;
		while (entry != "end")  //load ingredients
		{
			++count;			// count of ingredients in recipe
			++totalIngredients;	// count of ingredients in the linked list
			item->recipeNumber = x;
			std::replace(entry.begin(), entry.end(), '_', ' '); // replace all 'x' to 'y'
			item->ingredient = entry;
			infile >> item->amount;
			infile >> item->type;
			infile >> entry;

			lastItem = item;
			item = new ingredients;
			lastItem->nextIngredient = item;
		}

		recipes->ingredientCount = count;

		count = 0;
		getline(infile, entry); // align file ptr to next line
		getline(infile, entry);
		while (entry != "end")	// load procedures
		{
			++count;			//
								// total procedures in linked list
			++totalprocedures;
			task->recipeNumber = x;
			task->procedure = entry;

			lastTask = task;
			task = new procedures;
			lastTask->nextProcedure = task;
			getline(infile, entry);
		}

		recipes->ProcedureCount = count;
		lastRecipe = recipes;
		recipes = new recipe;
		lastRecipe->nextRecipe = recipes;
	}
	infile.close();
	return true;	//loaded recipes without error
}


std::list<Recipe> recipeList;
std::map<std::string, double> conversions; // conversions from cup to other units

void LoadConversions()
{
	// conversions from cup, all lowercase. should be of the form conversions["new unit"] = x * (1 cup)
	conversions["cup"] = 1;					// 1 cup = 1 cup
	conversions["tablespoon"] = 16;			// 1 cup = 16 tablespoons
	conversions["teaspoon"] = 48;			// 1 cup = 48 teaspoons
	conversions["liter"] = 0.236588;		// 1 cup = 0.236588 liter
	conversions["milliliter"] = 236.588;	// 1 cup = 236.588 ml
	conversions["pint"] = 0.5;				// 1 cup = 0.5 pint
	conversions["quart"] = 0.25;			// 1 cup = 0.25 quart

}