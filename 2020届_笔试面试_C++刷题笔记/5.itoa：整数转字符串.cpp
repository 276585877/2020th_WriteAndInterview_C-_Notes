#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
5.itoa:����ת�ַ���
***************************************/
// ָ�뷨
static char * my_itoa(int value, char * str)
{
	char *pstr = str; //str�����ܸı䣬һ��Ҫ����str
	if (value < 0)
	{
		*pstr++ = '-';
		value *= -1; //ת��Ϊ��������
	}
	int wei = 1; //������һλ
	int value_temp = value; // ���ڲ��Գ���
	while ((value_temp /= 10) > 0)
	{
		wei++;
	}
	pstr += wei; // �Ӻ���ǰת��
	*pstr-- = '\0'; // ���һλ��'\0'��β����ʵ����Ҳ���ԣ���Ϊ��ʼ��Ϊ0�˵�
	while (value > 0)
	{
		*pstr-- = value % 10 + '0';
		value /= 10;
	}
	return str;
}


int main_my_itoa(void)
{
	int num = -4564421;
	char str[20] = { 0 };
	cout << my_itoa(num, str) << endl;
	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}