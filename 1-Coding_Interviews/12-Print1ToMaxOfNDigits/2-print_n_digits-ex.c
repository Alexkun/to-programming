/*************************************************************************
	> File Name: 2-print_n_digits-ex.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 三  7/ 5 15:18:13 2017
 ************************************************************************/

#include <stdio.h>
#include "../commons/common.h"
#include <string.h>

void Print1ToN(int n);
void Print1ToNRecursively(char *num, int length, int index);

int main(){
	Print1ToN(-1);
	
	Print1ToN(0);
	Print1ToN(3);
	// Print1ToN(5);
	return 0;
}

void Print1ToN(int n){
	char number[ARRAY_SIZE_MEDIUM] = {'0'};
	number[ARRAY_SIZE_MEDIUM - 1] = '\0';
	int length = 0;
	int index = ARRAY_SIZE_MEDIUM - 1;

	Print1ToNRecursively(number, length, index);
}

// 递归方法，对1~N位全排列
void Print1ToNRecursively(char *num, int length, int index){

}