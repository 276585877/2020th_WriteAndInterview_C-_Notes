#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
��һ�������У�ÿһ������߱ȵ�ǰ��С�����ۼ�������������������С�͡�
���磺1 3 4 2 5��
1��߱�1С������û��
3��߱�3С������1
4��߱�4С������1��3
2��߱�2С������1
5��߱�5С������1��3��4��2
С�ͣ�1+1+3+1+1+3+4+2 = 16��

��������
ÿ������������߲����αȽϣ�O(n��ƽ��)��

�Ż�������
���ƹ鲢�����Merge���̣�Merge�����м�¼С�Ͳ�����С�͡�
ÿ��Merge���̣��ҵ���������ұ߶��ٸ���С�����¼���Ρ�

С�͵����˼·�͹鲢������񣬳���д��������������
�������⣺��ԭ���зֽ�ɾ����ܳ�����ȵ�����������
�ݹ���̣�ͳ���������к��������е�С��
�ϲ����⣺ͳ�����������кϲ����С��
*/

static int merge(vector<int> &array, int L, int mid, int R)
{
	vector<int> help(R - L + 1);
	int p1 = L;
	int p2 = mid + 1;
	int i = 0;
	int ret = 0;
	while (p1 <= mid && p2 <= R)
	{
		ret += array[p1] < array[p2] ? (R - p2 + 1) * array[p1] : 0;
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

	cout << "ret : " << ret << endl;
	cout << endl;
	return ret;
}

static int mergeSort(vector<int> &array, int L, int R)
{
	if (L >= R) 
	{
		return 0;
	}
	int mid = L + ((R - L) / 2);
	return (mergeSort(array, L, mid)     //�����������е�С��
		+ mergeSort(array, mid + 1, R)	 //�Ҳ���������е�С��
		+ merge(array, L, mid, R));		 //�ϲ������е�С��
}
static int smallSum(vector<int> &array)
{
	if (array.size() < 2) 
	{
		return 0;
	}
	return mergeSort(array, 0, array.size() - 1);
}

int main12312312141(void)
{
	vector<int> array = { 1 , 3 , 4 , 2 , 5 };
	int sum = smallSum(array);

	cout << "С��Ϊ��sum = " << sum << endl;

	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}