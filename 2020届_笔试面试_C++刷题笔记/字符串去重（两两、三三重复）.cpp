#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
/*
�ҽ����󴸣���һ�ҳ�����ı༭���Ҹ���У��Ͷ������Ӣ�ĸ������ݹ����ǳ����ˣ���Ϊÿ�춼Ҫȥ����������ƴд���󡣵��ǣ��������������ƽ���Ĺ����з��������ҷ���һ������ƴд����Ľݾ���

1. ����ͬ������ĸ����һ��һ����ƴд����ȥ��һ���ľͺ��������� helllo -> hello
2. ����һ������ĸ��AABB�ͣ�����һ��һ����ƴд����ȥ���ڶ��Ե�һ����ĸ�ͺ��������� helloo -> hello
3. ����Ĺ������ȡ������ҡ�ƥ�䣬�������AABBCC����ȻAABB��BBCC���Ǵ���ƴд��Ӧ�����ȿ����޸�AABB�����ΪAABCC

�������Ǹ���ţ���������ѧ���ھ���ͳ�����ƣ��������ԭ��д��һ���Զ�У����������Ч�ʴӴ���ɡ��ò��˶�ã��Ҿͻ����CEO�����϶��³���ӭȢ�׸��������������۷壬���붼�е�С�����أ�
����
����û�뵽���ұ������ˣ�����ʱ�ϰ����˵�� ����������Ҫ����ҵҵ�����ڿҿҡ������ַ֣���Ҫ���У���һ����һ�С�һ���������У�Ҫ�ǲ��У���һ�в���һ�У�һ�в������в��С��� �����������˺����л��㱵ġ���


��������:
��һ�а���һ������N����ʾ���������������ٸ���У����ַ�����

�������N�У�ÿ��Ϊһ����У����ַ�����

�������:
N�У�ÿ�а���һ�����޸�����ַ�����

��������1:
2
helloo
wooooooow

�������1:
hello
woow
*/

// ��ӡ��ά����vector<vector<int>> array
void print_2D_Array(vector<vector<char>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<char>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it;
		}
	}
}

static void function(string &str, const int n)
{
	// ��ͳ����Ҫ���ٸ�Ͱ
	int count = 1;
	for (size_t i = 0; i < str.size() - 1; ++i)
	{
		if (str[i] != str[i + 1])
		{
			count++;
		}
	}
	//cout << "count:" << count << endl;
	// ��Ԫ�ط���Ͱ
	vector<vector<char>> bucket(count);
	int j = 0;
	bucket[j].push_back(str[0]); // �Ƚ���һ��Ԫ�ط����һ��Ͱ
	for (size_t i = 1; i < str.size(); ++i)
	{
		if (str[i - 1] != str[i])
		{
			j++;
			bucket[j].push_back(str[i]);
		}
		else
		{
			bucket[j].push_back(str[i]);
		}
	}
	//print_2D_Array(bucket);
	//cout << endl;
	// ��Ͱ�е�Ԫ�ؽ��д���
	for (size_t i = 0; i < bucket.size(); ++i)
	{
		if (bucket[i].size() >= 3) // 1. ����ͬ������ĸ����һ��
		{
			while (bucket[i].size() >= 3)
			{
				bucket[i].pop_back();
			}
		}
	}
	for (size_t i = 0; i < bucket.size() - 1; ++i)
	{
		if ((bucket[i].size() == 2) && (bucket[i + 1].size() == 2)) // 2. ����һ������ĸ��AABB�ͣ�����һ��
		{
			bucket[i + 1].pop_back();
		}
	}
	print_2D_Array(bucket);
	cout << endl;
}

int main3331255531535135115(void)
{
	//int n = 2;
	//vector<string> str;
	//str.push_back("helloo1122");
	//str.push_back("wooooooow");


	int n = 0;
	cin >> n;
	vector<string> str;
	string in;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		str.push_back(in);
	}
	for (int i = 0; i < n; i++)
	{
		function(str[i], 2);
	}

	//cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}