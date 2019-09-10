#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

static struct BTreeNode
{
	int value;
	BTreeNode *left;
	BTreeNode *right;

	BTreeNode(int data)
	{
		this->value = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};
// �ؽ���������
static BTreeNode* reConstructBy_pre_vin(vector<int> &pre, vector<int> &vin)
{
	if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size())
	{
		cout << "�����ǰ�������򲻶ԣ��޷��ؽ���������" << endl;
		return nullptr;
	}

	BTreeNode *root = new BTreeNode(pre[0]); // ǰ��ĵ�һ������Ϊ��
	int len = pre.size();
	// ��ֻ��һ����ʱ����ֱ�ӷ��ظ�
	if (len == 1)
	{
		return root;
	}
	// ��ֹһ����ʱ���ҵ������еĸ���λ��
	int rootInorder = 0;
	for (; rootInorder < len; rootInorder++)
	{
		if (vin[rootInorder] == root->value)
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

// �ݹ飺����
static void preOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	cout << head->value << " ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}
// �ǵݹ飺����
static void preOrderUnRecur(BTreeNode *head) 
{
	if (head == nullptr)
	{
		return;
	}
	stack<BTreeNode *> my_stack;
	while (nullptr != head)
	{
		cout << head->value << " "; // �ȴ�ӡ���ڵ�
		if (head->right != nullptr)
		{
			my_stack.push(head->right);
		}
		if (head->left != nullptr)
		{
			my_stack.push(head->left);
		}

		if (!my_stack.empty())
		{
			head = my_stack.top();
			my_stack.pop();
		}
		else
		{
			head = nullptr;
		}
	}
}
// �ݹ飺����
static void inOrderRecur(BTreeNode *head) 
{
	if (head == nullptr) {
		return;
	}
	inOrderRecur(head->left);
	cout << head->value << " ";
	inOrderRecur(head->right);
}
// �ǵݹ飺����
static void inOrderUnRecur(BTreeNode *head)
{
	if (head == nullptr)
	{
		return;
	}
	stack<BTreeNode *> my_stack;
	while (head != nullptr || !my_stack.empty())
	{
		if (head != nullptr) // ��ǰ�ڵ㲻Ϊ�գ���ǰ�ڵ���ջ��������������
		{
			my_stack.push(head);
			head = head->left;
		}
		else // ��ǰ�ڵ�Ϊ�գ���ջ�������ڵ�Ϊ��ǰ�ڣ���������
		{
			head = my_stack.top();
			my_stack.pop();
			cout << head->value << " ";
			head = head->right;
		}
	}
}
// �ݹ飺����
static void posOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	posOrderRecur(head->left);
	posOrderRecur(head->right);
	cout << head->value << " ";
}
// �ǵݹ飺����
static void posOrderUnRecur(BTreeNode *head) 
{
	if (head == nullptr) {
		return;
	}
	stack<BTreeNode *> my_stack;
	stack<BTreeNode *> temp;
	while (nullptr != head) // ��ʵ������ֻ�������ҷ�����
	{ // ������->���Ҹ���
		temp.push(head);
		if (head->left != nullptr)
		{
			my_stack.push(head->left);
		}
		if (head->right != nullptr)
		{
			my_stack.push(head->right);
		}

		if (!my_stack.empty())
		{
			head = my_stack.top();
			my_stack.pop();
		}
		else
		{
			head = nullptr;
		}
	}
	while (!temp.empty())
	{
		head = temp.top();
		temp.pop();
		cout << head->value << " ";
	}
}
// �ǵݹ飺���
static void leverTrace(BTreeNode * head)
{
	if (head == nullptr)
	{
		return;
	}

	queue<BTreeNode *> my_queue;
	my_queue.push(head);
	while (!my_queue.empty())
	{
		int size = my_queue.size(); // ÿһ��Ľڵ�������ǿսڵ㣩
		for (int i = 0; i < size; i++)
		{// ������ɾ����ǰ�����нڵ㣬��������һ��ڵ�
			BTreeNode * cur = my_queue.front();
			my_queue.pop(); // ɾ����ǰ��ڵ�
			cout << cur->value << " ";
			if (cur->left != nullptr)
			{
				my_queue.push(cur->left); // ������һ����ڵ�
			}
			if (cur->right != nullptr)
			{
				my_queue.push(cur->right); // ������һ���ҽڵ�
			}
		}
	}
}
//static void leverTrace(BTreeNode * head)
//{
//	if (head == nullptr)
//	{
//		return;
//	}
//	queue<BTreeNode *> my_queue; // ������������ȵ�����ԭ��
//	while (nullptr != head)
//	{
//		cout << head->value << " ";
//		if (head->left != nullptr)
//		{
//			my_queue.push(head->left);
//		}
//		if (head->right != nullptr)
//		{
//			my_queue.push(head->right);
//		}
//
//		if (!my_queue.empty())
//		{
//			head = my_queue.front();
//			my_queue.pop();
//		}
//		else
//		{
//			head = nullptr;
//		}
//	}
//}


int main_�������ı���(void) // main_�������ı���
{
	vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BTreeNode *head = reConstructBy_pre_vin(preOrder, inOrder);

	cout << "�ݹ顪����";
	preOrderRecur(head);
	cout << endl;
	cout << "�ǵݹ�����";
	preOrderUnRecur(head);
	cout << endl;
	cout << endl;

	cout << "�ݹ顪����";
	inOrderRecur(head);
	cout << endl;
	cout << "�ǵݹ�����";
	inOrderUnRecur(head);
	cout << endl;
	cout << endl;

	cout << "�ݹ顪����";
	posOrderRecur(head);
	cout << endl;
	cout << "�ǵݹ����";
	posOrderUnRecur(head);
	cout << endl;
	cout << endl;

	cout << "�ǵݹ��Σ�";
	leverTrace(head);
	cout << endl;
	cout << endl;

	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}