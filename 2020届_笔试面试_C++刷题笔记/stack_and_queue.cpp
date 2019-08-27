#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

/*
stack
stack ��һ������������������ LIFO������ȳ����Ĳ���������Ԫ�ؽ���������һ�˲������ȡ��
�� 1�����죺 atack<int >myStack;
�� 2��ͨ�ò����� empty(), size(),
�� 3�����в����� pop(), push(),top(),
*/
void myStackTest()
{
	cout << "----------this is class stack demo---------------" << endl;
	stack<int >myStack;
	myStack.push(1);
	myStack.push(2);
	myStack.push(3); //Ԫ�ؽ�ջ


	auto top_num = myStack.top(); //ջ��Ԫ��
	cout << "the num of myStack is: " << top_num << endl;
	myStack.pop(); //����ջ��Ԫ��
	int top_num1 = myStack.top();
	cout << "the num of myStack is: " << top_num1 << endl;


	// ����
	while (!myStack.empty())
	{
		cout << "the num of myStack is: " << myStack.top() << endl;
		myStack.pop();
	}

	cout << endl;
	cout << endl;
	cout << endl;
}


/*
queue
queue ��һ�������������������� FIFO�������ȳ����Ĳ���������Ԫ�ز��뵽������һ�˲�����һ����ȡ��
�� 1�����죺 queue<int> myQueue;
�� 2��ͨ�ò����� empty(), size(), front(), back(),
�� 3�����в����� push(), pop(),
*/
void myQueueTest()
{
	cout << "---------------this is class queue demo-----" << endl;
	queue<int > myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(5); //����У���β�����ұߣ�


	queue<int> myQueue2(myQueue);
	while (!myQueue2.empty())
	{
		cout << myQueue2.front() << "  ";
		myQueue2.pop(); // ��ͷ������ߣ�
	}
	cout << endl;


	int front_num = myQueue.front(); //����ͷԪ��
	int back_num = myQueue.back(); //����βԪ��
	printf("the front and back num of the myQueue : %d and %d \n", front_num, back_num);


	myQueue.pop(); //����Ԫ�ز�����Ԫ��
	myQueue.pop();


	int front_num1 = myQueue.front();
	int back_num1 = myQueue.back();
	printf("the front and back num of the myQueue : %d and %d \n", front_num1, back_num1);

}


int main112211(void)
{
	myStackTest();
	myQueueTest();

	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	system("pause");
	return 0;
}