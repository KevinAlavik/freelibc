CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g -lfreelibc

OBJDIR = objects
OBJS = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(wildcard *.c)))

BIN = test

all : $(OBJDIR) $(BIN)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BIN) : $(OBJS)
	$(CC) $(OBJS) -o $(BIN) $(CFLAGS)

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

run:
	@./$(BIN)

clean:
	rm -rf $(wildcard *.o) objects test
