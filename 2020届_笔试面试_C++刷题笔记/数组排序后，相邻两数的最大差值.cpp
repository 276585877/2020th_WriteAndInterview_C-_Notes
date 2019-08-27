#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
����һ�����飬�������������������������ֵ��Ҫ��ʱ�临�Ӷ�O(n)���Ҳ����÷ǻ��ڱȽϵ�����
���磺1 1 3 6 7.   
1��1��ֵΪ0��
1��3��ֵΪ2��
3��6��ֵΪ3��
6��7��ֵΪ1��
������ֵΪ3.

˼·������Ͱ����ĸ������δ����Ͱ����
*/

static int bucket(long num, long len, long min, long max) 
{
	return (int)((num - min) * len / (max - min));
}

static int maxGap(int *array, const int len) 
{
	if (array == nullptr || len < 2) {
		return 0;
	}

	int minValue = INT_MAX;
	int maxValue = INT_MIN;
	for (int i = 0; i < len; i++) // �ҵ������е���Сֵ�����ֵ
	{
		minValue = min(minValue, array[i]);
		maxValue = max(maxValue, array[i]);
	}
	if (minValue == maxValue) // �����е�Ԫ�ض���һ����
	{
		return 0;
	}

	vector<bool> hasNum(len + 1, false); // c c(n,t): c ���� n ����ʼ��Ϊֵ t ��Ԫ��
	vector<int> maxs(len + 1, INT_MIN); // ���������ʼ��Ϊ��Сֵ
	vector<int> mins(len + 1, INT_MAX); // ��С�������ʼ��Ϊ���ֵ
	int bid = 0;
	for (int i = 0; i < len; i++) 
	{
		bid = bucket(array[i], len, minValue, maxValue); // ����Ͱ��ȷ��ĳ���������ڼ���Ͱ��bid��Ͱ�š�
		mins[bid] = hasNum[bid] ? min(mins[bid], array[i]) : array[i];
		maxs[bid] = hasNum[bid] ? max(maxs[bid], array[i]) : array[i];
		hasNum[bid] = true;
	}

	// ��������ң�ÿ����ǰ�ǿ�Ͱ����Сֵ����ǰһ���ǿ�Ͱ�����ֵ֮�������ֵ�������ϸ��¡�
	int res = 0;
	int lastMax = maxs[0]; // ��һ���ǿ�Ͱ�����ֵ��0��Ͱ��Ϊ���������Ԫ�ص���Сֵ�����Ա�Ȼ��Ϊ��Ͱ��
	for (int i = 1; i <= len; i++) // Ͱ���ң���len+1��Ͱ��
	{
		if (hasNum[i]) // �ǿ�Ͱ
		{
			res = max(res, mins[i] - lastMax);
			lastMax = maxs[i];
		}
	}

	return res;
}

int main0122052151(void)
{
	int array[] = { 1,6,5,15,3,4,2 };
	int len = sizeof(array) / sizeof(array[0]);

	cout << "����ֵ��" << maxGap(array, len) << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}