/*************************************************************************
	> File Name: linkstack.h
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 一  6/19 17:59:24 2017
 ************************************************************************/
#include <stdbool.h>
#include "common.h"

typedef struct LinkStackNode {  
    StackElementType data;  
    struct LinkStackNode* next;  
} LinkStack;  


//初始化堆栈  
LinkStack* InitLinkStack();


// 是否为空
bool IsEmpty(LinkStack* s);


// 入栈
void Push(LinkStack* s, StackElementType data);


// 出栈
StackElementType Pop(LinkStack* s);


// 打印链栈
void PrintLinkStack(LinkStack* s);



