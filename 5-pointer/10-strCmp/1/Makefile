# Makefile
CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = strCmp.o usestrCmp.o
BIN = usestrCmp

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
