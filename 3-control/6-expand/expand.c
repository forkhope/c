/* Write a function expand(s1, s2) that expands shorthand notations like
 * a-z in the string s1 into the equivalent complete list abc...xyz in s2.
 * Allow for letters of either case and digits, and be prepared to handle
 * cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing
 * - is taken literally. 作为前导和尾随的-字符原样打印.
 */
void expand(const char s1[], char s2[])
{
	int i, j;

	for (i = 0, j = 0; s1[i] != '\0'; ++i) {
		if (s1[i] == '-') {
			if (i == 0 || s1[i+1] == '\0')
				s2[j++] = s1[i]; /* 原样保留前导和尾随的-字符 */
			else {
				/* 下面的for循环,原来是按照下面的方式来写的:
				 * for (s2[j] = s1[i-1],k=0;s2[j]<s1[i+1];++j,++k)
				 *     s2[j] = s1[i-1] + k;
				 * 按照这种写法,程序运行会出错,原因是搞错了for循环里的语句
				 * 执行顺序.当执行完s2[j]=s1[i-1]+k,for循环会执行++j,++k;
				 * 然后才比较s2[j]<s1[i+1],但是j已经加了1,s2[j]指向刚才赋值
				 * 元素的下一位,其值不明确.程序原本是希望执行s2[j]=s1[i-]+k
				 * 然后比较s2[j]<s1[i+1],如果为真才++j.但由于没有仔细考虑
				 * for循环语句的执行顺序,结果程序的执行顺序是先为s2[j]赋值,
				 * 接着++j,才比较s2[j]<s1[i+1],此时s2[j]和刚才的s2[j]已不是
				 * 同一个元素,比较结果和预期不符,程序执行结果因此出错.
				 * 为了防止这种情况,下面的for循环使用s2[j++]<s1[i+1]来先比较
				 * 后为j加1,执行顺序和预期一致,程序运行无误.
				 */
				for (s2[j] = s1[i-1]; s2[j++] < s1[i+1];)
					s2[j] = s2[j-1] + 1;
			}
		}
	}
	s2[j] = '\0';	/* 不忘在字符串的末尾加上 '\0' 终止字符 */
}
