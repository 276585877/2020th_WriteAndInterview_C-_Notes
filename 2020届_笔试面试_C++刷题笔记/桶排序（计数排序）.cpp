#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>
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

//void bucketSort(int * array, const int len)
//{
//	int maxNum = INT_MIN;
//	for (int i = 0; i < len; ++i)
//	{
//		maxNum = max(maxNum, array[i]);
//	}
//
//	vector<int> bucket;
//	for (int i = 0; i < maxNum + 1; ++i)
//	{
//		// bucket[i] = 0; // �±����޸Ĳ��ǲ���
//		bucket.push_back(0);
//	}
//
//	for (int i = 0; i < len; ++i)
//	{
//		bucket[array[i]]++;
//	}
//
//	// ���򣬽�Ԫ�طŻ�array
//	int i = 0;
//	for (unsigned j = 0; j < bucket.size(); ++j)
//	{
//		for ( ;bucket[j] > 0 ; bucket[j]--)
//		{
//			array[i++] = j;
//		}
//	}
//}

void bucketSort(int *array, int len)
{
	if (array == nullptr || len < 2) 
	{
		return;
	}
	// �ҳ�Ԫ�ص�ȡֵ��Χ[0~n],��Ͱ�ĸ���Ϊn+1.
	int maxNum = INT_MIN;
	for (int i = 0; i < len; i++) 
	{
		maxNum = max(maxNum, array[i]);
	}
	// ����Ͱ����������Ԫ����Ϊ�±��Ͱ���м���
	vector<int> bucket;
	for (int i = 0; i < maxNum + 1; ++i)
	{
		bucket.push_back(0); // ��Ͱ���г�ʼ��
	}
	for (int i = 0; i < len; i++) 
	{
		bucket[array[i]]++;
	}
	// ���򣬽�Ԫ�طŻ�array
	int i = 0;
	for (unsigned j = 0; j < bucket.size(); j++) 
	{
		while (bucket[j]-- > 0) 
		{
			array[i++] = j;
		}
	}
}


int main1112233(void)
{
	int array[] = { 90, 50, 60, 20, 70, 30, 40, 80, 10 };
	int rightArray[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int len = sizeof(array) / sizeof(array[0]);

	cout << "����֮ǰ" << endl;
	prinft_array(array, len);

	//����
	bucketSort(array, len);

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