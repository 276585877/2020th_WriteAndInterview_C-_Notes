#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
С��ͬѧ���ѧϰ�˸����ۣ����˽⵽��ѧ�����Ķ��壺
��XΪһ�����������X����ȡn�ֲ�ͬ��ȡֵx1,x2,x3,��,xn��
ȡx1�ĸ���Ϊp1,ȡx2�ĸ���Ϊp2,�Դ����ơ������������X����ѧ����Ϊ��E[X]=x1*p1+x2*p2+��+xn*pn��
С���ص����У������̼�����ѧ���������ܰ�����ô��

����
�����һ��һ����n(1<=n<=100)����������n�У���i����������xi��pi��xi��pi����������
-100<=xi<=100, 0<=pi<=100����ʾ�������XȡֵΪxi�ĸ�����pi/100�����뱣֤p1+p2+p3+��+pn=100��
���
���һ�������������X����ѧ����E[x]��С������������뱣��3λ��

��������
3
0 50
1 20
2 30

�������
0.800
*/

int main5121563564154165614651465(void)
{
	int N;
	double sum = 0;
	while (cin >> N)
	{
		int x, p;
		while (N--)
		{
			cin >> x >> p;
			sum += x * static_cast<double>(p) / 100;
		}
		printf("%.3f\n", sum);
	}

	//cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}