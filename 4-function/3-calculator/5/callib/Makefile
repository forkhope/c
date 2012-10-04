# callib/Makefile
CC = gcc
CFLAGS = -Wall
LD = ld
OBJS = is_loweralpha.o is_space.o is_digit.o str_len.o a_to_f.o \
	   get_ch.o getop.o lstack.o
TARGET = callib.o

.PHONY: all clean

all: $(TARGET) clean

$(TARGET): $(OBJS)
	$(LD) -r -o $@ $^

clean:
	-rm -f $(OBJS)
