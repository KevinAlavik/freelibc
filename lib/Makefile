# Directory of include files
INCLUDE_DIR ?= "../include"

# Compiler and compiler flags
CC = gcc
CFLAGS = -fno-stack-protector -ffreestanding -Wall -Wextra -g -I$(INCLUDE_DIR)

# Folder for object libraries and compiled library
OBJ = obj
OBJDIR = $(OBJ)/objects
BIN = $(OBJ)/freelibc.a

# Source files
SRC_BUILTIN = $(wildcard routines/builtin/*.c)
SRC_STD = $(wildcard std/*.c)

OBJS = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(SRC_BUILTIN)))
OBJS += $(addprefix $(OBJDIR)/, $(patsubst std/%.c, %.o, $(SRC_STD)))

# Path where to install library
LIB_DIR ?= /usr/local/lib
INCLUDE_INSTALL_DIR ?= /usr/local/include/freelibc

.PHONY: all
all: $(OBJ) $(OBJDIR) $(BINFOLDER) $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINFOLDER):
	mkdir -p $(BINFOLDER)

$(BIN): $(OBJS)
	ar -r $(BIN) $^

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: std/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)

install: $(BIN)
	@echo "====> Installing freelibc.a to $(LIB_DIR)"
	install -d $(LIB_DIR)
	install $(BIN) $(LIB_DIR)/libfreelibc.a
	@echo "====> Installing headers to $(INCLUDE_INSTALL_DIR)"
	install -d $(INCLUDE_INSTALL_DIR)
	rsync -a $(INCLUDE_DIR)/ $(INCLUDE_INSTALL_DIR)/
	@echo "====> Configuring GCC"
	echo $(LIB_DIR) | sudo tee /etc/ld.so.conf.d/freelibc.conf
	sudo ldconfig
