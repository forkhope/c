CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = aTof.o useaTof.o
BIN = useaTof

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
