# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -g -Iinclude -Itest/unity

# Directories
SRC_DIR := src
BUILD_DIR := build
TEST_DIR := tests

# All .c files in src/
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Corresponding object files in build/
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Final executable
TARGET := $(BUILD_DIR)/app

# Test sources
TEST_SRC := $(TEST_DIR)/test_data_structures.c
UNITY_SRC := $(TEST_DIR)/unity/unity.c
TEST_TARGET := $(BUILD_DIR)/test_runner
TEST_SRCS := $(filter-out $(SRC_DIR)/main.c, $(SRCS))

# Default target
all: $(BUILD_DIR) $(TARGET)

# Rule to build the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files into .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to build the test runner (excluding main.c)
$(TEST_TARGET): $(TEST_SRCS) $(TEST_SRC) $(UNITY_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Run tests after building test_runner
test: $(TEST_TARGET)
	@echo "Running tests..."
	@./$(TEST_TARGET)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean

