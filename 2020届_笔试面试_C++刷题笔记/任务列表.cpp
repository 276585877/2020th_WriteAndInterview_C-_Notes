#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
����������һ̨��������̨�������Խ���������ʽ����
��1�������б������б�������N�����񣬶��ڵ�i�����񣬻�����Tiʱ�俪ʼִ�У�����1����λʱ�������ꡣ
��2����ʱ���񣬻�������������ʱ�����һ����ʱ���񣬵������б�������������ȼ�Ҫ������ʱ����
Ҳ����˵���������е�ʱ��Ż�ִ����ʱ����

���ڻ����Ѿ�����һ�������б�����������M����ʱ������Ŀ��������֪��ÿ����ʱ�����ʱ��ִ�С�
Ϊ�˼��������ǿ�����Ϊ��M����ʱ�����Ƕ����޹ؼ������ǿ���ͬʱִ�еģ�����Ӱ��ġ�

����
���������ж��飬ÿ�����ݵ�һ�а�����������N��M��1<=N, M<=10^5����
������һ����N����ͬ����T1,T2,T3.....TN��1<=T1
��������M�У�ÿ��һ������Qi��1<=Qi<=10^9������ʾ��i����ʱ����ĵĽ���ʱ�䡣

���
����ÿ����ʱ�����������ִ�е�ʱ�䡣

��������
5 6
1 2 3 5 6
3
2
1
4
5
6

�������
4
4
4
4
7
7
*/

int main4582634528465864583202543(void)
{
	int N, M;
	while (cin >> N >> M)
	{
		vector<int> times_Ti(N, 0); // �����б�
		for (int i = 0; i < N; i++)
		{
			int temp = 0;
			cin >> temp;
			times_Ti[i] = temp;
		}
		vector<int> times_Qi(M, 0); // ��ʱ����
		for (int i = 0; i < M; i++)
		{
			int temp = 0;
			cin >> temp;
			times_Qi[i] = temp;
		}
		//sort(times_Qi.begin(), times_Qi.end());
		vector<int> time(times_Ti.back() + 2, 0); // �±��1��ʼ������ĩβ1����������
		for (int i = 0; i < N; i++)
		{
			time[times_Ti[i]] = 1;
		}

		for (int i = 1; i < time.size(); i++) // �±��1��ʼ������ĩβ1����������
		{
			if (time[i] == 0) // ��ʱ����:i
			{
				for (int j = 0; j < times_Qi.size(); )
				{
					if (times_Qi[j] <= i)
					{
						cout << i << endl;
						times_Qi.erase(times_Qi.begin() + j);
					}
					else
					{
						j++;
					}
				}
			}
		}
	}
	
	//cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}