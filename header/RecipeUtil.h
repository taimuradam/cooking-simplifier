#ifndef RECIPE_UTIL_H
#define RECIPE_UTIL_H

#include "RecipeList.h"
#include "IngredientHashTable.h"

#include <iostream>
#include <iomanip>
#include <string>

void ingredientEdit(int ingredientInput, std::string ingredientName, std::string ingredientUnit, int ingredientAmt, IngredientList* ingredientList);
void recipeUtil(int ingredientInput, IngredientList* ingredientList);
void editRecipeUtil(int ingredientInput, RecipeList* mainList, std::string recipeName)

#endif