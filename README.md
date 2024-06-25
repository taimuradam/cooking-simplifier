# Cooking Simplifier

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Directory Structure](#directory-structure)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction
The Cooking Simplifier program allows users to input the names of meals along with their ingredients and amounts. These inputs are stored in an SQL database. The program can then pick a specified number of meals at random and compare ingredients to find overlapping ones, making grocery shopping more efficient.

## Features
- Input and store meal names with ingredients and amounts.
- Save data to an SQL database.
- Randomly select a specified number of meals.
- Compare ingredients across selected meals to find overlaps.
- Simplify grocery shopping by identifying common ingredients.

## Installation

### Prerequisites
- C++ compiler (e.g., g++)
- Make
- SQL database (e.g., SQLite)

### Steps
1. Clone the repository:
    ```sh
    git clone https://github.com/taimuradam/cooking-simplifier.git
    cd cooking-simplifier
    ```

2. Build the project using Make:
    ```sh
    make
    ```

## Usage
1. Run the program:
    ```sh
    ./CookingSimplifier
    ```

2. Follow the on-screen instructions to input meal names and ingredients, and perform other operations as needed.

## Directory Structure

The project is organized as follows:

- cooking-simplifier/
  - README.md
  - LICENSE
  - Makefile
  - source/
    - main.cpp
    - main.o (generated during build)
    - RecipeList.cpp
    - RecipeList.o (generated during build)
    - util.cpp
    - util.o (generated during build)
    - IngredientHashTable.cpp
    - IngredientHashTable.o (generated during build)
  - header/
    - RecipeList.h
    - util.h
    - IngredientHashTable.h

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your changes. Ensure that your code adheres to the project’s coding standards and includes appropriate tests.

## License
This project is licensed under the MIT License. See the `LICENSE` file for more details.

## Contact
For any questions or inquiries, please contact:

- Name: Taimur Adam
- Email: taadam@asu.edu

Feel free to reach out if you have any questions or need further assistance!