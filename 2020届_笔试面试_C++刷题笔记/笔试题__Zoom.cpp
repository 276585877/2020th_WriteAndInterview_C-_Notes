#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
����������a,b,c����һ������f(n) = n�ĸ�λ�������������磺f(12) = 1^3+2^3 = 9��
Ҫ��n�ĸ�����n���㣺a <= n <= b����c*f(n)=n��
*/

long long f(long long n)
{
	vector<int> nn;
	int temp = 0;
	long long sum = 0;
	while (n > 0)
	{
		temp = n % 10;
		n = n / 10;
		nn.push_back(temp);
	}

	for (auto it : nn)
	{
		sum += pow(it, 3);
	}
	//cout << " sum = " << sum << endl;
	return sum;
}

int main_Zoom������(void)
{
	long long a, b, c;
	cin >> c >> a >> b;
	int count = 0;
	for (long long n = a; n <= b; n++)
	{
		if ((c * f(n)) == n)
		{
			count++;
		}
	}
	cout << count << endl;
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}