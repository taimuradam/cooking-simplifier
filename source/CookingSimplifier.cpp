#include "../header/IngredientHashTable.h"
#include "../header/RecipeList.h"
#include "../header/util.h"

#include <iostream>
#include <iomanip>
#include <string>

int main() {

    IngredientList* ingredientList = new IngredientList();
    std::string ingredientName;
    double ingredientAmt;
    std::string ingredientUnit;
    int input = 0;

    do {
        std::cout << "1: insert, 2: edit, 3: remove, 4: print, -1: quit" << std::endl;
        std::cin >> input;
        std::cin.ignore(20, '\n');

        if (input == 1) {
            //insert
            std::cout << "Enter an ingredient: ";
            std::getline(std::cin, ingredientName);

            std::cout << "Enter the amount: ";
            std::cin >> ingredientAmt;
            std::cin.ignore(20, '\n');

            std::cout << "Enter the unit of measurement: ";
            std::getline(std::cin, ingredientUnit);

            ingredientName = capitalize(ingredientName);
            ingredientUnit = toLower(ingredientUnit);

            ingredientList->insert(ingredientName, ingredientAmt, ingredientUnit);
        }

        else if (input == 2) {
            //edit
            std::cout << "Enter an ingredient: ";
            std::getline(std::cin, ingredientName);

            ingredientName = capitalize(ingredientName);

            if (ingredientList->keyExists(ingredientName)) {
                std::cout << "Enter the amount: ";
                std::cin >> ingredientAmt;
                std::cin.ignore(20, '\n');

                std::cout << "Enter the unit of measurement: ";
                std::getline(std::cin, ingredientUnit);

                ingredientUnit = toLower(ingredientUnit);
                ingredientList->edit(ingredientName, ingredientAmt, ingredientUnit);
            }
            else {
                std::cout << "\nIngredient \"" << ingredientName << "\" doesn't exist in recipe.\n";
                std::cout << "Enter a valid ingredient name.\n\n";
            }
        }

        else if (input == 3) {
            //delete

            std::cout << "Enter an ingredient: ";
            std::getline(std::cin, ingredientName);

            ingredientName = capitalize(ingredientName);

            if (!ingredientList->remove(ingredientName)) {
                std::cout << "\nIngredient \"" << ingredientName << "\" doesn't exist in recipe.\n";
                std::cout << "Enter a valid ingredient name.\n\n";
            }
        }

        else if (input == 4) {
            //print
            ingredientList->printIngredientList();
        }

    } while(input != -1);

    ingredientList->printIngredientList();
    ingredientList->~IngredientList();

}