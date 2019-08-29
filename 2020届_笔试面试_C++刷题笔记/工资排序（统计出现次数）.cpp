/***************************************
����Ŀ����
ĳ��˾��N��Ա������������Ա�����ʵ��嵥��������ԱҪ�����ض���˳������Ա���Ĺ��ʡ�
�����չ��ʵ�Ƶ�ν������У��������嵥������Ƶ�νϸߵĹ�����Ƶ�νϵ͵Ĺ���֮ǰ���֡�
�����ͬ������ͬ��Ա������ͬ�Ĺ��ʣ��򽫰��ո����嵥�иù��ʵ�һ�γ��ֵ�˳�����С�
дһ���㷨����������Ա����Ա�����ʵ�˳��

���룺
1��num, һ��������ʾԱ������
2��salaries��Ա�������б�
�����
����һ�����չ���Ƶ�ν�����������б�
Լ������
1<=num<=10^5
1<=salaries[i]<=10^9
0=<i<num

������10,[20,40,26,25,40,20,40,20,40,25]
�����40 40 40 40 20 20 20 25 25 26
��˼·����
��������Ҫͳ�ƹ��ʵ�Ƶ�ν������򣬵�Ƶ��һ��ʱӦ�����ݵ�һ�γ�����������
����ͨ��һ��ѭ������������ ˳��CԱ�����ʡ�Ա���C����˳�򡢳���˳��C����Ƶ�� �Ĺ�ϵ��
�� ����˳��C����Ƶ�� ���򡣹��򣺳���Ƶ�β�һ��ʱ�������򣬷�����ݳ���˳����������
���������ĳ���˳��C����Ƶ�Σ����ݳ���˳���ȡ��Ӧ��Ա�����ʣ���ӵ�����б�
***************************************/
#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
using namespace std;

static bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

static void salaryfrequeny(int num, vector<int> &salaries)
{
	if (num <= 0)
	{
		return;
	}
	// ͳ�Ƴ��ִ�����myMap; // ��¼���ֵ�Ƶ�Ρ���map_temp; // ��¼���ֵ�ԭ����
	map<int, int> myMap; // ��¼���ֵ�Ƶ��
	vector<int> map_temp; // ��¼���ֵ�ԭ����
	for (auto it : salaries)
	{
		if (myMap.count(it) == 0) // ��һ�γ���
		{
			myMap[it] = 1;
			map_temp.push_back(it);
		}
		else
		{
			myMap[it] += 1;
		}
	}
	cout << "myMap" << endl;
	for (auto it : myMap)
	{
		cout << it.first << " : " << it.second << endl;
	}
	cout << "map_temp" << endl;
	for (auto it : map_temp)
	{
		cout << it << endl;
	}
	
	vector<pair<int, int>> result;
	for (auto it : map_temp)
	{
		result.push_back(pair<int, int>(myMap[it], it));
		cout << result.back().first << " : " << result.back().second << endl;
	}
	sort(result.begin(), result.end(), compare);

	for (auto it : result)
	{
		while (it.first--)
		{
			cout << it.second << " ";
		}
	}
	cout << endl;
}

int main_��������()
{
	const int num = 10;
	vector<int> salaries = { 20, 30, 26, 25, 40, 20, 40, 20, 40, 25 };

	salaryfrequeny(num, salaries);

	return 0;
}



