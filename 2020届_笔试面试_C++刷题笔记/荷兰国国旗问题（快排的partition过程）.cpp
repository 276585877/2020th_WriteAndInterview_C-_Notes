#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
�������������⣺
����һ�����飬��һ��num��
��С��num��������������ߣ�
������num�������������м䣬
������num�������������ұߣ�

˼·�����ƿ��ŵ�partition����
*/

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

static void partition(int *array, int L, int R, const int num)
{
	//int *help = new int[2];
	int lessRange = L - 1;
	int bigRange = R + 1;
	int key = num;
	while (L < bigRange)
	{
		if (array[L] < key)
		{
			swap(array, L++, ++lessRange);
		}
		else if (array[L] > key)
		{
			swap(array, L, --bigRange);
		}
		else
		{
			L++;
		}
	}

	//help[0] = lessRange;
	//help[1] = bigRange;
	//return help;
}

int main15212015110(void)
{
	int array[] = { 90, 50, 60, 20, 70, 30, 40, 80, 10 };
	int len = sizeof(array) / sizeof(array[0]);

	cout << "����֮ǰ��" << endl;
	prinft_array(array, len);

	partition(array, 0, len - 1, 60);

	cout << "����֮��" << endl;
	prinft_array(array, len);
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}