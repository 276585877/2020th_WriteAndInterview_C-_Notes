#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// �ָ��ַ���
static void SplitString(const string& source, vector<string>& des, const string& key)
{
	string::size_type pos1, pos2;
	pos2 = source.find(key);
	pos1 = 0;
	while (string::npos != pos2)
	{
		des.push_back(source.substr(pos1, pos2 - pos1));
		pos1 = pos2 + key.size();
		pos2 = source.find(key, pos1);
	}
	if (pos1 != source.length())
	{
		des.push_back(source.substr(pos1));
	}
}

// �ַ�������תΪint����
static void StringToInt(vector<string>& source, vector<int> &des)
{
	for (auto i = 0; !source.empty(); i++)
	{
		des.push_back(std::stoi(source.front()));
		source.erase(source.begin());
	}
}

int main212653805305220352355(void)
{
	int a = 2;
	vector<string> array1;
	vector<int> array2;

	char b = '5';
	string str1 = "1 2 3 4 5";

	// Int��char��ת;
	char c = a + '0'; // �÷�������0--9��10֮�󣨰���10��,������ȷ
	int d = c - '0';

	// Int��string��ת;
	string str2 = to_string(a);
	int e = stoi(str2);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;

	// �ָ��ַ��������vector<string> array1;�ַ�������
	SplitString(str1, array1, " ");
	for (auto it : array1)
	{
		cout << it << "_";
	}
	cout << endl;
	// ��vector<string> array1;�ַ������� ��� int����
	StringToInt(array1, array2);
	for (auto it : array2)
	{
		cout << it << "_";
	}
	cout << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}

