#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
C(n,m)=[n*(n-1)*...*(n-m)]/[m*(m-1)*...*1]
��n���ַ���ѡȡm���ַ���������е����

A(n,n)=[n*(n-1)*...*1]
ȫ�����㷨

A(n,m)=A(n,m)=C(n,m)*A(m,m)
�ɹ�ʽ���Խ���������ת��Ϊ��������ȫ��������

��˼·����
һ��A(n,n)ȫ���п���ʹ��STL�㷨:
next_permutation����һ��������ϡ�,��ʹ��ǰ��Ҫ�����������鰴�������򣬷���ֻ���ҳ�������֮���ȫ��������
prev_permutation����һ��������ϡ�,��ʹ��ǰ��Ҫ�����������鰴�������򣬷���ֻ���ҳ�������֮���ȫ��������

����A(n,n)ȫ���п���ʹ�õݹ��㷨:

����C(n,m)��ϣ��ݹ鷨��
��n���ַ����г�һ����ˮ�ߣ�Ȼ��ӵ�һ���ַ���ʼѡȡ�����ҽ��Ѿ�ѡȡ���ַ����б��棬
����Ѿ�ѡȡ��m���ַ�����ô�ͻ����һ����Ͻ������ʱ���⻹û�н����
Ӧ�ý��ոձ�������һ���ַ��ó�����Ȼ��ѡ����ˮ���ϵ���һ���ַ���
����Ѿ����ʵ�����ˮ�ߵ����һ���ַ���ѡȡ���ַ���û�дﵽm����
˵����ǰ������ַ��޷��õ�һ����ϣ�����󱣴���ַ��ó�����ѡ����һ���ַ���
*/

// A(n,n)ȫ���п���ʹ��STL�㷨:
static void StlFunction()
{
	cout << "��prev_permutation��3 2 1��ȫ����" << endl;
	int arr[] = { 3,2,1 };
	do
	{
		cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
	} while (prev_permutation(arr, arr + 3));      ///��ȡ��һ���ϴ��ֵ������У����3��Ϊ2��ֻ��ǰ������ȫ����


	cout << "��next_permutation��1 2 3��ȫ����" << endl;
	int arr1[] = { 1,2,3 };
	do
	{
		cout << arr1[0] << ' ' << arr1[1] << ' ' << arr1[2] << '\n';
	} while (next_permutation(arr1, arr1 + 3));      ///��ȡ��һ���ϴ��ֵ������У����3��Ϊ2��ֻ��ǰ������ȫ����
	///ע������˳�򣬱�ҪʱҪ�������Ƚ�������


	cout << "��next_permutation��1 2 3��ȫ����_ʹ�������͵�����:" << endl;
	vector<int> arr2 = { 1,2,3 };
	do
	{
		cout << arr2[0] << ' ' << arr2[1] << ' ' << arr2[2] << '\n';
	} while (next_permutation(arr2.begin(), arr2.end()));


	// ��ֻ��ĳһ���������У����������λ�����������г���Ϊ1��
}

/*
// C(n,m)��ϣ��ݹ鷨��
*  str:  Դ�ַ���
*  nLen: ��ϳ���
*  vector<char> ve: ������¼��ǰ�Ѿ����ʹ����ַ�
*  vector<string> result: ������¼��Ϻ�Ľ����ͨ��size()���Ի�����յ���Ͻ��
*/
static void perm(char* str, int nLen, vector<char>& ve, vector<string>& result)
{
	if (nLen == 0)   //�Ѿ��ҵ�һ��ȫ���е����,���������Ͼ���ve��
	{
		string st;
		vector<char>::iterator it = ve.begin();
		for (; it != ve.end(); it++)
		{
			st += *it;
		}
		result.push_back(st);    //�ҵ���һ����ϣ����������ڶ�̬������
		return;
	}
	if (*str == '\0')
		return;

	ve.push_back(*str);
	perm(str + 1, nLen - 1, ve, result);
	//�ݹ���������������ֻ�����֣�
	//ҪôstrΪ���ˣ�˵����ǰ�Ѿ�����һ���ַ�����
	//ҪônLenΪ0�ˣ�˵���Ѿ��ҵ���һ�����

	ve.pop_back(); // ��ʱҪ�����һ���ַ���ջ��Ȼ�������һ���ַ�
	perm(str + 1, nLen, ve, result);

}
/*
����Sectet������鵱ǰ��������Ƿ��ܹ��γ�����
�������ַ���Ϊ�ջ���nС��mʱ������һ���ձ�
* str:  n���ַ���ɵ��ַ���
* nLen: ��ϳ���m
*/
vector<string> Secret(char* str, int nLen)
{
	vector<string> strVect;

	if (str == NULL || nLen > strlen(str))    //����һ���ձ�
		return strVect;

	vector<char> chVect;
	perm(str, nLen, chVect, strVect);
	return strVect;
}


int main_�������(void)
{
	cout << "ȫ���У�" << endl;
	StlFunction();

	cout << "��ϣ�" << endl;
	char s[] = "12345";

	int n = strlen(s);
	int m = 4;

	vector<string> strVect = Secret(s, m);
	int nCount = strVect.size();
	if (nCount == 0)
	{
		cout << "��ǰ����������������й���!" << endl;
	}
	else
	{
		char buff[100];
		sprintf_s(buff, "C(%d,%d)һ����%d�����", n, m, nCount);
		cout << buff << endl;
		vector<string>::iterator it = strVect.begin();
		for (; it != strVect.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}