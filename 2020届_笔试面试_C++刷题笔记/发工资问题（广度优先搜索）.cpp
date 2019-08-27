#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
����Ҫ��Ա�������ʣ�Ա������������һ�ţ�ÿ��Ա��֪���˴˵�������
ÿ��Ա��ֻ֪���Լ�����Ա���Ĺ��ʣ����ĳԱ������߻��ұߵ��������ϣ�
����һ��������˹��ʸ�100Ԫ��ÿ������͹���100Ԫ����������͸����ٹ��ʡ�

����
���룺
4 //����Ա��
3 9 2 7 //Ա��˳���Լ���Ӧ������
�����
600 //100Ԫ��200Ԫ��100Ԫ��200Ԫ

6
1 2 3 4 5 6
2100 //100��200��300��400��500��600

5
1 1 1 1 1
500 //100��100��100��100��100

8
1 2 3 4 3 2 3 4
1800 //100 200 300 400 200 100 200 300

8
3 4 3 4 3 4 3 4
1200 //100 200 100 200 100 200 100 200

4
1 2 3 3
700 //100 200 300 100

˼·��100/100�֣���
���ڸ�����һ���������ӿ�ʼ���󣬵�һ����ʼ��Ϊ 100����������ʼ�� i + 100 �� money ֵ��
�� i ��Ӧ�������� i+1 ������Сʱ�� i+1 Ӧ���õ������Ǯ�������� money[i+1]=money[i]+100;
�� i ��Ӧ�������� i+1 ���ʱ������Ҳ���������� money[i+1] ��Ϊ 100 ��
�� i ��Ӧ�������� i+1 ��ʱ��money[i+1] Ӧ���Ǵ�ʱ��С�ģ�������Ϊ 100 �����ǿ��ܺ���ĸ�����ͬ�����С��
���Ҫ������������������Щ money ����һ�£��˴�����һ�� for ѭ����ѭ���� j=i+1 ��ʼ��
�� years[j-1]>years[j] && money[j - 1] <= money[j] ʱ�� j-- ��������������ֵ�� 100.����ۼ�
*/

static void fun(vector<int> &years, const int n)
{
	vector<int> money(n, 0);
	int result = 0;

	money[0] = 100;
	for (int i = 0; i < n - 1; ++i)
	{
		if (years[i] < years[i + 1]) // �� i ��Ӧ�������� i+1 ������Сʱ
		{
			money[i + 1] = money[i] + 100;
		}
		else if (years[i] > years[i + 1]) // �� i ��Ӧ�������� i+1 ��ʱ
		{
			money[i + 1] = 100;
			if (money[i] <= money[i + 1])
			{
				for (int j = i + 1; years[j - 1] > years[j] && money[j - 1] <= money[j]; --j)
				{
					money[j - 1] += 100;
				}
			}
		}
		else // �� i ��Ӧ�������� i+1 ���ʱ
		{
			money[i + 1] = 100;
		}
	}
	
	for (auto it : money)
	{
		cout << it << " ";
		result += it;
	}
	cout << result << endl;
}

int main_������(void)
{
	int n = 0;
	vector<int> years;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		years.push_back(temp);
	}

	fun(years, n);

	return 0;
}