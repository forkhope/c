align: align.c
	gcc -Wall -o $@ $<

unalign: align.c	# 使用 gcc 的 -Dmaroc 选项来定义一个宏
	gcc -Wall -DUNALIGN -o $@ $<
