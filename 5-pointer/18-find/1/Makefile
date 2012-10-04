# Makefile
CC = gcc
CFLAGS = -Wall -I include
LFLAGS = -Wall -o
ARCHIVES = libfind/libfind.o
OBJ = find.o
BIN = find

.PHONY: all clean

all: $(ARCHIVES) $(BIN) clean

$(ARCHIVES):
	(cd libfind; make)

$(BIN): $(ARCHIVES) $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(ARCHIVES) $(OBJ)
