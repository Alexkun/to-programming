/*************************************************************************
	> File Name: str.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com 
	> Created Time: 三  6/14 18:06:09 2017
 ************************************************************************/

#include<stdio.h>

/*
 * getstrlen - 获取char str[]类型实际字符串长度
 * @param - char str[] - 字符串指针
 * @return - 0: 长度为空；-1 数组满了且最后一个不是'\0'
 */
int getstrlen (char str[])
{
	int length = 0;




	return length;
}



/*
 * 判断int型数组是否含有某元素，并返回第一个下标
 * 返回-1表示不含有该元素
 */
int ArrContainInt(int arr[], int length, int value)
{
	if(NULL == arr || length <= 0)
		return -1;

	for(int i = 0; i < length; i++)
	{
		if(arr[i] == value)
			return i;
	}
	return -1;
}


/*
 * 判断char型数组是否含有某元素，并返回第一个下标
 */
int ArrContainChar(char arr[], int length, char value)
{
	if(NULL == arr || length <= 0)
		return -1;

	for(int i = 0; i < length; i++)
	{
		if(arr[i] == value)
			return i;
	}
	return -1;
}


