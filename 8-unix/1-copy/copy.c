#include <unistd.h>
#include <stdio.h>	/* 包含 BUFSIZ 宏的定义 */

int main(void)
{
	char buf[BUFSIZ] = {0};
	int n;

	/* unix系统中,文件描述符 0, 1, 2 分别表示 标准输入, 标准输出, 
	 * 标准错误输出. 对于 read() 和 write() 系统调用来说:
	 * Each call returns a count of the number of bytes transferred. On
	 * reading, the number of bytes returned may be less than the number
	 * requested. A return value of zero bytes implies end of file, and
	 * -1 indicates an error of some sort. For writing, the return value
	 * is the number of bytes written; an error has occurred if this
	 * isn't equal to the number requested.
	 * 下面用变量n来接受read()函数的返回值,然后把n作为参数调用write()函数
	 * 表示:读取到多少字符,就写出多少字符.如果把下面的write()函数写为:
	 * write(1, buf, BUFSIZ); 则可能会打印出多余字符.
	 * 另外, read()函数会读入回车字符并统计到返回值,即如果输入abc,然后回车,
	 * 则read()函数把 abc\n 四个字符存入第二个参数指向的缓冲区,并返回 4,而
	 * 不是 3, 如果使用printf("%s\n", buf)语句来打印read()函数读取到的字符串
	 * 则打印结果会有两个回车; read()函数不会在读取的字符串后面加上'\0'字符
	 */
	while ((n = read(0, buf, BUFSIZ)) > 0)
		write(1, buf, n);
	return 0;
}
