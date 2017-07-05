/*************************************************************************
	> File Name: test-unsigned-int.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 一  7/ 3 15:24:54 2017
 ************************************************************************/

#include<stdio.h>

int main()
{
	int num = -1;
	unsigned int unsigned_num = (unsigned int) num;
	printf("unsigned %d = %u\n", num, unsigned_num);
	printf("unsigned output %d = %u\n", num, num);

	return 0;
}
