# Makefile
CC = gcc
CFLAGS = -Wall -c -o
LFLAGS = -Wall -o
OBJ = squeeze.o usesqueeze.o
BIN = usesqueeze

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%.o: %.c
	$(CC) $(CFLAGS) $@ $<

squeeze.o: squeeze.c
usesqueeze.o: usesqueeze.c
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	rm -f $(OBJ)
