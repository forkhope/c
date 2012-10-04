CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = strCat.o usestrCat.o
BIN = usestrCat

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $@ $^

clean:
	-rm -f $(OBJS)
