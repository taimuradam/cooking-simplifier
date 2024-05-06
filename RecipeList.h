#include "IngredientList.h"

struct Recipe {
    std::string name;
    struct IngredientList* ingredientList;
    struct Recipe* next;

    Recipe(std::string name) {
        this->name = name;
        ingredientList = new IngredientList();
        next = nullptr;
    }

    ~Recipe() {
        delete ingredientList;
    }

    void addIngredient(std::string name, double amount, std::string unit) {
        ingredientList->insert(name, amount, unit);
    }

    void editIngredient(std::string name, double amount, std::string unit) {
        ingredientList->edit(name, amount, unit);
    }

    void removeIngredient(std::string name) {
        ingredientList->remove(name);
    }

};

//use a hash table for this
struct RecipeList {
    
};