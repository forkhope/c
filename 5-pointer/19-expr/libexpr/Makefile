# libexpr/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
OBJS = cType.o lstring.o aTof.o lstack.o
BIN = libexpr.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) -r -o $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
