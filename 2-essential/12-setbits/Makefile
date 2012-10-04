# Makefile
CC = gcc
CFLAGS = -Wall -c -o
LFLAGS = -Wall -o
OBJ = setbits.o usesetbits.o
BIN = usesetbits

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%.o: %.c
	$(CC) $(CFLAGS) $@ $<

setbits.o: setbits.c
usesetbits.o: usesetbits.c
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	rm -f $(OBJ)
