# Set Up Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Include directories
INCLUDES = -I$(SRC_DIR) -I$(COMMAND_DIR)

# Source and build directories
SRC_DIR = src
COMMAND_DIR = $(SRC_DIR)/command
BUILD_DIR = build

# Executable name
TARGET = $(BUILD_DIR)/KenwoodComm

# Source files
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/helpers.cpp $(SRC_DIR)/call_sign.cpp $(SRC_DIR)/command.cpp $(SRC_DIR)/commandset.cpp $(SRC_DIR)/defaults.cpp $(SRC_DIR)/fn.cpp $(SRC_DIR)/frequency.cpp $(SRC_DIR)/function.cpp $(SRC_DIR)/frequency_unit.cpp $(SRC_DIR)/model_number.cpp $(SRC_DIR)/session.cpp $(SRC_DIR)/switch.cpp $(SRC_DIR)/vfo.cpp
COMMAND_FILES = $(wildcard $(COMMAND_DIR)/*.cpp)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES)) \
            $(patsubst $(COMMAND_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(COMMAND_FILES))


# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile main source
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

# Compile command directory files
$(BUILD_DIR)/%.o: $(COMMAND_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

# Clean target
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean