#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
4.strstr��Ѱ��ĸ�����Ƿ����ĳ���Ӵ������ѣ�
ʵ���뷨�����αȶ�
***************************************/
// ָ�뷨
static char * my_strstr(const char * source, const char * sub)
{
	if (source == nullptr || sub == nullptr)
	{
		return nullptr;
	}

	char *cur = const_cast<char *>(source);
	while (*cur)
	{
		char *p2 = const_cast<char *>(sub);
		bool flag = true;
		if (*cur == *p2)
		{
			char *p1 = cur; // ��¼��һ����ͬ��λ�á�
			while (*p2)
			{
				if (*p1 != *p2)
				{
					flag = false;
					break;
				}
				p1++;
				p2++;
			}
			if (flag == true)
			{
				return cur;
			}
		}
		cur++;
	}
	if (*cur == '\0')
	{
		cout << "δ�ҵ�" << endl;
		return const_cast<char *>(sub);
	}
}


int main_my_strstr(void)
{
	const char * str = "fengcong is fucking too handsome";
	char *p = my_strstr(str, "is");
	cout << p << endl;

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}