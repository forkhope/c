# Makefile
CC = gcc
CFLAGS = -Wall -c -o
LFLAGS = -Wall -o
OBJ = htoi.o usehtoi.o
BIN = usehtoi

.PHONY: all clean

all: $(OBJ) $(BIN) clean
%.o: %.c
	$(CC) $(CFLAGS) $@ $<

htoi.o: htoi.c
usehtoio.o: usehtoi.c
# $^ --- 表示所有的依赖文件,以空格分开,不包含重复的依赖文件
$(BIN): $(OBJ)
	$(CC) $(LFLAGS) $@ $^

clean:
	rm -f $(OBJ)
