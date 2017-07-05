#include <stdio.h>
#include "../commons/common.h"
#include <stdlib.h>
#include <time.h>

void QuickSort(int arr[], int low, int high);
int Partition();
void Swap(int arr[], int in_a, int in_b);
void PrintArray(int arr[], int length);


int main()
{
	int arr[ARRAY_SIZE_HUGE] = {0};
	int length = 10; // length最大值不能超过 ARRAY_SIZE_HUGE 约 100W多
	int i = 0;
	srand(time(0));
	for(i= 1; i < length; i++) // 注意：下标从1开始
	{
		arr[i] = rand()%length; // 生成0~100W的数字
	}

	// printf("Inited nums:\n");
	// for(i = 0; i < length; i++)
	// {
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n");

	QuickSort(arr, 1, length );

	// printf("After sort, nums:\n");
	// for(i = 0; i < length; i++)
	// {
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n");
}

// 数组从1开始，0为备份位
void QuickSort(int arr[], int low, int high)
{
	int pivot = 0;
	if(low < high)
	{
		pivot = Partition(arr, low, high);

		QuickSort(arr, low, pivot - 1);
		QuickSort(arr, pivot + 1, high);
	}	
}

int Partition(int arr[], int low, int high)
{

	////
	printf("Before Partition, low=%d, high=%d\n", low, high);
	PrintArray(arr, 10);

	/**********************
	 * 优化1:  pivotkey值的选取，采用三数取中法
	 */
	int m = low + (high - low) / 2; // 计算中间元素的下标
	if(arr[low] > arr[high])
	{
		Swap(arr, low, high);
	}
	if(arr[m] > arr[high])
	{
		Swap(arr, m, high);
	}
	if(arr[m] > arr[low])  // 保证中间值交换到左边
	{
		Swap(arr, low, m);
	}

	int pivotkey = arr[low];


	/*
	 * 优化1完毕
	 ********************/

	arr[0] = pivotkey;     /* 优化2：排序算法过程优化  */
	while(low < high)
	{
		while(low < high && arr[high] >= pivotkey)
		{
			high--;
		}
		arr[low] = arr[high];
		while(low < high && arr[low] <= pivotkey)
		{
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = arr[0];

	////
	printf("After Partition, pivot=%d\n", low);
	PrintArray(arr, 10);

	return low;
}


void Swap(int arr[], int in_a, int in_b)
{
	// arr[in_a] = arr[in_a] + arr[in_b]; // 这样写有时候会出现以外的bug
	// arr[in_b] = arr[in_a] - arr[in_b];
	// arr[in_a] = arr[in_a] - arr[in_b];
	int tmp = arr[in_a];
	arr[in_a] = arr[in_b];
	arr[in_b] = tmp;
}

// 注：从下标1开始打印
void PrintArray(int arr[], int length)
{
	for(int i = 1; i <= length; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}



