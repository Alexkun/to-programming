/*************************************************************************
	> File Name: construct_binary_tree.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 二  6/20 16:39:57 2017
	> 
 ************************************************************************/

#include <stdio.h>
#include "../commons/bintree.h"
#include <stdlib.h>
#include "../commons/linkstack.h"

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

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//>>>>>>>>>>>>>遍历二叉树
//参考博客园另外解法：
//	http://www.cnblogs.com/dolphin0520/archive/2011/08/25/2153720.html#!comments

/*
 * 递归打印二叉树(先序遍历)
 */
void PrePrintBinaryTreeRecursive(BinaryTreeNode* root)
{
	if(NULL == root)
	{
		return;
	}


	if(NULL != root->pLeft)
	{
		printf("\nroot: %d ", root->value);
		printf(", left: %d ", root->pLeft->value);
		PrePrintBinaryTreeRecursive(root->pLeft);
	}
	if(NULL != root->pRight)
	{
		printf("\nroot: %d ", root->value);
		printf(", right: %d ", root->pRight->value);
		PrePrintBinaryTreeRecursive(root->pRight);
	}

}

/*
 * 迭代打印二叉树（先序遍历）
 */
bool isContain(int arr[], int length, int element)
{
	if(NULL == arr || length <= 0)
	{
		return false;
	}

	int i = 0;
	for(; i < length; i++)
	{
		if(arr[i] == element)
			return true;
	}
	return false;
}

void PrePrintBinaryTreeIteration(BinaryTreeNode* root)
{
	if(NULL == root)
		return;

	VoidLinkStack stack = InitVLS();
	if(!stack)
		fprintf(stderr, "%s\n", "Stack init err.");
	int visit[ARRAY_SIZE_MEDIUM] = {0};
	int length = 0;
	int i;
	bool visited = false;

	visit[length++] = root->value;
	VLSPush(stack, root);
	while(!VLSIsEmpty(stack))
	{
		BinaryTreeNode* node = VLSPeek(stack);
		if(node->pLeft)  // 含有左孩子
		{
			if(!isContain(visit, length, node->pLeft->value)) 
			{ // 左孩子未访问
				visit[length++] = node->pLeft->value;
				VLSPush(stack, node->pLeft);
				continue;
			}
			
		}

		if(node->pRight) // 含有右孩子
		{ 
			if(!isContain(visit, length, node->pRight->value))
			{ // 右孩子未访问
				visit[length++] = node->pRight->value;
				VLSPush(stack, node->pRight);
				continue;
			}
			else
			{
				VLSPop(stack);
				continue;
			}
		}
		VLSPop(stack);

	}
	printf("%s\n", "Pre visit nums: ");
	for(i = 0; i < length; i++)
	{
		printf("%d ", visit[i]);
	}
	printf("\n");

}

/*
 * 迭代打印二叉树（中序遍历）
 */
void MidPrintBinaryTreeIteration(BinaryTree root)
{
	if(NULL == root) return;

	VoidLinkStack stack = InitVLS();
	if(!stack)
	{
		fprintf(stderr, "%s\n", "Stack init err.");
		return;
	}	

	int visit[ARRAY_SIZE_MEDIUM] = {0};
	int length = 0;
	int i;
	bool visited = false;

	VLSPush(stack, root);
	while(!VLSIsEmpty(stack))
	{
		BinaryTreeNode* node = VLSPeek(stack);
		if(node->pLeft)  // 含有左孩子
		{
			if(!isContain(visit, length, node->pLeft->value)) 
			{ // 左孩子未访问
				VLSPush(stack, node->pLeft);
				continue;
			}
			
		}

		visit[length++] = node->value; // 访问当前节点
		node = VLSPop(stack);

		if(node->pRight) // 含有右孩子
		{ 
			if(!isContain(visit, length, node->pRight->value))
			{ // 右孩子未访问
				VLSPush(stack, node->pRight);
				continue;
			}
			
		}

	}
	printf("%s\n", "Mid visit nums: ");
	for(i = 0; i < length; i++)
	{
		printf("%d ", visit[i]);
	}
	printf("\n");
}


/*
 * 迭代打印二叉树（后序遍历）
 */
void AftPrintBinaryTreeIteration(BinaryTree root)
{
	if(NULL == root) return;

	VoidLinkStack stack = InitVLS();
	if(!stack)
	{
		fprintf(stderr, "%s\n", "Stack init err.");
		return;
	}	

	int visit[ARRAY_SIZE_MEDIUM] = {0};
	int length = 0;
	int i;
	bool visited = false;

	VLSPush(stack, root);
	while(!VLSIsEmpty(stack))
	{
		BinaryTreeNode* node = VLSPeek(stack);
		if(node->pLeft)  // 含有左孩子
		{
			if(!isContain(visit, length, node->pLeft->value)) 
			{ // 左孩子未访问
				VLSPush(stack, node->pLeft);
				continue;
			}
			
		}

		if(node->pRight) // 含有右孩子
		{ 
			if(!isContain(visit, length, node->pRight->value))
			{ // 右孩子未访问
				VLSPush(stack, node->pRight);
				continue;
			}
			
		}

		visit[length++] = node->value; // 访问当前节点
		VLSPop(stack);

	}
	printf("%s\n", "Aft visit nums: ");
	for(i = 0; i < length; i++)
	{
		printf("%d ", visit[i]);
	}
	printf("\n");
}


/*
 * 销毁一颗树
 * 方法：递归遍历并删除节点
 */
void DestroyBinaryTree(BinaryTree root)
{
	if(NULL == root)
	{
		return;
	}

	if(NULL != root->pLeft)
	{
		DestroyBinaryTree(root->pLeft);
	}
	if(NULL != root->pRight)
	{
		DestroyBinaryTree(root->pRight);
	}
	printf("del value: %d \n", root->value);
	free(root);
	root = NULL;
	return;
}

/*
int main()
{
	int preOrder[] = {1, 2, 4, 7, 3, 5, 6,8};
	int inOrder[] = {4, 7, 2, 1, 5, 3, 8, 6};
	BinaryTreeNode* root = ConstructPreAndIn(preOrder, inOrder, 8);

	printf("Pre print tree recursive.\n");
	PrePrintBinaryTreeRecursive(root);
	printf("\n");

	printf("\nPre print tree iteration.\n");
	PrePrintBinaryTreeIteration(root);

	printf("\nMid print tree iteration.\n");
	MidPrintBinaryTreeIteration(root);

	printf("\nAft print tree iteration.\n");
	AftPrintBinaryTreeIteration(root);

	DestroyBinaryTree(root);
	root = NULL;
	return 0;
}

*/


