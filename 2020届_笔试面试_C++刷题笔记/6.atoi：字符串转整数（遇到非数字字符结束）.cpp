#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
6.atoi���ַ���ת�����������������ַ�������
***************************************/
// ָ�뷨
static int my_atoi(const char * str)
{
	if (str == nullptr)
	{
		return 0;
	}
	int num = 0; //��Ҫ���ص�ֵ
	int flag = 1; //��¼������,1Ϊ��

	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else
	{
		flag = 1;
		*str == '+' ? str++ : str; // ����+�ţ���ǰ��һ����û�оͲ�ǰ����
	}

	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str++ - '0');
	}
	return num * flag;
}


int main_my_atoi(void)
{
	char str[20] = "+57124";
	cout << my_atoi(str) << endl;
	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}