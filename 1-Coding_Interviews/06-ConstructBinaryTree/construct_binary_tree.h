/*   construct_binary_tree.h   */

#include "../commons/bintree.h"
#include "../commons/linkstack.h"

// 要先申明
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, 
								int* startInorder, int* endInorder);


/*
 * 通过二叉树前中序遍历数组构建二叉树
 */
BinaryTreeNode* ConstructPreAndIn(int* preorder, int* inorder, int length);


BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, 
								int* startInorder, int* endInorder);


/*
 * 递归打印二叉树(先序遍历)
 */
void PrePrintBinaryTreeRecursive(BinaryTreeNode* root);


/*
 * 迭代打印二叉树（先序遍历）
 */
bool isContain(int arr[], int length, int element);


void PrePrintBinaryTreeIteration(BinaryTreeNode* root);



/*
 * 迭代打印二叉树（中序遍历）
 */
void MidPrintBinaryTreeIteration(BinaryTree root);


/*
 * 迭代打印二叉树（后序遍历）
 */
void AftPrintBinaryTreeIteration(BinaryTree root);


/*
 * 销毁一颗树
 * 方法：递归遍历并删除节点
 */
void DestroyBinaryTree(BinaryTree root);




