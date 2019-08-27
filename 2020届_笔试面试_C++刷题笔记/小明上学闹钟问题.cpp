#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
����������
ţţ����˯��ͷ�����������˺ܶ����ӣ�ֻ�����������ʱ�����Ż��ѹ������Ҿ������𴲡�
��������������ҪX���ӵ�����ң��Ͽ�ʱ��Ϊ�����AʱB�֣��������������ʲôʱ����
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а���һ������������ʾ���ӵ�����N(N<=100)��
��������N��ÿ�а���������������ʾ������������ʱ��ΪHi(0<=A<24)ʱMi(0<=B<60)�֡�
��������һ�а���һ����������ʾ������������ҪX(0<=X<=100)���ӵ�����ҡ�
��������һ�а���������������ʾ�Ͽ�ʱ��ΪA(0<=A<24)ʱB(0<=B<60)�֡�
���ݱ�֤������һ�����ӿ�����ţţ��ʱ������ҡ�
����˼·
��һ������Сʱ��Ϊ���ӣ���ӵ������
�ڶ������������� �� ������ͬʱ��Ϊ���¼��� ��
1.�жϵ�ǰʱ��᲻��ٵ� Ҳ���� ��ʣʱ�� = ����Уʱ��-·��-���ӣ����С��0�϶��ٵ���
2.��������㣬��������ʣʱ����С��(���Ե���0) �� i ��λ�ø�ֵ��min a[min]������ٵ�������
3.����/60���õľ���Сʱ ����%60���õľ���ʣ�µķ��ӣ�

���룺
3 //���˼�������
5 0 //��1�����ӵ�Сʱ���ͷ�����
6 0 //��2�����ӵ�Сʱ���ͷ�����
7 0 //��3�����ӵ�Сʱ���ͷ�����
59 //��ѧУҪ���ٷ���
6 59 //�Ͽε�Сʱ���ͷ�����
�����
6 0 //�������ʱ��
*/

// �����ά����vector<vector<int>> array
static void input_2D_Array(vector<vector<int>> &array, const int n, const int m)
{
	int temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> temp;
			array[i].push_back(temp);
		}
	}
}

static void fun(vector<vector<int>> &time, const int n, const int x, int deadLine[])
{
	//3
	//5 0
	//6 0
	//7 0
	//59

	//6 0
	vector<int> sumTime;
	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		sumTime.push_back(time[i][0] * 60 + time[i][1] + x);
	}
	sort(sumTime.begin(), sumTime.end());
	for (auto it : sumTime)
	{
		//cout << "it + " << it << endl;
		if (it <= deadLine[0]*60 + deadLine[1])
		{
			result = it;
		}
	}
	cout << (result - x)/60 << " " << (result - x)%60 << endl;
}

int main1512163112631162416584168(void)
{
	int n;
	cin >> n;
	int x;
	int deadLine[2];
	vector<vector<int>> array(n);
	input_2D_Array(array, n, 2);
	cin >> x;
	cin >> deadLine[0] >> deadLine[1];
	fun(array, n, x, deadLine);
	return 0;
}