#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
СB�˻𳵺�������һ����N�е�M��֮�����С�����·;��ʱ˯ʱ�ѡ����������ۿ�����ķ羰ʱ��
ע�⵽ÿ����վ����һ���ر���ɫ�����ģ����������������Ľ����Ǿ�����һС���֡�
СB�ڳ˳����������������ѵ�ʱ�䣬�������ó��յ�ʱ����˯���С�
��վʱ������������̸����һ·�ļ��ţ������Ǿ��ú�����˼��

���ǰ�N����M֮�侭����վ��������ɫ�����г�����Ȼ�������СB�ǵõ�������ɫ���У�
�����ж�СB�����Ǵ�N��M֮����Щ������ܿ�����˵��ɫ�����ģ����Ǹ����Ͳ����ܿ�����
��ɫ����ĸ������ͬ����ĸ������ͬ����ɫ����ͬ����ĸ���ʾ��ͬ����ɫ��

����
�������ж���������ݡ�ÿ��������ݰ������У���һ��Ϊһ����Сд������ĸ���ɵķǿ��ַ�����
���Ȳ�����10^5����ʾN��M֮�䳵վ����ɫ���𳵴�M��N����ʱ�������ĳ�վ��ͬ��ֻ�Ƿ����෴��
�ڶ���ΪСB�ڵ�һ��˯��ʱ��������ɫ���У�������ΪСB�ڵڶ���˯��ʱ��������ɫ���С�
�������ж���Сд��������ĸ���ɵ��ַ��������Ȳ�����100����ĸ��
ÿ�����е���ɫ˳�����а�СB������ʱ��˳�����С�
���
��ÿ��������ݣ��ڵ������������СB�����з���
forward �C ��N��M����
backward �C ��M��N����
both �C ���ַ����п��ܣ�
invalid �C �����ܿ�����������ɫ���У�

��������
atob
a
b
aaacaaa
aca
aa

�������
forward
both
*/

int main410584036641354512568416451365841()
{
	string str, str1, str2;
	while (cin >> str >> str1 >> str2)
	{
		bool flag1 = false, flag2 = false;
		unsigned int index = 0;
		if (!str.empty())
		{
			//forward
			if (!str1.empty() && str.find(str1) != string::npos)  //�Ӵ�1�ǿ�������ĸ�����ҵ�
			{
				index = str.find(str1) + str1.length();          //�ҵ�ĸ�����Ӵ�2�Ŀ�ʼ����λ��
				flag1 = (!str2.empty() && str.find(str2, index) != string::npos) ? true : false;
			}
			reverse(str.begin(), str.end());                  //��תĸ��

			//backward
			if (!str1.empty() && str.find(str1) != string::npos)
			{
				index = str.find(str1) + str1.length();
				flag2 = (!str2.empty() && str.find(str2, index) != string::npos) ? true : false;
			}
			if (flag1 && flag2)
				cout << "both" << endl;
			else if (flag1)
				cout << "forward" << endl;
			else if (flag2)
				cout << "backward" << endl;
			else
				cout << "invalid" << endl;
		}
	}
	return 0;
}