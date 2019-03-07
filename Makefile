CC=g++
CFLAGS = -std=c++17 -Wall -g -I $(HEADER_DIR)

SOURCE_DIR = src
HEADER_DIR = headers
BUILD_DIR = obj
OUTPUT_DIR = bin

TARGET = Output.exe
OBJECTS = $(addprefix $(BUILD_DIR)/, main.o)


make_directories:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OUTPUT_DIR)

all: build run clean
	
run: $(OUTPUT_DIR)/$(TARGET)
	./$(OUTPUT_DIR)/$(TARGET)

#Compile all Files
build: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/$(TARGET) $(OBJECTS)

#Main object file
$(BUILD_DIR)/main.o: make_directories $(SOURCE_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/main.cpp -o $@

#Cleans all object files
clean:
	rm -rf $(BUILD_DIR) $(OUTPUT_DIR)

	