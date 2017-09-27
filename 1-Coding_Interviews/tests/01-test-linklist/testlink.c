/*************************************************************************
	> File Name: testlink.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com 
	> Created Time: 一  6/19 15:20:56 2017
 ************************************************************************/

#include<stdio.h>
#include "../../commons/list.h"

int main()
{
	ListNode* pHead = NULL;
	// 1，添加节点
	AddToTail(&pHead, 1);
	AddToTail(&pHead, 2);
	AddToTail(&pHead, 3);
	AddToTail(&pHead, 4);
	AddToTail(&pHead, 5);
	AddToTail(&pHead, 6);
	AddToTail(&pHead, 7);
	AddToTail(&pHead, 8);
	AddToTail(&pHead, 9);
	PrintList(pHead, "Ori. ");

	// 2，删除节点；
	RemoveNode(&pHead, 6);
	RemoveNode(&pHead, 9);
	PrintList(pHead, "After remove.");

	return 0;
}
