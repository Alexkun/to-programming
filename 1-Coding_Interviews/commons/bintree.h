/*************************************************************************
	> File Name: bintree.h
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 二  6/20 16:55:47 2017
 ************************************************************************/
#pragma once
#include "common.h"

typedef struct BinaryTreeNode
{
	TreeElementType value;
	struct BinaryTreeNode* pLeft;
	struct BinaryTreeNode* pRight;
}BinaryTreeNode, *BinaryTree;


/*
 * 初始化树
 */
BinaryTreeNode* InitBinTree(TreeElementType v);

/*
 * 添加节点
 */




