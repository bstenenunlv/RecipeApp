#include "Records.h"

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <algorithm>
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

//********************************************************************************************
//									global variables
//********************************************************************************************
typedef enum { quantity = 1, cups = 2, tablespoons = 3, teaspoons = 4, sticks = 5 } measures;

int	recipeQuantity;		//number of recipes
int	totalIngredients;	//number of total ingredients of all recipes
int	totalprocedures;	//number of total procedures of all recipes
double serves;			// number of servings
double amount[30];		// allows modification of servings 

std::string oldSearchString = ""; //for search uses

recipe *recipes, *firstRecipe, *lastRecipe;  //I use only the first two each
ingredients *item, *firstItem, *lastItem;	 //  don't move first of any item
procedures *task, *firstTask, *lastTask;

std::vector<recipe*> lastSearchedRecipeContainer;
recipe* activeRecipe = NULL;	// current recipe
recipe* previousActiveRecipe = NULL;
//********************************************************************************************
//							 Pass Recipe Name (a system string is returned--not std lib) 
//********************************************************************************************
String^ recipeName(int index)  //passes recipe name string when given index
{
	recipes = firstRecipe;
	for (int x = 0; x < index; ++x) recipes = recipes->nextRecipe;
	return gcnew String(recipes->title.c_str());
}
std::string stringToLower(std::string str)
{
	std::string result;

	for (int i = 0; i < str.length(); ++i)
	{
		result += ::tolower(str[i]);
	}
	return result;

}

