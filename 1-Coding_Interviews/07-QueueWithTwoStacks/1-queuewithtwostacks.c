#include <stdio.h>
#include "../commons/stack.h"
#include <stdbool.h>

Stack* s1;
Stack* s2;
bool first = true;

void InitQueue();
bool AppendTail(int element);
int DeleteHead();

int main()
{
	printf("In queue: 1, 2\n");
	AppendTail(1);
	AppendTail(2);
	printf("Out queue:%d\n", DeleteHead());
	printf("In queue: 3, 4, 5.\n");
	AppendTail(3);
	AppendTail(4);
	AppendTail(5);
	printf("Out queue:%d\n", DeleteHead());
	printf("Out queue:%d\n", DeleteHead());
	printf("Out queue:%d\n", DeleteHead());
	printf("Out queue:%d\n", DeleteHead());
	return 0;
}

void InitQueue()
{
	if(first)
	{
		s1 = InitStack();
		s2 = InitStack();
		first = false;
	}
}

bool AppendTail(int element)
{
	if(first) InitQueue();

	// 1，s2不为空，则将所有元素入s1
	while(!IsEmpty(s2))
	{
		Push(s1, Pop(s2));
	}

	// 2，元素入栈
	if(!IsFull(s1))
	{
		return Push(s1, element);
	}
	else
	{
		fprintf(stderr, "Stack s1 is Full.");
		return false;
	}
}


int DeleteHead()
{
	if(first) InitQueue();

	// 1，若s1不为空，则将所有元素入栈s2
	while(!IsEmpty(s1))
	{
		Push(s2, Pop(s1));
	}

	// 2，s2元素出栈
	return Pop(s2);

}





