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

// ��������ѣ��±��1��ʼ���±�0λΪ���λ��
void Heap_build_1(int * array, int heapSize)
{
	for (int root = heapSize / 2; root >= 1; --root)
	{
		int rootElement = array[root];
		int child = 2 * root;
		while (child <= heapSize)
		{
			if (child + 1 <= heapSize) // �Һ��Ӵ���
			{
				child = array[child] >= array[child + 1] ? child : (child + 1);
			}
			
			if (rootElement >= array[child])
			{
				break;
			}
			swap(array, child, child / 2);
			child *= 2;
		}
	}
}
void heapify_1(int *array, int root, int heapSize)
{
	int child = root * 2;
	while (child <= heapSize) // ���Ӵ���
	{
		if (child + 1 <= heapSize) // �Һ��Ӵ���
		{
			child = array[child + 1] > array[child] ? (child + 1) : child;
		}

		if (array[root] >= array[child])
		{
			break;
		}
		swap(array, child, root);
		root = child;
		child = root * 2;
	}
}
void heapSort_1(int *array, const int len)
{
	if (array == nullptr || len < 2)
	{
		return;
	}
	// ��������ѣ����±�1��ʼ��
	Heap_build_1(array, len - 1);

	cout << "�����:" << endl;
	prinft_array(array, len);
	cout << endl;

	// ����������
	int size = len;
	swap(array, 1, --size); // ������һ���ڵ�����һ���ڵ�
	while (size > 1)
	{
		heapify_1(array, 1, size - 1); // size�����Ǽ�ȥ��1��ģ������൱��ĩβ��Ԫ�ر������ˡ�
		swap(array, 1, --size);
	}
}



int main04515605(void)
{
	int array[] = { 0, 90, 50, 60, 20, 70, 30, 40, 80, 10 };
	int rightArray[] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int len = sizeof(array) / sizeof(array[0]);
	cout << "����֮ǰ" << endl;
	prinft_array(array, len);
	//����
	heapSort_1(array, len);
	//Heap_sort(array, len);
	cout << "����֮��" << endl;
	prinft_array(array, len);

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