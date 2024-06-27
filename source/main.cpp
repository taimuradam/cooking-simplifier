#include "../header/IngredientHashTable.h"
#include "../header/RecipeList.h"
#include "../header/RecipeUtil.h"
#include "../header/util.h"

int main() {

    RecipeList* mainList = new RecipeList();
    std::string recipeName;
    int input = 0;
    int ingredientInput = 0;

    do {
        std::cout << "1: Insert a recipe, 2: Edit a recipe, 3: Remove a recipe, 4: Print the recipe list, -1: Quit" << std::endl;
        std::cin >> input;
        std::cin.ignore(20, '\n');
        std::cout << std::endl;


        if (input == 1) {
            //insert a recipe
            std::cout << "Enter the recipe name: ";
            std::getline(std::cin, recipeName);
            capitalize(recipeName);

            if (mainList->keyExists(recipeName)) {
                //check if recipe is already in the list
                std::cout << "Recipe already exists in the list." << std::endl;
                std::cout << "Choose a new recipe name.\n" << std::endl;
                continue;
            }

            mainList->insert(recipeName);
            
            std::cout << "\nRecipe " << recipeName << " inserted.\n" << std::endl;

            Recipe * currRecipe = mainList->getRecipe(recipeName);
            IngredientList* ingredientList = currRecipe->ingredientList;
            
            recipeUtil(ingredientInput, ingredientList);

            ingredientInput = 0;
        }

        else if (input == 2) {
            //edit a recipe
            do {
                std::cout << "What would you like to edit?" << std::endl;
                std::cout << "1: Recipe name, 2: Edit ingredients in a recipe, 3: Print recipe list, -1: Go back" << std::endl;
                std::cin >> ingredientInput;
                std::cin.ignore(20, '\n');

                editRecipeUtil(ingredientInput, mainList, recipeName);

            } while (ingredientInput != -1);

            ingredientInput = 0;
        }

        else if (input == 3) {
            //remove a recipe
            std::cout << "What recipe would you like to remove: " << std::endl;
            std::getline(std::cin, recipeName);
            capitalize(recipeName);

            if (mainList->remove(recipeName)) {
                std::cout << recipeName << " deleted.\n" << std::endl;
            }
            else {
                std::cout << "\n" << recipeName << "doesn't exist in the list.\n" << std::endl;
            }
        }

        else if (input == 4) {
            //print recipe list
            mainList->printRecipeList();
        }

    } while(input != -1);
}