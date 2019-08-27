#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Array_to_Queue // ѭ������
{
public:
	Array_to_Queue(int initSize)
	{
		if (initSize < 0)
		{
			cout << ("The init size is less than 0") << endl;
			return;
		}
		capacity = initSize;
		arr = new int[capacity];
		size = 0;
		first = 0;
		last = 0;
	}

public:
	void push(int value)
	{
		if (size == capacity)
		{
			cout << ("The queue is full") << endl;
			return;
		}
		size++;
		arr[last] = value; // �ŵ���β
		last = (last == (capacity - 1)) ? 0 : last + 1; // ��last�Ƿ�������ĩ�ˣ���Ϊ�棬����ؿ�ʼλ��0.
	}

	void pop()
	{
		if (size == 0)
		{
			cout << ("The queue is empty") << endl;
			return;
		}
		size--;
		first = (first == (capacity - 1)) ? 0 : first + 1; // ��first�Ƿ�������ĩ�ˣ���Ϊ�棬����ؿ�ʼλ��0.
	}

	int front()
	{
		if (size == 0)
		{
			cout << ("The queue is empty") << endl;
			return -1;
		}
		return arr[first];
	}

	int getSize()
	{
		return size;
	}
private:
	int *arr = nullptr;
	int first = 0; // ��ͷ
	int last = 0; // ��β
	int size = 0;
	int capacity = 0;

};

int main21215221515555(void)
{
	Array_to_Queue queue(5);
	for (int i = 0; i < 5; i++)
	{
		queue.push(i + 1);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << queue.front() << "  ";
		queue.pop();
		cout << queue.getSize() << endl;
	}
	cout << endl;

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}