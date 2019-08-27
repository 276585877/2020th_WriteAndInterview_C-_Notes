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
��������װ��������Ϊ���װ���ص���Ʒ
***************************************/
static vector<bool> knasSack_full(int n, int c, vector<int> &weight, vector<int> &value)
{
	// ����ֵ��n+1�У���i�д����i����Ʒ����ÿһ����һ��һά����vector<int>(c + 1, 0)������c+1�У���i�д���������Ϊi��
	// �ڳ�ʼ��ʱ���ܳ�ʼ��Ϊ0����Ҫ��ʼ��Ϊ����״̬���ڸ�ֵʱҲ����Դ���״̬���жϡ�
	vector<vector <int>> maxValue_table(n + 1, vector<int>(c + 1, -1)); // �뾭������в��-1��ʾ����ʹ����װ��
	print_2D_Array(maxValue_table);
	// ��¼��Ʒѡ��ѡ���±��0��ʼ��
	vector<bool> result(n, false);
	// ������̬�滮��
	for (int i = 1; i <= n; i++) // ��0�в�ʹ�ã�û��0����Ʒ
	{
		for (int j = 1; j <= c; j++) // ��0�б�������Ϊ0����ʼ��Ϊ0���ɣ�
		{
			if (i == 1) // ��1�У���1����Ʒ���±�Ϊ0����ֻ��һ����Ʒ��ֻҪ�ܷ��£�ֱ�ӷš�
			{
				maxValue_table[i][j] = (weight[i - 1] == j ? value[i - 1] : -1); // ���==�ţ���Ϊֻ��1����Ʒ��ֻ���ڸ���Ʒ��������װ��
			}
			else
			{
				// ��һ�������ֵ���������ӵ�i����Ʒ��ǰ��i-1����Ʒ������ֵ
				int frontValue = maxValue_table[i - 1][j];
				// �ӵ�i����Ʒ����ǰ��Ʒ�ļ�ֵ + ʣ��ռ�ļ�ֵ
				int thisValue = -1;
				if (weight[i - 1] == j)
				{
					thisValue = value[i - 1]; // ȷ����Ҫ�ӵ�i����Ʒ���Ҹպ�ֻ����ô�������������ֻ�е�i��
				}
				else if(weight[i - 1] < j) // װ�˵�i��������ʣ������������װ��
				{
					if (maxValue_table[i - 1][j - weight[i - 1]] == -1) 
					{
						thisValue = -1;// ʣ��ռ�ļ�ֵ����-1ʱ����ʾʣ�µĿռ䲻�ܱ�װ������ǰ��Ʒ����װ��
					}
					else // ʣ��ռ�ļ�ֵ������-1ʱ����ʾʣ�µĿռ��ܱ�װ������ǰ��Ʒ��װ
					{
						thisValue = value[i - 1] + maxValue_table[i - 1][j - weight[i - 1]];
					}
				}
				// ���� topValue��thisValue�нϴ��һ��
				maxValue_table[i][j] = (frontValue > thisValue ? frontValue : thisValue);
			}
		}
	}
	print_2D_Array(maxValue_table);

	// ��̬�滮�������ˣ����ڸ�����Ʒ�����ͱ���������ѡ������ֵ��װ�ء�
	for (int i = n, j = c; i > 0; i--) // �����½ǿ�ʼ��
	{
		if (maxValue_table[i][j] > maxValue_table[i - 1][j])
		{
			result[i - 1] = true;
			j = j - weight[i - 1];
		}
	}

	return result;
}


int main_��������װ��(void)
{
	int n = 5; // ��Ʒ����
	int c = 10; // �����������
	vector<int> weight = { 2,2,6,5,4 };
	vector<int> value = { 6,3,5,4,6 };
	int sumValue = 0;
	vector<bool> result = knasSack_full(n, c, weight, value);
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i])
		{
			sumValue += value[i];
		}
		// ��Ʒѡ��������±꣬��0��ʼ
		cout << "��" << i << "����Ʒ��" << (result[i] == true ? "ѡ" : "��ѡ") << endl;
	}
	cout << sumValue << endl; // �ܼ�ֵ

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}