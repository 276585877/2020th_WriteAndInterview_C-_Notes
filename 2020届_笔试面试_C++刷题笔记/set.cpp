#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

/*
//����Ԫ�ض��ǰ����ֵ����Զ����� set ֻ�м�ֵ����ֵ������ֵ
�� 1�����죺
�� 2��ͨ�ò����� empty(), insert(), erase(), size(), swap(), find(), count(),
�� 3�����в����� equal_range(), lower_bound(), upper_bound()
*/
void mySetTest()
{
	cout << "----this is class set demo-------" << endl;
	set<string >mySet = { "a", "c", "b" };


	/*
	//insert ����һ�� pair<first,second>�� first ��һ��������ָ����и����ؼ��ֵ�ֵ�� second ��һ�� bool ����
	���� true ���ʾ����ɹ�����Ϊ false ���ʾ����ʧ�ܣ�˵���Ѿ����ڣ�������ʲôҲ����
	m.insert(e); //���� pair ����
	m.insert(beg, end); //����Χ�ڵ�Ԫ�ز���
	m.insert(iter, e); //unknow
	*/
	bool flag = mySet.empty();
	auto ret = mySet.insert("d"); //�����ֵ
	cout << "insert : " << *ret.first << endl;
	cout << "after inserting, mySet is : \n";
	if (ret.second)
	{
		for (auto tmp : mySet)
			cout << tmp << ends;  // a  b  c  d  �Զ�����
	};
	cout << "\n";


	// eraseɾ��Ԫ��
	auto ret1 = mySet.erase("d"); //ɾ��Ԫ��
	cout << "after erase d, mySet is : \n";
	for (auto tmp : mySet)
		cout << tmp << ends;
	cout << "\n";


	// find����Ԫ��
	auto ret2 = mySet.find("a");
	if (ret2 == mySet.end())
		cout << "dont find it \n";
	else
		cout << "find it:" << *ret2 << endl;

	// ����Ԫ�ظ���
	unsigned int cnt = mySet.count("a");
	printf("a occurred %d times \n", cnt);


	// ����һ���ǵݼ����� [first, last)���������еĵ�һ��   ���ڵ���   ֵ val����������λ�õĵ�����
	set<string>::iterator iter_beg = mySet.lower_bound("b");
	cout << "iter_beg : " << *iter_beg << endl;
	// ����һ���ǵݼ����� [first, last)���������е�һ��   ����   val����������λ�õĵ�����
	set<string>::iterator iter_end = mySet.upper_bound("b");
	cout << "iter_end : " << *iter_end << endl;
	//�����ؼ��ֵķ�Χ[lower_bound, upper_bound)
}

int main25126226(void)
{
	mySetTest();

	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	system("pause");
	return 0;
}