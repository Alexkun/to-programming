/*************************************************************************
	> File Name: numof1inbinary.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 五  6/30 11:49:53 2017
 ************************************************************************/

#include<stdio.h>

int GetNum(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d has %d of '1'.\n", n, GetNum(n));
	n = 0x7FFFFFFF;
	printf("%d has %d of '1'.\n", n, GetNum(n));
	n = 0x80000000;
	printf("%d has %d of '1'.\n", n, GetNum(n));
	n = 0xFFFFFFFF;
	printf("%d has %d of '1'.\n", n, GetNum(n));
	return 0;
}
