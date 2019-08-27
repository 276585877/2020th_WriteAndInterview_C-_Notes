#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����
ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ��������
�ж��������Ƿ��и�������

��˼·����
��Ϊ������ģ���ô��������ݼ�����������ɣ����ĸ�������ĸ�λ�ÿ�ʼ�����ԣ�
*/

static void printArray(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
}

/***************************************
��˼·����
��Ϊ������ģ���ô��������ݼ�����������ɣ����ĸ�������ĸ�λ�ÿ�ʼ�����ԣ�
***************************************/
static bool function(vector<vector<int>> array, const int key)
{
	int temp = array[0][array[0].size() - 1];
	int row = 0;
	int colum = array[0].size() - 1;
	while (row <= array.size() - 1 && colum >= 0)
	{
		temp = array[row][colum];
		if (temp > key)
		{
			colum--;
		}
		else if (temp < key)
		{
			row++;
		}
		else
		{
			return true;
		}
	}

	return false;
}

int main_01(void)
{
	vector<vector<int>> Input(4);
	Input[0].push_back(1);
	Input[0].push_back(2);
	Input[0].push_back(8);
	Input[0].push_back(9);
	Input[1].push_back(2);
	Input[1].push_back(4);
	Input[1].push_back(9);
	Input[1].push_back(12);
	Input[2].push_back(4);
	Input[2].push_back(7);
	Input[2].push_back(10);
	Input[2].push_back(13);
	Input[3].push_back(6);
	Input[3].push_back(8);
	Input[3].push_back(11);
	Input[3].push_back(15);
	
	int key = 1;

	printArray(Input);

	if (function(Input, key))
	{
		cout << "\n�ҵ�:"<< key <<"��\n";
	}

	else
	{
		cout << "\nδ�ҵ�:" << key << "��\n";
	}
	//�Զ��Ű棺ctrl+k+F
	return 0;
}