#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(const int val)
	{
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};

static void preOrderPrintf(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->val << "  ";
	preOrderPrintf(root->left);
	preOrderPrintf(root->right);
}

/***************************************
��Ŀ����
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}��
���ؽ������������ء�
��˼·����
��ǰ������������У����������3�����־���3������������ֵ���ٺ�����������ֶ�������������ֵ��
�������Ǿ���ǰ�����������������������У��ֱ��ҵ�������������Ӧ�������С�
��Ȼ�����Ѿ��ֱ��ҵ�������������ǰ��������к�����������У�
���ǿ�����ͬ���ķ����ֱ�ȥ��������������Ҳ����˵������������������õݹ�ķ���ȥ��ɡ�
***************************************/
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		TreeNode *root = new TreeNode(pre[0]); // ǰ��ĵ�һ������Ϊ��
		int len = pre.size();
		// ��ֻ��һ����ʱ����ֱ�ӷ��ظ�
		if (len == 1)
		{
			return root;
		}
		// ��ֹһ����ʱ
		// �ҵ������еĸ���λ��
		int i = 0;
		for ( ; i < len; i++)
		{
			if (vin[i] == root->val)
			{
				break; // ��ʱ��iֵ���Ǹ��������е�λ��
			}
		}
		// �ݹ鴴��������
		if (i == 0)
		{
			root->left = nullptr; // �ݹ����
		}
		else
		{
			vector<int> newpre;
			vector<int> newvin;
			for (int j = 0; j < i; j++)
			{
				newpre.push_back(pre[j + 1]);
				newvin.push_back(vin[j]);
			}
			root->left = reConstructBinaryTree(newpre, newvin);
		}
		// �ݹ鴴��������
		if (i == len - 1)
		{
			root->right = nullptr;
		}
		else
		{
			vector<int> newpre;
			vector<int> newvin;
			for (int j = i + 1; j < len; j++)
			{
				newpre.push_back(pre[j]);
				newvin.push_back(vin[j]);
			}
			root->right = reConstructBinaryTree(newpre, newvin);
		}
		return root;
	}
};


int main_�ؽ���������ǰ�������ֵ��(void)
{
	vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Solution result;
	TreeNode *root = result.reConstructBinaryTree(preOrder, inOrder);

	preOrderPrintf(root);

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}