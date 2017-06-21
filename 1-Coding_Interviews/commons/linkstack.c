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
LinkStack* InitLinkStack() {  
    LinkStack* s;  
    s = (LinkStack*)malloc(sizeof(LinkStack));  
    if (!s) {  
        printf("空间不足\n");  
        return NULL;
    }  
    s->data = -1;
    s->next = NULL;  
    return s;  
}  

// 是否为空
bool IsEmpty(LinkStack* s) {  
    return (s->next == NULL);  
}  

// 入栈
void Push(LinkStack* s, StackElementType data) {  
    LinkStack* cell;  
    cell = (LinkStack*)malloc(sizeof(LinkStack));  
    if (!cell) {  
        printf("空间不足\n");  
    }  
    cell->data = data;  
    cell->next = s->next;  
    s->next = cell;  
}  

// 出栈
StackElementType Pop(LinkStack* s) {  
    LinkStack* firstCell;  
    StackElementType topData;  
    if (IsEmpty(s)) {  
        printf("空栈\n");  
        return STACK_ERROR_NUM;  
    }  
    firstCell = s->next;  
    s->next = firstCell->next;  
    topData = firstCell->data;  
    free(firstCell);  
    return topData;  
}  
  
// 打印链栈;不打印头结点
void PrintLinkStack(LinkStack* s) {  
    printf("当前栈中的元素:\n");  
    LinkStack* p;  
    p = s;  
    while (p->next != NULL) {  
        p = p->next;  
        printf("%d\n",p->data);  
    }  
}  


