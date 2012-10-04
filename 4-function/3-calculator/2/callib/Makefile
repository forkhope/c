# callib/Makefile
# 虽然下面并没有显式使用 CC 变量,但是 make 命令在自动推导.o文件时,会隐式的
# 使用 CC 变量,由于 CC 变量在 make 命令中的默认值是 cc,如果下面不为 CC 变量
# 赋值为 gcc 的话, make 命令将使用 cc 编译器来生成 .o 文件.
CC = gcc
# make 命令自动推导.o文件时,强制使用编译选项 -c -o,同时会使用CFLAGS变量
# 的值作为其他选项,即其使用的编译命令相当于: gcc $(CFLAGS) -c -o
# 所以在定义 CFLAGS 变量时,不需要加上 -c -o;当然加上也不会报错,但没必要
CFLAGS = -Wall
# 下面的 LD 变量不定义也可以, make 命令本身就存在LD变量,其默认值也是 ld
LD = ld
OBJS = isSpace.o isDigit.o aTof.o lstack.o get-ch.o getop.o

.PHONY: all clean

all: callib.o clean

# make 命令本身的自动推导就是这样定义的,所以的两条语句可以不用写
#%o: %c
#	$(CC) $(CFLAGS) $@ $<

callib.o: $(OBJS)
	$(LD) -r -o callib.o $(OBJS)

# 下面的6条语句可以不用写, make 命令会根据同名的.c文件来生成同名的.o文件
#isSpace.o: isSpace.c
#isDigit.o: isDigit.c
#aTof.o: aTof.c
#lstack.o: lstack.c
#get-ch.o: get-ch.c
#getop.o: getop.c

# 在 rm 命令前面加一个小减号的意思是: 也许某些文件出现问题(例如文件不存在),
# 但不要管,继续做后面的事;当然 rm 命令的 -f 选项本身就是要忽略不存在的文件
clean:
	-rm -f $(OBJS)
