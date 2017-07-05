/*************************************************************************
	> File Name: 2-fibonacci-ex.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 四  6/29 17:34:45 2017
 ************************************************************************/

#include<stdio.h>


long long Fibonacci(unsigned n)
{
	long long fib_one = 0;
	long long fib_two = 1;
	long long fib_num = 0;
	int i;
	for (i = 2; i <= n; i++)
	{
		fib_num = fib_two + fib_one;
		fib_one = fib_two;
		fib_two = fib_num;
	}
	return fib_num;

}

int main()
{
	printf("Fib(90)=%lld\n", Fibonacci(90));
	return 0;
}
