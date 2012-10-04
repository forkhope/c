CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = getLine.o strindex.o grep.o
BIN = grep

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
