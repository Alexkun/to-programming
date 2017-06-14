/*************************************************************************
	> File Name: find.c
	> Author: Y.K.Young
	> Mail: as86yks@163.com 
	> Created Time: 三  6/14 10:03:26 2017
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>
#include "../commons/common.h"

/*
 * 查找二维矩阵matrix中是否包含一个数
 * 二维矩阵matrix示例
 *	1 2 8 9
 *	2 4 9 12
 *	4 7 10 13
 *	6 8 11 15
 * 注意：二维数组矩阵传过来需要指定列数；也可用一维数组传参
 */

bool Find(int matrix[][MAX_COL], int rows, int columns, int number)
{
	// 0，边界值检查
	if(NULL==matrix || rows<=0 || columns<=0 )
	{
		return false;
	}

	// 1，查找过程
	int row = 0;
	int col = columns - 1;
	bool find = false;
	while(row<=rows-1 && col>=0 && !find)
	{
		if(number == matrix[row][col])
		{
			find = true;
			break;
		}
		else if(number < matrix[row][col])
		{
			col--;
		}
		else {
			row++;
		}
	}
	return find;
}

/*
 * 查找一维数组matrix中是否含有数字numnber
 * 其中一维数组存储的是矩阵
 * 
 */
bool FindEx(int matrix[], int rows, int columns, int number)
{
	//0, 边界值检查
	if(NULL==matrix || rows<=0 || columns>=0)
	{
		return false;
	}

	//1, 查找数字
	int row = 0;
	int col = columns - 1;
	bool find = false;
	while(row<=rows-1 && col>=0)
	{
		if(number == matrix[row * columns + col])
		{
			find = true;
			break;
		}
		else if(number < matrix[row * columns + col])
			-- col;
		else
			++ row;
	}
	return find;
}


int main()
{
	setlocale(LC_CTYPE, "");
	int row = 0;
	int col = 0;
	int number = 0;
	int matrix[MAX_ROW][MAX_COL] = {0};
	int i, j;
	wprintf(L"请输入矩阵行数和列数，空格隔开：\n");
	scanf("%d %d", &row, &col);
	if(col > 0 && row > 0)
	{
		wprintf(L"请输入矩阵，空格隔开：\n");
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < col; j++)
			{
				scanf("%d", &matrix[i][j]);
				printf("matrix[%d][%d]=%d\n", i, j, matrix[i][j]);
			}
		}
	}
	wprintf(L"请输入要查找的数字：\n");
	scanf("%d", &number);
	printf("%d\n", Find(matrix, row, col, number));

	return 0;
}
