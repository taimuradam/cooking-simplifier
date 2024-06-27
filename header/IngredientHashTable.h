#ifndef INGREDIENT_HASHTABLE_H
#define INGREDIENT_HASHTABLE_H

#include <string>

#define CAPACITY 15 // Size of the HashTable.

struct Ingredient {

    std::string name;
    double amount;
    std::string unit;
    struct Ingredient* next;

    //constructor
    Ingredient(std::string name, double amount, std::string unit);
};

struct IngredientList
{
    //create a list which is basically an unordered array
    Ingredient* ingredientList[CAPACITY];
    int size;
    int count;

    IngredientList();
    ~IngredientList();
    IngredientList(const IngredientList& other);
    int HashFunction(std::string str);
    bool keyExists(std::string ingredientName);  //true if exists, false if not
    bool insert(std::string name, double amount, std::string unit); //true if success, false if not
    bool remove(std::string name); //true if success, false if not
    bool edit(std::string name, double amount, std::string unit);
    void printIngredientList();
};

#endif