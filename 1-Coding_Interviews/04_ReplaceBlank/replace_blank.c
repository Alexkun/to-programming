/*************************************************************************
	> File Name: replace_blank.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com 
	> Created Time: 三  6/14 11:32:24 2017
 ************************************************************************/

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include "../commons/common.h"
#include "../commons/io.h"

/* 
 * 将字符串中的空格替换为"%20"
 * 思路：1，计算替换后，新增的空间大小；2，从后边的空格开始，往前替换，依次将字符串替换到空格位置；
 * 注意：假定string[]开辟的空间很长，远远超过length
 */
void ReplaceBlank(char string[], int length)
{
	int space[STRING_LENGTH_MEDIUM] = {0};
	int i, j;
	int new_length = 0;
	for(i = 0, j = 0; i < length; i++){
		if(' ' == string[i])
			space[j++] = i;
	}
	new_length = length + 2 * j;
	for(i = length, j = new_length; i >= 0; i--, j--){
		if(' ' == string[i]){
			string[j--] = '0';
			string[j--] = '2';
			string[j] = '%';
		}else{
			string[j] = string[i];
		}
	}
}

int main()
{
	char str[STRING_LENGTH_MEDIUM] = "";
	int length = 0;
	char *line = my_readline("请输入含有空格的字符串：");
	if(NULL != line)
	{
		strcpy(str, line);
	}
	free(line);
	line = NULL;
	length = strlen(str);
	printf("Test output~\n");
	printf("Str=%s\nlength=%d\n", str, length);
	ReplaceBlank(str, length);
	printf("Replaced str=%s\nlength=%lu\n", str, strlen(str));
	return 0;

}
