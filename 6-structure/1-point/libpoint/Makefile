# libpoint/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
OBJS = setcursor.o makepoint.o drawrow.o drawborder.o drawrect.o
BIN = libpoint.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) -r -o $@ $^

clean:
	-rm -f $(OBJS)
