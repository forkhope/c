# Makefile
CC = gcc
CFLAGS = -Wall -I include
LFLAGS = -Wall -o
ARCHIVES = libsort/libsort.o
OBJ = sort.o
BIN = sort

.PHONY: all clean

all: $(ARCHIVES) $(BIN) clean

$(ARCHIVES):
	(cd libsort; make)

$(BIN): $(ARCHIVES) $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(ARCHIVES) $(OBJ)
