/*************************************************************************
	> File Name: 1-fibonacci.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 四  6/29 16:25:23 2017
 ************************************************************************/

#include<stdio.h>
#include "../commons/common.h"

long long Fib_Save(long long fib[], int n)
{
	if (n <= 0) return 0;
	if (0 == fib[n]){
		if (1 == n){
			fib[1] = 1;
			return 1;
		}else if (2 == n){
			fib[2] = 1;
			return 1;
		}else {
			long long num = Fib_Save(fib, n-1) + Fib_Save(fib, n-2);
			fib[n] = num;
			return num;
		}
	}else{
		return fib[n];
	}

}


int main()
{
	long long fib[ARRAY_SIZE_LONG] = {0};
	int n = 3;
	//printf("Fib(%d)=%lld\n", n, Fib_Save(fib, n));
	n = 10;
	//printf("Fib(%d)=%lld\n", n, Fib_Save(fib, n));
	n = 90;
	printf("Fib(%d)=%lld\n", n, Fib_Save(fib, n));
	/* for(n = 0; n < 50; n++){
		printf("Fib(%d)=%lld\n", n, Fib_Save(fib, n));
	} */
	return 0;
}
