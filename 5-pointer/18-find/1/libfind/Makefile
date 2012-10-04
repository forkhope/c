# libfind/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
OBJS = getLine.o strLen.o strnCmp.o strStr.o
BIN = libfind.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) -r -o $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
