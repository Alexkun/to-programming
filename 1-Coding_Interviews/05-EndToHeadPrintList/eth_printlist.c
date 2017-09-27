/*************************************************************************
	> File Name: eth_printlist.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 二  6/20 11:01:42 2017
 ************************************************************************/

#include <stdio.h>
#include "../commons/list.h"
#include "../commons/linkstack.h"
#include <stdlib.h>



void Reverse_PrintList(ListNode *pHead)
{
	LinkStack *stack = InitLinkStack();
	if(NULL != pHead)
	{
		ListNode *pNode = pHead;
		while(pNode->next)
		{
			pNode = pNode->next;
			Push(stack, pNode->value);
		}
		PrintLinkStack(stack);
	}
}

void ReversePrintList_Recursiveluy(ListNode* pHead)
{

	if(NULL == pHead)
		return;
	else if(pHead->next == NULL)
	{
		printf("%d ", pHead->value);
	}
	else
	{
		ReversePrintList_Recursiveluy(pHead->next);
		printf("%d ", pHead->value);
	}
}

int main()
{
	// 0，初始化链表
	ListNode *pHead = InitLinkList();
	AddToTail(&pHead, 1);
	AddToTail(&pHead, 2);
	AddToTail(&pHead, 3);

	// 1，反转打印
	Reverse_PrintList(pHead);

    // 2，递归打印链表
    printf("\n递归打印链表：\n");
    ReversePrintList_Recursiveluy(pHead);

    DestroyLinkList(pHead);
	return 0;
}



