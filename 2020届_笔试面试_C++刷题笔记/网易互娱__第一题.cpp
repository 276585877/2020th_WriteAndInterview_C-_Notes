#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/***************************************
����Ŀ����
�ж������һ������תΪ�����ƺ��ܷ��γɻ���
����������
��һ����n����n������
����n�У�n������
���������
�Ƿ�Ϊ����
���룺
3
2
3
5
�����
NO
YES
YES
��˼·����
1��תΪ�����ƣ��жϼ���
2����ת����ջ���������÷�����ȥ�ҽ���
***************************************/

static string TenToTwo(int n)
{
	string ans = "";
	do
	{
		int t = n % 2;
		ans += t + '0';
		n /= 2;
	} while (n != 0);    //ʹ��do{}while�����Է�ֹ����Ϊ0�����
	reverse(ans.begin(), ans.end());
	return ans;
}

int ���׻���__��һ��(void) // ���׻���__��һ��
{
	int n;
	while (cin >> n)
	{
		if (n <= 0)
		{
			break;
		}
		vector<int> input_(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> input_[i];
		}
		for (int i = 0; i < n; ++i)
		{
			string res = TenToTwo(input_[i]);
			cout << "res = " << res << endl;
			string num2 = res;
			reverse(num2.begin(), num2.end());
			cout << (num2 == res ? "YES" : "NO") << endl;
		}
	}
	return 0;
}