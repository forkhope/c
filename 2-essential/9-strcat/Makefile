# Makefile
CC = gcc
CFLAGS = -Wall -c -o
LFLAGS = -Wall -o
OBJ = strcat.o usestrcat.o
BIN = usestrcat

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%.o: %.c
	$(CC) $(CFLAGS) $@ $<

strcat.o: strcat.c
usestrcat.o: usestrcat.c
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	rm -f $(OBJ)
