# Makefile
# CFLAGS是编译选项, LFLAGS是链接选项
CC = gcc
CFLAGS = -Wall -c -o
LFLAGS = -Wall -o
OBJS = lib/aToi.o useaToi.o
BIN = useaToi

.PHONY: all clean
all: $(OBJS) $(BIN) clean

%.o : %.c
	$(CC) $(CFLAGS) $@ $<

lib/aToi.o : lib/aToi.c
useaToi.o : useaToi.c
$(BIN) : $(OBJS)
	$(CC) $(LFLAGS) $@ $(OBJS)

clean:
	rm -f $(OBJS)	# rm -f 忽略不存在的文件,不打印警告信息
