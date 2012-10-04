#include <stdio.h>
#include <time.h>

extern int rand(void);
extern void srand(unsigned int seed);

/* rand()函数可以用来产生随机数,但是这不是真正意义上的随机数,是一个伪随机数,
 * 是根据一个数(等于srand(seed)传入的seed或者默认是1)为基准以某个递推公式算
 * 出来的一系列数.关于rand()和srand()的更详细说明见本目录下的 rand.c 文件.
 * 使用rand()和srand()产生随机数的一般步骤如下:
 * 1) 给srand()提供一个种子,它是一个 unsigned int 类型;
 * 2) 调用rand(),它会根据提供给srand()的种子值返回一个随机数(0到RAND_MAX);
 * 3) 根据需要多次调用rand(),从而不间断地得到新的随机数;
 * 4) 可以给srand()提供一个新的种子值,从而进一步"随机化"rand()的输出结果.
 */
int main()
{
	int i, random;

	/* rand()产生的是伪随机数,每次执行main()函数时,如果随机数种子的值是一样
	 * 的,则rand()所产生的随机数也是一样的.为了产生不一样的随机数,可以使用
	 * 系统时间作为种子的值,因为每一次运行程序的时间是不同的,种子的值不同,
	 * rand()产生的随机数的值也就不同.下面的 time() returns the time as the
	 * number of seconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
	 */
	srand((unsigned int)time(NULL));
	for (i = 0; i < 10; ++i) {
		random = rand();
		printf("产生的第 %d 个随机数是 %d\n", i+1, random);
	}
	printf("-----------------------------------\n");
	for (i = 0; i < 10; ++i) {
		random = rand() % 10;
		printf("产生的0到9之间的第 %d 个随机数是 %d\n", i+1, random);
	}
	return 0;
}
