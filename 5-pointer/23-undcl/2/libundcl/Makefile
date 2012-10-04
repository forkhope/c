# libundcl/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
OBJS = getch.o token.o
BIN = libundcl.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) -r -o $@ $^

clean:
	-rm -f $(OBJS)
