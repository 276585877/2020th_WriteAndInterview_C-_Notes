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
static void * my_memset(const void * source, void * dest, size_t len)
{
	if (dest == nullptr || source == nullptr)
	{
		return nullptr;
	}

	char *pdest = (char *)(dest);
	char *psor = (char *)(source);
	char *plast = (char *)(source)+len;
	while (psor < plast)
	{
		*pdest++ = *psor++;
	}
	return dest;
}


int main_my_memset(void)
{
	char str[50] = "fengcong is fucking too handsome";
	char dest[50] = { 0 };
	char *pstr = dest;  //��ջ�Ͽ���һ���ڴ棬����ָ��

	//cout << (char *)my_memcpy(str, pstr, 30) << endl;
	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}