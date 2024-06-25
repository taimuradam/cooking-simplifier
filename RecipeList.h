#ifndef RECIPE_LIST_H
#define RECIPE_LIST_H

#include <iostream>
#include "IngredientHashTable.h"

#define CAPACITY1 100

struct Recipe {
    std::string name;
    struct IngredientList* ingredientList;
    struct Recipe* next;

    Recipe(std::string name);
    ~Recipe();
    void addIngredient(std::string name, double amount, std::string unit);
    void editIngredient(std::string name, double amount, std::string unit);
    void removeIngredient(std::string name);
};

struct RecipeList {
    Recipe* recipeList[CAPACITY1];
    int size;
    int count;

    RecipeList();
    ~RecipeList();
    int HashFunction(std::string str);
    bool keyExists(std::string recipeName);
    bool insert(std::string recipeName);
    bool remove(std::string recipeName);
    bool edit(std::string oldName, std::string newName);
    void printRecipeList();
};

#endif