#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
�� n ���ַ�����ÿ���ַ��������� A-J �Ĵ�д�ַ����ɡ�
�����㽫ÿ���ַ�ӳ��Ϊһ�� 0-9 �����֣���ͬ�ַ�ӳ��Ϊ��ͬ�����֡�
����ÿ���ַ����Ϳ��Կ���һ��������Ψһ��Ҫ������Щ���������������������ǵ��ַ���������ǰ���㡣
������������ӳ���ַ�����ʹ����Щ�ַ�����ʾ������֮�����

��������:
ÿ���������������һ�����ݣ�ÿ�����ݵ�һ��Ϊһ�������� n �� �������� n �У�
ÿ��һ�����Ȳ����� 12 �ҽ�������д��ĸ A-J ���ַ����� n ������ 50�������ٴ���һ���ַ������κ��ַ���������ĸ��

�������:
���һ��������ʾ�����Ƕ��١�

ʾ��1
����
2
ABC
BCA
���
1875

��˼·����
�� table = A B C D E F G H I J
��λȨֵ Ϊ 1
ʮλȨֵ Ϊ 10
��λȨֵ Ϊ 100
�������ƣ� û�г��ֵ���ĸȨֵΪ 0

�� A ��Ȩ��Ϊ 100 + 1  = 101
B ��Ȩ��Ϊ    10 + 100 = 110
C ��Ȩ��Ϊ    1 + 10   = 11
*/

// ���������������ַ������
static string calculateAdd(string &a1, string &a2)
{
	//string str1 = "21421";
	//string str2 = "809327";
	string str1 = a1;
	string str2 = a2;
	string result = "";
	cout << "str1�ĳ���Ϊ��" << str1.size() << endl;
	cout << "str2�ĳ���Ϊ��" << str2.size() << endl;

	int quotient = 0;
	int remainder = 0;
	int sum = 0;
	int strNum1 = str1.size();
	int strNum2 = str2.size();
	int max = strNum1 > strNum2 ? strNum1 : strNum2;
	cout << "max�ĳ���Ϊ��" << max << endl;

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	for (int i = 0; i < max; ++i)
	{
		int nStr1 = i < strNum1 ? (str1[i] - 48) : 0;
		int nStr2 = i < strNum2 ? (str2[i] - 48) : 0;
		sum = nStr1 + nStr2 + quotient;
		if (sum > 9)
		{
			quotient = sum / 10;
			remainder = sum % 10;
		}
		else
		{
			quotient = 0;
			remainder = sum;
		}
		result = (char)(remainder + 48) + result;
	}
	if (quotient != 0)
	{
		result = (char)(quotient + 48) + result;
	}
	// 21421 + 809327 = 830748.
	return result;
}


static void function(vector<string> &str)
{
	// ��һ�������ַ���Ȩֵ
	map<char, int> my_map;
	for (int i = 0; i < str.size(); ++i)
	{
		string str_temp = str[i];
		for (int j = str_temp.size() - 1; j >= 0; --j)
		{
			if (my_map.insert(pair<char, int>(str_temp[j], pow(10, str_temp.size() - j - 1))).second)
			{
				// ����ɹ���˵����ֵΪ�µ�
				continue;
			}
			else
			{
				// ���벻�ɹ���˵����ֵ��Ϊ�µ�
				my_map[str_temp[j]] += pow(10, str_temp.size() - j - 1);
			}
		}
	}
	multimap<int, char, greater<int>> my_multimap; // ��ֵ�Ӵ�Сgreater<int>,��ֵ��С����less<Type> 
	for (auto it : my_map)
	{
		cout << it.first << " : " << it.second << endl;
		my_multimap.insert(pair<int, char>(it.second, it.first));
	}

	const int max = 9;
	int index = 0;
	for (auto it : my_multimap)
	{
		cout << it.first << " : " << it.second << endl;
		my_map[it.second] = max - index;
		index++;
	}
	for (auto it : my_map)
	{
		cout << it.first << " : " << it.second << endl;
	}
	for (int i = 0; i < str.size(); ++i)
	{
		for (int j = 0; j < str[i].size(); ++j)
		{
			str[i][j] = my_map[str[i][j]] + '0';
			cout << str[i][j];
		}
		cout << endl;
	}
	cout << calculateAdd(str[0], str[1]) << endl;
}

int main_�ַ������ӳ��(void)
{
	int n = 2;
	vector<string> str = { "ABCC", "BCDA" };

	function(str);
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}