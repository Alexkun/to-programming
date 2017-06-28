#include <iostream>
using namespace std;

#include "cqueue.h"

int main()
{
	cout<<"Will put in queue: 1,2,3,4"<<endl;
	CQueue<int> queue;
	queue.appendTail(1);
	queue.appendTail(2);
	queue.appendTail(3);
	queue.appendTail(4);
	cout<<"Will remove head twice: "<<endl;
	cout<<queue.deleteHead()<<endl;
	cout<<queue.deleteHead()<<endl;
	cout<<"Will put in queue: 5,6,7,8"<<endl;
	queue.appendTail(5);
	queue.appendTail(6);
	queue.appendTail(7);
	queue.appendTail(8);
	cout<<"Will remove all elements remained."<<endl;
	while(!queue.empty())
	{
		cout<<queue.deleteHead()<<endl;
	}

	return 0;
}
