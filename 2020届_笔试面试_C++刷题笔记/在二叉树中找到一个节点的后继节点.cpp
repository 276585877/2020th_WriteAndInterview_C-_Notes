#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
/*
��Ŀ���ڶ��������ҵ�һ���ڵ�ĺ�̽ڵ㡣
 *  �ýṹ����ͨ�������ڵ�ṹ����һ��ָ�򸸽ڵ��parentָ�롣��
	����һ ��BTreeNode *���͵Ľڵ���ɵĶ�����������ÿ���ڵ��parentָ��
	����ȷ��ָ�� �Լ��ĸ��ڵ㣬ͷ�ڵ��parentָ��nullptr��ֻ��һ����
	�������е�ĳ���ڵ� node����ʵ�ַ���node�ĺ�̽ڵ�ĺ�����

	��̽ڵ㣺�ڶ���������������������У�node����һ���ڵ����node�ĺ�̽ڵ㡣
	ǰ�̽ڵ㣺�ڶ���������������������У�node����һ���ڵ����node��ǰ�̽ڵ㡣
˼·��
	����һ������node����parentָ�룬�ҵ�ͷ��㣬Ȼ����������������ҵ�node��㣬Ȼ���ҵ�������һ�����
	��������
	��ǰ�����  ������������
�����Һ�̽�㣬���������Һ���
	1->���ڵ�X���������������ĺ�̽���������������������Ľ�㣨������������û�����������Ǿ�������������
	2->���ڵ�Xû����������������ѭ���������ýڵ������������ĸ���
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

// �ҽڵ�Ϊ����������ڵ�
static BTreeNode * getLeftMost(BTreeNode * node) 
{
	if (node == nullptr) {
		return node;
	}
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

// �Һ�̽ڵ�
static BTreeNode * getSuccessorNode(BTreeNode * node) 
{
	if (node == nullptr) {
		return node;
	}
	if (node->right != nullptr) {
		return getLeftMost(node->right);
	}
	else {//�ҽڵ�Ϊ��
		BTreeNode * parent = node->parent;
		while (parent != nullptr && parent->left != node) {
			node = parent;
			parent = node->parent;
		}
		return parent;
	}
}


int main0202021122101255(void)
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
	cout << laterNode->value << endl;
	
	curNode = head->left->left;
	cout << curNode->value << " �ĺ�̽ڵ㣺";
	laterNode = getSuccessorNode(curNode);
	cout << laterNode->value << endl;

	curNode = head->left->left->right;
	cout << curNode->value << " �ĺ�̽ڵ㣺";
	laterNode = getSuccessorNode(curNode);
	cout << laterNode->value << endl;

	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}