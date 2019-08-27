#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

/*
map �ǹ�������������   �ض�˳��   �洢�� key (��ֵ) value (ӳ��ֵ) ����γɵ�Ԫ�ء�
�� 1�����죺 map<string, int>, pair<string, int>, make_pair(v1, v2)
�� 2����������� first, second, insert(), erase(), count(), find(), operator[]();
*/
void myMapTest()
{
	cout << "---------this is class map demo---------" << endl;
	map<string, int>myMap;
	auto myPair1 = pair<string, int>("hello", 1);
	auto myPair2 = make_pair("bworld", 3);
	auto myPair3 = make_pair("cqqqqq", 10);

	map<string, int, less<string>>myMap2;// ��ֵ�Ӵ�Сgreater<int>,��ֵ��С����less<Type> 
	/*
	//insert ����һ�� pair<first,second>; first ��һ��������ָ����и����ؼ��ֵ�ֵ�� second ��һ�� bool �������� true ���ʾ����ɹ���
	//��Ϊ false ���ʾ����ʧ�ܣ�˵���Ѿ����ڣ�������ʲôҲ������ֻ���ֶ���++
	m.insert(myPair1); //���� pair ����
	m.insert(beg, end); //����Χ�ڵ�Ԫ�ز���
	m.insert(iter, e); //unknow
	*/
	// �洢˳��Ϊ �� key�ؼ���  ������˳��
	auto ret1 = myMap.insert(myPair1);//insert ����һ�� pair<first,second>;
	if (ret1.second)
		cout << "insert successfully\n"; //���� pair ����
	printf("%s---->%d\n", ret1.first->first.c_str(), ret1.first->second);
	auto ret2 = myMap.insert(myPair2);
	if (ret2.second)
		cout << "insert successfully\n";
	printf("%s---->%d\n", ret2.first->first.c_str(), ret2.first->second);
	auto ret3 = myMap.insert(myPair3);
	if (ret3.second)
		cout << "insert successfully\n";
	printf("%s---->%d\n", ret3.first->first.c_str(), ret3.first->second);
	printf("\n");


	// ������������ӡ
	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		printf("%s---->%d\n", iter->first.c_str(), iter->second);
	}
	printf("\n");


	// �±���������޸Ļ����
	++myMap["aaabbb"]; //ʹ���±���������������ڣ��򴴽��µļ�ֵ��(word, 0)��ע����insert������
	myMap["world"] += 2;
	cout << "after operator[], myMap is : \n";
	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		printf("%s---->%d\n", iter->first.c_str(), iter->second);
	}
	printf("\n");


	/*
	m.erase(k); //ɾ���ؼ���Ϊ k ��Ԫ��
	m.erase(p); //ɾ�������� p ָ���Ԫ��
	m.erase(b, e); //ɾ����Χ�ڵ�Ԫ��
	*/
	myMap.erase("aaabbb");//ɾ���ؼ���Ϊword��Ԫ��
	cout << "after erasing, myMap is : \n";
	//for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	//{
	//	printf("%s---->%d\n", iter->first.c_str(), iter->second);
	//}
	for (auto tem : myMap)
	{
		cout << tem.first << "---->" << tem.second << endl;
	}
	printf("\n");


	// ����Ԫ�ظ���
	unsigned cnt = myMap.count("hello"); //���عؼ��ֵĸ���
	printf("hello occurred %d times\n", cnt);
	printf("\n");


	// ����ĳ���ؼ��ֵĵ�����
	cout << "find keyword hello : \n";
	auto ret4 = myMap.find("hello"); //����ҵ��򷵻ص������� ���򷵻�map::end �ĵ�����
	if (ret4 != myMap.end()) // ������һ�䣬����û�ҵ����ᱨ����Ϊ���ܴ�myMap.end()����ȡֵ��
	{
		printf("%s---->%d\n", ret4->first.c_str(), ret4->second);
	}
	printf("\n");


	// map �������򣬲�������


	// ����һ���ǵݼ����� [first, last)���������еĵ�һ��   ���ڵ���   ֵ val����������λ�õĵ�����
	auto ret5 = myMap.lower_bound("cqqqqq");// lower_bound(myMap.begin(), myMap.end(), "sss");
	printf("%s---->%d\n", ret5->first.c_str(), ret5->second);
	printf("\n");


	// ����һ���ǵݼ����� [first, last)���������е�һ��   ����   val����������λ�õĵ�����
	auto ret6 = myMap.upper_bound("cqqqqq");// lower_bound(myMap.begin(), myMap.end(), "sss");
	printf("%s---->%d\n", ret6->first.c_str(), ret6->second);
	printf("\n");

}


int main1165161(void)
{
	myMapTest();

	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	system("pause");
	return 0;
}