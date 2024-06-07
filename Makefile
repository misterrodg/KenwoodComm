# Set Up Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source and build directories
SRC_DIR = src
BUILD_DIR = build

# Source files
# SRC = $(wildcard $(SRC_DIR)/*.cpp)
SRC = src/main.cpp src/helpers.cpp src/auto_information.cpp src/call_sign.cpp src/command.cpp src/command_prefix.cpp src/commandset.cpp src/defaults.cpp src/model_number.cpp src/session.cpp src/switch.cpp

# Object files (place in the build directory)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))

# Executable name
TARGET = $(BUILD_DIR)/KenwoodComm

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove compiled objects and the executable
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean
