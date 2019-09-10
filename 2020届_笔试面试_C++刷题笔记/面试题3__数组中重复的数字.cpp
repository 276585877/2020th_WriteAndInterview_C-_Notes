#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// This does the trick,���������ת�����±�
inline const int iterator_to_index(vector<int> &a, vector<int>::iterator it)
{
	return it - a.begin();
}
// This does the trick,���������ת�����±�
inline const int iterator_to_index(vector<int> &a, vector<int>::reverse_iterator it)
{
	return a.rend() - it - 1;
}

/***************************************
����Ŀ����
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡�
���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��
����������
{2,3,1,0,2,5,3}
���������
2
��˼·����
1�����򣺵�ǰ���һ����ȣ����ظ�
2����ϣ��ÿ�β���Ԫ�أ��жϸ�Ԫ���Ƿ����
3���±������ֶ�Ӧ����Ԫ�طŵ���Ӧ�±��λ���ϡ�
4��ǰ��ָ�룺ÿ��Ԫ�ش�ǰ�ҡ��Ӻ��ң��Ա�λ�á�
***************************************/
// ˼·3
static bool duplicate(vector<int> &numbers, int length, int &duplication)
{
	if (numbers.size() == 0 || length == 0)
	{
		return false;
	}

	int temp = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i]<0 || numbers[i]>length - 1)//��[0, n-1]��Χ�������
		{
			return false;
		}
	}

	for (int i = 0; i < length; i++)
	{
		while (i != numbers[i]) // numbers[i]��ֵ������i��������ν�����Ԫ��numbers[i]����iλ�á�
		{
			if (numbers[i] == numbers[numbers[i]])
			{// �����ظ�
				duplication = numbers[i];
				return true;
			}
			else
			{// �������򽻻�
				int temp = numbers[i];
				numbers[i] = numbers[temp];
				numbers[temp] = temp;
			}
		}
	}
	// �����˶�û���ҵ�����û���ظ��ġ�
	return false;
}
// ˼·4
static bool duplicate(vector<int> &numbers, int length)
{
	if (numbers.size() == 0 || length == 0)
	{
		return false;
	}

	int temp = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i]<0 || numbers[i]>length - 1)//��[0, n-1]��Χ�������
		{
			return false;
		}
	}

	auto it_front = numbers.begin();
	auto it_back = numbers.rbegin();
	for (int i = 0; i < length; i++)
	{
		it_front = find(numbers.begin(), numbers.end(), numbers[i]); // ˳����
		it_back = find(numbers.rbegin(), numbers.rend() , numbers[i]); // ������
		int index_front = iterator_to_index(numbers, it_front);
		int index_back = iterator_to_index(numbers, it_back);
		//cout << "index_front:" << index_front << endl;
		//cout << "index_back:" << index_back << endl;
		if (index_front != index_back) // �ҵ�һ���ظ��ģ����Ҳ��ظ��ģ�index_front == index_back
		{
			cout << numbers[index_front] << endl;
			return true;
		}
	}
	// �����˶�û���ҵ�����û���ظ��ġ�
	return false;
}

int main_�������ظ�������(void)
{
	vector<int> arr = { 2,3,1,0,2,5,3 };
	// ˼·3
	//int duplication = 0;
	//if (duplicate(arr, arr.size(), duplication))
	//{
	//	cout << "�ҵ���" << duplication << endl;
	//}
	//else
	//{
	//	cout << "δ�ҵ���" << endl;
	//}

	// ˼·4
	if (duplicate(arr, arr.size()))
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ���" << endl;
	}


	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}
