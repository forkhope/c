CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = strCpy.o usestrCpy.o
BIN = usestrCpy

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(OBJS)
