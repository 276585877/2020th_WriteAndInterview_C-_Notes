#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
����Ŀ����
�ȿ��ȣ�һ����30��
���ĳһ���ܺȿ��ȣ�����������һ�κȹ����ȵ�ʱ��>=d��������һ�α���ȿ��ȵ�ʱ��Ҳ>=d
�������Ǵӣ��ſ�ʼö�٣����������������������Ǿ������ȿ��ȣ�������һ�κȿ��ȵ�ʱ��Ϊ���죬
���������һ�α���ȿ��ȵ�ʱ�䣬���µ�����һ�α���ȿ��ȵ�ʱ��

�����⣬�ȿ���
������k++����Ϊ��k�죬�൱���´κ��ǵ�k+1��֮�������������
���������ж�һ��m=0�������ʵ���Ͼ��Ǵӵ�һ�쿪ʼ̰�ĵĺ�
Ȼ����ڴ���������������ô�ж�
���жϴӵ�һ�쵽��num[0]��Ҫ�ȶ����쿧�ȣ���Ϊ��num[0]�����Ҫ�ȣ�
Ȼ������һ���ܺȵ������Դ����Ƶ�������ȥֱ�����˵���һ��֮ǰ�����Ƿ�״̬
������һ��һ�ε��жϣ����ڴӣ�num[i],num[i+1]��������ұյ�������˵��
����Ҳ�ǵ������ƣ���num[i+1]�����Ҫ�ȣ�Ȼ�����k�죬��Ҫע����ǣ���Ϊ��num[i]Ҳ�Ǳ���Ҫ�ȿ��ȵģ�
����˵�������˵�num[i]+k֮ǰ���ǷǷ�����
����Ǵ���num[m-1]����30����Σ����Ҳ��̰�ĵ��ж�һ�¾����ˡ�
��˼·����

***************************************/
static int t, k, m;
static int num[33];
static int ans = 0;
int main_���׻���__������() // ţ���ϵĴ���
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &k, &m);
		k++;
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &num[i]);
		}
		ans = 0;
		if (m == 0)
		{
			int temp = 1;
			while (temp <= 30)
			{
				ans++;
				temp += k;
			}
			printf("%d\n", ans);
			continue;
		}
		int temp = num[0];

		while (temp >= 1)
		{
			ans++;
			temp -= k;
		}
		for (int i = 1; i < m; i++)
		{
			temp = num[i];
			while (temp >= num[i - 1] + k)
			{
				ans++;
				temp -= k;
			}
		}
		temp = num[m - 1] + k;
		while (temp <= 30)
		{
			ans++;
			temp += k;
		}
		printf("%d\n", ans);
	}
	return 0;
}
//int main(void)
//{
//	int n;
//	cin >> n;
//	vector<int> res(n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		int K, M;
//		cin >> K >> M;
//		vector<int> marr(M, 0);
//		for (int j = 0; j < M; j++)
//		{
//			cin >> marr[j];
//		}
//
//		int count = 0;
//		if (marr.size() == 0)
//		{
//			count = 30 / (K + 1);
//		}
//		else
//		{
//			count = M;
//			count += (marr[0] - 1) / (K + 1);
//			if (marr.size() > 1)
//			{
//				for (int j = 1; j < M; j++)
//				{
//					if (marr[j] - marr[j - 1] > (K + 1))
//					{
//						count += (marr[j] - marr[j - 1] - 1) / (K + 1);
//					}
//				}
//				count += (30 - marr[marr.size() - 1]) / (K + 1);
//			}
//		}
//		res[i] = count;
//	}
//	for (auto it : res)
//	{
//		cout << it << endl;
//	}
//	return 0;
//}