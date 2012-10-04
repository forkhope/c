# lib/Makefile
CC = gcc
CFLAGS = -Wall
LD = ld
OBJS = is_space.o is_digit.o get_ch.o getfloat.o
BIN = lib.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) -r -o $(BIN) $(OBJS)

clean:
	-rm -f $(OBJS)
