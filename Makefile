CC = gcc
CFLAGS =  -Wall -Werror -Wextra -pedantic -std=gnu89 -Wunused-variable -I./$(INCLUDE_DIR)
LDFLAGS = 


SRC_DIR = src
INCLUDE_DIR = $(SRC_DIR)/include
BUILD_DIR = Build
BINARY_DIR = Bin


# All source files
SOURCE = $(wildcard $(SRC_DIR)/*.c)

# All object files
OBJECT = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCE))

# The final output executable
BINARY = shell



all: $(BINARY)
	@echo 'Compiled Successfully'

$(BINARY): $(OBJECT)
	@echo 'linking...'
	@mkdir -p $(BINARY_DIR)
	@$(CC) $(LDFLAGS) $^ -o $@
	@mv $(BINARY) $(BINARY_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo 'compiling...'
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clear: 
	@echo 'cleaning...'
	@rm -rfv $(BUILD_DIR) $(BINARY_DIR)

.PHONY: all clean
