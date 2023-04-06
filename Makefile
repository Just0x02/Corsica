CXX = g++
C_FLAGS = -Wall -Wextra -Wno-sign-compare -Wno-maybe-uninitialized -Wno-unused-parameter -Wno-write-strings -O3
CSTD = -std=c++23
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
SRCS := $(shell find $(SRC_DIR) -type f -name '*.c' -o -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS:%.cpp=%.o))
LD_FLAGS = -lGLEW -lglfw -lGL -lnoise -I ./include -L ./lib
BUILD_TARGET = $(BIN_DIR)/main

all: $(BUILD_TARGET)

$(BUILD_TARGET): $(OBJS)
	$(CXX) $(C_FLAGS) $(CSTD) $^ -o $@ $(LD_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(C_FLAGS) $(CSTD) -c $< -o $@ $(LD_FLAGS)

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	@mkdir $(OBJ_DIR)
	@mkdir $(BIN_DIR)

debug:
	@make clean
	@make -j32 C_FLAGS="-Wall -Wextra -pedantic -O3"

silent-fast:
	@make clean
	@make -j32 C_FLAGS="-O0 -w"

# CXX = g++
# C_FLAGS = -Wall -Wextra -pedantic -O0
# CSTD = -std=c++23
# SRC_DIR = src
# OBJ_DIR = obj
# BIN_DIR = bin
# SRCS := $(shell find $(SRC_DIR) -type f -name '*.c' -o -name '*.cpp')
# OBJS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS:%.cpp=%.o),$(SRCS:%.c=%.o))
# LD_FLAGS = -lGLEW -lglfw -lGL -I ./include -L ./lib
# BUILD_TARGET = $(BIN_DIR)/main

# all: $(BUILD_TARGET)

# $(BUILD_TARGET): $(OBJS)
# 	$(CXX) $(C_FLAGS) $(CSTD) $^ -o $@ $(LD_FLAGS)

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(@D)
# 	$(CXX) $(LD_FLAGS) $(C_FLAGS) $(CSTD) -c $< -o $@

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	@mkdir -p $(@D)
# 	$(CXX) $(LD_FLAGS) $(C_FLAGS) $(CSTD) -c $< -o $@

# .PHONY: clean
# clean:
# 	@rm -rf $(OBJ_DIR) $(BIN_DIR)

# CXX = g++
# C_FLAGS = -Wall -Wextra -pedantic -O2
# CSTD = -std=c++23
# SRCS := $(shell find . -type f -name '*.c' -o -name '*.cpp')
# LD_FLAGS = -lGLEW -lglfw -lGL -I ./include -L ./lib
# BUILD_TARGET = main

# all: $(BUILD_TARGET)

# $(BUILD_TARGET): $(SRCS)
# 	$(CXX) $(C_FLAGS) $(CSTD) $^ -o $@ $(LD_FLAGS)

# .PHONY: clean
# clean:
# 	rm -f $(BUILD_TARGET)

# CXX = g++

# C_FLAGS = -Wall -Wextra -pedantic -O2

# CSTD = -std=c++23

# SRCS := $(shell find -type f -name '*.c') $(shell find -type f -name '*.cpp')

# LD_FLAGS = -lGLEW -lglfw -lGL -I ./include -L ./lib

# BUILD_TARGET = ./main

# all:
# 	$(CXX) $(C_FLAGS) $(SRCS) -o $(BUILD_TARGET) $(LD_FLAGS) $(CSTD)