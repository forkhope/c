# Makefile
CC = gcc
CFLAGS = -Wall -c -o
LFLAGS = -Wall -o
OBJ = iToa.o useiToa.o
BIN = useiToa

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%o: %c
	$(CC) $(CFLAGS) $@ $<

iToa.o: iToa.c
useiToa.o: useiToa.c
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	rm -f $(OBJ)
