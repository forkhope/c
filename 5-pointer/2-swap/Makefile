# Makefile
CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = swap.o useswap.o
BIN = useswap

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(OBJS)
