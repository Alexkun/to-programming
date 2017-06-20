/*************************************************************************
	> File Name: 1-test-stack.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 二  6/20 10:27:10 2017
 ************************************************************************/

#include<stdio.h>
#include "../../commons/common.h"
#include "../../commons/stack.h"

int main()
{
	// 0，初始化与入栈
	printf("测试栈~");
	Stack* stack = InitStack();
	Push(stack, 3);
	Push(stack, 2);
	Push(stack, 1);
	PrintStack(stack);

	// 1，出栈测试
	Pop(stack);
	Pop(stack);
	printf("两次出栈后：");
	PrintStack(stack);

	return 0;
}


