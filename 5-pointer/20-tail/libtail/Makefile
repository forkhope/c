# libtail/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
OBJS = cType.o aToi.o alloc.o lstring.o lines.o
BIN = libtail.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) -r -o $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
