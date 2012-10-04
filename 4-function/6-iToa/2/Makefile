# Makefile
CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = itoa.o useitoa.o
BIN = useitoa

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(OBJS)
