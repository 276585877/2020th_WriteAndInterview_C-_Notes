#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
3.strcpy�������ַ������ƣ����ư���'\0'��
ʵ���뷨��һֱ���Ƶ�'\0'����
***************************************/
// ָ�뷨
static char * my_strcpy(char * dest, const char * source)
{
	if (dest == nullptr || source == nullptr)
	{
		return nullptr;//���Ŀ�Ĳ�������ԴΪ�գ���ô��ֱ�ӷ���
	}

	while (*source)
	{ 
		*dest++ = *source++;
	}
	*dest = '\0';
	return dest;
}


int main_my_strcpy(void)
{
	const char * str1 = "fengcong is fucking too handsome";
	//char str2[100]; //Ŀ���ַ�����
	char *str2 = new char[strlen(str1) + 1];
	my_strcpy(str2, str1);
	cout << str2 << endl;

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}