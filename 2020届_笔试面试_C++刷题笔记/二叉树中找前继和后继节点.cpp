#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
/*
��Ŀ���ڶ��������ҵ�һ���ڵ�ĺ�̽ڵ㡣
 *  �ýṹ����ͨ�������ڵ�ṹ����һ��ָ�򸸽ڵ��parentָ�롣
	������һ��BTreeNode *���͵Ľڵ���ɵĶ�����������ÿ���ڵ��parentָ��
	����ȷ��ָ���Լ��ĸ��ڵ㣬ͷ�ڵ��parentָ��nullptr��ֻ��һ����
	�������е�ĳ���ڵ� node����ʵ�ַ���node�ĺ�̽ڵ�ĺ�����

	��̽ڵ㣺�ڶ���������������������У�node����һ���ڵ����node�ĺ�̽ڵ㡣
	ǰ�̽ڵ㣺�ڶ���������������������У�node����һ���ڵ����node��ǰ�̽ڵ㡣
˼·��
	����һ������node����parentָ�룬�ҵ�ͷ��㣬Ȼ����������������ҵ�node��㣬Ȼ���ҵ�������һ�����
	��������
�Һ�̽�㣬���������Һ���:
	1->���ڵ�X���������������ĺ�̽���������������������Ľ�㣨������������û�����������Ǿ�������������
	2->��Ϊ�����ǣ��󡢸����ң����ԣ�X�ڵ�û��������ʱ��X�ڵ����������������е����һ������Ľڵ㣬
		��X�ĺ�̽ڵ�Ӧ�ڸ��������ĸ��ڵ㡣���ԣ�����ѭ���������ýڵ������������ĸ���

��ǰ�̽ڵ㣬������������:
	1->���ڵ�X����������������ǰ�̽��������������������ҵĽ�㣨������������û�����������Ǿ�������������
	2->��Ϊ�����ǣ��󡢸����ң����ԣ�X�ڵ�û��������ʱ��X�ڵ����������������е�����һ������Ľڵ㣬
		��X��ǰ�̽ڵ�Ӧ�ڸ��������ĸ��ڵ㡣���ԣ�����ѭ���������ýڵ������������ĸ���
*/
static struct BTreeNode
{
	int value;
	BTreeNode *left;
	BTreeNode *right;
	BTreeNode *parent;

	BTreeNode(int data)
	{
		this->value = data;
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
	}
};

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

// �ҽڵ㲻Ϊ�գ���������������ڵ�
static BTreeNode * getLeftMost(BTreeNode * node) 
{
	while (node->left != nullptr) 
	{
		node = node->left;
	}
	return node;
}
// ��ڵ㲻Ϊ�գ��������������ҽڵ�
static BTreeNode * getRightMost(BTreeNode * node)
{
	while (node->right != nullptr)
	{
		node = node->right;
	}
	return node;
}

// �Һ�̽ڵ�
static BTreeNode * getSuccessorNode(BTreeNode * node) 
{
	if (node == nullptr) 
	{
		return node;
	}
	if (node->right != nullptr) 
	{
		return getLeftMost(node->right);
	}
	else // �ҽڵ�Ϊ��
	{
		BTreeNode * parent = node->parent;
		while (parent != nullptr && parent->left != node) 
		{ // ����ѭ���������ýڵ������������ĸ���
			node = parent;
			parent = node->parent;
		}
		return parent; // parent�Ǹ���
	}
}
// ��ǰ�̽ڵ�
static BTreeNode * getPreNode(BTreeNode * node)
{
	if (node == nullptr)
	{
		return node;
	}
	if (node->left != nullptr)
	{
		return getRightMost(node->left);
	}
	else // ��ڵ�Ϊ��
	{
		BTreeNode * parent = node->parent;
		while (parent != nullptr && parent->right != node)
		{ // ����ѭ���������ýڵ������������ĸ���
			node = parent;
			parent = node->parent;
		}
		return parent; // parent�Ǹ���
	}
}


int main_����������ǰ�̺ͺ�̽ڵ�(void) // main_����������ǰ�̺ͺ�̽ڵ�
{
	BTreeNode * head = new BTreeNode(6);
	head->parent = nullptr;
	head->left = new BTreeNode(3);
	head->left->parent = head;
	head->left->left = new BTreeNode(1);
	head->left->left->parent = head->left;
	head->left->left->right = new BTreeNode(2);
	head->left->left->right->parent = head->left->left;
	head->left->right = new BTreeNode(4);
	head->left->right->parent = head->left;
	head->left->right->right = new BTreeNode(5);
	head->left->right->right->parent = head->left->right;
	head->right = new BTreeNode(9);
	head->right->parent = head;
	head->right->left = new BTreeNode(8);
	head->right->left->parent = head->right;
	head->right->left->left = new BTreeNode(7);
	head->right->left->left->parent = head->right->left;
	head->right->right = new BTreeNode(10);
	head->right->right->parent = head->right;

	cout << "�ݹ顪����";
	inOrderRecur(head);
	cout << endl;

	BTreeNode * curNode;
	BTreeNode * laterNode;

	curNode = head->left;
	cout << curNode->value << " �ĺ�̽ڵ㣺";
	laterNode = getSuccessorNode(curNode);
	cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;
	cout << curNode->value << " ��ǰ�̽ڵ㣺";
	laterNode = getPreNode(curNode);
	 cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;
	
	curNode = head->left->left;
	cout << curNode->value << " �ĺ�̽ڵ㣺";
	laterNode = getSuccessorNode(curNode);
	 cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;
	cout << curNode->value << " ��ǰ�̽ڵ㣺";
	laterNode = getPreNode(curNode);
	 cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;

	curNode = head->left->left->right;
	cout << curNode->value << " �ĺ�̽ڵ㣺";
	laterNode = getSuccessorNode(curNode);
	 cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;
	cout << curNode->value << " ��ǰ�̽ڵ㣺";
	laterNode = getPreNode(curNode);
	 cout << (laterNode == nullptr ? -1 : laterNode->value) << endl;

	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}