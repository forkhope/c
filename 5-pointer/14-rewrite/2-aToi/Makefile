CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = aToi.o useaToi.o
BIN = useaToi

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(OBJS)
