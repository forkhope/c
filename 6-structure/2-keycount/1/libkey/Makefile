# libkey/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
LDFLAGS = -r -o
OBJS = keytab.o getch.o getword.o lstring.o binsearch.o
BIN = libkey.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) $@ $^

clean:
	-rm -f $(OBJS)
