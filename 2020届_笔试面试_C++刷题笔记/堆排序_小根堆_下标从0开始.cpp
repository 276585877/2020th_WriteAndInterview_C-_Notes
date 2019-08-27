#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//������ĺ����ǽ���,�������Ϊ���飬���ڵ�λ�ã����鳤��

// ������ӡ
static void prinft_array(int * array, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "array[" << i << "]:" << array[i] << endl;
	}
}

static void swap(int * array, int x, int y)
{
	int temp = 0;
	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

// ���Դ�һ���յĴ���ѿ�ʼ���������,index��0��ʼ��
void minHeap_build_0(int *array, int index)
{
	while (array[index] < array[(index - 1) / 2]) // ����λ�õ�ֵ���丸�ڵ��ֵ���򽻻�����ֵ��������ѭ����
	{	// (0-1)/2 = 0�����������жϣ�array[0] > array[0] ?  ����ѭ��
		swap(array, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}
void minheapify_0(int *array, int root, int heapSize)
{
	int child = root * 2 + 1;
	while (child < heapSize) // ���Ӵ���
	{
		if (child + 1 < heapSize) // �Һ��Ӵ���
		{
			child = array[child + 1] < array[child] ? (child + 1) : child;
		}

		if (array[root] <= array[child])
		{
			break;
		}
		swap(array, child, root);
		root = child;
		child = root * 2 + 1;
	}
}
void minheapSort_0(int *array, const int len)
{
	if (array == nullptr || len < 2)
	{
		return;
	}
	// ��������ѣ����±�0��ʼ��
	for (int i = 0; i < len; i++)
	{
		minHeap_build_0(array, i);
	}
	// ����������
	int size = len;
	swap(array, 0, --size); // ������һ���ڵ�����һ���ڵ�
	while (size > 0)
	{
		minheapify_0(array, 0, size); // size�����Ǽ�ȥ��1��ģ������൱��ĩβ��Ԫ�ر������ˡ�
		swap(array, 0, --size);
	}
}



int main2342342343(void)
{
	int array[] = { 90, 50, 60, 20, 70, 30, 40, 80, 10 };
	int rightArray[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int len = sizeof(array) / sizeof(array[0]);
	cout << "����֮ǰ" << endl;
	prinft_array(array, len);
	//����
	minheapSort_0(array, len);
	cout << "����֮��" << endl;
	prinft_array(array, len);
	reverse(array, array + len);
	//sort(array, array + len);
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] != rightArray[i])
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "\n����ɹ���\n" << endl;
	}
	else
	{
		cout << "\n����ʧ�ܣ�\n" << endl;
	}

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}