# Makefile
CC = gcc
CFLAGS = -Wall -c -o
LFLAGS = -Wall -o
OBJ = aToi.o useaToi.o
BIN = useaToi

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%o: %c
	$(CC) $(CFLAGS) $@ $<

aTio.o: aToi.c
useaToi.o: useaToi.c
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean: 
	rm -f $(OBJ)
