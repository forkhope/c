# Makefile
CC = gcc
CFLAGS = -Wall -c -o
LFLAGS = -Wall -o
OBJ = rand.o userand.o
BIN = userand

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%.o: %.c
	$(CC) $(CFLAGS) $@ $<

rand.o: rand.c
userand.o: userand.c
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $(OBJ)

clean:
	rm -f $(OBJ)
