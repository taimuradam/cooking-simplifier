#include "RecipeList.h"
#include <iostream>

//Recipe functions
Recipe::Recipe(std::string name) {
    this->name = name;
    ingredientList = new IngredientList();
    next = nullptr;
}

Recipe::~Recipe() {
    delete ingredientList;
}

void Recipe::addIngredient(std::string name, double amount, std::string unit) {
    ingredientList->insert(name, amount, unit);
}

void Recipe::editIngredient(std::string name, double amount, std::string unit) {
    ingredientList->edit(name, amount, unit);
}

void Recipe::removeIngredient(std::string name) {
    ingredientList->remove(name);
}

//RecipeList functions
RecipeList::RecipeList() {
    this->size = 100;
    count = 0;
    for (int i = 0; i < size; i++) {
        recipeList[i] = nullptr;
    }
}

RecipeList::~RecipeList() {
    for (int i = 0; i < CAPACITY1; ++i) {
        Recipe* current = recipeList[i];
        while (current != nullptr) {
            Recipe* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
}

int RecipeList::HashFunction(std::string str) {
    int hash = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        hash += c;
    }
    return hash % CAPACITY1;
}

bool RecipeList::keyExists(std::string ingredientName) {
    int hashValue = HashFunction(ingredientName);
    Recipe* temp = recipeList[hashValue];

    while (temp != nullptr) {
        if (temp->name == ingredientName) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool RecipeList::insert(std::string recipeName) {
    Recipe* newRecipe = new Recipe(recipeName);

    int hashValue = HashFunction(recipeName);
    bool exists = keyExists(recipeName);

    if (exists == true) {
        // If the ingredient is already in the list
        return false;
    } else {
        Recipe* temp = recipeList[hashValue];

        if (temp == nullptr) {
            // If the list at the hashValue index is empty
            recipeList[hashValue] = newRecipe;
        } else {
            // Traverse to the end of the linked list and insert the new ingredient
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newRecipe;
        }
        count++;
        return true;
    }
}

bool RecipeList::remove(std::string recipeName) {
    bool exists = keyExists(recipeName);
    int hashValue = HashFunction(recipeName);

    if (exists == false) {
        //if ingredient is not in the list
        return false;
    }
    else {
        Recipe* current = recipeList[hashValue];
        Recipe* prev = nullptr;

        while (current != nullptr) {
            if (current->name.compare(recipeName) == 0) {
                if (prev == nullptr) {
                    // Removing the first node
                    recipeList[hashValue] = current->next;
                    delete current;
                } else {
                    // Removing a node in the middle or end of the list
                    prev->next = current->next;
                    delete current;
                }
            }
            prev = current;
            current = current->next;
        }
        return true;
    }
}

bool RecipeList::edit(std::string oldName, std::string newName) {
    bool exists = keyExists(oldName);
    int hashValue = HashFunction(oldName);

    if (exists == false) {
        //ingredient not in list
        return false;
    }
    else {
        Recipe* temp = recipeList[hashValue];
        while (temp != nullptr) {
            if (temp->name.compare(oldName) == 0) {
                remove(oldName);
                insert(newName);
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}

void RecipeList::printRecipeList() {
    for (int i = 0; i < size; i++) {
        Recipe *current = recipeList[i];
        while (current != nullptr) {
            std::cout << "Recipe: " << current->name << std::endl;
            current->ingredientList->printIngredientList();
            current = current->next;
        }
    }
}