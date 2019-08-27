#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
����������ʵ�� ջ��
һ��data���ݶ��С�һ��help�������С�
*/

class TwoQueuesStack 
{
	public: void push(int pushInt) 
	{
		data.push(pushInt);
	}

	public: int top() 
	{
		if (data.empty()) {
			cout << ("The init size is less than 0") << endl;
			return -1;
		}
		while (data.size() > 1) 
		{
			help.push(data.front());
			data.pop();
		}
		int temp = data.front(); // data��ֻʣ��������Ԫ�أ�������ȳ���
		data.pop();
		help.push(temp);
		data.swap(help); // ���������ڵ�Ԫ�ؽ��н���
		return temp;
	}

	public: void pop() 
	{
		if (data.empty()) 
		{
			cout << ("The init size is less than 0") << endl;
			return;
		}
		while (data.size() > 1) 
		{
			help.push(data.front());
			data.pop();
		}
		data.pop(); // data��ֻʣ��������Ԫ�أ�������ȳ���
		data.swap(help); // ���������ڵ�Ԫ�ؽ��н���
	}
private: queue<int> data;
private: queue<int> help;
};

int main151000012(void)
{
	TwoQueuesStack stack;
	for (int i = 0; i < 5; i++)
	{
		stack.push(i + 1);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << stack.top() << "  ";
		stack.pop();
	}
	cout << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}