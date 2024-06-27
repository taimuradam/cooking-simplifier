# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++98 -Wall -Wextra

# Executable name
TARGET = CookingSimplifier

# Source files directory
SRCDIR = source

# Header files directory
INCDIR = header

# Source files
SOURCES = $(SRCDIR)/IngredientHashTable.cpp $(SRCDIR)/RecipeList.cpp $(SRCDIR)/main.cpp $(SRCDIR)/util.cpp $(SRCDIR)/RecipeUtil.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files
HEADERS = $(INCDIR)/IngredientHashTable.h $(INCDIR)/RecipeList.h $(INCDIR)/util.h $(INCDIR)/RecipeUtil.h

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets
.PHONY: all clean