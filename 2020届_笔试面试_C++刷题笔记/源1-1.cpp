#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(pair<long long, int> a, pair<long long, int> b)
{
	return a.first < b.first;
}

int main__111112315(void)
{
	int N = 0;
	while (cin >> N)
	{
		if (N <= 0)
		{
			cout << "0" << endl;
			return 0;
		}

		vector<pair<long long, int>> Hi(N);
		for (int i = 0; i < N; i++)
		{
			long long temp;
			cin >> temp;
			Hi[i] = pair<long long, int>(temp, i + 1);
		}

		sort(Hi.begin(), Hi.end(), compare);
		//cout << endl;
		//for (auto it : Hi) // ����
		//{
		//	cout << it.first << ":" << it.second << endl;
		//}

		int count = 1;
		vector<int> result;
		result.push_back(Hi[0].second);
		for (auto it1 : Hi)
		{
			bool flag = true;
			for (auto it2 : result)
			{
				if (abs(it1.second - it2) == 0) // ��һ�����
				{
					flag = false; // �ı��ˡ�
					break;
				}
				else if (abs(it1.second - it2) == 1) // ��ʾ���������
				{
					result.push_back(it1.second);
					flag = false; // �ı��ˡ�
					break;
				}
			}
			if (flag == true && it1 != Hi.back()) // δ�ı䣬��result����û���ҵ�������ţ������ж�
			{
				if (result.size() > 3)
				{
					count += result.size() - 3;
				}
				result.clear();
				result.push_back(it1.second);
				count++;
			}
		}
		//cout << "count = " << count << endl;
		cout << count << endl;
	}
	return 0;
}