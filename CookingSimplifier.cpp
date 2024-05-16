#include "IngredientHashTable.h"

int main() {

    IngredientList* newList = new IngredientList();
    std::string ingredientName;
    double ingredientAmt;
    std::string ingredientUnit;
    int input = 0;
    

    do {
        
        std::cout << "1: insert, 2: edit, 3: remove, 4: print, -1: quit" << std::endl;
        std::cin >> input;
        std::cin.ignore(20, '\n');

        if (input == 1) {
            std::cout << "Enter an ingredient: ";
            std::getline(std::cin, ingredientName);

            std::cout << "Enter the amount: ";
            std::cin >> ingredientAmt;
            std::cin.ignore(20, '\n');

            std::cout << "Enter the unit of measurement: ";
            std::getline(std::cin, ingredientUnit);

            newList->insert(ingredientName, ingredientAmt, ingredientUnit);
        }
        else if (input == 2) {
            std::cout << "Enter an ingredient: ";
            std::getline(std::cin, ingredientName);

            std::cout << "Enter the amount: ";
            std::cin >> ingredientAmt;
            std::cin.ignore(20, '\n');

            std::cout << "Enter the unit of measurement: ";
            std::getline(std::cin, ingredientUnit);

            newList->edit(ingredientName, ingredientAmt, ingredientUnit);
        }
        else if (input == 3) {
            std::cout << "Enter an ingredient: ";
            std::getline(std::cin, ingredientName);

            newList->remove(ingredientName);
        }
        else if (input == 4) {
            newList->printIngredientList();
        }

    } while(input != -1);

    newList->printIngredientList();

}