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
1����ͷ��β�����ַ������滻��ʱ�临�Ӷ�ΪO(n2)��Ч�ʵ�
2����β��ͷ�����ַ������滻��ʱ�临�Ӷ�ΪO(n)��Ч�ʸ�
***************************************/
// 1��
static void replaceSpace1(string &str, int length)
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
/***************************************
��˼·����
// 2����ָ��P1ָ��ԭʼ�ַ�����ĩβ��ָ��P2ָ���滻���ַ�����ĩβ��
��ǰ�ƶ�ָ��P1�����P1ָ���Ԫ�ز��ǿո���P1ָ���Ԫ�ظ��Ƹ�P2ָ���λ�ã�
���P1ָ���Ԫ���ǿո���P2������ǰ�ƶ�������%20����P1==P2ʱ�������滻��
***************************************/
static void replaceSpace2(string &str, int length)
{
	// �߽���1���ж��ַ������Ƿ�Ϊ��
	if (str.size() == 0)
	{
		return;
	}

	const string key = "%20";
	// �����ַ�����ͳ�ƿո�������滻ǰ�ַ��������滻���ַ�����
	int CountOfBlanks = 0; // �ո����
	int Originallength = 0;// �滻ǰ�ַ�����
	int newLen = 0;           // �滻���ַ�����
	for (int i = 0; str[i] != '\0'; ++i)
	{
		Originallength++;
		if (str[i] == ' ')
		{
			++CountOfBlanks;
		}
	}
	newLen = Originallength + (key.size() - 1) * CountOfBlanks;// �滻���ַ����� = �滻ǰ�ĸ���+��Ҫ�滻�ĸ���*(�滻���ַ�����-1)

	// �߽���2���ж��ַ������Ƿ�Խ��
	if (newLen > length)
	{
		return;
	}

	// �滻�ո�
	int p_Original = Originallength;// ָ��ԭʼ�ַ�����ĩβ(\0)
	int p_New = newLen;// ָ���滻���ַ�����ĩβ(\0)
	while (p_Original != p_New)         // �滻����������
	{
		if (str[p_Original] == ' ')
		{
			str[p_Original--] = '0';
			str[p_Original--] = '2';
			str[p_Original--] = '%';
		}
		else
		{
			str[p_New--] = str[p_Original--];
		}
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
	replaceSpace2(str, str.size());
	cout << "str = " << str << endl;

	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}