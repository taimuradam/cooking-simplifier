#define CAPACITY 15 // Size of the HashTable.
#include <string>

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
    int HashFunction(std::string str);
    bool keyExists(std::string ingredientName);  //index if exists, -1 if not
    bool insert(std::string name, double amount, std::string unit); //true if success, false if not
    bool remove(std::string name); //true if success, false if not
    bool edit(std::string name, double amount, std::string unit);
    void printIngredientList();
};