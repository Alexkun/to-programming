/*************************************************************************
	> File Name: construct_binary_tree.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 二  6/20 16:39:57 2017
 ************************************************************************/

#include <stdio.h>
#include "../commons/bintree.h"
#include <stdlib.h>
#include "../commons/stack.h"

// 要先申明
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, 
								int* startInorder, int* endInorder);


/*
 * 通过二叉树前中序遍历数组构建二叉树
 */
BinaryTreeNode* ConstructPreAndIn(int* preorder, int* inorder, int length)
{
	if(preorder == NULL || inorder == NULL || length <= 0)
	{
		return NULL;
	}
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}


BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, 
								int* startInorder, int* endInorder)
{
	// 1，前序遍历确定根节点
	BinaryTreeNode* root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	root->value = *startPreorder; // 根节点的值

	////
	printf("startPreorder=%d, endPreorder=%d; startInorder=%d, endInorder=%d\n", *startPreorder, *endPreorder, *startInorder, *endInorder);

	// 2，中序遍历划分子树
	int rootIndex = -1; // 中序遍历数组中的索引值
	int length = endPreorder - startPreorder + 1;
	int i = 0;
	for(i = 0; i < length; i++)
	{
		if(*(startInorder + i) == *(startPreorder + 0))
			rootIndex = i;

	}
	if(-1 == rootIndex) // 中序遍历数组中没找到根节点，除非两个数组不一致，不然不会出错
	{
		fprintf(stderr, "%s\n", "ERROR in finding rootIndex in inorder array.");

		printf("startPreorder=%d, endPreorder=%d; startInorder=%d, endInorder=%d\n", *startPreorder, *endPreorder, *startInorder, *endInorder);


		return NULL;
	}

	if(1 == length) // 数组长度为1
	{
		root->pLeft = NULL;
		root->pRight = NULL;
		return root;
	}
	else
	{
		int leftLength = rootIndex;
		int rightLength = length - rootIndex - 1;
		if(leftLength > 0)
		{
			////
			printf("Before left: leftLength=%d ;", leftLength);

			root->pLeft = ConstructCore(startPreorder + 1, startPreorder + leftLength, 
									startInorder, startInorder + leftLength - 1);
		}
		else
			root->pLeft = NULL;
		if(rightLength > 0)
		{
			////
			printf("Before right: rightLength=%d ;", rightLength);

			root->pRight = ConstructCore(startPreorder + leftLength + 1, startPreorder + length - 1,
									startInorder + leftLength + 1, startInorder + length - 1);
		}
		else
			root->pRight = NULL;

		return root;
	}
}


/*
 * 递归打印二叉树(先序遍历)
 */
void PrePrintBinaryTree(BinaryTreeNode* root)
{
	if(NULL == root)
	{
		return;
	}


	if(NULL != root->pLeft)
	{
		printf("\nroot: %d ", root->value);
		printf(", left: %d ", root->pLeft->value);
		PrintBinaryTree(root->pLeft);
	}
	if(NULL != root->pRight)
	{
		printf("\nroot: %d ", root->value);
		printf(", right: %d ", root->pRight->value);
		PrintBinaryTree(root->pRight);
	}

}

/*
 * 迭代打印二叉树（先序遍历）
 */

void PrePrintBinaryTreeIteration(BinaryTreeNode* root)
{
	if(NULL == root)
		return;

	Stack* stack = InitStack();
	if(!stack)
		fprintf(stderr, "%s\n", "Stack init err.");
	int arr[ARRAY_SIZE_MEDIUM] = {0};

	Push(stack, root->value);
	while(!IsEmpty)
	{
		int value = Pop(stack);

	}

}



int main()
{
	int preOrder[] = {1, 2, 4, 7, 3, 5, 6,8};
	int inOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};
	BinaryTreeNode* root = ConstructPreAndIn(preOrder, inOrder, 8);

	PrePrintBinaryTree(root);
	return 0;
}

