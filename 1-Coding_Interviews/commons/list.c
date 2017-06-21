/*************************************************************************
	> File Name: list.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com 
	> Created Time: 一  6/19 14:51:45 2017
 ************************************************************************/

#include <stdio.h>
#include "list.h"
#include <stdlib.h>




/*
 * 初始化链表，生成头结点
 *
 */
ListNode* InitLinkList()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	pHead->value = -1;
	pHead->next = NULL;
	return pHead;
}


/*
 * 尾部添加节点
 *
 */
void AddToTail(ListNode ** pHead, int value)
{
	ListNode* pNew = (ListNode* )malloc(NODE_LEN);
	pNew->value = value;
	pNew->next = NULL;

	if(NULL == pHead || NULL == *pHead)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;

		while(pNode->next != NULL)
			pNode = pNode->next;

		pNode->next = pNew;
	}
}



/*
 * 删除一个节点
 *
 */
void RemoveNode(ListNode** pHead, int value)
{
	if(NULL == pHead || NULL == *pHead)
	{
		return;
	}

	ListNode* pToDel = NULL;
	if((*pHead)->value == value)
	{
		pToDel = *pHead;
		*pHead = (*pHead)->next;
		free(pToDel);
		pToDel = NULL;
	}
	else
	{
		ListNode* pNode = *pHead;
		while(pNode->next != NULL && pNode->next->value != value)
			pNode = pNode->next;

		if(pNode->next != NULL && pNode->next->value == value)
		{
			pToDel = pNode->next;
			pNode->next = pToDel->next;
		}
		if(NULL != pToDel)
		{
			free(pToDel);
			pToDel = NULL;
		}
	}
}



/*
 * 打印一个链表所有元素
 *
 */
void PrintList(ListNode* pHead, const char* msg)
{
	if(NULL == pHead)
	{
		printf("List is NULL.\n");
		return;
	}

	ListNode* pNode = pHead;
	printf("%s With headnode: ", msg);
	while(pNode->next != NULL)
	{
		printf("%d ", pNode->value);
		pNode = pNode->next;
	}
	printf("%d \n", pNode->value);

}


/*
 * 销毁一个链表
 */
void DestroyLinkList(ListNode *pHead)
{
	if(NULL == pHead)
		return;
	else
	{
		ListNode* pToDel;
		while(pHead->next)
		{
			pToDel = pHead;
			pHead = pHead->next;
			free(pToDel);
		}
		free(pHead);
		pHead = NULL;
		pToDel = NULL;
		
	}
}