//splits a string
std::vector<std::string> stringSplit(const std::string &text, char delimiter) {
	std::vector<std::string> tokens;
	std::size_t start = 0, end = 0;
	while ((end = text.find(delimiter, start)) != std::string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}

double fractionalStringToDouble(const std::string &str)
{
	typedef std::vector<std::string> StringContainer;
	StringContainer spaceSplit = stringSplit(str, ' ');
	
	if (spaceSplit.size() == 1)	// either a whole or fraction alone
	{
		StringContainer slashSplit = stringSplit(spaceSplit[0], '/');
		if (slashSplit.size() == 1) // whole number
		{
			return atof(spaceSplit[0].c_str());
		}
		else //fraction
		{
			double numerator = atof(slashSplit[0].c_str());
			double denominator = atof(slashSplit[1].c_str());
			return numerator / denominator;
		}
	}
	else  // mixed number
	{
		StringContainer slashSplit = stringSplit(spaceSplit[1], '/');
		double whole = atof(spaceSplit[0].c_str());
		double numerator = atof(slashSplit[0].c_str());
		double denominator = atof(slashSplit[1].c_str());
		return whole + (numerator / denominator);
	}
}


std::vector<recipe*> findRecipesContaining(std::string str)
{
	str = stringToLower(str);
	std::vector<recipe*> result;
	recipe* r = firstRecipe;
	for (int i = 0; i < recipeQuantity; ++i)
	{
		std::string title = stringToLower(r->title);
		if (str.length() < 1 || title.find(str) != std::string::npos) // substring found or no search param
		{
			result.push_back(r);
		}
		r = r->nextRecipe;
	}
	lastSearchedRecipeContainer = result;
	return lastSearchedRecipeContainer;
}

std::string getNearestCommonFraction(double decimal)
{
	std::string result = "";

	int whole = (int)decimal;
	double remainder = 0;
	remainder = decimal - whole;

	if (whole > 0)
	{
		result = std::to_string(whole);
		if (remainder > 0)
			result += " ";
	}

	/*
	1/16	0.0625
	1/8		0.125
	1/6		0.1667
	3/16	0.1875
	1/4		0.25
	5/16	0.3125
	1/3		0.3333
	3/8		0.375
	7/16	0.4375
	1/2		0.5
	9/16	0.5625
	5/8		0.625
	2/3		0.667
	11/16	0.6875
	3/4		0.75
	13/16	0.8125
	5/6		0.833
	7/8		0.875
	15/16	0.9375
	*/
	if (remainder > 0)
	{
		remainder -= (0.00001); // so its less

		if (remainder < (1.0 / 16.0))
			result += "1/16";
		else if (remainder < (1.0 / 8.0))
			result += "1/8";
		else if (remainder < (1.0 / 6.0))
			result += "1/6";
		else if (remainder < (3.0/ 16.0))
			result += "3/16";
		else if (remainder < (1.0 / 4.0))
			result += "1/4";
		else if (remainder < (5.0 / 16.0))
			result += "5/16";
		else if (remainder < (1.0 / 3.0))
			result += "1/3";
		else if (remainder < (3.0 / 8.0))
			result += "3/8";
		else if (remainder < (7.0 / 16.0))
			result += "7/16";
		else if (remainder < (1.0 / 2.0))
			result += "1/2";
		else if (remainder < (9.0 / 16.0))
			result += "9/16";
		else if (remainder < (5.0 / 8.0))
			result += "5/8";
		else if (remainder < (2.0 / 3.0))
			result += "2/3";
		else if (remainder < (11.0 / 16.0))
			result += "11/16";
		else if (remainder < (3.0 / 4.0))
			result += "3/4";
		else if (remainder < (13.0 / 16.0))
			result += "13/16";
		else if (remainder < (5.0 / 6.0))
			result += "5/6";
		else if (remainder < (7.0 / 8.0))
			result += "7/8";
		else
			result += "15/16";
	}
	return result;
}

std::string systemStrToStdStr(System::String^ sStr)
{
	char cstring[500] = { 0 };
	sprintf_s(cstring, "%s", sStr);
	return std::string(cstring);
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
bool saveRecipes(void)
{
	std::ofstream outfile;
	outfile.open("recipes.txt");

	outfile << "Group Recipes" << std::endl;
	outfile << recipeQuantity << std::endl;

	recipe * currentRecipe = firstRecipe;
	for (int j = 0; j < recipeQuantity; ++j)
	{
		outfile << currentRecipe->title << std::endl;
		outfile << "serves " << currentRecipe->servings << std::endl;

		ingredients * currentItem = firstItem;

		for (int i = 0; i < totalIngredients; ++i)
		{
			if (currentItem->recipeNumber == currentRecipe->recipeNumber)
			{
				std::string name = currentItem->ingredient;
				std::replace(name.begin(), name.end(), ' ', '_'); // replace all 'x' to 'y'
				outfile << name << " " << currentItem->amount << " " << currentItem->type << std::endl;
			}
			currentItem = currentItem->nextIngredient;
		}
		outfile << "end" << std::endl;

		procedures * currentProcedure = firstTask;

		for (int i = 0; i < totalprocedures; ++i)
		{
			if (currentProcedure->recipeNumber == currentRecipe->recipeNumber)
			{
				outfile << currentProcedure->procedure << std::endl;
			}
			currentProcedure = currentProcedure->nextProcedure;
		}
		outfile << "end" << std::endl;

		currentRecipe = currentRecipe->nextRecipe;

	}
	

	outfile.close();
	return true;
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

	findRecipesContaining(""); // build base list
	return true;	//loaded recipes without error
}




void AddNewRecipe(std::string name, int servings, std::vector<ingredients> ingredientList, std::vector<std::string> procedureList)
{
	recipe * r = new recipe();
	int id = r->recipeNumber = lastRecipe->recipeNumber + 1;
	lastRecipe->nextRecipe = r;
	lastRecipe = r;


	r->title = name;
	r->ingredientCount = ingredientList.size();
	r->ProcedureCount = procedureList.size();

	r->servings = servings;
	r->nextRecipe = NULL;
	++recipeQuantity;


	for (std::vector<ingredients>::iterator i = ingredientList.begin(); i != ingredientList.end(); ++i)
	{
		ingredients * thisIngredient = new ingredients;
		thisIngredient->recipeNumber = id;
		thisIngredient->amount = i->amount;
		thisIngredient->ingredient = i->ingredient;
		thisIngredient->type = i->type;
		lastItem->nextIngredient = thisIngredient;
		lastItem = thisIngredient;
		++totalIngredients;
	}
	for (std::vector<std::string>::iterator i = procedureList.begin(); i != procedureList.end(); ++i)
	{
		procedures * thisProcedure = new procedures;
		thisProcedure->recipeNumber = id;
		thisProcedure->procedure = *i;
		lastTask->nextProcedure = thisProcedure;
		lastTask = thisProcedure;
		++totalprocedures;
		
	}
	
}