# Set Up Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Include directories
INCLUDES = -I$(SRC_DIR) -I$(COMMAND_DIR) -I$(CONFIG_DIR) -I$(CORE_DIR) -I$(PARAMETER_DIR)

# Source and build directories
SRC_DIR = src
COMMAND_DIR = $(SRC_DIR)/command
CONFIG_DIR = $(SRC_DIR)/config
CORE_DIR = $(SRC_DIR)/core
PARAMETER_DIR = $(SRC_DIR)/parameter
BUILD_DIR = build

# Executable name
TARGET = $(BUILD_DIR)/KenwoodComm

# Source files
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/command.cpp $(SRC_DIR)/command_dispatcher.cpp $(SRC_DIR)/commandset.cpp $(SRC_DIR)/helpers.cpp ${SRC_DIR}/radio_profile.cpp $(SRC_DIR)/response.cpp ${SRC_DIR}/response_result.cpp $(SRC_DIR)/serial.cpp $(SRC_DIR)/session.cpp
COMMAND_FILES = $(wildcard $(COMMAND_DIR)/*.cpp)
CONFIG_FILES = $(wildcard $(CONFIG_DIR)/*.cpp)
CORE_FILES = $(wildcard $(CORE_DIR)/*.cpp)
PARAMETER_FILES = $(wildcard $(PARAMETER_DIR)/*.cpp)

# Object files
SRC_OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))
COMMAND_OBJ_FILES = $(patsubst $(COMMAND_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(COMMAND_FILES))
CONFIG_OBJ_FILES = $(patsubst $(CONFIG_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CONFIG_FILES))
CORE_OBJ_FILES = $(patsubst $(CORE_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CORE_FILES))
PARAMETER_OBJ_FILES = $(patsubst $(PARAMETER_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(PARAMETER_FILES))
OBJ_FILES = $(SRC_OBJ_FILES) $(COMMAND_OBJ_FILES) $(CONFIG_OBJ_FILES) $(CORE_OBJ_FILES) $(PARAMETER_OBJ_FILES)

# Default target
all: $(TARGET)

# ---------------------------------------------------------------------------
# Test target
# ---------------------------------------------------------------------------
TEST_DIR = tests
TEST_TARGET = $(BUILD_DIR)/KenwoodCommTests
TEST_INCLUDES = $(INCLUDES) -I$(TEST_DIR)

# All test .cpp files (main + parameter/ + command/ + integration/)
TEST_SRC_FILES = $(shell find $(TEST_DIR) -name '*.cpp')

# Production sources without main.cpp (shared with test binary)
PROD_SRC_NO_MAIN = $(filter-out $(SRC_DIR)/main.cpp, $(SRC_FILES)) \
                   $(COMMAND_FILES) $(CONFIG_FILES) $(CORE_FILES) $(PARAMETER_FILES)

test: $(TEST_TARGET)
	@./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRC_FILES) $(PROD_SRC_NO_MAIN)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_INCLUDES) -o $@ $^

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

# Compile config directory files
$(BUILD_DIR)/%.o: $(CONFIG_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

# Compile core directory files
$(BUILD_DIR)/%.o: $(CORE_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

# Compile parameter directory files
$(BUILD_DIR)/%.o: $(PARAMETER_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

# Clean target
clean:
	rm -f $(OBJ_FILES) $(TARGET)

clean-src:
	rm -f $(SRC_OBJ_FILES)

clean-command:
	rm -f $(COMMAND_OBJ_FILES)

clean-config:
	rm -f $(CONFIG_OBJ_FILES)

clean-core:
	rm -f $(CORE_OBJ_FILES)

clean-parameter:
	rm -f $(PARAMETER_OBJ_FILES)

clean-target:
	rm -f $(TARGET)

.PHONY: all clean clean-src clean-command clean-config clean-core clean-parameter clean-target
.PHONY: test
