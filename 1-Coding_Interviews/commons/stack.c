/*************************************************************************
	> File Name: stack.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com 
	> Created Time: 一  6/19 17:08:25 2017
 ************************************************************************/

#include <stdio.h>
#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

/*
 * 初始化栈  
 */
Stack* InitStack() {  
    Stack* stack;  
    stack = (Stack*)malloc(sizeof(Stack));  
    if (!stack) {  
        printf("空间不足\n");  
        return NULL;  
    }  
    stack->top = -1;  
    return stack;  
}  

// 判断是否已满
bool IsFull(Stack* stack) {  
    if (stack->top == MAX_STACK_SIZE - 1) {  
        //printf("堆栈已满\n");  
        return true;  
    }  
    return false;  
}  
 
// 判断是否为空 
bool IsEmpty(Stack* stack) {  
    if (stack->top == -1) {  
        //printf("堆栈空\n");  
        return true;  
    }  
    return false;  
}  
  
//入栈  
bool Push(Stack* stack, StackElementType item) {  
    if (IsFull(stack)) {  
        return false;  
    }  
    stack->data[++stack->top] = item;  
    return true;
}  
  
//出栈  
StackElementType Pop(Stack* stack) {  
    if (IsEmpty(stack)) {  
        return STACK_ERROR_NUM;  
    }  
    return stack->data[stack->top--];  
}  

//打印栈中元素
void PrintStack(Stack* stack) {  
    printf("当前栈中的元素:\n");  
    int i;  
    for (i = stack->top; i >= 0; i--) {  
        printf("%d\n", stack->data[i]);  
    }  
}  



