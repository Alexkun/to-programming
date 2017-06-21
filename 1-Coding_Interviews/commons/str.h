/*************************************************************************
	> File Name: str.h
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com 
	> Created Time: 三  6/14 18:02:20 2017
 ************************************************************************/


/*
 * getstrlen - 获取char str[]类型实际字符串长度
 * @param - char str[] - 字符串指针
 * @return - 0: 长度为空；-1 数组满了且最后一个不是'\0'
 */
int getstrlen (char str[]);


/*
 * 判断int型数组是否含有某元素，并返回第一个下标
 */
int ArrContainInt(int arr[], int length, int value);


/*
 * 判断char型数组是否含有某元素，并返回第一个下标
 */
int ArrContainChar(char arr[], int length, char value);

