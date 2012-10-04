# Makefile
CC = gcc
CFLAGS = -Wall -I include
LFLAGS = -Wall -o
ARCHIVES = libpoint/libpoint.o libgetch/libgetch.o
OBJ = point.o
BIN = point

.PHONY: all clean

all: $(ARCHIVES) $(BIN) clean

libpoint/libpoint.o:
	(cd libpoint; make)

libgetch/libgetch.o:
	(cd libgetch; make)

$(BIN): $(ARCHIVES) $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(ARCHIVES) $(OBJ)
