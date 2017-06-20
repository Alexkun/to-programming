/*************************************************************************
	> File Name: io.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com 
	> Created Time: 三  6/14 15:53:39 2017
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "io.h"

/*
 * my_readline - 打印提示语并读取一行内容
 * 参考 知乎-https://www.zhihu.com/question/28794052
 * 用于gcc下不能使用不安全的"gets"函数
 * @param - char* prompt 提示语句的指针
 * @return - char* 返回读取到的内容，用完需要free掉
 */
char *my_readline(const char *prompt)
{
	size_t capacity = 80; /* 初始值 */
	int ch, len = 0;
	char *p = (char*)malloc(capacity);
	if(p == NULL) return NULL;  /* 开辟内存失败 */
	wprintf(L"%s\n", prompt);
	while((ch = getchar()) != '\n' && ch != EOF)
	{
		if(len == capacity)
		{
			char *newp = (char*)realloc(p, capacity*=2);
			if(newp == NULL)
			{
				free(p);
				return NULL;
			}
			p = newp;
		}
		p[len++] = ch;
	}
	p[len] = '\0';
	return p;
}



