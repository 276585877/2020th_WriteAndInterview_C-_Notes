#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

/***************************************
����Ŀ����
һ��������n���ڵ㣬ÿ���ڵ���������Ȩֵ�����ң�������һ��Ľڵ�Ȩֵ֮�ͱ���һ��ļ��Ȩֵ֮���ϸ�С����ô����һ�ŵ�������
����������
��һ����N����N������
�ڶ�����n����n���ڵ�
����n�У�����ڵ㣬��k�д�����Ϊk�Ľڵ㣬�ֱ����Ȩֵ�����ӵı�š��Һ��ӵı�š�
���������
YES����NO���Ƿ��ǵ�����
���룺
1
8
2 -1 -1
1  5  3
4 -1  6
2 -1 -1
3  0  2
2  4  7
7 -1 -1
2 -1 -1
�����
YES
��˼·����
1���ҵ����ڵ�-�����л�-�������л�(����)-��ͳ��ÿһ��ڵ��Ȩֵ��
***************************************/
// �������Ľڵ�
static struct BTreeNode
{
	int num;
	int value;
	BTreeNode *left;
	BTreeNode *right;

	BTreeNode(int num, int value)
	{
		this->num = num;
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
	}
};
//�ҵ����ڵ�
static int getHeadNum(vector<int> &Left, vector<int> &Right)
{
	for (int i = 0; i < Left.size(); i++)
	{
		if (find(Left.begin(), Left.end(), i) == Left.end() && 
			find(Right.begin(), Right.end(), i) == Right.end())
		{
			return i;
		}
	}
}
//���л�
static vector<string> seriease(int headNum, vector<int> &Value, vector<int> &Left, vector<int> &Right)
{
	vector<string> result;
	queue<int> my_queue;
	while (true)
	{
		if (headNum == -1)
		{
			result.push_back("#");
		}
		else
		{
			result.push_back(to_string(headNum));
			my_queue.push(Left[headNum]);
			my_queue.push(Right[headNum]);
		}

		if (!my_queue.empty())
		{
			headNum = my_queue.front();
			my_queue.pop();
		}
		else
		{
			break;
		}
	}
	return result;
}
//�����л�(����)
static BTreeNode * reconByLevelString(vector<string> &nums, vector<int> &Value)
{
	string num = nums.front();
	nums.erase(nums.begin());
	if (num == "#")
	{
		return nullptr;
	}
	BTreeNode *head = new BTreeNode(stoi(num), Value[stoi(num)]); // ����ͷ��㡣
	BTreeNode *cur = head;

	// ����кͷ����л�һ������
	queue<BTreeNode *> my_queue;
	while (!nums.empty())
	{
		if (nums.front() != "#") // ���
		{
			my_queue.push(new BTreeNode(stoi(nums.front()), Value[stoi(nums.front())]));
		}
		cur->left = nums.front() != "#" ? my_queue.back() : nullptr;
		nums.erase(nums.begin());

		if (nums.front() != "#") // �ұ�
		{
			my_queue.push(new BTreeNode(stoi(nums.front()), Value[stoi(nums.front())]));
		}
		cur->right = nums.front() != "#" ? my_queue.back() : nullptr;
		nums.erase(nums.begin());

		if (!my_queue.empty())
		{
			cur = my_queue.front();
			my_queue.pop();
		}
		else
		{
			break;
		}
	}
	return head;
}
//ͳ��ÿһ��ڵ��Ȩֵ
static vector<int> isIncrease(BTreeNode * head, int n)
{
	vector<int> res;
	queue<BTreeNode *> my_queue;
	my_queue.push(head);
	while (!my_queue.empty())
	{
		int sum = 0;
		int size = my_queue.size();
		for (int i = 0; i < size; i++) // ÿ��ѭ��������һ�����нڵ㡣
		{
			BTreeNode * node = my_queue.front();
			my_queue.pop();
			sum += node->value;
			if (node->left != nullptr)
			{
				my_queue.push(node->left);
			}
			if (node->right != nullptr)
			{
				my_queue.push(node->right);
			}
		}
		res.push_back(sum);
	}
	return res;
}

int ���׻���__�ڶ���(void) // ���׻���__�ڶ���
{
	int N;
	while (cin >> N)
	{
		vector<bool> result(N, false);
		for (int i = 0; i < N; i++)
		{
			int n;
			cin >> n; // �ڵ���
			vector<int> Value(n, 0);
			vector<int> Left(n, -1);
			vector<int> Right(n, -1);
			for (int j = 0; j < n; j++)
			{
				cin >> Value[j];
				cin >> Left[j];
				cin >> Right[j];
			}
			//����
			int headNum = getHeadNum(Left, Right);
			vector<string> res = seriease(headNum, Value, Left, Right);
			BTreeNode * head = reconByLevelString(res, Value);
			//�ж�
			vector<int> result1 = isIncrease(head, n);
			vector<int> result2(result1);
			sort(result2.begin(), result2.end());
			result[i] = (result1 == result2 ? true : false);
		}
		for (auto it : result)
		{
			cout << (it == true ? "YES" : "NO") << endl;
		}
	}
	return 0;
}