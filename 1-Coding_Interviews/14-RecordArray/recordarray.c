/*************************************************************************
	> File Name: recorearray.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 三  7/ 5 15:55:40 2017
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void Record(int *pData, unsigned int length, bool (*judge)(int)){
	if (NULL == pData || 0 == length) return;

	int *pBegin;
	int *pEnd;
	pBegin = pData + 1;
	pEnd = pData + length;
	while (pBegin < pEnd){
		while (pBegin < pEnd && !judge(*pBegin)){
			pBegin++;
		}

		while (pBegin < pEnd && judge(*pEnd)){
			pEnd--;
		}

		if (pBegin < pEnd){
			int tmp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = tmp;
		}
	}

}

// 判断是不是偶数
bool judge(int num){
	return (num & 0x1) == 0;
}


void PrintArr(int num[], int length){
	if (length <= 0) return;

	int i = 1;
	for(; i <= length; i++){
		printf("%d ", num[i]);
	}
	printf("\n");
}

int main(){
	srand(time(0));
	int length = 10;
	int num[11] = {0};
	int i = 0;
	for(i = 1; i <= length; i++){
		num[i] = rand() % 100 + 1;
	}

	printf("Before sort, num:\n");
	PrintArr(num, length);

	printf("After sort, num:\n");
	Record(num, length, judge);
	PrintArr(num, length);

	printf("After sort, num:\n");
	Record(num, 1, judge);
	PrintArr(num, length);

	printf("After sort, num:\n");
	Record(NULL, 1, judge);
	PrintArr(num, length);
	return 0;
}


