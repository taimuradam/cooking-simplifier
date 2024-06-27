#include "../header/util.h"
#include "../header/IngredientHashTable.h"

std::string capitalize(std::string string) {
    //capitalize the first character of a string
    for (int i = string.length() - 1; i >= 0; i--) {
        if (i == 0) {
            string[i] = toupper(string[i]);
        }
        else {
            string[i] = tolower(string[i]);
        }
    }
    return string;
}

std::string toLower(std::string string) {
    //makes all charaters in string lowercase
    for (int i = string.length() - 1; i >= 0; i--) {
        string[i] = tolower(string[i]);
    }
    return string;
}