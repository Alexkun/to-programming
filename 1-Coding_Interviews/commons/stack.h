/*************************************************************************
	> File Name: stack.h
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com 
	> Created Time: 一  6/19 17:08:18 2017
	> 参考：http://blog.csdn.net/song_hui_xiang/article/details/47122327
 ************************************************************************/


/*  
 * 堆栈的数组实现
 */
#include <stdio.h> 
#include "common.h"
#include <stdbool.h>
#define MAX_STACK_SIZE ARRAY_SIZE_MEDIUM

  
//堆栈的顺序存储结构通常由一个一维数组和一个记录栈顶元素位置的变量组成  
typedef struct {  
    StackElementType data[MAX_STACK_SIZE];  
    int top;  
} Stack;  
  
/*
 * 初始化栈  
 */
Stack* InitStack();

// 判断是否已满
bool IsFull(Stack* stack);

// 判断是否为空 
int IsEmpty(Stack* stack);

//入栈  
bool Push(Stack* stack, StackElementType item);

//出栈  
StackElementType Pop(Stack* stack);

//打印栈中元素
void PrintStack(Stack* stack);

/***************************************************/
/*
 * 堆栈的链表实现
 */

