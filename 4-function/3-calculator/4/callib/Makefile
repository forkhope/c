# callib/Makefile
CC = gcc
CFLAGS = -Wall
LD = ld
OBJS = is_space.o is_digit.o is_loweralpha.o a_to_f.o lstack.o \
	   get_ch.o getop.o str_len.o
TARGET = callib.o

.PHONY: all clean

all: $(TARGET) clean

$(TARGET): $(OBJS)
	$(LD) -r -o $(TARGET) $(OBJS)

clean:
	-rm -f $(OBJS)
