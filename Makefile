# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Source files
LINKEDLIST_SRC = linkedlist.cpp
MAIN_SRC ?= main.cpp

# Object files
OBJECTS = $(LINKEDLIST_SRC:.cpp=.o) $(MAIN_SRC:.cpp=.o)

# Executable name (derived from MAIN_SRC)
EXECUTABLE = $(basename $(MAIN_SRC))

# Default target
all: $(EXECUTABLE)

# Link the program
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Phony targets
.PHONY: all clean
