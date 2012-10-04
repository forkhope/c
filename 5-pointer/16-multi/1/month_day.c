#include <stdio.h>

int day_of_year(unsigned int year, 
		unsigned int month, unsigned int day);
int month_day(unsigned int year, unsigned int yearday,
		unsigned int *pmonth, unsigned int *pday);
char *month_name(const int n);

/* There is no error checking in day_of_year or month_day.
 * Remedy this defect.
 */
int main(void)
{
	unsigned int month, day;
	int i;

	month_day(1988, 60, &month, &day);
	printf("1988年的第60天是 %d 月 %d 日\n", month, day);
	printf("1988年的 %d 月 %d 日是该年的第 %d 天\n",
			month, day, day_of_year(1988, month, day));
	for (i = 0; i < 13; ++i)
		printf("%s\n", month_name(i));
	return 0;
}

/* We made it char to illustrate a legitimate use of char of storing small
 * non-character integers. char型可以存放的整数范围是 -128 ~ 127
 */
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* I have selected the year 1752 as the lowest allowed year, because that
 * is when Great Britain switched to the Gregorian calendar, and the leap
 * year validation is valid only for the Gregorian calender.
 */

/* day_of_year: set day of year from month & day */
int day_of_year(unsigned int year, 
		unsigned int month, unsigned int day)
{
	int i, leap;
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if (year < 1752 || month > 12 || day > daytab[leap][month])
		return -1;
	for (i = 1; i < month; ++i)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
int month_day(unsigned int year, unsigned int yearday,
		unsigned int *pmonth, unsigned int *pday)
{
	int i, leap;
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if (year < 1752 || (leap && yearday > 366) || (!leap && yearday > 365))
		return -1;
	for (i = 1; yearday > daytab[leap][i]; ++i)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
	return 0;
}

/* month_name: return name of n-th month */
char *month_name(const int n)
{
	/* 字符串常量会返回一个指向它开始位置的字符指针 */
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}
