#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

/***************************************
��˼·����
һ��һ�����ҳ���key2�ĵط���������key1�滻��
***************************************/
//void replaceSpace(char *str, int length)
//{
//	const string key1 = "%20";
//	const string key2 = " ";
//	string temp(str);
//	while (true)
//	{
//		int p = temp.find(key2); // ����key2��һ�γ��ֵ�λ�ã��±ꡣ
//		if (p == -1)
//		{
//			break;
//		}
//		temp.replace(temp.begin() + p, temp.begin() + p + key2.size(), key1);
//	}
//	*str = temp.substr(0);
//	//strcpy(str, const_cast<char *>(temp.c_str()));
//}
void replaceSpace(string &str, int length)
{
	const string key1 = "%20";
	const string key2 = " ";
	while (true)
	{
		int p = str.find(key2); // ����key2��һ�γ��ֵ�λ�ã��±ꡣ
		if (p == -1)
		{
			break;
		}
		str.replace(str.begin() + p, str.begin() + p + key2.size(), key1);
	}
}

int main_�滻�ո��ַ������Һ��滻��(void)
{
	//char *str = new char[30];
	//string temp = "We Are Happy  12313";
	//strncpy_s(str, 30, const_cast<char *>(temp.c_str()), temp.length());
	//replaceSpace(str, 30); // ��ţ�����ϣ����������char *.
	//cout << "str : " << str << endl;
	
	string str("We Are Happy  12313");
	replaceSpace(str, str.size());
	cout << "str = " << str << endl;

	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}