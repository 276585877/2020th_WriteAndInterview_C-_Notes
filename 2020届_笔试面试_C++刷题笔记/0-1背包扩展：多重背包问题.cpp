/*
���ͣ�https://blog.csdn.net/hongtao_6/article/details/93924799
���ͣ�https://blog.csdn.net/laoniu_c/article/details/38453083
��̬�滮���
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

// ��ӡ��ά����vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << setw(3) << *it;
		}
		cout << endl;
	}
	cout << endl;
}

/***************************************
n����Ʒ��ÿ����Ʒ��weight����ֵvalue���������������c.
��Ʒ��ָ������ֻ����num�����weight��value�������³�ʼ�����ɡ�
***************************************/
static int knasSack_kTimes(int n, int c, vector<int> &weight, vector<int> &value, vector<int> &num)
{
	vector<int> weightVec;
	vector<int> valueVec;
	// ��Ʒ��ָ������ֻ����num�����weight��value�������³�ʼ�����ɡ�
	for (int i = 0; i < n; i++)
	{
		while (num[i]--)
		{
			weightVec.push_back(weight[i]);
			valueVec.push_back(value[i]);
		}
	}
	// ��Ʒ��ָ������ֻ����num�����weight��value�������³�ʼ�����ɡ�

	/*
	���м�����뾭�䱳���������һ�¡�
	.......
	.......
	.......
	*/
	return 0;
}

int main_���ر�������(void) // main_���ر�������
{
	int n = 5; // ��Ʒ����
	int c = 10; // �����������
	vector<int> weight = { 2,2,6,5,4 };
	vector<int> value = { 6,3,5,4,6 };
	vector<int> num = { 0 };
	int sumValue = 0;
	knasSack_kTimes(n, c, weight, value, num);

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}