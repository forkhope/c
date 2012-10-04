# libtree/Makefile
CC = gcc
CFLAGS = -Wall -I ../include
LD = ld
LDFLAGS = -r -o
OBJS = lstring.o getword.o talloc.o addtree.o treeprint.o \
	   resorttree.o
BIN = libtree.o

.PHONY: all clean

all: $(BIN) clean

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) $@ $^

clean:
	-rm -f $(OBJS)
