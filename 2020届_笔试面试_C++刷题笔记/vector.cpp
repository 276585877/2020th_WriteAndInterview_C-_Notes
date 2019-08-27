#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �����ά����vector<vector<int>> array
static void input_2D_Array(vector<vector<int>> &array, const int n, const int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			// ����ֱ��ͨ����vector[0] = "aa"��ֵ���±����޸Ĳ��ǲ���
			array[i].push_back((i + 1)*(j + 1));
		}
	}
}

// ��ӡ��ά����vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

/*
ʵ�� vector ������һά������
�� 1�����졢��ֵ:
�� 2������������ size(), empty(), push_back(), pop_back(), insert(), erase(), clear(), swap();
*/
static void myVectorTest_1D()
{
	cout << "-----------this is class vector demo------" << endl;
	vector<int> myVec = { 1, 3, 5, 7, 9 };
	vector<int> myVec1 = { 4, 6, 8 };
	cout << "the size of myVec�� " << myVec.size() << endl;
	myVec.reserve(10);// �����������ٿ����ɵ�Ԫ����
	cout << "max_size : " << myVec.max_size() << endl; // �������������ɵ����Ԫ����
	myVec.shrink_to_fit(); // ������С�� capacity������������Ӧ�� size��Ԫ��������


	cout << "myVec.front():" << myVec.front() << endl; // ���������е�һ��Ԫ�ص�����
	cout << "myVec.back():" << myVec.back() << endl; // �������������һ��Ԫ�ص�����


	//��β������ַ�
	myVec.push_back(0);
	cout << "after pushing, myVec is: " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << endl;


	/*
	insert()�汾��
	�� 1�� insert(p, t) //�ڵ����� p ��λ�ò���һ��ֵΪ t������ָ������ӵ�Ԫ�صĵ�����
	�� 2�� insert(p, b, e) //��������[b, e��ָ����Ԫ�ز��뵽 p ��ָλ�ã����ص�һ������Ԫ�صĵ�����
	�� 3�� insert(p, il) //���б��е�Ԫ�ز��룬���ص�һ������Ԫ�صĵ�����
	//���ڵ�����ȷ����Χ��������ҿ���������
	*/
	auto ret = myVec.insert(myVec.begin() + 1, 2); //���뵥��Ԫ�أ����ظ�Ԫ�ص�����
	cout << "after inserting , myVec is : " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << "���صĵ�����ֵΪ�� " << *ret << endl;


	//��������[b, e��ָ����Ԫ�ز��뵽 p ��ָλ�ã����ص�һ������Ԫ�صĵ�����
	auto ret1 = myVec.insert(myVec.begin() + 1, myVec1.begin(), myVec1.end());
	cout << "after inserting , myVec is : " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << "���صĵ�����ֵΪ�� " << *ret1 << endl;


	/*
	erase()�汾��
	�� 1�� erase(p) //ɾ�������� p ��ָԪ�أ�������һ��Ԫ�صĵ�����
	�� 2�� erase(b, e) //ɾ��������[b, e) ��Χ�ڵ�Ԫ�أ�
	//���ڵ�����ȷ����Χ��������ҿ���������
	*/
	//ɾ������������ָ���Ԫ�أ�
	auto ret2 = myVec.erase(myVec.begin() + 1);
	cout << "after earsing , myVec is : " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << "���صĵ�����ֵΪ�� " << *ret2 << endl;


	//ɾ��������[b, e) ��Χ�ڵ�Ԫ�أ�
	auto ret3 = myVec.erase(myVec.begin() + 1, myVec.begin() + 4);
	cout << "after earsing , myVec is : " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << "���صĵ�����ֵΪ�� " << *ret3 << endl;


	//��������������ֵ����ʵʵ���ϲ�������
	swap(myVec, myVec1);
	cout << "after swapping , myVec is : " << endl;
	for (auto tmp : myVec)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	// 8.�㷨  �㷨�͵����� �����޷������ ,��ĳ��Ԫ���������еĸ���
	auto num1 = count(myVec.begin(), myVec.end(), 2);//��2���ĸ���
	cout << "num1 : " << num1 << endl;


	// �� vector ��ɾ�����е�Ԫ�أ������٣������� size Ϊ 0 ������
	myVec1.clear(); 
}


/*
ʵ�� vector �����Ķ�ά������
*/
void myVectorTest_2D()
{
	// 9.��ά������vector��Ҫ��ʾ�����һά�������У�
	int n = 4;
	int m = 3;
	vector<vector<int>> array(n);
	input_2D_Array(array, n, m);
	print_2D_Array(array);

	// 10.��ά���������ӡ
	for (unsigned i = 0; i < array.size(); i++)
	{
		reverse(array[i].begin(), array[i].end());
	}
	print_2D_Array(array);

}


int main1561651651()
{
	myVectorTest_1D();

	cout << endl;
	cout << endl;

	myVectorTest_2D();
	

	system("pause");
	return 0;
	//�Զ��Ű棺ctrl+K,ctrl+F
}