# Makefile
CC = gcc
CFLAGS = -Wall -c -o
LFLAGS = -Wall -o
OBJ = rightrot.o userightrot.o
BIN = userightrot

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%.o: %.c
	$(CC) $(CFLAGS) $@  $<

rightrot.o: rightrot.c
userightrot.o: userightrot.c
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	rm -f $(OBJ)
