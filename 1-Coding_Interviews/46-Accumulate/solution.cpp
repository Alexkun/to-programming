/*************************************************************************
	> File Name: solution.cpp
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 三  9/13 21:21:21 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
	public:
		Solution() {
			++N; Sum += N;
		}

		static void Reset() {
			N = 0; Sum = 0;
		}

		static unsigned int GetSum() {
			return Sum;
		}

	private:
		static unsigned int N;
		static unsigned int Sum;
};

unsigned int Solution::N = 0;
unsigned int Solution::Sum = 0;

unsigned int Sum_Solution1(unsigned int n)
{
	Solution::Reset();

	Solution *s = new Solution[n];
	delete []s;
	s = NULL;

	return Solution::GetSum();

}

int main()
{

	cout<<Sum_Solution1(10)<<endl;
}


