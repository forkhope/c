# libhash/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
LDFLAGS = -r -o
OBJS = hash.o hashtab.o lookup.o install.o hashprint.o getword.o \
	   lstring.o unDef.o
BIN = libhash.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) $@ $^

clean:
	-rm -f $(OBJS)
