/*************************************************************************
	> File Name: substructureintree.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 四  7/ 6 15:10:20 2017
 ************************************************************************/

#include<stdio.h>
#include "../commons/bintree.h"
#include <stdbool.h>

bool HaveSubTreeRecurse(BinaryTree pRoot1, BinaryTree pRoot2);
bool DoesTree1HasTree2Recurse(BinaryTree pRoot1, BinaryTree pRoot2);

bool HaveSubTreeRecurse(BinaryTree pRoot1, BinaryTree pRoot2){
	if (NULL == pRoot1 || NULL == pRoot2){
		return false;
	}

	bool result = false;
	if (pRoot1->value == pRoot2->value)
		result = DoesTree1HasTree2Recurse(pRoot1, pRoot2);
	if (!result)
		result = HaveSubTreeRecurse(pRoot1->pLeft, pRoot2);
	if (!result)
		result = HaveSubTreeRecurse(pRoot1->pRight, pRoot2);

	return result;

}



bool DoesTree1HasTree2Recurse(BinaryTree pRoot1, BinaryTree pRoot2){
	if (NULL == pRoot2)
		return true;
	if (NULL == pRoot1)
		return false;
	if (pRoot1->value == pRoot2->value){
		return DoesTree1HasTree2Recurse(pRoot1->pLeft, pRoot2->pLeft) &&
				DoesTree1HasTree2Recurse(pRoot1->pRight, pRoot2->pRight);

	}else
		return false;
}


int main(){

	BinaryTreeNode nodes[10];
	BinaryTree pRoot1 = &nodes[0];
	pRoot1->value = 8;
	pRoot1->pLeft = &nodes[1];
	pRoot1->pRight = &nodes[2];
	nodes[1].value = 8;
	nodes[1].pLeft = &nodes[3];
	nodes[1].pRight = &nodes[4];
	nodes[2].value = 7;
	nodes[2].pLeft = nodes[2].pRight = NULL;
	nodes[3].value = 9;
	nodes[3].pLeft = nodes[3].pRight = NULL;
	nodes[4].value = 2;
	nodes[4].pLeft = &nodes[5];
	nodes[4].pRight = &nodes[6];
	nodes[5].value = 4;
	nodes[6].value = 6;
	nodes[5].pLeft = nodes[5].pRight = nodes[6].pLeft = nodes[6].pRight = NULL;
	BinaryTree pRoot2 = &nodes[7];
	nodes[7].value = 8;
	nodes[7].pLeft = &nodes[8];
	nodes[7].pRight = &nodes[9];
	nodes[8].value = 9;
	nodes[8].pLeft = nodes[8].pRight = NULL;
	nodes[9].value = 9;
	nodes[9].pLeft = nodes[9].pRight = NULL;


	printf("Tree1 has Tree2 ? %d\n", HaveSubTreeRecurse(pRoot1, pRoot2));


}




