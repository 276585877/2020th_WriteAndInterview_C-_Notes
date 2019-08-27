#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;

/*
�ж������������Ƿ��ཻ�Լ��ཻ����������һ���ཻ�ڵ㣬������������л���Ҳ�����޻���������ǿ��Դ����¼������������

1���ж�һ���������Ƿ���ڻ�·������޻�������null����֮�������뻷�ڵ㡣
	��һ�֣�ʹ��HashSet��
	�ڶ��֣�ʹ�ÿ���ָ�롣��https://blog.csdn.net/Yufail/article/details/88236625��
		 * ���裺
		 * ��׼����������ָ�룬һ��һ����һ����һ��һ��������������л�������ָ��϶��������������ָ���ߵ���null��������޻���
		 * �ڵ�����ָ�������󣬽���ָ��ָ��ͷ�ڵ㣬Ȼ������ָ��ÿ�ζ�ͬʱ��һ����������ָ�����ʱ���͵���������뻷�ڵ㣬���ؼ��ɡ�
2�����������������޻���������Ӧ���ӳ���������ཻ������null����֮�����ص�һ���ཻ�ڵ㡣
3�����һ���л���һ���޻����������ཻ��
4�����������������л���������Ӧ���ӳ���������ཻ������null����֮�����ص�һ���ཻ�ڵ㡣
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
	for (int i = 0; i < 5; i++)
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
/***************************************
��һ�֣�ʹ��HashSet��
***************************************/
static Node *getLoopNode_1(Node *head)
{
	unordered_set<Node *> set;
	Node *cur = head;
	while (nullptr != cur)
	{
		auto it = set.insert(cur); //��Ա���� insert() ���Բ�����Ϊ��������ĵ���Ԫ�ء�����������£����᷵��һ�� pair ������� pair �������һ�����������Լ�һ�����ӵĲ���ֵ����˵�������Ƿ�ɹ���
		if (!it.second)
		{
			return cur;
		}
		cur = cur->next;
	}
	return nullptr;
}
/***************************************
�ڶ��֣�ʹ�ÿ���ָ�롣��https://blog.csdn.net/Yufail/article/details/88236625��
	* ���裺
	* ��׼����������ָ�룬һ��һ����һ����һ��һ��������������л�������ָ��϶��������������ָ���ߵ���null��������޻���
	* �ڵ�����ָ�������󣬽���ָ��ָ��ͷ�ڵ㣬Ȼ������ָ��ÿ�ζ�ͬʱ��һ����������ָ�����ʱ���͵���������뻷�ڵ㣬���ؼ��ɡ�
***************************************/
static Node *getLoopNode_2(Node *head)
{
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
	{
		return nullptr;
	}
	Node *slow = head->next;
	Node *fast = head->next->next; // Ҫ��֤���������ѭ����Ҫ��Ϊ��ǰ��һ����
	while (slow != fast) // ������ָ�������󣬿϶��л�
	{
		if (fast == nullptr || fast->next == nullptr)
		{
			return nullptr;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = head; // ����ָ��ָ��ͷ�ڵ㣬
	// Ȼ������ָ��ÿ�ζ�ͬʱ��һ����������ָ�����ʱ���͵���������뻷�ڵ㣬���ؼ��ɡ�
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
/***************************************
 * ���������޻�����ĵ�һ���ཻ�ڵ㡣������һ��HashSet������������������������ཻ��endһ����ͬ��
 * ���裺
 * �ٱ������������ֱ�õ����Ⱥ����һ���ڵ�length1,end1;length2,end2��
 * ��������������ཻ��endһ����ͬ�����򣬲��ཻ��ֱ�ӷ���null��
 * ��ȷ�����������ȵĲ�ֵ���ó����������߲�ֵ��ô��Ĳ�����Ȼ����������ͬʱ�ߣ�������ʱ����ǵ�һ���ཻ�ڵ㡣
***************************************/
static Node *allNoLoop(Node *head1, Node *head2)
{
	Node *end1 = head1;
	int length1 = 0;
	while (nullptr != end1)
	{
		length1++;
		end1 = end1->next;
	}
	Node *end2 = head2;
	int length2 = 0;
	while (nullptr != end2)
	{
		length2++;
		end2 = end2->next;
	}
	if (end1 != end2)
	{
		return nullptr;
	}
	
	Node * bigHead = nullptr;
	Node * samllHead = nullptr;
	bigHead = length1 >= length2 ? head1 : head2;
	samllHead = bigHead == head1 ? head2 : head1;
	int difference = abs(length1 - length2);
	for (int i = 0; i < difference; ++i)
	{
		bigHead = bigHead->next;
	}
	while (bigHead != samllHead)
	{
		bigHead = bigHead->next;
		samllHead = samllHead->next;
	}
	return samllHead;
}
/***************************************
* ���������л�����ĵ�һ���ཻ�ڵ㡣
 * ���裺
 * ���ж������л���������ཻ����������֣����ܲ��ཻ����һ���ཻ���ڶ����ཻ������Ӧ��ͼ�ϣ���
 * ���������������뻷�ڵ���ȣ���Ϊ��һ���ཻ�����
 * ����Ե�һ���ཻ�������ʵ���޻������ཻ���ۻ�����һ�£�ֻ�������㳤�ȵ�ʱ���޻��ǵ�end���л����ǵ��뻷�ڵ㣻
 * ���������ȣ���Ϊ���ཻ���ߵڶ����ཻ�����
 * �ݴ�ʱ��loopNode1һֱ�����ߣ�����ڻص��Լ�֮ǰ��û������loopNode2����Ϊ���������ཻ��
 * �����ཻ��ֱ�ӷ���loopNode1��loopNode2���ɣ���Ϊ���������ǵ�һ���ཻ�ڵ㣬ֻ��������Բ�ͬ������Եġ�
***************************************/
static Node *allLoop(Node *head1, Node *head2, Node *LoopNode1, Node *LoopNode2)
{
	if (LoopNode1 == LoopNode2)
	{
		int length1 = 0;
		int length2 = 0;
		Node *end1 = head1;
		Node *end2 = head2;
		while (LoopNode1 != end1)
		{
			length1++;
			end1 = end1->next;
		}
		while (LoopNode2 != end2)
		{
			length2++;
			end2 = end2->next;
		}
		Node * bigHead = nullptr;
		Node * samllHead = nullptr;
		bigHead = length1 >= length2 ? head1 : head2;
		samllHead = bigHead == head1 ? head2 : head1;
		int difference = abs(length1 - length2);
		for (int i = 0; i < difference; ++i)
		{
			bigHead = bigHead->next;
		}
		while (bigHead != samllHead)
		{
			bigHead = bigHead->next;
			samllHead = samllHead->next;
		}
		return bigHead;
	}
	else if (LoopNode1->next == LoopNode2 || LoopNode2->next == LoopNode1)
	{
		Node *temp = LoopNode1->next;
		while (temp != LoopNode1)
		{
			if (temp == LoopNode2)
			{
				return LoopNode1;
				//or return loopNode2;
			}
			temp = temp->next;
		}
		return nullptr;
	}
	else
	{
		return nullptr;
	}
}


int main00411101011055544545222(void)
{
	Node *Head1 = nullptr;
	Head1 = creatList();
	//printList(Head1);
	Node *cur = Head1;
	while (cur->data != 4) // �ҵ�ĩβ���γɻ�
	{
		cur = cur->next;
	}
	cur->next = Head1->next;

	Node *Head2 = nullptr;
	Head2 = creatList();
	Head2->next->next = Head1;
	//printList(Head2);

	// 1���ж��Ƿ��л������ַ���
	Node *LoopNode1 = nullptr;
	Node *LoopNode2 = nullptr;
	LoopNode1 = getLoopNode_1(Head1);
	LoopNode2 = getLoopNode_1(Head2);
	//Node *LoopNode3 = nullptr;
	//Node *LoopNode4 = nullptr;
	//LoopNode3 = getLoopNode_2(Head1);
	//LoopNode4 = getLoopNode_2(Head2);

	// 2��������ж��Ƿ��ཻ
	Node *IntersectionNode = nullptr;
	if (LoopNode1 == nullptr && LoopNode2 == nullptr)
	{
		IntersectionNode = allNoLoop(Head1, Head2);
	}
	else if(LoopNode1 != nullptr && LoopNode2 != nullptr)
	{
		IntersectionNode = allLoop(Head1, Head2, LoopNode1, LoopNode2);
	}
	else
	{
		IntersectionNode = nullptr;
	}

	if (IntersectionNode == nullptr)
	{
		cout << "δ�ཻ" << endl;
	}
	else
	{
		cout << "�ཻ�ڽڵ�: " << IntersectionNode->data << endl;
	}

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}