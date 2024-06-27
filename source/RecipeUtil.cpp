#include "../header/RecipeUtil.h"
#include "../header/util.h"

void ingredientEdit(int ingredientInput, std::string ingredientName, std::string ingredientUnit, int ingredientAmt, IngredientList* ingredientList) {
    if (ingredientInput == 1) {
        // insert an ingredient
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
    else if (ingredientInput == 2) {
        //edit an  ingredient
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

    else if (ingredientInput == 3) {
        //delete an ingredient

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

    else if (ingredientInput == 4) {
        //print an ingredient
        if (ingredientList->count != 0) {
            std::cout << std::endl;
            ingredientList->printIngredientList();
        }
        else {
            std::cout << "Ingredient list is empty.\n" << std::endl;
        }
    }
}

void recipeUtil(int ingredientInput, IngredientList* ingredientList) {
    do {
        std::cout << "What action would you like to perform?" << std::endl;
        std::cout << "1: Add an ingredient, 2: Edit an ingredient, 3: Remove an ingredient, 4: Print ingredient list, -1: Go back" << std::endl;
        std::cin >> ingredientInput;
        std::cin.ignore(20, '\n');

        if (ingredientInput == -1) {
            break;
        }

        std::string ingredientName;
        double ingredientAmt = 0.0;
        std::string ingredientUnit;

        ingredientEdit(ingredientInput, ingredientName, ingredientUnit, ingredientAmt, ingredientList);

    } while (ingredientInput != -1);
}

void editRecipeUtil(int ingredientInput, RecipeList* mainList, std::string recipeName) {
    std::string oldRecipeName;

    if (ingredientInput == 1) {
        //edit recipe name
        std::cout << "Which recipe would you like to update: " << std::endl;
        std::getline(std::cin, oldRecipeName);
        std::cout << "What would you like to change it to: " << std::endl;
        std::getline(std::cin, recipeName);
        capitalize(oldRecipeName);
        capitalize(recipeName);

        if (mainList->edit(oldRecipeName, recipeName)) {
            std::cout << oldRecipeName << " updated to " << recipeName << ".\n" << std::endl;
        }
    }

    if (ingredientInput == 2) {
        //edit ingredient in a recipe
        std::cout << "What recipe would you like to edit: " << std::endl;
        std::getline(std::cin, recipeName);
        capitalize(recipeName);
        
        Recipe * currRecipe = mainList->getRecipe(recipeName);

        if (currRecipe == nullptr) {
            std::cout << recipeName << " doesn't exist in the list.\n" << std::endl;
        }
        else {
            IngredientList* ingredientList = currRecipe->ingredientList;
            recipeUtil(ingredientInput, ingredientList);
        }
    }

    if (ingredientInput == 3) {
        //print recipe list
        mainList->printRecipeList();
    }
}