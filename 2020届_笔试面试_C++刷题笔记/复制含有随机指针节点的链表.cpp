#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

/*
����Ŀ����
����һ�����������ڵ����������£�
struct Node
	 {
		 int data;
		 Node *next;
		 Node *rand;
	 };
Node �е� data �ǽڵ�ֵ��next ָ������������е� next ָ�������һ������ָ����һ���ڵ㣬
rand ָ���� Node ����������ָ�룬���ָ�����ָ�������е�����һ���ڵ㣬Ҳ����ָ�� NULL��
����һ���� Node �ڵ�������ɵ��޻��������ͷ�ڵ� head����ʵ��һ���������������������нṹ�ĸ��ƣ�
�����ظ��Ƶ��������ͷ�ڵ㡣���磺����1->2->3->NULL��
���� 1 �� rand ָ��ָ�� 3��2 �� rand ָ��ָ��NULL��3 �� rand ָ��ָ�� 1�����ƺ������Ӧ��Ҳ�����ֽṹ��
��˼·����
������ͨ�ⷨ��ʹ��hash_map
�������׽ⷨ��1->2->3-NULL   ------>    1->1'->2->2'->3->3'->NULL
������������ͨ�㷨���ǽ����㷨�ҵ� rand ����Ӧ�� Node �ǹؼ���
�����ס���
������ʹ�ö�������ݽṹ��ֻʹ�����޼�������������ʱ�临�Ӷ�Ϊ O(N)�����ԭ����Ҫʵ�ֵĺ�����
*/
struct Node
{
	int data;
	Node *next;
	Node *rand;
};

// ��ӡ������ڵ�ĵ�����
void printListWithRand(Node *head)
{
	while (NULL != head)
	{
		if (NULL != head->rand)
			cout << head->data << " rand is: " << head->rand->data << endl;
		else
			cout << head->data << " rand is: NULL " << endl;

		if (NULL != head->next)
			cout << head->data << " next is: " << head->next->data << endl;
		else
			cout << head->data << " next is: NULL " << endl;
		head = head->next;
	}
}

static Node * creatList() // ����������(����ͷ�ڵ�ĵ�����)��new�����Ŀؼ����������÷��ء�������ڴ�й©
{
	Node *head = nullptr;
	Node *ptr = nullptr;
	for (int i = 1; i < 5; i++)
	{
		if (nullptr == head) // ������Ϊ�˱���head1ͣ���ڵ�һ���ڵ㲻�����ø���ָ��ptr�ƶ���
		{
			head = new Node;
			head->data = i;
			head->next = nullptr;
			head->rand = nullptr;
			ptr = head;
			continue;
		}
		ptr->next = new Node;
		ptr = ptr->next;
		ptr->data = i;
		ptr->next = nullptr;
		ptr->rand = nullptr;
	}
	return head;
}

// ��ͨ�ⷨ��ʹ��hash_map
Node* copyListWithRand_1(Node *head)
{
	unordered_map<Node *, Node *> map;
	Node *cur = head;
	while (nullptr != cur) // �ȴ��������еĸ��ƽڵ㣬��ʱ��ָ��Null
	{
		Node *ptr = new Node;
		ptr->data = cur->data;
		ptr->next = nullptr; // ��һ�����ƽڵ㻹δnew������������ָ��null
		ptr->rand = nullptr; // randҲ��ͬ��
		map[cur] = ptr;    //һһ��Ӧ�Ĺ�ϵ
		cur = cur->next;
	}
	cur = head;
	while (nullptr != cur) // �������ƽڵ��ָ��
	{
		map[cur]->next = map[cur->next];
		map[cur]->rand = map[cur->rand];
		cur = cur->next;
	}
	return map[head];
}

// ���׽ⷨ��1->2->3 - NULL------ > 1->1'->2->2'->3->3'->NULL
Node* copyListWithRand_2(Node *head)
{
	if (nullptr == head)
	{
		return nullptr;
	}
	// ����ڵ�1'��2'��3'......
	Node *cur = head;
	Node *next = nullptr; // next�������1'��2'��3'......
	while (nullptr != cur)
	{
		next = new Node;
		next->data = cur->data*10;
		next->next = cur->next;
		next->rand = nullptr;
		cur->next = next;
		cur = next->next;
	}
	// ����rand
	cur = head;
	Node *curCopy = nullptr;
	while (nullptr != cur)
	{
		next = cur->next->next;
		curCopy = cur->next;
		curCopy->rand = cur->rand == nullptr ? nullptr : cur->rand->next;
		cur = next;
	}
	// ���ԭ����͸�������
	Node *res = head->next;
	cur = head;
	while (nullptr != cur)
	{
		next = cur->next->next;
		curCopy = cur->next;
		cur->next = next;
		curCopy->next = next == nullptr ? nullptr : next->next;
		cur = next;
	}

	// rand�Ͳ��һ����������⣬��Ϊ��ǰ����Ѿ�����ˣ������cur->rand->next;ָ��ͱ��ˡ�
	//cur = head;
	//Node *res = head->next;
	//Node *curCopy = nullptr;
	//while (nullptr != cur)
	//{ // rand�Ͳ��һ����������⣬��Ϊ��ǰ����Ѿ�����ˣ������cur->rand->next;ָ��ͱ��ˡ�
	//	next = cur->next->next;
	//	curCopy = cur->next;
	//	curCopy->rand = cur->rand == nullptr ? nullptr : cur->rand->next;
	//	curCopy->next = next == nullptr ? nullptr : next->next;
	//	cur->next = next;
	//	cur = next;
	//}
	return res;
}


int main0000503025222220202220220(void)
{
	Node *Head = nullptr;
	Head = creatList();
	Head->rand = Head->next->next;
	Head->next->rand = nullptr;
	Head->next->next->rand = Head;
	Head->next->next->next->rand = Head->next;

	printListWithRand(Head);
	cout << endl;

	Node *Head_copy = nullptr;
	Head_copy = copyListWithRand_2(Head);
	printListWithRand(Head_copy);

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}