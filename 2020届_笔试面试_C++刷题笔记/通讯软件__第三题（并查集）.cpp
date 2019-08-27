#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;

/***************************************
����Ŀ����
��ͨѶ����У���Ⱥ����ת����Ϣ����ʹ��һ����Ϣ��ɢ���ܶ������������֪��m��Ⱥ��
����һ���˰�һ����Ϣ���͵����Լ����ڵ�����Ⱥ���棬��ЩȺ�����ÿ�����ְ���Ϣ�ڴ�ת���������е�Ⱥ���棬
��������Ⱥ���˶�ת����һ�κ���󼸸����յ�����Ϣ����������Ϣ���ˣ�������յ���Ϣ��������ʮ��������������Ҫ�ӻ��з���
����������
����һ����Ϣ������
Ⱥ�����m
Ⱥ��1��Ա�����б�
Ⱥ��2��Ա�����б�
...
Ⱥ��m��Ա�����б�

����ȫ��Ӣ���ַ���������Ӣ����ĸ�Ϳո���󳤶Ȳ�����100�ַ�
Ⱥ�����m��ʮ����������󲻳���100.
Ⱥ���Ա�����б����1�������������������֮���Զ��Ÿ�����
���������
��ʮ�������������յ���Ϣ������
������һ������Ϣ���ˣ�Ҳͳ�ƽ�ȥ���ظ����յ���Ϣֻͳ��һ��
���룺
Jack
3
Jack,Tom,Anny,Lucy
Tom,Danny
Jack,Lily
�����
6
��˼·����
���鼯����������ӳ��������飬�Ϳ������ˡ�
***************************************/

// ��ӡ��ά����vector<vector<int>> array
static void print_2D_Array(vector<vector<string>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<string>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
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

// �ݹ����x�ĸ��ڵ㣬findSet�ǲ��鼯
static int find(vector<int>& findSet, int x)
{
	return findSet[x] == x ? x : find(findSet, findSet[x]);
}

// ��������ͨ�����ڵ�ȴ��ͬ����Ҫ��������
static void join(vector<int>& findSet, int x, int y)
{
	int root1 = find(findSet, x);
	int root2 = find(findSet, y);
	if (root1 != root2)
	{
		findSet[root1] = root2;
	}
}

int main_������_ͨѶ���(void)
{
	//���룺
	//	Jack
	//	3
	//	Jack,Tom,Anny,Lucy
	//	Tom,Danny
	//	Jack,Lily
	string Name = "";
	while (cin >> Name)
	{
		int M = 0;
		cin >> M;
		vector<string> temp(M);
		for (int i = 0; i < M; i++)
		{
			cin >> temp[i];
		}
		vector<vector<string>> names(M);
		for (int i = 0; i < M; i++)
		{
			SplitString(temp[i], names[i], ",");
		}
		print_2D_Array(names);

		map<string, int> mymap;
		int N = 1;
		for (auto it1 : names)
		{
			for (auto it2 : it1)
			{
				if (mymap.insert(pair<string, int>(it2, N)).second)
				{
					N++;
				}
			}
		}

		for (auto it : mymap)
		{
			cout << it.first << " : " << it.second << endl;
		}
		vector<vector<int>> names_map(M);
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < names[i].size(); j++)
			{
				names_map[i].push_back(mymap[names[i][j]]);
				cout << "names_map[" << i << "][" << j << "] = " << names_map[i][j] << endl;
			}
		}

		// ��ʼ�� N �������Ӽ��ϣ���ʼ�����鼯
		vector<int> findSet(N + 1, 0);
		for (int i = 1; i <= N; i++)
		{
			findSet[i] = i; // ��0��ʼ��0λ�ò�ʹ�á�
		}
		// ����x��y�����ڵ�
		for (int i = 0; i < M; i++)
		{
			for (int j = 1; j < names[i].size(); j++)
			{
				join(findSet, names_map[i][0], names_map[i][j]); // ÿ�ϲ�һ�Σ����鼯findSet���Ӽ�����һ��
			}
		}
		// �ҵ�С��(1)�ڲ��鼯�еĴ���
		int k = find(findSet, mymap[Name]);
		// ������������kΪ�����Ԫ�ظ���
		int count = 0;
		for (int i = 1; i <= N; i++)
		{
			if (k == find(findSet, i))
			{
				count++;
			}
		}

		cout << count << endl; // �ҵ���Name�й�ϵ�ĸ�����
	}

	return 0;
}