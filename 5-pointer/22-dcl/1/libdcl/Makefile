# libdcl/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
OBJS = getch.o token.o dcl.o
BIN = libdcl.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) -r -o $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
