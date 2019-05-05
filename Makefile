CC=g++
CFLAGS = -std=c++17 -g -Wall -I $(HEADER_DIR)

# Directories
SOURCE_DIR = src
HEADER_DIR = headers
BUILD_DIR = obj
OUTPUT_DIR = bin
TEST_DIR = tests
# Targets for output
TARGET = Output.exe
TEST_TARGET = Test.exe

# Source files
SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
TESTS = $(wildcard $(TEST_DIR)/*.cpp)

# Objects
OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TESTS))
#TEST_OBJECTS := $(filter-out $(TEST_DIR)/ArithmeticTests.cpp, $(TEST_OBJECTS))

tests = ConstructorTests,ComparisonTests,IncrementTests,ArithmeticTests
log_lvl = error

make_directories:
	@ mkdir -p $(BUILD_DIR)
	@ mkdir -p $(OUTPUT_DIR)

# Compile all files
all: build run clean

# Compile run and clean test
RunTests: build_tests run_tests clean

run: build $(OUTPUT_DIR)/$(TARGET)
	@ ./$(OUTPUT_DIR)/$(TARGET)

run_tests: build_tests $(OUTPUT_DIR)/$(TEST_TARGET)
	-@ ./$(OUTPUT_DIR)/$(TEST_TARGET) --log_level=$(log_lvl) --run_test=$(tests) 
	
# Make object files
$(OBJECTS): $(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.cpp
	@ $(CC) $(CFLAGS) -c $< -o $@

# Make test files
$(TEST_OBJECTS): $(BUILD_DIR)/%.o : $(TEST_DIR)/%.cpp
	@ $(CC) $(CFLAGS) -c $< -o $@

build: make_directories $(OBJECTS)
	@ $(CC) $(CFLAGS) $(OBJECTS) -o $(OUTPUT_DIR)/$(TARGET)

build_tests: make_directories $(OBJECTS) $(TEST_OBJECTS)
	@ $(CC) $(CFLAGS) $(OBJECTS) $(TEST_OBJECTS) -lboost_unit_test_framework  -o $(OUTPUT_DIR)/$(TEST_TARGET)

# Cleans all object files
.PHONY: all clean
clean:
	@ rm -rf $(BUILD_DIR) $(OUTPUT_DIR) .vscode/ipch