#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
��Ŀ����
ʵ��ɾ���ַ����г��ִ������ٵ��ַ���������ַ����ִ���һ������ɾ����
���ɾ����Щ���ʺ���ַ������ַ����������ַ�����ԭ����˳��
��������:
�ַ���ֻ����СдӢ����ĸ, �����ǷǷ����룬������ַ�������С�ڵ���20���ֽڡ�

�������:
ɾ���ַ����г��ִ������ٵ��ַ�����ַ�����

ʾ��1
����
����
abcdd
���
����
dd
*/

int main1502_ɾ���ַ����г��ִ������ٵ��ַ�(void)
{
	string str = "";

	while (cin >> str)
	{
		map<char, int> my_map;

		for (int i = 0; i < str.size(); i++) // Ԫ�ظ���������
		{
			auto it = my_map.insert(pair<char, int>(str[i], 0));
			if (it.second)
			{
				my_map[str[i]] = 1;
			}
			else
			{
				my_map[str[i]]++;
			}
		}

		int minVuale = 20;
		for (auto it : my_map)
		{
			//cout << it.first << " : " << it.second << endl;
			if (it.second < minVuale)
			{
				minVuale = it.second;
			}
			//cout << "minVuale : " << minVuale << endl;
		}

		vector<char> my_v;
		for (auto it : my_map)
		{
			if (it.second != minVuale)
			{
				my_v.push_back(it.first);
			}
		}

		//for (auto it : my_v)
		//{
		//	cout << it << endl;
		//}

		for (int i = 0; i < str.size(); i++)
		{
			if (find(my_v.begin(), my_v.end(), str[i]) != my_v.end())
			{
				cout << str[i];
			}
		}
		cout << endl;
	}
	
	//�Զ��Ű棺ctrl+k+F
	return 0;
}