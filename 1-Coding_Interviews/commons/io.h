/*************************************************************************
	> File Name: io.h
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com 
	> Created Time: 三  6/14 15:46:20 2017
 ************************************************************************/

/*
 * my_readline - 打印提示语并读取一行内容
 * 参考 知乎-https://www.zhihu.com/question/28794052
 * 用于gcc下不能使用不安全的"gets"函数
 * @param - char* prompt 提示语句的指针
 * @return - char* 返回读取到的内容，用完需要free掉
 */
char *my_readline(const char *prompt);


