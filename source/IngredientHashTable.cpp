#include <iostream>
#include <iomanip>
#include "../header/IngredientHashTable.h"

//Ingredient functions
Ingredient::Ingredient(std::string name, double amount, std::string unit) {
    //constructor
    this->name = name;
    this->amount = amount;
    this->unit = unit;
    this->next = nullptr;
}

IngredientList::IngredientList() {
    //constructor, initialize all variables
    size = 15;
    count = 0;
    for (int i = 0; i < size; i++) {
        ingredientList[i] = nullptr;
    }
}

//IngredientList functions
IngredientList::~IngredientList() {
    for (int i = 0; i < CAPACITY; ++i) {
        Ingredient* current = ingredientList[i];
        while (current != nullptr) {
            Ingredient* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
}

IngredientList::IngredientList(const IngredientList& other) {
    //copy constructor
    size = other.size;
    count = other.count;

    for (int i = 0; i < size; ++i) {
        if (other.ingredientList[i] == nullptr) {
            ingredientList[i] = nullptr;
        } else {
            // Copy the linked list of ingredients
            ingredientList[i] = new Ingredient(*other.ingredientList[i]);
            Ingredient* current = ingredientList[i];
            Ingredient* otherCurrent = other.ingredientList[i]->next;

            while (otherCurrent != nullptr) {
                current->next = new Ingredient(*otherCurrent);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }
    }
}

int IngredientList::HashFunction(std::string str) {
    int hash = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        hash += c;
    }
    return hash % CAPACITY;
}

bool IngredientList::keyExists(std::string ingredientName) {
    int hashValue = HashFunction(ingredientName);
    Ingredient* temp = ingredientList[hashValue];

    while (temp != nullptr) {
        if (temp->name == ingredientName) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool IngredientList::insert(std::string name, double amount, std::string unit) {
    Ingredient* newIngredient = new Ingredient(name, amount, unit);

    int hashValue = HashFunction(name);
    bool exists = keyExists(name);

    if (exists == true) {
        // If the ingredient is already in the list
        return false;
    } else {
        Ingredient* temp = ingredientList[hashValue];

        if (temp == nullptr) {
            // If the list at the hashValue index is empty
            ingredientList[hashValue] = newIngredient;
        } else {
            // Traverse to the end of the linked list and insert the new ingredient
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newIngredient;
        }
        count++;
        return true;
    }
}

bool IngredientList::remove(std::string name) {
    bool exists = keyExists(name);
    int hashValue = HashFunction(name);

    if (exists == false) {
        //if ingredient is not in the list
        return false;
    }
    else {
        Ingredient* current = ingredientList[hashValue];
        Ingredient* prev = nullptr;

        while (current != nullptr) {
            if (current->name.compare(name) == 0) {
                if (prev == nullptr) {
                    // Removing the first node
                    ingredientList[hashValue] = current->next;
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

bool IngredientList::edit(std::string name, double amount, std::string unit) {
    bool exists = keyExists(name);
    int hashValue = HashFunction(name);

    if (exists == false) {
        //ingredient not in list
        return false;
    }
    else {
        Ingredient* temp = ingredientList[hashValue];
        while (temp != nullptr) {
            if (temp->name.compare(name) == 0) {
                temp->amount = amount;
                temp->unit = unit;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}

void IngredientList::printIngredientList() {

    std::cout << std::left << std::setw(20) << "Ingredient Name"
              << std::setw(15) << "Amount"
              << std::setw(15) << "Unit" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    for (int i = 0; i < size; i++) {
        Ingredient* current = ingredientList[i];
        while (current != nullptr) {
            std::cout << std::setw(20) << current->name
                      << std::fixed << std::setprecision(2)
                      << std::setw(15) << current->amount
                      << std::setw(15) << current->unit << std::endl;
            current = current->next;
        }
    }

    std::cout << std::endl;

}