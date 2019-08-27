#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

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

static void sort(int* array, int len) {
	for (int i = 0; i < len - 1; i++)
	{
		int index = 0;
		for (int j = 0; j < len - i; j++)
		{
			if (array[j] > array[index])
			{
				index = j;
			}
		}
		swap(array, 0, index); // ֻ����0λ����ĳ��λ�ý���
		swap(array, 0, len - i - 1); // ֻ����0λ����ĳ��λ�ý���
	}
}

int main0124541_1052(void)
{
	int array[] = { 5, 8, 6, 2, 7, 3, 4, 0, 1 };
	int rightArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int len = sizeof(array) / sizeof(array[0]);

	cout << "����֮ǰ" << endl;
	prinft_array(array, len);
	//����
	sort(array, len);//���ⲿ�ļ�#include "ѡ������.h"��
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
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}