# Set Up Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source and build directories
SRC_DIR = src
BUILD_DIR = build

# Source files
# SRC = $(wildcard $(SRC_DIR)/*.cpp)
SRC = src/main.cpp src/helpers.cpp src/command_base.cpp src/command_switch.cpp src/antenna_tuner.cpp src/auto_information.cpp src/call_sign.cpp src/command.cpp src/command_prefix.cpp src/commandset.cpp src/defaults.cpp src/dcs.cpp src/dcs_id.cpp src/dn.cpp src/fn.cpp src/frequency.cpp src/function.cpp src/frequency_unit.cpp src/hold.cpp src/id.cpp src/if.cpp src/lk.cpp src/lo.cpp src/model_number.cpp src/ms.cpp src/rc.cpp src/rd.cpp src/rt.cpp src/ru.cpp src/rx.cpp src/session.cpp src/switch.cpp src/tx.cpp src/up.cpp src/vfo.cpp

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
