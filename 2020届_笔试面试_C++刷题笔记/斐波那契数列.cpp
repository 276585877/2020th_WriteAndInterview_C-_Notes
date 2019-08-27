#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
��Ŀ����
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����n<=39
��˼·����
����˼·��쳲��������У�F(0)=0��F(1)=1, F(n)=F(n-1)+F(n-2)��n>=2��n��N*��
��һ��˼·����ֱ�۵��뷨�������ú����ĵݹ�����������ʱ�临�ӶȺͿռ临�Ӷȶ����󣬸��Ӷ���O��2^n������Ҳд����ش��룬���س�ʱ��
�ڶ���˼·������0����n��쳲���������Ԫ�ض�����������������С�
������˼·����һ��˼·�õ������飬ռ�ÿռ�϶ࡣ��ˣ����ԸĽ�Ϊֻ������������
***************************************/
class Solution {
public:
	//// ��һ��˼·����ֱ�۵��뷨�������ú����ĵݹ�������
	//int Fibonacci(int n) { // �������úܷ�ʱ��
	//	if (n == 0)
	//	{
	//		return 0;
	//	}
	//	if (n == 1)
	//	{
	//		return 1;
	//	}
	//	return Fibonacci(n - 1) + Fibonacci(n - 2);
	//}

	//// �ڶ���˼·������0����n��쳲���������Ԫ�ض�����������������С�
	//int Fibonacci(int n) {
	//	vector<int> Fibonacci_array(39);
	//	Fibonacci_array[0] = 0;
	//	Fibonacci_array[1] = 1;
	//	for (int i = 2; i <= n; i++)
	//	{
	//		Fibonacci_array[i] = Fibonacci_array[i - 1] + Fibonacci_array[i - 2];
	//	}
	//	return Fibonacci_array[n];
	//}

	// ������˼·����һ��˼·�õ������飬ռ�ÿռ�϶ࡣ��ˣ����ԸĽ�Ϊֻ������������
	int Fibonacci(int n) {
		int first = 0;
		int second = 1;
		int result = first + second;
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}
		for (int i = 2; i < n; i++) // �±��Ǵ�0��ʼ��
		{
			first = second;
			second = result;
			result = first + second;
		}
		return result;
	}
};

int main_쳲���������(void)
{
	Solution result;
	cout << "result = " << result.Fibonacci(5) << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}