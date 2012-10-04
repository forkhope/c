CC = gcc
CFLAGS = -Wall
LFLAGS = -Wall -o
OBJS = strend.o usestrend.o
BIN = usestrend

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
