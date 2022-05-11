# Agradecimentos ao Chase Lambert pelo tutorial em https://makefiletutorial.com/#makefile-cookbook
# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
CC := gcc
CPPC := g++

TARGET_EXEC := out

BUILD_DIR := build
SRC_DIRS := src external/glad/src
INC_DIR := include

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. Make will incorrectly expand these otherwise.
SRCS := $(shell find $(SRC_DIRS) -name '*.cc' -or -name '*.c')

# String substitution for every C/C++ file.
# As an example, hello.cc turns into ./build/hello.cc.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# Every folder in ./include will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(INC_DIR) -type d) external/glad/include external/glfw-3.3.7/win64/include
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
# Bibliotecas
LIB_DIRS := external/glfw-3.3.7/win64/lib
LIB_FLAGS := $(addprefix -L,$(LIB_DIRS))
LIBS := -l:libglfw3.a

CPPFLAGS := $(INC_FLAGS) -Wall -Werror -std=c++17
CFLAGS := $(INC_FLAGS) -Wall -Werror -std=c17

# The final build step.
$(TARGET_EXEC): $(OBJS)
	$(CPPC) $(OBJS) $(LIB_FLAGS) $(LIBS) -o $@

# Build step for CPP source
$(BUILD_DIR)/%.cc.o: %.cc
	mkdir -p $(dir $@)
	$(CPPC) $(CPPFLAGS) -c $< -o $@

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET_EXEC)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
	rm -r $(TARGET_EXEC)