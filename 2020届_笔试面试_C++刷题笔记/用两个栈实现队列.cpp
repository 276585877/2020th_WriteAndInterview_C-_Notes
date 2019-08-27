#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

/***************************************
��Ŀ����
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
��˼·����

***************************************/
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.size() != 0) // �Ƚ�stack2�е�ֵ��գ���Ϊ���ǿ϶����Ƚ����еġ�
		{
			int tmp = stack2.top();
			stack2.pop();
			return tmp;
		}
		else // stack2����ˣ�������stack1�е����ݵ���stack2
		{
			while (stack1.size() != 0) // ��stack_push����stack_pop�Ĺ���
			{
				int tmp = stack1.top();
				stack1.pop();
				stack2.push(tmp);
			}
			return pop(); // ������һ��stack2��ջ����
		}
	}

private:
	stack<int> stack1; // pushջ��ֻ�����
	stack<int> stack2; // popջ��ֻ����
};

int main_����ջʵ�ֶ���(void)
{
	Solution myqueue;

	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}