#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
9.strcat���ַ�������
˼·��ֱ�ӽ���Ŀ���ַ�����β��
***************************************/
// ָ�뷨
static char * my_strcat(char * dest, const char * src)
{
	char *pdest = dest;
	while (*pdest)
	{
		pdest++; // ��β��ȥ
	}
	while (*src)
	{
		*pdest++ = *src++;
	}
	return dest;
}


int main_my_strcat(void) // main_my_strcat
{
	char str[30] = " fucking too handsome";
	char dest[50] = "fengcong is";
	cout << my_strcat(dest, str) << endl;
	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}