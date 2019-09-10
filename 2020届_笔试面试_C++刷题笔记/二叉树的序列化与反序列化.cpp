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

// ����ʽ�����л�
static string serialByPre(BTreeNode *head)
{
	if (head == nullptr) 
	{
		return "# ";
	}
	string res = "";
	res += to_string(head->value) + " "; // ͷ
	res += serialByPre(head->left); // ��
	res += serialByPre(head->right); // ��
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
	BTreeNode *head = new BTreeNode(stoi(value)); // ͷ
	head->left = reconPreOrderString(values); // ��
	head->right = reconPreOrderString(values); // ��
	return head;
}
static BTreeNode * reconByPreString(string &preStr) 
{
	vector<string> values;
	SplitString(preStr, values, " "); // �Կո�ָ��ַ���
	return reconPreOrderString(values);
}

// ����ʽ�����л��������޷������л�
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

// ����ʽ�����л��������޷������л�
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

	queue<BTreeNode *> my_queue;
	my_queue.push(head);
	string res = "";
	while (!my_queue.empty())
	{
		int size = my_queue.size();
		for (int i = 0; i < size; i++)
		{
			BTreeNode * cur = my_queue.front();
			my_queue.pop();
			if (cur == nullptr) // �����л�ʱ��Ϊ�յĽڵ㣬Ҫд�ɡ�#����һ����־
			{
				res += "# ";
			}
			else
			{
				res += to_string(cur->value) + " ";
				my_queue.push(cur->left);
				my_queue.push(cur->right);
			}
		}
	}
	return res;
}
//static string serialByLevel(BTreeNode *head) 
//{
//	if (head == nullptr) 
//	{
//		return "# ";
//	}
//	string res = "";
//	res += to_string(head->value) + " "; // ͷ
//	queue<BTreeNode *> my_queue;
//	while (head != nullptr)
//	{
//		// res += to_string(head->value) + " "; // ����������ӣ���Ϊ�����head�Ƕ��е����ģ��Ѿ������һ���ˡ�
//		if (head->left != nullptr)
//		{
//			my_queue.push(head->left);
//		}
//		res += (head->left != nullptr ? to_string(head->left->value) : "#") + " ";
//		if (head->right != nullptr)
//		{
//			my_queue.push(head->right);
//		}
//		res += (head->right != nullptr ? to_string(head->right->value) : "#") + " ";
//
//		if (!my_queue.empty())
//		{
//			head = my_queue.front();
//			my_queue.pop();
//		}
//		else
//		{
//			break;
//		}
//	}
//	return res;
//}
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

int main_���л��뷴���л�(void) // main_���л��뷴���л�
{
	vector<int> preOrder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> inOrder = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BTreeNode *head = reConstructBy_pre_vin(preOrder, inOrder);

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