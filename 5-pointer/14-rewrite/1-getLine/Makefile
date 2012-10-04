CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = getLine.o usegetLine.o
BIN = usegetLine

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
