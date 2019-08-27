/*
forward_list���������������������������������е��κεط����к㶨��ʱ�����Ͳ���������
*/

#include <iostream>
#include <string>
#include <cmath>
#include <forward_list>
using namespace std;


void myForward_listTest()
{
	cout << "----this is class forward_list demo---" << endl;
	forward_list<int> myForward_list = { 1, 3, 7, 5, 5 };
	cout << "the front of myForward_list is : " << myForward_list.front() << endl; //front ��
	myForward_list.push_front(0); // ͷ�巨
	for (auto tmp : myForward_list)
		cout << tmp << ' ';
	cout << endl;


	/*
	lst.insert_after(p, t) //�ڵ����� p ֮���λ�ò���Ԫ�� t������ָ�����Ԫ�صĵ�����
	lst.insert_after(p, b, e) //�ڵ����� p ֮����뷶ΧΪ[b, e����Ԫ�أ��������һ����������ĵ�����
	*/
	myForward_list.insert_after(myForward_list.before_begin(), 9);
	//list �� forward_list ��Ȼ��֧��+,-����������֧��++��-- ����
	cout << "after inserting , myForward_list is : " << endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		cout << *iter << ends;
	}
	cout << '\n';
	

	//ɾ��ĳһ�ض�λ��Ԫ��
	myForward_list.erase_after(myForward_list.before_begin());
	cout << "after erasing , myForward_list is : " << endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		cout << *iter << ends;
	}
	cout << '\n';


	myForward_list.remove(1); //ɾ��ĳһ�ض�ֵԪ��
	//myForward_list.remove_if(is_odd); //���մ���ν����ɾ��ĳһԪ��


	//ɾ���ظ���Ԫ��
	myForward_list.unique(); 
	cout << "after unique , myForward_list is : " << endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		cout << *iter << ends;
	}
	cout << '\n';


	//���������ݽ�������
	myForward_list.sort(); 
	cout << "after sorting , myForward_list is : " << endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		cout << *iter << ends;
	}
	cout << '\n';


	// ���������ݽ�������
	myForward_list.reverse();
	cout << "after reverse , myForward_list is : " << endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		cout << *iter << ends;
	}
	cout << '\n';
}

int main04111111111111111111111(void)
{
	myForward_listTest();
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	system("pause");
	return 0;
}