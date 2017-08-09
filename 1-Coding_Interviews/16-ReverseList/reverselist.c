/*************************************************************************
	> File Name: reverselist.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 四  7/ 6 10:03:59 2017
 ************************************************************************/

#include <stdio.h>
#include "../commons/list.h"
#include <stdlib.h>
#include <time.h>

/* 
 * 注意：此链表头结点为有效节点
 */
ListNode* ReverseList(ListNode* pHead){
	if (NULL == pHead) return NULL;
	if (NULL == pHead->next) return pHead;

	ListNode* pFirst = pHead;
	ListNode* pLast = pHead;
	ListNode* pNow = NULL;
	pFirst = pFirst->next;
	pNow = pFirst;
	pLast->next = NULL;
	while (pFirst){
		pFirst = pFirst->next;
		pNow->next = pLast;
		pLast = pNow;
		pNow = pFirst;
	}
	return pLast;

}

int main(){
	srand(time(0));
	ListNode* pHead = NULL;
	int i = 0;
	for (; i < 10; i++){
		AddToTail(&pHead, rand()%100);
	}
	PrintList(pHead, "Origin list ");

	ListNode* pNode = ReverseList(pHead);
	PrintList(pNode, "Reversed list ");


	return 0;

}