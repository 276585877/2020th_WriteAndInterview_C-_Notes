#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
8.memset����ָ���ڴ�ÿ���ֽڸ�ĳ��ֵ
˼·��һ��һ���ĸ�ֵ
***************************************/
// ָ�뷨
static void * my_memset(void * dest, const int val, size_t len)
{
	if (dest == nullptr)
	{
		return nullptr;
	}

	char *pdest = (char *)(dest);
	while (len--)
	{
		*pdest++ = val;
	}
	return dest;
}


int main_my_memset(void) // main_my_memset
{
	char str[50] = "fengcong is fucking too handsome";
	cout << (char *)my_memset(str, 65, 5) << endl;
	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}