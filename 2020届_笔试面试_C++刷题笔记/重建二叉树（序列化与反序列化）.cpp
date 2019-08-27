#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// �������Ľڵ�
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

// �ݹ飺�������
static void preOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	cout << head->value << " ";
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

// ����ʽ�������л�
static BTreeNode *reconPreOrderString(vector<string> &values)
{ // �ַ�������
	string value = values.front();
	values.erase(values.begin());
	if (value == "#")
	{
		return nullptr;
	}
	BTreeNode *head = new BTreeNode(stoi(value));
	head->left = reconPreOrderString(values);
	head->right = reconPreOrderString(values);
	return head;
}
static BTreeNode *reconPreOrderString(vector<int> &values)
{ // int����
	int value = values.front();
	values.erase(values.begin());
	if (value == -1)
	{
		return nullptr;
	}
	BTreeNode *head = new BTreeNode(value); // �Ƚ������ڵ�
	head->left = reconPreOrderString(values); // �ٽ���������
	head->right = reconPreOrderString(values); // �ٽ���������
	return head;
}

int main_�Է����л���ʽ�ؽ�������(void)
{
	vector<string> data = { "0", "1", "3", "#", "#", "4", "#", "#", "2", "#", "#" };
	BTreeNode *head = nullptr;
	head = reconPreOrderString(data);
	preOrderRecur(head);

	cout << endl;
	cout << endl;

	vector<int> data1 = { 0, 1, 3, -1, -1, 4, -1, -1, 2, -1, -1 };
	BTreeNode *head1 = nullptr;
	head1 = reconPreOrderString(data1);
	preOrderRecur(head1);

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}