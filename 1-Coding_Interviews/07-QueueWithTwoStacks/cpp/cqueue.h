#include <iostream>
#include <stack>
#include <exception>
using namespace std;

template <typename T>
class CQueue
{
public:

	
	void appendTail(const T & element)
	{
		while(!stack2.empty())
		{
			T& data = stack2.top();
			stack2.pop();
			stack1.push(data);
		}

		stack1.push(element);
	}

	T deleteHead() throw(std::logic_error)
	{
		int num = stack1.size() - 1;
		
		for(int i = 0; i < num; i++)
		{
			T & data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}

		if(stack1.size() == 1)
		{
			T & data = stack1.top();
			stack1.pop();
			return data;
		}
		else if(stack2.size() > 0)
		{
			T & data = stack2.top();
			stack2.pop();
			return data;
		}
		else 
		{
			throw new logic_error("Queue is empty.");
		}
	}

	bool empty()
	{
		return stack1.empty() && stack2.empty();
	}

private:
	stack<T> stack1;
	stack<T> stack2;
};

