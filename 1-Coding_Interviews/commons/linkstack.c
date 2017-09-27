/*************************************************************************
	> File Name: linkstack.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 一  6/19 17:59:32 2017
 ************************************************************************/

#include <stdio.h>  
#include <stdlib.h> 
#include "linkstack.h"
#include <stdbool.h>

  

  
//初始化堆栈  
LinkStack InitLinkStack() {  
    LinkStack s;  
    s = (LinkStack)malloc(sizeof(LinkStackNode));  
    if (!s) {  
        printf("空间不足\n");  
        return NULL;
    }  
    s->data = -1;
    s->next = NULL;  
    return s;  
}  

// 是否为空
bool IsEmpty(LinkStack s) {  
    return (s->next == NULL);  
}  

// 入栈
bool Push(LinkStack s, StackElementType data) {  

    LinkStack node;  
    node = (LinkStack)malloc(sizeof(LinkStackNode));  
    if (!node) {  
        printf("空间不足\n");  
    }
    node->data = data;

    node->next = s->next;  
    s->next = node;  
    return true;
} 

// 出栈
StackElementType Pop(LinkStack s) {  
    LinkStack firstCell;  
    StackElementType topData;  
    if (IsEmpty(s)) {  
        fprintf(stderr, "%s\n", "Err: Null stack pop."); 
        return STACK_ERROR_NUM;  
    }  
    firstCell = s->next;  
    s->next = firstCell->next;  
    topData = firstCell->data;  
    free(firstCell);  
    firstCell = NULL;
    return topData;  
}  
  
// 打印链栈;不打印头结点
void PrintLinkStack(LinkStack s) {  
    //printf("当前栈中的元素:\n");  
    LinkStack p;  
    p = s;  
    while (p->next != NULL) {  
        p = p->next;  
        printf("%d\n",p->data);  
    }  
}  


/***********************************************
    > 无名链栈实现

*************************************************/
// 初始化无名链表
VoidLinkStack InitVLS(void)
{
    VoidLinkStack pHead = (VoidLinkStack) malloc(sizeof(VLSNode));
    if(!pHead)
        exit(-1);
    return pHead;
}

// 无名链表是否为空
bool VLSIsEmpty(VoidLinkStack s)
{
    return (s->next == NULL);
}



// 入栈
bool VLSPush(VoidLinkStack s, void* p_data)
{
    if(NULL == p_data)
        return false;

    VLSNode *node = (VLSNode*) malloc(sizeof(VLSNode));
    if(!node)
        return false;
    node->next = s->next;
    node->p_data = p_data;
    s->next = node;
    return true;
}

// 出栈
void* VLSPop(VoidLinkStack s)
{
    VLSNode* node;
    if(VLSIsEmpty(s)){
        fprintf(stderr, "%s\n", "Err: Null VLS stack pop.");
        return NULL;
    }
    node = s->next;
    s->next = node->next;
    void* data;
    data = node->p_data;
    free(node);
    node = NULL;
    return data;
}

// 查看栈顶元素
void* VLSPeek(VoidLinkStack s)
{
    VLSNode* node;
    if(VLSIsEmpty(s))
    {
        fprintf(stderr, "%s\n", "Err: Null VLS stack pop.");
        return NULL;
    }
    node = s->next;
    return node->p_data;
}

