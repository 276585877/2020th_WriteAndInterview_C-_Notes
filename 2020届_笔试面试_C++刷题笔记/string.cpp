#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
ʵ�� string �����Ĳ�����
�� 1�����졢��ֵ:
�� 2������������ size(), empty(), push_back(), pop_back(), insert(), erase(), clear();
�� 3�� string ���в����� substr(), append(), replace(), find()ϵ�к���, compare(), strstr()
*/
void myStringTest()
{
	cout << "---------this is class string demo--------------------------" << endl;
	string str1 = "hello world";
	cout << "the length of str1�� " << str1.size() << endl; // 11.


	str1.push_back('!'); //��β������ַ�
	cout << "after pushing, str1 is: " << str1 << endl;


	auto ret = str1.insert(str1.begin() + 5, '@');// ����Ϊ����������������ַ������ص���ָ�����Ԫ�صĵ�����
	cout << "after inserting, str1 is : " << str1 << endl;
	cout << "���뷵�صĵ�������ָ���ֵΪ�� " << *ret << endl;


	auto ret1 = str1.insert(6, "#"); //����Ϊ�±�ģ���������ַ��������ص��ǲ���֮�� str1 ������,��ס�ַ����±��Ǵ� 0 ��ʼ��
	cout << "after inserting, str1 is : " << str1 << endl;
	cout << "���뷵�ص�ֵΪ�� " << ret1 << endl;


	auto ret2 = str1.erase(str1.begin() + 5); //���ܵ������汾�ģ�����ɾ��Ԫ�ص���һ��Ԫ�صĵ�����
	cout << "after earsing , str1 is: " << str1 << endl;
	cout << "���صĵ�����ָ��Ԫ��Ϊ�� " << *ret2 << endl;


	auto ret3 = str1.erase(5, 1); //�����±�����ģ�����ɾ�����ȣ�����ɾ������ַ���
	cout << "after earsing , str1 is: " << str1 << endl;
	cout << "����ɾ������ַ���Ϊ�� " << ret3 << endl;


	//string s.substr(pos, n) //n ��ȱʧ������β����n��д��Ĭ�ϵ��ַ���ĩβ
	string str2 = str1.substr(0, 5); //�� 0 ��ʼ������Ϊ 5 ���Ӵ�
	cout << "after substr, str2 is :" << str2 << endl;


	str1.append("!!!"); //��β������Ӵ�
	cout << "after appending, str1 is :" << str1 << endl;


	//string &s.replace(range, args) //�� range ��Χ�ڵ�Ԫ�أ��滻Ϊ args�����Բ�һ����
	//�������ֳ����ģ�
	str1.replace(5, 1, "###"); //(pos, len, str)��ʽ
	cout << "after replace, str1 is : " << str1 << endl;


	str1.replace(str1.begin() + 5, str1.begin() + 7, "%%%"); //(iterator1, iterator2, string)��ʽ
	cout << "after replace, str1 is : " << str1 << endl;


	//s.compare() ��Ŀǰ�ͼ�ס��һ�����У�����Ҳ�ǲ�ס
	auto ret4 = str1.compare(str2); // compare���ڱȽ������ַ����Ƿ���ȡ������������Ϊ0��str1 > str2 ���1��str1 < str2���-1��
	if (ret4 == 1)
	{
		cout << "str1 > str2" << endl;
	}
	else if (ret4 == -1)
	{
		cout << "str1 < str2" << endl;
	}
	else
	{
		cout << "str1 = str2" << endl;
	}	


	/*
	find ϵ�к�����
	(1) s.find(args) //���� s �е�һ�γ��ֵ�λ��,�������Ӵ��������е�һ���ַ����±�
	(2) s.rfind(args) //�������һ��...
	(3) s.find_first_of(args) //�� s �в��� args ���κ�һ���ַ��ĵ�һ�γ��ֵ�λ�ã�
	(4) s.find_last_of(args) //�� s �в��� args ���κ�һ���ַ����һ�γ��ֵ�λ�á�
	(5) s.find_first_not_of(args) //�� s �в��ҵ�һ������ args �е��ַ�
	(6) s.find_last_not_of(args) //�������һ������ args �е��ַ�
	*/
	auto pos = str1.find(str2); // strstr(char *, char *)
	cout << "str2 is at the pos : " << pos << " of str1" << endl;

	string numbers("01234556789");
	string name("r2d2");
	auto pos1 = name.find_first_of(numbers);
	cout << "number first at the pos : " << pos1 << " of name" << endl;


	// Ԫ�ؼ���
	auto cnt = count(numbers.begin(), numbers.end(), '5');
	cout << "cnt : " << cnt << endl;


	// �ַ�������
	string str3;
	str3 = str2;
	cout << "str3 : " << str3 << endl;
}

// �ָ��ַ���
static void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
	{
		v.push_back(s.substr(pos1));
	}
}

// �ַ�������תΪint����
static void StringToInt(vector<string>& s, vector<int> &v)
{
	for (auto i = 0; !s.empty(); i++)
	{
		v.push_back(std::stoi(s.front()));
		s.erase(s.begin());
	}
}


int main16165168(void)
{
	myStringTest();

	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	system("pause");
	return 0;
}