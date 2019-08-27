#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

// �ָ��ַ���
static void SplitString(const string& source, vector<string>& des, const string& key)
{
	string::size_type pos1, pos2;
	pos2 = source.find(key);
	pos1 = 0;
	while (string::npos != pos2)
	{
		des.push_back(source.substr(pos1, pos2 - pos1));
		pos1 = pos2 + key.size();
		pos2 = source.find(key, pos1);
	}
	if (pos1 != source.length())
	{
		des.push_back(source.substr(pos1));
	}
}
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
// �ݹ飺�������
static void inOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	inOrderRecur(head->left);
	cout << head->value << " ";
	inOrderRecur(head->right);
}
// �ݹ飺�������
static void posOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	posOrderRecur(head->left);
	posOrderRecur(head->right);
	cout << head->value << " ";
}
// �ǵݹ飺��α���
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

// ����ʽ�����л�
static string serialByPre(BTreeNode *head)
{
	if (head == nullptr) 
	{
		return "# ";
	}
	string res = "";
	res += to_string(head->value) + " ";
	res += serialByPre(head->left);
	res += serialByPre(head->right);
	return res;
}
// ����ʽ�������л�
static BTreeNode *reconPreOrderString(vector<string> &values)
{
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
static BTreeNode * reconByPreString(string &preStr) 
{
	vector<string> values;
	SplitString(preStr, values, " "); // �Կո�ָ��ַ���
	return reconPreOrderString(values);
}

// ����ʽ�����л�
static string serialByPosOrder(BTreeNode *head)
{
	if (head == nullptr)
	{
		return "# ";
	}
	string res = "";
	res += serialByPosOrder(head->left);
	res += serialByPosOrder(head->right);
	res += to_string(head->value) + " ";
	return res;
}

// ����ʽ�����л�
static string serialByInOrder(BTreeNode *head)
{
	if (head == nullptr)
	{
		return "# ";
	}
	string res = "";
	res += serialByInOrder(head->left);
	res += to_string(head->value) + " ";
	res += serialByInOrder(head->right);
	return res;
}

// ��η�ʽ�����л�
static string serialByLevel(BTreeNode *head) 
{
	if (head == nullptr) 
	{
		return "# ";
	}
	string res = "";
	res += to_string(head->value) + " ";
	queue<BTreeNode *> my_queue;
	while (head != nullptr)
	{
		// res += to_string(head->value) + " "; // ����������ӣ���Ϊ�����head�Ƕ��е����ģ��Ѿ������һ���ˡ�
		if (head->left != nullptr)
		{
			my_queue.push(head->left);
		}
		res += (head->left != nullptr ? to_string(head->left->value) : "#") + " ";
		if (head->right != nullptr)
		{
			my_queue.push(head->right);
		}
		res += (head->right != nullptr ? to_string(head->right->value) : "#") + " ";

		if (!my_queue.empty())
		{
			head = my_queue.front();
			my_queue.pop();
		}
		else
		{
			break;
		}
	}
	return res;
}
// ��η�ʽ�������л�
static BTreeNode * reconByLevelString(string &leverStr)
{
	vector<string> values;
	SplitString(leverStr, values, " "); // �Կո�ָ��ַ���

	string value = values.front();
	values.erase(values.begin());
	if (value == "#")
	{
		return nullptr;
	}
	BTreeNode *head = new BTreeNode(stoi(value)); // ��value����ͷ��㡣
	BTreeNode *cur = head;

	// ����кͷ����л�һ������
	queue<BTreeNode *> my_queue;
	while (!values.empty())
	{
		if (values.front() != "#") // ���
		{
			my_queue.push(new BTreeNode(stoi(values.front())));
		}
		cur->left = values.front() != "#" ? my_queue.back() : nullptr;
		values.erase(values.begin());

		if (values.front() != "#") // �ұ�
		{
			my_queue.push(new BTreeNode(stoi(values.front())));
		}
		cur->right = values.front() != "#" ? my_queue.back() : nullptr;
		values.erase(values.begin());
		
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

int main_���л��뷴���л�(void)
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

	cout << "����ʽ�����л���";
	string preStr = serialByPre(head);
	cout << preStr << endl;

	cout << "����ʽ�������л���";
	cout << "�ݹ顪���������";
	BTreeNode * head2 = reconByPreString(preStr);
	preOrderRecur(head2);
	cout << endl;
	cout << endl;
	

	cout << "����ʽ�����л���";
	string inOrderStr = serialByInOrder(head);
	cout << inOrderStr << endl;

	cout << "�ݹ顪�������(�����ܷ����л�)��";
	inOrderRecur(head);
	cout << endl;
	cout << endl;


	cout << "����ʽ�����л���";
	string posOrderStr = serialByPosOrder(head);
	cout << posOrderStr << endl;

	cout << "�ݹ顪�������(�����ܷ����л�)��";
	posOrderRecur(head);
	cout << endl;
	cout << endl;


	cout << "��η�ʽ�����л���";
	string leverStr = serialByLevel(head);
	cout << leverStr << endl;

	cout << "��η�ʽ�������л���";
	cout << "�ǵݹ��α�����";
	BTreeNode * head4 = reconByLevelString(leverStr);
	leverTrace(head4);
	cout << endl;
	cout << endl;

	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}