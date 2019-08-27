#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
/*
����˼�룺��������λ���и�ɲ�ͬ�����֣�Ȼ��ÿ��λ���ֱ�Ƚϡ�
���������������д��Ƚ���ֵͳһΪͬ������λ���ȣ���λ�϶̵���ǰ�油�㡣
Ȼ�󣬴����λ��ʼ�����ν���һ���������������λ����һֱ�����λ��������Ժ�, ���оͱ��һ���������С�
1. ���ո�λ����������
2. ����ʮλ����������
3. ���հ�λ����������
......
*/

// ��ӡ��ά����vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
}


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

// ������������Ԫ�ص�������ݵ�λ��,�����������
int maxbits(int *arr, const int len) 
{
	int maxNum = INT_MIN;
	for (int i = 0; i < len; i++) 
	{
		maxNum = max(maxNum, arr[i]);
	}
	int res = 0;
	while (maxNum != 0) 
	{
		res++;
		maxNum /= 10;
	}
	return res;
}
//void radixSort(int *array, int len) //��������
//{
//	const int radix = 10;
//	int bitNum = maxbits(array, len);
//	int *bucket = new int[len];
//	int count[radix]; //������
//	int i, j, k;
//	int basic = 1;
//	for (i = 1; i <= bitNum; i++) //����d������
//	{
//		for (j = 0; j < radix; j++)
//		{
//			count[j] = 0; //ÿ�η���ǰ��ռ�����
//		}
//		for (j = 0; j < len; j++) // ������Ԫ�صĵ�iλ����Ͱ����
//		{
//			k = (array[j] / basic) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
//			count[k]++;
//		}
//		for (j = 1; j < radix; j++) 
//		{
//			count[j] = count[j - 1] + count[j]; //��count�е�λ�����η����ÿ��Ͱ
//		}
//		for (j = len - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
//		{
//			k = (array[j] / basic) % 10;
//			bucket[count[k] - 1] = array[j];
//			count[k]--;
//		}
//		for (j = 0; j < len; j++) //����ʱ��������ݸ��Ƶ�array��
//		{
//			array[j] = bucket[j];
//		}
//		basic = basic * 10;
//	}
//}
void radixSort_2(int *array, int len) //��������
{
	const int radix = 10;
	int basic = 1;
	int bitNum = maxbits(array, len);
	vector<vector<int>> bucket(radix);
	int i, j, k;
	for (i = 1; i <= bitNum; ++i)
	{
		for (j = 0; j < bucket.size(); ++j)
		{
			bucket[j].clear();
		}
		for (j = 0; j < len; ++j)
		{
			k = (array[j] / basic) % 10;
			bucket[k].push_back(array[j]);
		}

		int index = 0;
		for (j = 0; j < bucket.size(); ++j)
		{
			for (k = 0; k < bucket[j].size(); ++k)
			{
				array[index++] = bucket[j][k];
			}
		}

		basic *= 10;
	}
}

//void radixSort_2(int *array, int len) //��������
//{
//	const int radix = 10;
//	int bitNum = maxbits(array, len);
//	vector<vector<int>> bucket(radix);
//	int i, j, k;
//	int basic = 1;
//	for (i = 1; i <= bitNum; i++) //����d������
//	{
//		for (j = 0; j < radix; j++)
//		{
//			bucket[j].clear(); //ÿ�η���ǰ��ռ�����
//		}
//		for (j = 0; j < len; j++) // ������Ԫ�صĵ�iλ����Ͱ����
//		{
//			k = (array[j] / basic) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
//			bucket[k].push_back(array[j]);
//		}
//		int index = 0;
//		for (j = 0; j < radix; j++)
//		{
//			for (k = 0; k < bucket[j].size(); k++)
//			{
//				array[index++] = bucket[j][k];
//			}
//		}
//		basic = basic * 10;
//	}
//}


int main122311123(void)
{
	int array[] = { 92, 50, 60, 23, 70, 35, 40, 88, 10 };
	int rightArray[] = { 10, 23, 35, 40, 50, 60, 70, 88, 92 };
	int len = sizeof(array) / sizeof(array[0]);

	cout << "����֮ǰ" << endl;
	prinft_array(array, len);

	//����
	radixSort_2(array, len);

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