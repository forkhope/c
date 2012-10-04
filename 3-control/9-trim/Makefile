# Makefile
CC = gcc
CFLAGS = -Wall -c -o
LFLAGS = -Wall -o
OBJ = trim.o usetrim.o
BIN = usetrim

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%o: %c
	$(CC) $(CFLAGS) $@ $<

trim.o: trim.c
usetrim.o: usetrim.c
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	rm -f $(OBJ)
