#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;



// ��д���룺����ջʵ��һ������
class Solution
{
public:
	void push(int node) 
	{
		stack_push.push(node);
	}

	int pop() 
	{
		if (stack_pop.size() != 0) 
		{
			int tmp = stack_pop.top();
			stack_pop.pop();
			return tmp;
		}
		else 
		{
			while (stack_push.size() != 0) // ��stack_push����stack_pop�Ĺ���
			{
				int tmp = stack_push.top();
				stack_push.pop();
				stack_pop.push(tmp);
			}
			return pop();
		}
	}

private:
	stack<int> stack_push;// �����
	stack<int> stack_pop;// ������
};


int main1121212131(void)
{
	Solution q;
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	for (size_t i = 0; i < 4; i++)
	{
		cout << q.pop() << "  ";

	}
	cout << endl;
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}