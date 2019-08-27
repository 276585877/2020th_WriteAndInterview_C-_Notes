#include <iostream>
#include <string>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(deque<int> myDeque)
{
	for (auto tmp : myDeque)
	{
		cout << tmp << ends;
	}
}


/*
//��˫�˶��У��� double-ended queue�����������ˣ�ǰ�˻��ˣ������ɾ����
//�ص㣺֧��������ʣ��������ڲ����в����ɾ�������������˲���ɾ��������ã�
�� 1��������
�� 2��ͨ�ò����� push_back(), pop_back(), insert(), erase(),
clear(), swap(), empty(), back(), front(), at(), []
�� 3�����в����� push_front(), pop_front()
*/
void myDequeTest()
{
	cout << "-----this is class deque demo--" << endl;
	deque<int >myDeque = { 3, 5, 7 ,7 ,7, 7};
	printDeque(myDeque);
	cout << '\n';


	myDeque.push_back(9); //�ڶ���β�����Ԫ��
	myDeque.push_front(1); //�ڶ���ͷ�����Ԫ��
	cout << "after pushing, myDeque is: \n";
	printDeque(myDeque);
	cout << '\n';


	myDeque.pop_back(); // ɾ�� deque �����е����һ��Ԫ�أ���Ч�ؽ�������С����һ��
	myDeque.pop_front(); // ɾ�� deque �����еĵ�һ��Ԫ�أ���Ч�ؼ�С���С
	printDeque(myDeque);
	cout << '\n';


	myDeque.emplace_front(10); // �� deque �Ŀ�ͷ����һ���µ�Ԫ�أ������䵱ǰ�ĵ�һ��Ԫ��֮ǰ
	myDeque.emplace_back(11); // �� deque ��ĩβ����һ���µ�Ԫ�أ������ڵ�ǰ�����һ��Ԫ��֮��
	printDeque(myDeque);
	cout << '\n';


	/*
	insert()�汾��
	�� 1�� insert(p, t) //�ڵ����� p ֮ǰ����һ��ֵΪ t������ָ������ӵ�Ԫ�صĵ�����
	�� 2�� insert(p, b, e) //��������[b, e��ָ����Ԫ�ز��뵽 p ��ָλ�ã����ص�һ������Ԫ�صĵ�����
	//���ڵ�����ȷ����Χ��������ҿ���������
	*/
	auto ret = myDeque.insert(myDeque.begin() + 1, 2);
	cout << "after inserting, myDeque is: \n";
	printDeque(myDeque);
	cout << '\n';
	cout << "���ص���ָ���Ԫ��Ϊ�� ";
	cout << *ret << endl;


	//��������[b, e��ָ����Ԫ�ز��뵽 p ��ָλ�ã����ص�һ������Ԫ�صĵ�����
	deque<int> myDeque2 = { 7,8,8 };
	auto ret1 = myDeque.insert(myDeque.begin(), myDeque2.begin(), myDeque2.end());
	cout << "after inserting , myDeque is : " << endl;
	printDeque(myDeque);
	cout << '\n';
	cout << "���صĵ�����ֵΪ�� " << *ret1 << endl;


	// erase:
	auto ret2 = myDeque.erase(myDeque.begin() + 1);
	cout << "after earsing, myDeque is: \n";
	printDeque(myDeque);
	cout << '\n';
	cout << "���ص���ָ���Ԫ��Ϊ�� ";
	cout << *ret2 << endl;


	// ����
	auto cnt = count(myDeque.begin(), myDeque.end(), 7);
	cout << "cnt = " << cnt << endl;


	// sort ����
	sort(myDeque.begin(), myDeque.end());
	cout << "after sort, myDeque is: \n";
	printDeque(myDeque);
	cout << endl;


	// ɾ���ظ�Ԫ�أ�����ûɶ�ã�û��ɾ����
	auto itit = unique(myDeque.begin(), myDeque.end());
	myDeque.erase(itit, myDeque.end());//����Ԫ�أ������ظ�Ԫ��������������ظ������е�β���������
	// һ�� sort ֮��ʹ�ø�Ԫ�ؽ��ظ�Ԫ�ط�������ظ������еĺ��棬Ȼ�����ʹ�� erase ɾ��
	printDeque(myDeque);
	cout << endl;
}



int main1231231(void)
{
	myDequeTest();


	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	system("pause");
	return 0;
}