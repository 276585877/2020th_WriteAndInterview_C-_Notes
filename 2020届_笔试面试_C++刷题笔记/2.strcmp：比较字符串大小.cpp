#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
2.strcmp���Ƚ��ַ�����С��һ�������ַ�������
ʵ���뷨�����δ��ַ�����ʼһֱ�ҵ���ͬ���Ǹ��ַ����бȽϣ��ó���С
***************************************/
// ָ�뷨
static int my_strcmp(const char * str1, const char * str2)
{
	while (*str1 && *str1 == *str2)
	{ // һֱ�ҵ������ַ�����ͬ�ĵط�
		str1++;
		str2++;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else if (*str1 == *str2)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}


int main_my_strcmp(void)
{
	const char * str1 = "feng1";
	const char * str2 = "feng1";

	cout << my_strcmp(str1, str2) << endl;

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}