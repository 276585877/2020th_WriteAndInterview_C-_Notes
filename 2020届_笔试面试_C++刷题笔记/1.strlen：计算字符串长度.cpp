#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
1.strlen�������ַ������ȣ�������'\0'��
ʵ���뷨�������ַ�����ֱ��'\0'����
***************************************/
// ָ�뷨
static unsigned int my_strlen(const char *str)
{
	int len = 0;
	while (*(str++)) // *(str++) �� *str++ һ��
	{
		len++;
	}
	return len;
}


int main_my_strlen(void)
{
	const char *str = "fengcong is fucking too handsome";  //32��
	cout << strlen(str) << endl;
	cout << my_strlen(str) << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}