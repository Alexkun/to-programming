/*************************************************************************
	> File Name: linkstack.h
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 一  6/19 17:59:24 2017
 ************************************************************************/
#pragma once
#include <stdbool.h>
#include "common.h"

typedef struct LinkStackNode {  
    StackElementType data;  
    struct LinkStackNode* next;  
} LinkStackNode, *LinkStack;  


//初始化堆栈  
LinkStack InitLinkStack();


// 是否为空
bool IsEmpty(LinkStack s);


// 入栈
// 栈结构：头指针指向栈顶元素，后续元素依次指向栈底
bool Push(LinkStack s, StackElementType data);


// 出栈
StackElementType Pop(LinkStack s);


// 打印链栈
void PrintLinkStack(LinkStack s);



/********************************************************
	> 无名链表
	> 特性：元素类型未定，采用void* 型
*********************************************************/
typedef struct VoidLinkStackNode {
	void* p_data;
	struct VoidLinkStackNode* next;
} VLSNode, *VoidLinkStack;

// 初始化无名链表
VoidLinkStack InitVLS(void);

// 无名链表是否为空
bool VLSIsEmpty(VoidLinkStack s);

// 入栈
bool VLSPush(VoidLinkStack s, void* p_data);

// 出栈
void* VLSPop(VoidLinkStack s);

// 打印无名链栈 -- 该方法不能实现，需要自己打印

// 查看栈顶元素
void* VLSPeek(VoidLinkStack s);



