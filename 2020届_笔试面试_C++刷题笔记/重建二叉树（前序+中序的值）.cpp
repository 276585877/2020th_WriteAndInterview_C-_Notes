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
static void inOrderPrintf(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	inOrderPrintf(root->left);
	cout << root->val << "  ";
	inOrderPrintf(root->right);
}
static void posOrderPrintf(TreeNode *root)
{
	if (root == nullptr)
	{
		return;
	}
	posOrderPrintf(root->left);
	posOrderPrintf(root->right);
	cout << root->val << "  ";
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
static TreeNode* reConstructBy_pre_vin(vector<int> &pre, vector<int> &vin) 
{
	if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size())
	{
		cout << "�����ǰ�������򲻶ԣ��޷��ؽ���������" << endl;
		return nullptr;
	}

	TreeNode *root = new TreeNode(pre[0]); // ǰ��ĵ�һ������Ϊ��
	int len = pre.size();
	// ��ֻ��һ����ʱ����ֱ�ӷ��ظ�
	if (len == 1)
	{
		return root;
	}
	// ��ֹһ����ʱ���ҵ������еĸ���λ��
	int rootInorder = 0;
	for ( ; rootInorder < len; rootInorder++)
	{
		if (vin[rootInorder] == root->val)
		{
			break;// ��ʱ��iֵ���Ǹ��������е�λ��
		}
	}
	// �ݹ鴴��������
	if (rootInorder == 0) // ������ֻʣһ��Ԫ���ˣ����Ǹ�
	{
		root->left = nullptr;
	}
	else
	{
		vector<int> newPre;
		vector<int> newVin;
		for (int i = 0; i < rootInorder; i++)
		{
			newPre.push_back(pre[i + 1]);
			newVin.push_back(vin[i]);
		}
		root->left = reConstructBy_pre_vin(newPre, newVin);
	}
	// �ݹ鴴��������
	if (rootInorder == len - 1) // ������ֻʣһ��Ԫ���ˣ����Ǹ�
	{
		root->right = nullptr;
	}
	else
	{
		vector<int> newPre;
		vector<int> newVin;
		for (int i = rootInorder + 1; i < len; i++)
		{
			newPre.push_back(pre[i]);
			newVin.push_back(vin[i]);
		}
		root->right = reConstructBy_pre_vin(newPre, newVin);
	}
	return root;
}
// �Ժ���������ؽ�
static TreeNode* reConstructBy_pos_vin(vector<int> &pos, vector<int> &vin)
{
	if (pos.size() == 0 || vin.size() == 0 || pos.size() != vin.size())
	{
		cout << "�����ǰ�������򲻶ԣ��޷��ؽ���������" << endl;
		return nullptr;
	}

	int len = pos.size();
	TreeNode *root = new TreeNode(pos[len - 1]); // ��������һ������Ϊ��
	// ��ֻ��һ����ʱ����ֱ�ӷ��ظ�
	if (len == 1)
	{
		return root;
	}
	// ��ֹһ����ʱ���ҵ������еĸ���λ��
	int rootInorder = 0;
	for (; rootInorder < len; rootInorder++)
	{
		if (vin[rootInorder] == root->val)
		{
			break;// ��ʱ��iֵ���Ǹ��������е�λ��
		}
	}
	// �ݹ鴴��������
	if (rootInorder == 0) // ������ֻʣһ��Ԫ���ˣ����Ǹ�
	{
		root->left = nullptr;
	}
	else
	{
		vector<int> newPos;
		vector<int> newVin;
		for (int i = 0; i < rootInorder; i++)
		{
			newPos.push_back(pos[i]);
			newVin.push_back(vin[i]);
		}
		root->left = reConstructBy_pos_vin(newPos, newVin);
	}
	// �ݹ鴴��������
	if (rootInorder == len - 1) // ������ֻʣһ��Ԫ���ˣ����Ǹ�
	{
		root->right = nullptr;
	}
	else
	{
		vector<int> newPos;
		vector<int> newVin;
		for (int i = rootInorder + 1; i < len; i++)
		{
			newPos.push_back(pos[i - 1]);
			newVin.push_back(vin[i]);
		}
		root->right = reConstructBy_pos_vin(newPos, newVin);
	}
	return root;
}


int main_�ؽ���������ǰ�������ֵ��(void) // main_�ؽ���������ǰ�������ֵ��
{
	vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };
	vector<int> posOrder = { 7, 4, 2, 5, 8, 6, 3, 1 };

	//TreeNode *root = reConstructBy_pre_vin(preOrder, inOrder);
	TreeNode *root = reConstructBy_pos_vin(posOrder, inOrder);

	cout << "�ؽ���ǰ��" << endl;
	preOrderPrintf(root);
	cout << endl;

	cout << "�ؽ�������" << endl;
	inOrderPrintf(root);
	cout << endl;

	cout << "�ؽ������" << endl;
	posOrderPrintf(root);
	cout << endl;

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}