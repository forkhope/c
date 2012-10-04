# Makefile
CC = gcc
CFLAGS = -Wall -Iinclude 
LFLAGS = -Wall -o
ARCHIVES = callib/callib.o
OBJ = calculator.o
BIN = calculator

.PHONY: all clean

all: callib/callib.o $(BIN) clean
#%o: %c
#	$(CC) $(CFLAGS) $@ $<

callib/callib.o:
	(cd callib; make)

#calculator.o: calculator.c
# 源程序包含 <math.h> 头文件时,需要使用 -lm 选项,否则会提示找不到函数
$(BIN): $(OBJ) $(ARCHIVES)
	$(CC) $(LFLAGS) $@ $^ -lm

clean:
	-rm -f $(OBJ) $(ARCHIVES)
