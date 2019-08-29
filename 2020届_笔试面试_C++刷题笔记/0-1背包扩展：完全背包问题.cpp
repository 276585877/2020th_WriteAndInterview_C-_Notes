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
��Ʒ����������࣬��ʼ��ʱ���������ʼ�����ɡ��������times��ʾ���˼�����ǰ��Ʒ��
��ע�⡿
��Ϊÿ����Ʒ�������������Կ��ܻ��ж��ֲ�ͬ��ѡ������ֻ���һ��ѡ���ȫ��ѡ�������ֵ�����Ը�������ֵ���������ѡ��
***************************************/
static vector<int> knasSack_nTimes(int n, int c, vector<int> &weight, vector<int> &value)
{
	// ����ֵ��n+1�У���i�д����i����Ʒ����ÿһ����һ��һά����vector<int>(c + 1, 0)������c+1�У���i�д���������Ϊi��
	vector<vector <int>> maxValue_table(n + 1, vector<int>(c + 1, 0));
	// ��¼��Ʒѡ��ѡ���±��0��ʼ��
	vector<int> result(n, false);
	// �������times��ʾ���˼�����ǰ��Ʒ��
	int times = 0;
	// ������̬�滮��
	for (int i = 1; i <= n; i++) // ��0�в�ʹ�ã�û��0����Ʒ
	{
		for (int j = 1; j <= c; j++) // ��0�б�������Ϊ0����ʼ��Ϊ0���ɣ�
		{
			times = j / weight[i - 1]; // j����������ܷ��¼���i�����Ʒ��
			if (i == 1) // ��1�У���1����Ʒ���±�Ϊ0��
			{
				maxValue_table[i][j] = (times > 0 ? value[i - 1] * times : 0);
			}
			else
			{
				// ��һ�������ֵ���������ӵ�i����Ʒ��ǰ��i-1����Ʒ������ֵ
				int frontValue = maxValue_table[i - 1][j];
				// �ӵ�i����Ʒ����ǰ��Ʒ�ļ�ֵ + ʣ��ռ�ļ�ֵ
				int thisValue = 0;
				if (times > 0)
				{
					for (int k = 1; k <= times; k++)
					{
						thisValue = value[i - 1] * k + maxValue_table[i - 1][j - weight[i - 1] * k] > thisValue ? value[i - 1] * k + maxValue_table[i - 1][j - weight[i - 1] * k] : thisValue;			
					}
				}
				else
				{
					thisValue = frontValue;
				}
				// ���� topValue��thisValue�нϴ��һ��
				maxValue_table[i][j] = (frontValue > thisValue ? frontValue : thisValue);
			}
		}
	}
	print_2D_Array(maxValue_table);
	// ��̬�滮�������ˣ����ڸ�����Ʒ�����ͱ���������ѡ������ֵ��װ�ء�
	for (int i = n, j = c; i > 0; i--) // �����½ǿ�ʼ��
	{ // ͬһ���У����������������������˵����ǰ��ѡ�˵ġ�
		if (maxValue_table[i][j] > maxValue_table[i - 1][j])
		{
			int times = j / weight[i - 1];
			result[i - 1] = times;
			//j = j - weight[i - 1];
			j = j - weight[i - 1] * times;
		}
	}
	return result;
}


int main_��ȫ��������(void) // main_��ȫ��������
{
	int n = 5; // ��Ʒ����
	int c = 10; // �����������
	vector<int> weight = { 2,2,6,5,4 };
	vector<int> value = { 6,3,2,4,7 };
	int sumValue = 0;
	vector<int> result = knasSack_nTimes(n, c, weight, value);
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] != 0)
		{
			sumValue += value[i] * result[i];
		}
		// ��Ʒѡ��������±꣬��0��ʼ
		cout << "��" << i << "����Ʒ��" << (result[i] != 0 ? "ѡ" : "��ѡ") << result[i] << "��" << endl;
		//cout << "��" << i << "����Ʒ��" << (result[i] == true ? "ѡ" : "��ѡ") << endl;
	}
	cout << sumValue << endl; // �ܼ�ֵ

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}