/*************************************************************************
	> File Name: print_n_digits.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 三  7/ 5 09:57:52 2017
 ************************************************************************/

#include <stdio.h>
#include "../commons/common.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM_DIGIT ARRAY_SIZE_LONG // 10241

typedef struct BigNum
{
	char arr[MAX_NUM_DIGIT]; // 从最后一位往前计数
	int start;	// 起始下标
	int length; // 字符长度
} BigNum, *pBigNum;

BigNum *Init(void);
bool Inc(BigNum *pBigNum, int maxDigit);
void PrintBigNum(BigNum *pBigNum);
void Print1ToN(BigNum *pBigNum, int n);




BigNum *Init(void){
	BigNum *bNum = (BigNum*)malloc(sizeof(BigNum));
	memset(bNum->arr, '0', sizeof(bNum->arr) - 1);
	bNum->length = 0;
	bNum->start = MAX_NUM_DIGIT - 1; 
	bNum->arr[bNum->start] = '\0';
	return bNum;
}


inline bool Inc(BigNum *pBigNum, int maxDigit){
	if (pBigNum->length <= 0){
		pBigNum->arr[--pBigNum->start] = '1';
		pBigNum->length = 1;
		return true;
	}

	int start = MAX_NUM_DIGIT - 2; // 注意有效位从这里开始
	while (start >= 0){    // 处理进位

		if (pBigNum->arr[start] < '9'){
			pBigNum->arr[start] = pBigNum->arr[start] + 1;
			break;
		}else {
			pBigNum->arr[start] = '0';
			start--;
		}
	}
	if (start < 0){
		pBigNum->start = 0;
		return false;
	}else{
		if (start < pBigNum->start){
			pBigNum->start = start;
			pBigNum->length ++;

			////
			//printf("length=%d\n", pBigNum->length);
		}
		if (pBigNum->length <= maxDigit)  // 限制最高位
			return true;
		else
			return false;
	}
}

inline void PrintBigNum(BigNum *pBigNum){
	if (NULL == pBigNum || pBigNum->length <= 0){
		return;
	}

	int start = 0;
	int count = 0;
	for (start = pBigNum->start, count = 0; count < pBigNum->length; count++){
		printf("%c", pBigNum->arr[start++]);
	}
	printf("\t");
}


void Print1ToN(BigNum *pBigNum, int n){
	if (n < 1) return;

	for (; pBigNum->length <= n;){
		if (Inc(pBigNum, n)){
			PrintBigNum(pBigNum);
		}
	}

}

void Destroy(BigNum *p){
	free(p);
	p = NULL;
}


int main(){
	BigNum *pBigNum = Init();

	int nDigit = 2;

	Print1ToN(pBigNum, nDigit);

	pBigNum = Init();
	nDigit = 0;
	Print1ToN(pBigNum, nDigit);
	nDigit = 10;
	Print1ToN(pBigNum, nDigit);

	free(pBigNum);
	pBigNum = NULL;

	return 0;



}
