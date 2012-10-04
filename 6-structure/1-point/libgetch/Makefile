# libgetch/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
OBJS = getch.o getpoint.o aToi.o
BIN = libgetch.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) -r -o $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
