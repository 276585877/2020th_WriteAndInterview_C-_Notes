#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
��������⣺��һ�������У������������ұ�������������������һ������ԣ����ӡ��������ԡ�

˼·����С���������ƣ�ʹ�����ƹ鲢������㷨��

����Ե����˼·�͹鲢������񣬳���д��������������
�������⣺��ԭ���зֽ�ɾ����ܳ�����ȵ�����������
�ݹ���̣�ͳ���������к��������е������
�ϲ����⣺ͳ�����������кϲ���������
*/

static int merge(vector<int> &array, int L, int mid, int R)
{
	int *help = new int[R - L + 1];
	int p1 = L;
	int p2 = mid + 1;
	int i = 0;
	int ret = 0;
	while (p1 <= mid && p2 <= R)
	{
		ret += array[p1] > array[p2] ? (mid - p1 + 1) : 0;
		if (array[p1] > array[p2]) // ��ӡ�����
		{
			for (int j = p1; j <= mid; ++j)
			{
				cout << "(" << array[j] << "," << array[p2] << ")" << endl;
			}
		}
		help[i++] = array[p1] <= array[p2] ? array[p1++] : array[p2++];
	}
	while (p1 <= mid)
	{
		help[i++] = array[p1++];
	}
	while (p2 <= R)
	{
		help[i++] = array[p2++];
	}

	for (int j = 0; j < i; ++j)
	{
		array[L + j] = help[j];
	}

	delete[]help;
	help = nullptr;
	//cout << "ret : " << ret << endl;
	//cout << endl;
	return ret;
}

static int mergeSort(vector<int> &array, int L, int R)
{
	if (L >= R)
	{
		return 0;
	}
	int mid = L + ((R - L) / 2);
	return (mergeSort(array, L, mid)     //�����������е�����Ը���
		+ mergeSort(array, mid + 1, R)	 //�Ҳ���������е�����Ը���
		+ merge(array, L, mid, R));		 //�ϲ������е�����Ը���
}
static int reversePair(vector<int> &array)
{
	if (array.size() < 2)
	{
		return 0;
	}
	return mergeSort(array, 0, array.size() - 1);
}


int main2111525231(void)
{
	//vector<int> array = { 3,1,4,5,2 };
	vector<int> array = { -1, 3, 3, 5, 5, 41, 5435, -11, 3423, 4432, -4421, 34432 };

	int sum = reversePair(array);
	cout << "����Ը���Ϊ��sum = " << sum << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}