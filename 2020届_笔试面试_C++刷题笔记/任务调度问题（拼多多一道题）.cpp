#include<iostream>
#include <list>
#include <vector>
using namespace std;

/*
��Ŀ��
����һ����N������ÿ������ÿ��������Ҫpi��ʱ�����ִ�С�ͬʱ������֮�����������ϵ�����磺
����1��������2��3����1������2��3ִ����֮�����ִ�С�ÿ��ֻ��ִ��һ����������ϣ����С������
��ƽ������ʱ����һ������ķ���ʱ������Ϊ����ִ�����ʱ�̼�ȥƽ̨���������ʱ�̡���0ʱ�̣�����
N�������Ѿ������ա�
���磺
���룺
5 6				5������6��������ϵ
1 2 1 1 1		��i������Ĵ���ʱ��pi
1 2				������6�д���6��������ϵ����1�У�2����1,��2������1ִ��������ִ��
1 3
1 4
2 5 
3 5
4 5
�����
1 3 4 2 5		ִ������ı�ţ���ִ��1����ִ��3����������4  2  5.
*/

static void printArray(vector<vector<int>> temp)
{
	for (int i = 0; i < temp.size(); ++i)
	{
		cout << i << " : ";
		for (int j = 0; j < temp[i].size(); ++j)
		{
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}

int findMinTimeTask(vector<vector<int>> &temp, vector<int> pi)
{
	int minIndex = 0; // ��ʼ��Ϊʱ���������
	for (int i = 0; i < pi.size(); i++)
	{
		minIndex = pi[minIndex] > pi[i] ? minIndex : i;
	}
	minIndex += 1;
	for (int i = 0; i < 6; i++)
	{
		if (temp[i].empty())
		{
			minIndex = pi[i - 1] < pi[minIndex - 1] ? i : minIndex;
		}
	}
	return minIndex;
}

void deleteTask(vector<vector<int>> &temp, int minIndex)
{
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < temp[i].size(); j++)
		{
			if (temp[i][j] == minIndex)
			{
				cout << "*(temp[i].begin() + j) : " << *(temp[i].begin() + j) << endl;
				temp[i].erase(temp[i].begin() + j);
			}
		}
	}
}

int main_adasdwerdxczxcdf(void)
{
	int n = 5;
	int m = 6;
	vector<int> pi = { 1,2,1,1,1 };
	int rely[6][2] = { {1,2},{1,3},{1,4},{2,5},{3,5},{4,5} };
	vector<vector<int>> temp(6);
	temp[0].push_back(-1);
	for (int i = 0; i < 6; ++i)
	{
		cout << rely[i][1] << "  " << rely[i][0] << endl;
		temp[rely[i][1]].push_back(rely[i][0]);
	}
	printArray(temp);

	vector<int> output;
	int index = 0;
	int minIndex = 0;
	for (int i = 0; i < n; i++)
	{
		minIndex = findMinTimeTask(temp, pi);
		cout << "minIndex : " << minIndex << endl;

		output.push_back(minIndex);

		temp[minIndex].push_back(-1);

		deleteTask(temp, minIndex);

		printArray(temp);


	}
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << "  ";
	}
	
	cout<<"��ɣ�"<<endl;
	system("pause");
	return 0;
}