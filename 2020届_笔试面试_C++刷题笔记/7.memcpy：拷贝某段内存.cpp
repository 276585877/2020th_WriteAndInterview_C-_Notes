#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
7.memcpy:����ĳ���ڴ�
˼·��һ��һ���Ŀ���
***************************************/
// ָ�뷨
static void * my_memcpy(const void * source ,void * dest, size_t len)
{
	if (dest == nullptr || source == nullptr)
	{
		return nullptr;
	}
	
	char *pdest = (char *)(dest);
	char *psor = (char *)(source);
	char *plast = (char *)(source) + len;
	while (psor < plast)
	{
		*pdest++ = *psor++;
	}
	return dest;
}


int main_my_memcpy(void)
{
	char str[50] = "fengcong is fucking too handsome";
	char dest[50] = { 0 };
	char *pstr = dest;  //��ջ�Ͽ���һ���ڴ棬����ָ��

	cout << (char *)my_memcpy(str, pstr, 30) << endl;
	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}