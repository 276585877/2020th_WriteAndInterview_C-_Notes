/***************************************
����Ŀ����
�������ַ����У���Щ�ַ���һ���������γɵ�������Ҳ�п�����ȣ�
��ˣ����������������б������߼������������У�
��˼·����
�䳤�ȿ���ʹ�ö�̬�滮����<https://blog.csdn.net/someone_and_anyone/article/details/81044153>
ͼ�еĿհ׸�����Ҫ������Ӧ�����֣�������־���c[i][j]�Ķ��壬��¼��LCS�ĳ���ֵ����
��Ĺ������ݵݹ鹫ʽ��
����˵��
���������i,j����Ӧ������Ԫ����ȣ��ø��ӵ�ֵ = c[i-1,j-1] + 1��
������ȣ�ȡc[i-1,j] �� c[i,j-1]�����ֵ�����c�������½ǵ�Ԫ�ؾ�������������еĳ���
***************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// ��ӡ��ά����vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

/***************************************
DP_table����̬�滮��
maxLen������������еĳ���
result�����ж������������У���һ��ֻ��������һ����
***************************************/
static void LCSofLen(string str1, string str2)
{
	int len1 = str1.size(); // ��
	int len2 = str2.size(); // ��
	vector<vector<int>> DP_table(len1 + 1,vector<int>(len2 + 1, 0)); // ��̬�滮��
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				DP_table[i][j] = DP_table[i - 1][j - 1] + 1;
			else
				DP_table[i][j] = max(DP_table[i][j - 1], DP_table[i - 1][j]);
		}
	}
	print_2D_Array(DP_table);
	cout << "maxLen = " << DP_table[len1][len2] << endl;

	vector<char> result; // ������һ��������
	for (int i = len1, j = len2; i > 0 && j > 0; )
	{
		if (str1[i - 1] != str2[j - 1])
		{
			if (DP_table[i][j - 1] > DP_table[i - 1][j])
				j--;
			else if (DP_table[i][j - 1] == DP_table[i - 1][j])
				i--; // ���ʱ��������ֵ���ȡһ�£����Ի���ʱҲ�����ѡ��ѡ������i--��ѡ������j--
			else
				i--;
		}
		else
		{
			result.push_back(str1[i - 1]);
			i--;
			j--;
		}
	}
	reverse(result.begin(), result.end());
	for (auto it : result)
	{
		cout << it << "  ";
	}
	cout << endl;
}

int main_�����������()
{
	string str1 = "13456778";
	string str2 = "357486782";
	LCSofLen(str1, str2);
	return 0;
}

