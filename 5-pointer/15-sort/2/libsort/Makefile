# libsort/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
OBJS = lstring.o lines.o qsort.o
BIN = libsort.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) -r -o $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
