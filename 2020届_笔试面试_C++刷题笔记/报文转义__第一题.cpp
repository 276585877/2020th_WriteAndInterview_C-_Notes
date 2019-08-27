#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

/***************************************
����Ŀ����
ʵ�ֱ���ת�幦�ܣ��������������0x0A��ת���2���ֽ�0x12  0x34��
						�������0x0B��ת���2���ֽ�0xAB  0xCD��
����������
1�����뱨��Ϊ16���ƣ����뱨�ĳ��Ȳ�����127������ı��ĵ�һ���ֽ�Ϊ���ĳ��ȣ�
��һ���ֽڣ����ĳ��ȣ�����ʽ���ĵ�һ���֣����ǲ�����ת�塣
2������ı���ÿ���ֽ��ÿո������
���������
1�����ת���ı��ģ�ת���ı��ĳ���Ҳ������255������ı��ĵ�һ���ֽ�Ϊ���ĳ��ȣ�
��������ı��ĵ�һ���ֽڣ����ĳ��ȣ�������ʽ���ĵ�һ���֣�
2������ı������ݶ��Ǵ�д��16���ƣ��������Ϊ16���ƣ�ǰ����0xǰ׺��
3������ı���ÿ���ֽ��ÿո������
���룺8 1 2 3 4 5 6 A
�����9 1 2 3 4 5 6 12 34
��˼·����
��Ҫ�䴦����������ı�����ʽ��
***************************************/
// 16����ת10���ƣ�ʮ������תʮ���ƣ�������ǰ׺
static int sixteenToTen(string s)
{
	int res = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		int temp;
		if (s[i] >= 'A' && s[i] <= 'F')
		{
			temp = s[i] - 'A' + 10;
		}
		else
		{
			temp = s[i] - '0';
		}
		res = res * 15 + temp;
	}
	return res;

}
//10����ת16���ƣ�ʮ����תʮ�����ƣ�������ǰ׺
static string tenToSixteen(int n)
{
	string stringBuilder = "";
	while (n > 0) {
		char temp;
		if (n % 16 >= 10) {
			temp = (char)('A' + n % 16 - 10);
		}
		else {
			temp = (char)('0' + n % 16);
		}
		stringBuilder += temp;
		n /= 16;
	}
	reverse(stringBuilder.begin(), stringBuilder.end());
	return stringBuilder;
}

int main_��һ��(void)
{
	while (true)
	{
		string len; // ϵͳ��������ʮ�����ơ�
		cin >> len;
		int n = sixteenToTen(len); // תΪ10����
		int count = 1;
		vector<string> myArr;
		myArr.push_back(len);
		if (n > 1 && n <= 127)
		{
			for (int i = 1; i < n; i++)
			{
				string str;
				cin >> str;
				if (str == "A")
				{
					myArr.push_back("12");
					myArr.push_back("34");
					count += 2;
				}
				else if (str == "B")
				{
					myArr.push_back("AB");
					myArr.push_back("CD");
					count += 2;
				}
				else 
				{
					myArr.push_back(str);
					count++;
				}
			}
		}
		myArr[0] = tenToSixteen(count);
		for (auto it : myArr)
		{
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}