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
	queue<BTreeNode *> my_queue; // ������������ȵ�����ԭ��
	while (nullptr != head)
	{
		cout << head->value << " ";
		if (head->left != nullptr)
		{
			my_queue.push(head->left);
		}
		if (head->right != nullptr)
		{
			my_queue.push(head->right);
		}

		if (!my_queue.empty())
		{
			head = my_queue.front();
			my_queue.pop();
		}
		else
		{
			head = nullptr;
		}
	}
}


int main200545411551154514(void)
{
	BTreeNode *head = new BTreeNode(5);
	head->left = new BTreeNode(3);
	head->right = new BTreeNode(8);
	head->left->left = new BTreeNode(2);
	head->left->right = new BTreeNode(4);
	head->left->left->left = new BTreeNode(1);
	head->right->left = new BTreeNode(7);
	head->right->left->left = new BTreeNode(6);
	head->right->right = new BTreeNode(10);
	head->right->right->left = new BTreeNode(9);
	head->right->right->right = new BTreeNode(11);

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