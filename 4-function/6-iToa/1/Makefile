# Makefile
CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = iToa.o useiToa.o
BIN = useiToa

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(OBJS)
