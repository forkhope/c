# Makefile
CC = gcc
CFLAGS = -Wall -Iinclude -c -o
LFLAGS = -Wall -o
OBJ = lstack.o getCh.o lib/isSpace.o lib/isDigit.o getop.o \
	  aTof.o calculator.o
BIN = calculator

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%o: %c
	$(CC) $(CFLAGS) $@ $<

lstack.o: lstack.c
getCh.o: getCh.c
lib/isSpace.o: lib/isSpace.c
lib/isDigit.o: lib/isDigit.c
getop.o: getop.c
aTof.o: aTof.c
calculator.o: calculator.c
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	rm -f $(OBJ)
