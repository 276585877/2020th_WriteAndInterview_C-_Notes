#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

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


static string add(string &a1, string &a2)
{
	// please write your code here.
	char key = '0';
	string result_xiao = "";
	string result_zheng = "";
	string result = "";
	string a1_zheng, a2_zheng;
	string a1_xiao, a2_xiao;
	auto p1 = a1.find(".");
	auto p2 = a2.find(".");
	a1_zheng = a1.substr(0, p1);
	a1_xiao = a1.substr(p1 + 1);
	a2_zheng = a2.substr(0, p2);
	a2_xiao = a2.substr(p2 + 1);

	// С�����ִ���(��ʵҲ�ǵ�������������)
	auto strNum1 = a1_xiao.size();
	auto strNum2 = a2_xiao.size();
	auto max = strNum1 > strNum2 ? strNum1 : strNum2;
	result_xiao = calculateAdd(a1_xiao, a2_xiao);
	// �������ִ���
	if (result_xiao.size() > max) // С�����ֻ��λ1����������
	{
		//result_xiao.erase(0,1); // �±���ʽ��0��λ�ã�ɾ��1��
		result_xiao.erase(result_xiao.begin()); // ��������ʽ
		a2_zheng.back() = a2_zheng.back() + 1; // �������ֽ�λ1��С��������ӵõ��ġ�
		result_zheng = calculateAdd(a1_zheng, a2_zheng);
	}
	else
	{
		result_zheng = calculateAdd(a1_zheng, a2_zheng);
	}
	// �ϲ�
	result = result_zheng + "." + result_xiao;
	return result;
}

int main22852855551212251251251265165(void)
{

	string a1 = "1134344141331441230.523125512235123431";
	string a2 = "11341234126512351231.51134132512341324236123521311";
	string a3;
	a3 = add(a1, a2);
	cout << a3 << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}