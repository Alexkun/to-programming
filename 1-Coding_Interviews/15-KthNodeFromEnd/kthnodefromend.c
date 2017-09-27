/*************************************************************************
	> File Name: kthnodefromend.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 四  7/ 6 09:23:34 2017
 ************************************************************************/

#include<stdio.h>
#include "../commons/list.h"
#include <stdlib.h>
#include <time.h>


/*
 * 双指针法查找单链表倒数第K个节点
 * 只需遍历一次即可
 */
ListNode* FindKthFromEnd(ListNode* pHead, unsigned int k){
	if (k <= 0) return NULL;
	if (NULL == pHead || NULL == pHead->next) return NULL;

	ListNode* pFirst = pHead;
	ListNode* pKth = pHead;

	int count = 0;
	while (pFirst->next){
		count++;
		pFirst = pFirst->next;
		if (count >= k){
			pKth = pKth->next;
		}

	}
	if (pKth == pHead)
		return NULL;
	else
		return pKth;
}

int main(){
	srand(time(0));
	ListNode* pHead = InitLinkList();
	int i = 0;
	for (; i < 10; i++){
		AddToTail(&pHead, rand()%100);
	}
	PrintList(pHead, "Origin list=");

	ListNode* pNode = FindKthFromEnd(pHead, 5);
	printf("Last %d node from end is : %d\n", 5, pNode->value);


	return 0;

}


