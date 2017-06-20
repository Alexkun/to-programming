/*************************************************************************
	> File Name: list.h
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com 
	> Created Time: 一  6/19 14:42:57 2017
	> Content: 链表相关
 ************************************************************************/
#pragma once
#include <stdio.h>
#define NODE_LEN sizeof(struct ListNode)


typedef struct ListNode
{
	int value;
	struct ListNode* next;

} ListNode;

/*
 * 尾部添加节点
 *
 */
void AddToTail(ListNode** pHead, int value);


/*
 * 删除一个节点
 *
 */
void RemoveNode(ListNode** pHead, int value);


/*
 * 打印一个链表所有元素
 *
 */
void PrintList(ListNode *pHead, const char* msg);


