/*
list��˫�����������������������������е��κεط����г���ʱ�����Ͳ���������
���ң����������������Ͻ��е�����
*/

#include <iostream>
#include <list>
#include <string>
using namespace std;
/*
(1)���죺
(2)ͨ�ú����� push_back(), pop_back(), empty(), clear(), swap(), insert(), erase(), reverse()
(3)���в����� push_front(), pop_front(), merge(), remove(), remove_if()
*/

// һԪν��
bool is_odd(const int x) //�䵱һԪν��
{
	return (x % 2 == 1);
}


void myListTest()
{
	cout << "------this is class List demo----" << endl;
	list<int> myList{ 3, 5 };
	myList.push_back(7);
	myList.push_front(1); //˫������֧�������˵Ŀ��ٲ����ɾ��
	cout << "after push, myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	//���������������һ�����ڴ˲���׸��
	auto ret = myList.insert(myList.end(), 9);
	myList.insert(myList.begin(), 2); // �����������޴�
	cout << "after inserting, myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	// ����
	myList.sort();
	// ����
	// myList.reverse();


	list<int >myList1 = { 2, 4, 6, 8 };
	myList.merge(myList1); //�ϲ����������������غϲ���������������ϲ�֮ǰ������һ����ͻᱨ��
	cout << "after merging, myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	// ɾ������ֵΪ 8 ��Ԫ��
	myList.remove(8); 
	cout << "after removing, myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	//remove_if() //����������ʱ��ɾ��
	myList.remove_if(is_odd);//����Ϊ����ָ��
	cout << "after remove_if(is_odd), myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';


	//ɾ���ظ���Ԫ��
	myList.unique();
	cout << "after unique , myList is : " << endl;
	for (auto tmp : myList)
	{
		cout << tmp << ' ';
	}
	cout << '\n';

	
	// ��������
	list<int > mylist2;
	mylist2.assign(myList.begin(), myList.end());
	cout << "after assign , mylist2 is : " << endl;
	for (auto tmp : mylist2)
	{
		cout << tmp << ' ';
	}
	cout << '\n';
}

int main0211(void)
{
	myListTest();

	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	system("pause");
	return 0;
}