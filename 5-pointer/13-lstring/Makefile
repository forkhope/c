CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = lstring.o uselstring.o
BIN = uselstring

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
