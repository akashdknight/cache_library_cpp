# Variables
CXX = g++
CXXFLAGS = -g -std=c++17 -MMD -MP

# Source files
SRC = $(wildcard *.cpp)                # All .cpp files in the current directory
SRC += $(wildcard packages/*.cpp)      # All .cpp files in the packages directory
SRC += $(wildcard utilities/*.cpp)     # All .cpp files in the utilities directory

# Object files
OBJ = $(SRC:.cpp=.o)                    # Object files corresponding to the source files
# Dependency files
DEP = $(SRC:.cpp=.d)                    # Dependency files for each source file

# Header files
HEADERS = $(wildcard *.h)               # All .h files in the current directory
HEADERS += $(wildcard packages/*.h)     # All .h files in the packages directory
HEADERS += $(wildcard utilities/*.h)    # All .h files in the utilities directory

# Target executable
TARGET = my_program                     # Name of the final executable

# Default target
all: $(TARGET)

# Linking the object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling the source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include the dependency files
-include $(DEP)

# Clean up the build
clean:
	rm -f $(OBJ) $(DEP) $(TARGET)

# Phony targets
.PHONY: all clean
