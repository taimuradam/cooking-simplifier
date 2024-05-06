//This is a basic class defining file
//Ingredient and a list of ingredients is defined
//supports insert, remove and edit
//This will be used in the RecipeList.h file

#include <iostream>
#include <iomanip>
#include <string>

struct Ingredient {

    std::string name;
    double amount;
    std::string unit;
    struct Ingredient* next;

    Ingredient(std::string name, double amount, std::string unit) {
        this->name = name;
        this->amount = amount;
        this->unit = unit;
        this->next = nullptr;
    }
};

struct IngredientList {

    private:
        struct Ingredient* head;

    public:
        IngredientList();
        ~IngredientList();
        Ingredient* getHead();
        int findIngredient(std::string name);   //returns -1 if fail, index of ingredient if success
        void insert(std::string name, double amount, std::string unit);
        int edit(std::string name, double amount, std::string unit);    //returns -1 if fail, 1 if success
        int remove(std::string name);    //returns -1 if fail, 1 if success
        void printIngredientList();

};

IngredientList::IngredientList() : head(nullptr) {}

IngredientList::~IngredientList() {
    Ingredient* current = head;
    while (current != nullptr) {
        Ingredient* temp = current;
        current = current->next;
        delete temp;
    }
}

Ingredient* IngredientList::getHead() {
    return head;
}

int IngredientList::findIngredient(std::string name) {
    Ingredient* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->name.compare(name) == 0) {
            return index;
        }
        index++;
        current = current->next;
    }
    return -1;
}

void IngredientList::insert(std::string name, double amount, std::string unit) {
    Ingredient* newIngredient = new Ingredient(name, amount, unit);

    if (head == nullptr) {
        head = newIngredient;
    } else {
        Ingredient* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newIngredient;
    }   
}

int IngredientList::edit(std::string name, double amount, std::string unit) {
    if (head == nullptr) {
        return -1;  //list is empty
    }

    Ingredient* current = head;
    while (current != nullptr) {
        if (current->name.compare(name) == 0) {
            current->amount = amount;
            current->unit = unit;
            return 1;
        }
        current = current->next;
    }
    return -1;  //ingredient not found in list
}

int IngredientList::remove(std::string name) {
    if (head == nullptr) {
        return -1;  // List is empty
    }

    Ingredient* current = head;
    Ingredient* prev = nullptr;

    while (current != nullptr) {
        if (current->name == name) {
            if (prev == nullptr) {
                // Removing the first node
                head = current->next;
                delete current;
                return 1;
            } else {
                // Removing a node in the middle or end of the list
                prev->next = current->next;
                delete current;
                return 1;
            }
        }
        prev = current;
        current = current->next;
    }

    return -1;  // Ingredient not found in list
}

void IngredientList::printIngredientList() {
    Ingredient* current = head;

    while (current != nullptr) {
        std::cout << std::setw(15) << current->name
               << std::fixed << std::setprecision(2) << std::setw(12) << current->amount
               << std::setw(15) << current->unit << std::endl;
        current = current->next;
    }
}