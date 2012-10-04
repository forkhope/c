# Makefile 文件

# 下面两行定义了一个隐含规则,其中的 %号 相当于 通配符,表示符合这种格式的文件
# 就使用命令 gcc -o $@ $< 来编译.例如最下面的 getchar: getchar.c 就只需要定
# 义目标,不需要指定命令, make命令 会自动使用下面定义的隐含规则来编译它.
%: %.c
	gcc -o $@ $<

getchar: getchar.c
