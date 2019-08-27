#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

//���ַ�ʽ��1���ֶ������ڴ档2��ʹ��STL���vector��
static void printArray(int *array, const int len)
{
	// �������
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << '\t';
	}
	cout << endl;
}

static void printArray(vector<int> &array)
{
	for (auto it = array.begin(); it != array.end(); ++it)
	{
		cout << *it << '\t';
	}
	cout << endl;
}

int main12_21(void)
{
	int N = 0;
	cin >> N;

	// һά��������ڴ�����￪ʼ
	int *array = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];   //��Ҫ�ֶ�����Ԫ��
	}
	//cin.get();  //������Ҫ���������еĻ��з�

	// �������
	printArray(array, N);
	delete array;

	system("pause");
	return 0;
	//�Զ��Ű棺ctrl+K,ctrl+F
}

//�������붨�岻�̶���С���ַ�ʱ,����ʹ�� vector(����) ��׼�⡣
int main_121331125(void) 
{
	// �����������ڴ洢��������
	vector<int> vec;
	int N = 0;
	int num = 0;
	cin >> N;
	// ��ʾ vec ��ʼ��С
	cout << "vector size = " << vec.size() << endl;

	// ������ vec ׷�� N ������ֵ
	for (int i = 0; i < N; i++) 
	{
		cin >> num;
		vec.push_back(num);
	}

	// ��ʾ׷�Ӻ� vec �Ĵ�С
	cout << "extended vector size = " << vec.size() << endl;
	/////////////////�������//////////////////////////////////
	printArray(vec);
	system("pause");
	return 0;
}