#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int 	app_type;
	char 	*aid;
	char	*addr;
} AppInfo;

typedef struct {
	int		gsm;
	int		cdma;
	int		imus;
	int		num;
	AppInfo	app[3];
} AppStatus_v6;

typedef struct {
	int		gsm;
	int		cdma;
	int		num;
	AppInfo	app[3];
} AppStatus;

/* 分析结构体指针变量的存取顺序 */
int main(void)
{
	AppStatus_v6	*p_v6;
	AppStatus		*p;
	int				i;

	if ((p_v6 = (AppStatus_v6 *)malloc(sizeof(AppStatus_v6))) == NULL)
		return 1;
	p_v6->gsm 	= 5;
	p_v6->cdma	= 4;
	p_v6->imus 	= 3;
	p_v6->num	= 2;
	for (i = 0; i < 3; ++i) {
		p_v6->app[i].app_type	= 8;
		p_v6->app[i].aid		= NULL;
		p_v6->app[i].addr		= NULL;
	}
	printf("%d %d %d %d ", p_v6->gsm, p_v6->cdma, p_v6->imus, p_v6->num);
	for (i = 0; i < 3; ++i)
		printf("%d %d %d ", p_v6->app[i].app_type, 
				(int)p_v6->app[i].aid, (int)p_v6->app[i].addr);
	printf("\n");

	p = (AppStatus *)p_v6;
	/* 上面将 p_v6 转换为 AppStatus * 类型的指针后赋给 p; 由于结构体变量
	 * 不是按变量名存取,所以下面的 p->num != p_v6->num; 实际上,此时 p->num
	 * 相当于 p_v6->imus,两者都是自身结构体的第三个成员,程序的输出结果可以
	 * 看到这一点; 依此类推, p->app[0].app_type 会等于 p_v6->num,确实如此.
	 * 仔细分析上面的输出结果和下面的输出结果,会有所启发.
	 */
	printf("%d %d %d ", p->gsm, p->cdma, p->num);
	for (i = 0; i < 3; ++i)
		printf("%d %d %d ", p->app[i].app_type, 
				(int)p->app[i].aid, (int)p->app[i].addr);
	printf("\n");
	return 0;
}
