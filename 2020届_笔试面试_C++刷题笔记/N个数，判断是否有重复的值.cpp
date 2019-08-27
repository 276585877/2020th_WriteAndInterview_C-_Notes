#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void swap1(int *array, const int x, const int y)
{
	int temp = array[y];
	array[y] = array[x];
	array[x] = temp;
}

/*
һ������ΪN���������飬������ÿ��Ԫ�ص�ȡֵ��Χ��[0,n-1],
�жϸ���������ظ���������˵һ�����˼·����д����
*/

//bool IsDuplicateNumber(int *array, int n)
//{
//	if (array == nullptr) return false;
//	int i, temp;
//	for (i = 0; i < n; i++)
//	{
//		while (array[i] != i)
//		{
//			if (array[array[i]] == array[i])// ��ǰλ�õ�ֵ�͸�ֵΪ�±��λ����ֵ�Ƿ���ȡ�
//				return true;
//			temp = array[array[i]];
//			array[array[i]] = array[i];
//			array[i] = temp;
//		}
//	}
//	return false;
//}

static bool IsDuplicateNumber(int *array, int n)
{
	if (array == nullptr) return false;
	int i;
	for (i = 0; i < n; i++)
	{
		if (array[i] != i)
		{
			if (array[array[i]] == array[i])
			{
				return true;
			}
			swap1(array, array[i], i);
		}
		else
		{
			continue;
		}
	}
	return false;
}

int main1525156(void)
{
	int *array = new int[10];
	for (int i = 0; i < 10; ++i)
	{
		array[i] = (i * 2 + 10 / 3) % 10;
		//array[i] = 9-i;
		cout << array[i] << "  ";
	}
	if (IsDuplicateNumber(array, 10))
	{
		cout << "���ظ���";
	}
	else
	{
		cout << "���ظ���";
	}
	
	cout<<"\nWrite By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}