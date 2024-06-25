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
        std::cout << std::endl;


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

            if (ingredientList->insert(ingredientName, ingredientAmt, ingredientUnit)) {
                std::cout << "\n" << ingredientName << " inserted into ingredients.\n" << std::endl;
            }
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

                std::cout << "\n" << ingredientName << " updated to " << ingredientAmt << " " << ingredientUnit << ".\n" << std::endl;

            }
            else {
                std::cout << "\n" << ingredientName << " doesn't exist in recipe.\n";
                std::cout << "Enter a valid ingredient name.\n" << std::endl;
            }
        }

        else if (input == 3) {
            //delete

            std::cout << "Enter an ingredient: ";
            std::getline(std::cin, ingredientName);

            ingredientName = capitalize(ingredientName);

            if (!ingredientList->remove(ingredientName)) {
                std::cout << "\n" << ingredientName << " doesn't exist in recipe.\n";
                std::cout << "Enter a valid ingredient name.\n" << std::endl;
            }
            else {
                std::cout << "\n" << ingredientName << " deleted.\n" << std::endl;
            }
        }

        else if (input == 4) {
            //print
            if (ingredientList->count != 0) {
                ingredientList->printIngredientList();
            }
            else {
                std::cout << "Ingredient list is empty.\n" << std::endl;
            }
        }

    } while(input != -1);

    if (ingredientList->count != 0) {
        ingredientList->printIngredientList();
    }
    ingredientList->~IngredientList();
}