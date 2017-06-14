/*************************************************************************
	> File Name: replace_blank.c
	> Author: Y.K.Young
	> Mail: as86yks@163.com 
	> Created Time: 三  6/14 11:32:24 2017
 ************************************************************************/

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include "../commons/common.h"
#include "../commons/io.h"

/* 
 * 将字符串中的空格替换为"%20"
 */
void ReplaceBlank(char string[], int length)
{
	
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
	length = sizeof(str);
	printf("Test output~\n");
	wprintf(L"字符串为：%s\n长度为：%d\n", str, length);
	ReplaceBlank(str, length);
	return 0;

}
