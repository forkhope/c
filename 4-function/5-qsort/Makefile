# Makefile
CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = qsort.o useqsort.o
BIN = useqsort

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(OBJS)
