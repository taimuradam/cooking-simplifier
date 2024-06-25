# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++98 -Wall -Wextra

# Executable name
TARGET = CookingSimplifier

# Source files
SOURCES = IngredientHashTable.cpp RecipeList.cpp CookingSimplifier.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files
HEADERS = IngredientHashTable.h RecipeList.h

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets
.PHONY: all clean