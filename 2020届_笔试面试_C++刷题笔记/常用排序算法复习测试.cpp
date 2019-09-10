#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// ������ӡ
static void prinft_array(vector<int> &array, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "array[" << i << "]:" << array[i] << endl;
	}
}

static void swap(vector<int> &array, int x, int y)
{
	int temp = 0;
	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

// ѡ��
//static void Sort(vector<int> &array, const int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		int minIndex = i;
//		int j = i + 1;
//		for ( ; j < len; j++)
//		{
//			if (array[minIndex] >= array[j])
//			{
//				minIndex = j;
//			}
//		}
//		if (minIndex != i)
//		{
//			swap(array, i, minIndex);
//		}
//	}
//
//}

// ð�ݷ�
//static void Sort(vector<int> &array, const int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		bool flag = true;
//		for (int j = 0; j < len - i - 1; j++)
//		{
//			if (array[j] > array[j + 1])
//			{
//				flag = false;
//				swap(array, j, j + 1);
//			}
//		}
//		if (flag == true)
//		{
//			return;
//		}
//	}
//}

// ���뷨
//static void Sort(vector<int> &array, const int len)
//{
//	for (int i = 1; i < len; i++)
//	{
//		int temp = array[i];
//		int j = i - 1;
//		for ( ; j >= 0; j--)
//		{
//			if (array[j] > temp)
//			{
//				array[j + 1] = array[j];
//			}
//			else
//			{
//				break;
//			}
//		}
//		array[j + 1] = temp;
//	}
//}

// �鲢������
//static void Merge(vector<int> &array, int L, int midPos, int R)
//{
//	int p1 = L;
//	int p2 = midPos + 1;
//	int i = 0;
//	vector<int> help(R - L + 1);
//	while (p1 <= midPos && p2 <= R)
//	{
//		help[i++] = array[p1] < array[p2] ? array[p1++] : array[p2++];
//	}
//	while (p1 <= midPos)
//	{
//		help[i++] = array[p1++];
//	}
//	while (p2 <= R)
//	{
//		help[i++] = array[p2++];
//	}
//
//	for (int j = 0; j < i; j++)
//	{
//		array[j + L] = help[j];
//	}
//}
//static void MergeSort(vector<int> &array, int L, int R)
//{
//	if (L >= R)
//	{
//		return;
//	}
//	int midPos = L + (R - L) / 2;
//	MergeSort(array, 0, midPos);
//	MergeSort(array, midPos + 1, R);
//	Merge(array, 0, midPos, R);
//}
//static void Sort(vector<int> &array, const int len)
//{
//	if (len <= 1)
//	{
//		return;
//	}
//	MergeSort(array, 0, len - 1);
//}

// ��������
//static int * partition(vector<int> &array, int L, int R)
//{
//	int lessRange = L - 1;
//	int bigRange = R + 1;
//	int key = array[R];
//	while (L < bigRange)
//	{
//		if (array[L] < key)
//		{
//			swap(array, L++, ++lessRange);
//		}
//		else if (array[L] > key)
//		{
//			swap(array, L, --bigRange);
//		}
//		else
//		{
//			L++;
//		}
//	}
//	int * help = new int[2];
//	help[0] = lessRange;
//	help[1] = bigRange;
//	return help;
//}
//static void Quicksort(vector<int> &array, int L, int R)
//{
//	if (L >= R)
//	{
//		return;
//	}
//	int *help = nullptr;
//	help = partition(array, L, R);
//	Quicksort(array, L, help[0]);
//	Quicksort(array, help[1], R);
//	if (help != nullptr)
//	{
//		delete help;
//		help = nullptr;
//	}
//}
//static void Sort(vector<int> &array, const int len)
//{
//	if (len <= 1)
//	{
//		return;
//	}
//	Quicksort(array, 0, len - 1);
//}

// ϣ�������㷨
static void Sort(vector<int> &array, const int len)
{
	if (len <= 1)
	{
		return;
	}
	int gap = len;
	do 
	{
		gap = gap / 3 + 1;// gap ���϶�����1
		for (int i = gap; i < len; i += gap)
		{
			int temp = array[i];
			int j = i - gap;
			for ( ; j >= 0; j -= gap)
			{
				if (array[j] > temp)
				{
					array[j + gap] = array[j];
				}
				else
				{
					break;
				}
			}
			array[j + gap] = temp;
		}
	} while (gap > 1);
}

int main_��������(void) // main_��������
{
	vector<int> array = { 90, 50, 60, 20, 70, 30, 40, 80, 10 };
	vector<int> rightArray = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int len = array.size();

	cout << "����֮ǰ" << endl;
	prinft_array(array, len);
	//����
	Sort(array, len);//���ⲿ�ļ�#include "ѡ������.h"��
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