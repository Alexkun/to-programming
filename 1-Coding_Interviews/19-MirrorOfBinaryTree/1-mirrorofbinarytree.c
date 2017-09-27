/*************************************************************************
	> File Name: 1-mirrorofbinarytree.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 四  7/ 6 16:13:20 2017
 ************************************************************************/

#include <stdio.h>
#include "../commons/bintree.h"
#include "../commons/linkstack.h"
#include "../06-ConstructBinaryTree/construct_binary_tree.h"

BinaryTree MirrorOfBTRecurse(BinaryTree pRoot){
	if (NULL == pRoot) return NULL;
	if (NULL == pRoot->pLeft && NULL == pRoot->pRight)
		return pRoot;

	BinaryTreeNode* pNode = pRoot->pLeft;
	pRoot->pLeft = pRoot->pRight;
	pRoot->pRight = pNode;

	MirrorOfBTRecurse(pRoot->pLeft);
	MirrorOfBTRecurse(pRoot->pRight);
	return pRoot;
}

void SwitchLeftAndRight(BinaryTreeNode* pNode){
	if (NULL == pNode) return;
	BinaryTreeNode* tmpNode = pNode->pLeft;
	pNode->pLeft = pNode->pRight;
	pNode->pRight = tmpNode;
}

BinaryTree MirrorOfBTIterator(BinaryTree pRoot){
	if (NULL == pRoot) return NULL;
	if (NULL == pRoot->pLeft && NULL == pRoot->pRight)
		return pRoot;

	BinaryTreeNode* pNode = NULL;
	VoidLinkStack stack = InitVLS();
	pNode = pRoot;
	while (pNode || !VLSIsEmpty(stack)){

		while (pNode){
			SwitchLeftAndRight(pNode);
			VLSPush(stack, pNode);
			pNode = pNode->pLeft;
		}

		if (!VLSIsEmpty(stack)){
			pNode = (BinaryTreeNode*) VLSPop(stack);
			pNode = pNode->pRight;
		}



	}
	return pRoot;
	
}


int main(){
	int preOrder[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};
	BinaryTree pRoot = ConstructPreAndIn(preOrder, inOrder, 8);

	printf("\nPre print tree iteration.\n");
	PrePrintBinaryTreeIteration(pRoot);


	printf("After Recurse mirror, pre print tree iteration.\n");
	MirrorOfBTRecurse(pRoot);
	PrePrintBinaryTreeIteration(pRoot);

	printf("After Iteration mirror, the tree should be same as original. Pre print tree iteration.\n");
	MirrorOfBTIterator(pRoot);
	PrePrintBinaryTreeIteration(pRoot);

	DestroyBinaryTree(pRoot);
	return 0;
}

