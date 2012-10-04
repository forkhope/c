# Makefile
CC = gcc
CFLAGS = -Wall -Iinclude -c -o
LFLAGS = -Wall -o
OBJ = lib/isSpace.o lib/isDigit.o aTof.o getLine.o useaTof.o
BIN = useaTof

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%o: %c
	$(CC) $(CFLAGS) $@ $<

lib/isSpace.o: lib/isSpace.c
lib/isDigit.o: lib/isDigit.c
aTof.o: aTof.c
getLine.o: getLine.c
useaTof.o: useaTof.c
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	rm -f $(OBJ)
