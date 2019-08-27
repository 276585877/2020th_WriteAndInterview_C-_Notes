#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
Given:
1->2->3->4 you should return the list as 2->1->4->3

��������ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
�ݹ鷨��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
*/
static struct Node
{
	int data;
	Node *next;
};

// ��ӡ����ͷ�ڵ�ĵ�����
static void printList(Node *head)
{
	while (head != nullptr)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

static Node * creatList() // ����������(����ͷ�ڵ�ĵ�����)��new�����Ŀؼ����������÷��ء�������ڴ�й©
{
	Node *head = nullptr;
	Node *ptr = nullptr;
	for (int i = 1; i < 8; i++)
	{
		if (nullptr == head) // ������Ϊ�˱���head1ͣ���ڵ�һ���ڵ㲻�����ø���ָ��ptr�ƶ���
		{
			head = new Node;
			head->data = i;
			head->next = nullptr;
			ptr = head;
			continue;
		}
		ptr->next = new Node;
		ptr = ptr->next;
		ptr->data = i;
		ptr->next = nullptr;
	}
	return head;
}

//static Node * reversePairList(Node *head)
//{// �ô���ֻ������ż�����ڵ㣬��������ͨ�õķ�����
//	if (head == nullptr || head->next == nullptr)
//	{
//		return head;
//	}
//	Node *cur = head;
//	Node *next = cur->next;
//	Node *res = next;
//	Node *nextnext = next->next;
//	while (cur != nullptr && next != nullptr)
//	{ 
//		next = cur->next;
//		nextnext = next->next;
//
//		cur->next = nextnext == nullptr ? nextnext : nextnext->next;
//		next->next = cur;
//
//		cur = nextnext;
//	}
//	return res;
//}

// ������ĳɶԷ�ת��
static Node * reversePairList_2(Node *head)
{// �ô������������������ڵ�
	Node *dummy = new Node; // �����ڵ�
	dummy->data = 0;
	dummy->next = head;
	Node *pre = dummy;
	Node *cur = head;
	Node *next = cur->next;
	while (cur != nullptr && cur->next != nullptr)
	{
		next = cur->next;
		cur->next = next->next;
		next->next = pre->next;
		pre->next = next;
		pre = cur;
		cur = cur->next;
	}
	return dummy->next;
}

int main5455656561546456645456564(void)
{
	Node *Head1 = nullptr;
	Head1 = creatList();
	printList(Head1);

	Head1 = reversePairList_2(Head1);

	cout << "�ɶԷ�ת����" << endl;
	printList(Head1);

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}