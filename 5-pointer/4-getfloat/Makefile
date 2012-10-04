# Makefile
CC = gcc
CFLAGS = -Wall -I include
LFLAGS = -Wall -o
ARCHIVES = lib/lib.o
OBJ = usegetfloat.o
BIN = usegetfloat

.PHONY: all clean

all: $(ARCHIVES) $(BIN) clean

$(ARCHIVES):
	(cd lib; make)

$(BIN): $(ARCHIVES) $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(ARCHIVES) $(OBJ)
