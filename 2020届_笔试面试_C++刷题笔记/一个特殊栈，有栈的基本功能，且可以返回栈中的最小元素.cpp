#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

/*
ʵ��һ������ջ����ջ�Ļ������ܣ��ҿ��Է���ջ�е���СԪ��

˼·������ջͬʱʹ�ã�һ��ջ����ʹ�ã�һ��Minջ��ֻѹ�뵱ǰ����ջ�е���СԪ�ء�
*/

class MyStack_getMin
{

public:
	void push(int newNum) 
	{
		stackData.push(newNum);
		if (stackMin.empty()) {
			stackMin.push(newNum);
		}
		else 
		{
			stackMin.push(newNum <= getmin() ? newNum : getmin());
		}
	}

public:
	void pop() 
	{
		if (stackData.empty()) {
			cout << ("Your stack is empty.") << endl;
			return;
		}
		stackData.pop();
		stackMin.pop();
	}

public:
	int top()
	{
		if (stackData.empty()) {
			cout << ("Your stack is empty.") << endl;
			return -1;
		}
		return stackData.top();
	}

public:
	int getmin() 
	{
		if (stackMin.empty()) 
		{
			cout << ("Your stack is empty.") << endl;
			return -1;
		}
		return stackMin.top();
	}

public:
	int getSize()
	{
		if (stackData.empty())
		{
			cout << ("Your stack is empty.") << endl;
			return -1;
		}
		return stackData.size();
	}

private:
	stack<int> stackData;
	stack<int> stackMin;
};

int main123123141(void)
{
	MyStack_getMin stack1;
	
	stack1.push(5);
	stack1.push(1);
	stack1.push(3);
	stack1.push(7);
	stack1.push(0);
	stack1.push(2);
	stack1.push(5);

	cout << "Ŀǰջ��Ԫ��:\t" << "Ŀǰջ��Ԫ�ظ�����\t" << "Ŀǰջ��Ԫ����Сֵ��\t" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << stack1.top() << "  \t\t";
		cout << stack1.getSize() << "  \t\t\t";
		cout << "Min = " << stack1.getmin() << endl;
		stack1.pop();
	}
	cout << endl;

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}