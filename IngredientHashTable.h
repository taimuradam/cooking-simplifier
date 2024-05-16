#define CAPACITY 15 // Size of the HashTable.
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

struct IngredientList
{
    private:
        //create a list file which is basically an unordered array
        Ingredient* ingredientList[CAPACITY];
        int size;
        int count;

    public:
        IngredientList();
        ~IngredientList();
        int HashFunction(std::string str);
        int keyExists(std::string ingredientName);  //index if exists, -1 if not
        bool insert(std::string name, double amount, std::string unit); //true if success, false if not
        bool remove(std::string name); //true if success, false if not
        bool edit(std::string name, double amount, std::string unit);
        void printIngredientList();
};

IngredientList::IngredientList() {
    //constructor, initialize all variables
    size = 15;
    count = 0;
    for (int i = 0; i < size; i++) {
        ingredientList[i] = nullptr;
    }
}

IngredientList::~IngredientList() {
    // Clear all elements in the hash table and perform any necessary cleanup
    for (int i = 0; i < CAPACITY; ++i) {
        Ingredient* current = ingredientList[i];
        while (current != nullptr) {
            Ingredient* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        ingredientList[i] = nullptr; // Optional: Set the pointer to nullptr after deletion
    }
}

int IngredientList::HashFunction(std::string str)
{
    int i = 0;

    for (int j = 0; str[j]; j++) {
        i += str[j];
    }
    std::cout << "Hash Value: " << i % CAPACITY << std::endl;
    return i % CAPACITY;
}

int IngredientList::keyExists(std::string ingredientName) {
    int hashValue = HashFunction(ingredientName);
    Ingredient* temp = ingredientList[hashValue];
    int returnValue = -1;

    while (temp != nullptr) {
        if (temp->name.compare(ingredientName) == 0) {
            returnValue = hashValue;
        }
        temp = temp->next;
    }
    return returnValue;
}

bool IngredientList::insert(std::string name, double amount, std::string unit) {
    Ingredient* newIngredient = new Ingredient(name, amount, unit);

    int hashValue = HashFunction(name);
    int exists = keyExists(name);

    if (exists != -1) {
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
    int exists = keyExists(name);

    if (exists == -1) {
        //if ingredient is not in the list
        return false;
    }
    else {
        Ingredient* current = ingredientList[exists];
        Ingredient* prev = nullptr;

        while (current != nullptr) {
            if (current->name.compare(name) == 0) {
                if (prev == nullptr) {
                    // Removing the first node
                    ingredientList[exists] = current->next;
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
    int exists = keyExists(name);

    if (exists == -1) {
        //ingredient not in list
        return false;
    }
    else {
        Ingredient* temp = ingredientList[exists];
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

    Ingredient* current;

    for (int i = 0; i < size; i ++) {
        current = ingredientList[i];
        while (current != nullptr) {
            std::cout << std::setw(15) << current->name
                << std::fixed << std::setprecision(2) << std::setw(12) << current->amount
                << std::setw(15) << current->unit << std::endl;
            current = current->next;
        }
    }
}