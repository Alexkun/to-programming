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
	int length = 1000000; // length最大值不能超过 ARRAY_SIZE_HUGE 约 100W多
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
	// printf("Before Partition, low=%d, high=%d\n", low, high);
	// PrintArray(arr, 10);


	int pivotkey = arr[low];
	while(low < high)
	{
		while(low < high && arr[high] >= pivotkey)
		{
			high--;
		}
		Swap(arr, low, high);
		while(low < high && arr[low] <= pivotkey)
		{
			low++;
		}
		Swap(arr, low, high);
	}

	////
	// printf("After Partition, pivot=%d\n", low);
	// PrintArray(arr, 10);

	return low;
}


void Swap(int arr[], int in_a, int in_b)
{
	// arr[in_a] = arr[in_a] + arr[in_b]; // 这样写有时候会出现以外bug
	// arr[in_b] = arr[in_a] - arr[in_b];
	// arr[in_a] = arr[in_a] - arr[in_b];
	int tmp = arr[in_a];
	arr[in_a] = arr[in_b];
	arr[in_b] = tmp;
}

void PrintArray(int arr[], int length)
{
	for(int i = 0; i < length; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
