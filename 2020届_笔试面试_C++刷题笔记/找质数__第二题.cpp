#include <iostream>
#include <vector>
using namespace std;

/***************************************
����Ŀ����
�����Ķ���Ϊ���ڴ���1����Ȼ���У�����1�����������ܱ�������Ȼ����������2,3,23�ȡ�
����һ��ȡֵ��Χ[low,high)���ҵ��÷�Χ�ڵ����������������Щ������ʮλ��֮�ͺ͸�λ��֮�͵Ľ�Сֵ��
���������С��10������ʮλ��Ϊ0��ע��low��ȡֵ��Χ�ڣ�high���ڡ�
����������
��һ�����룺low��high��������֤����С��0����low < high�����ÿ�������Ϸ��ԣ����û�������������0
���������
����ҵ���������ʮλ��֮�ͺ͸�λ��֮�͵Ľ�Сֵ��
���룺151 160
�����8
˵����[151,160)֮��������151��157��ʮλ֮�ͣ�5+5=10����λ֮�ͣ�1+7=8���������8.
��˼·����

***************************************/

int main_�ڶ���(void)
{
	int low, high;
	while (cin >> low >> high)
	{
		bool flag = true;
		vector<int> arr;
		for (int value = low; value < high; value++)
		{
			flag = true;
			for (int i = 2; i < value; i++)
			{
				if (0 == value % i)
				{
					flag = false; // ����֮������ܱ�value������������������
				}
			}
			if (true == flag)
			{
				arr.push_back(value); // �����е���������������
			}
		}

		int firstNumSum = 0;
		int secondNumSum = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			firstNumSum += arr[i] % 10; // ���еĸ�λ�ĺ�
			secondNumSum += arr[i] >= 10 ? (arr[i] / 10 % 10) : 0; // ���е�ʮλ�ĺ�
		}
		cout << (firstNumSum < secondNumSum ? firstNumSum : secondNumSum) << endl;
	}
	return 0;
}