#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// ���������к���fun�Ĺ����ǣ��ӵ�λ��ʼȡ�������ͱ���s��ż��λ�ϵ�����
// ���ι���һ����������t�У���λ���ڸ�λ����λ�����ڵ�λ��

static void fun(long s, long *t)
{
	long s1 = 10;
	s /= 10;
	*t = s % 10;
	while (s > 0)
	{
		s = s / 100;
		*t = s % 10 * s1 + *t;
		s1 = s1 * 10;
	}
}


int main_0251646463165(void)
{
	long s, t;
	cout << "\nPlease enter s:  ";
	cin >> s;
	fun(s, &t);
	cout << "\nThe result is: " << t << endl;

	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}