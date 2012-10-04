# Makefile
CC = gcc
CFLAGS = -Wall -I include
LFLAGS = -Wall -o
ARCHIVES = callib/callib.o
OBJ = calculator.o
BIN = calculator

.PHONY: all clean

all: $(ARCHIVES) $(BIN) clean

$(ARCHIVES):
	(cd callib; make)

$(BIN): $(ARCHIVES) $(OBJ)
	$(CC) $(LFLAGS) $@ $^ -lm

clean:
	-rm -f $(ARCHIVES) $(OBJ)
