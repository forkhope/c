# callib/Makefile
CC = gcc
CFLAGS = -Wall
LD = ld
OBJS = is_space.o is_loweralpha.o is_digit.o a_to_f.o lstack.o get_ch.o \
	   getop.o

.PHONY: all clean

all: callib.o clean

callib.o: $(OBJS)
	$(LD) -r -o callib.o $(OBJS)

clean: 
	-rm -f $(OBJS)
