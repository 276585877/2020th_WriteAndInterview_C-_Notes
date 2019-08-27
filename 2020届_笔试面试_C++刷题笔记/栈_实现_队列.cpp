#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

/*
����ջ��ʵ�ֶ��У�
һ��pushջ��һ��popջ��
�Ƚ�����ȫ��װ��pushջ��ÿ����Ҫ������ʱ���ж�popջ�Ƿ�Ϊ�յģ�
��Ϊ�յģ���pushջ������ȫ������popջ��������popջ��ջ����
����Ϊ�յģ���ֱ�ӵ���popջ��ջ����
*/

class TwoStacksQueue 
{
public: 
	void push(int pushInt) 
	{
		stackPush.push(pushInt);
	}

	public: void pop() {
		if (stackPop.empty() && stackPush.empty()) {
			cout << ("The queue is empty") << endl;
			return;
		}
		else if (stackPop.empty()) { // ��pushջ������ȫ������popջ��������popջ��ջ����
			while (!stackPush.empty()) {
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		stackPop.pop();
	}

	public: int front() {
		if (stackPop.empty() && stackPush.empty()) {
			cout << ("The queue is empty") << endl;
			return -1;
		}
		else if (stackPop.empty()) { // ��pushջ������ȫ������popջ��������popջ��ջ����
			while (!stackPush.empty()) {
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
		return stackPop.top();
	}

private: stack<int> stackPush;
private: stack<int> stackPop;
};


int main2122222221111(void)
{
	TwoStacksQueue queue;
	for (int i = 0; i < 5; i++)
	{
		queue.push(i + 1);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << queue.front() << "  ";
		queue.pop();
	}
	cout << endl;

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}