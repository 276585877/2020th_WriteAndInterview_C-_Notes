#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
��ͨ������������ڵ�ŵ�����Ȼ��partition���޿ռ临�Ӷ�Ҫ�����ȶ���Ҫ��
���׷������������ֳ�����������Ȼ��ϲ����ռ临�Ӷ�O(1)�����ȶ���
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
	for (int i = 0; i < 15; i++)
	{
		if (nullptr == head) // ������Ϊ�˱���head1ͣ���ڵ�һ���ڵ㲻�����ø���ָ��ptr�ƶ���
		{
			head = new Node;
			head->data = rand() % 10;
			head->next = nullptr;
			ptr = head;
			continue;
		}
		ptr->next = new Node;
		ptr = ptr->next;
		ptr->data = rand() % 10;
		ptr->next = nullptr;
	}
	return head;
}

// ��ͨ������������ڵ�ŵ�����Ȼ��partition���޿ռ临�Ӷ�Ҫ�����ȶ���Ҫ��
static void partitionList_1(Node *head, int piovt)
{
	vector<int> array;
	Node * cur = head;
	while (cur != nullptr)
	{
		array.push_back(cur->data);
		cur = cur->next;
	}
	sort(array.begin(), array.end());
	reverse(array.begin(), array.end());
	cur = head;
	while (cur != nullptr)
	{
		cur->data = array.back();
		array.pop_back();
		cur = cur->next;
	}
}

// ���׷������������ֳ�����������Ȼ��ϲ����ռ临�Ӷ�O(1)�����ȶ���
/*
��������ǽ�ԭ�����������λ��ֳ�����������������ֱ�Ϊ:
small����������С�ڵĲ��֣�equal��������м���ȵĲ��֣�big��������ұߵĴ��ڲ��֣�
�������������Լ�������ָ��Head��Tail�ֱ������Ե�ͷ����β�����ֳ�����������֮��
����ֻ��Ҫ��������Ȼ��͸�����ֵ�Ƚϣ��������������������������ֵ�Ϳ����ˣ����������������������Ϳ����ˣ�
*/
static void partitionList_2(Node *head, int piovt)
{
	if (head == nullptr)return;
	Node *sHead = nullptr, *sTail = nullptr; //С�ڲ��������  head ��tail
	Node *eHead = nullptr, *eTail = nullptr; //���ڲ�������ġ�head ��tail
	Node *bHead = nullptr, *bTail = nullptr; //���ڲ�������ġ�head ��tail

	Node *next = nullptr;  //����������һ�����
	Node *cur = head;

	//���ֵ���������ͬ������
	while (cur != nullptr) 
	{
		next = cur->next;
		cur->next = nullptr; //�����Ϊ������ƴ�Ӻ����һ���Ͳ�����ȥ��ֵ��next��Ϊnullptr ��
		if (cur->data < piovt) 
		{  //��small ���֡��ֲ�
			if (sHead == nullptr) 
			{ //small���ֵĵ�һ�����
				sHead = cur;
				sTail = cur;
			}
			else 
			{ //small���ֵķǵ�һ���ڵ�
				sTail->next = cur; //��cur�ŵ�small���һ��
				sTail = cur;  //����small���ֵ�sTail
			}
		}
		else if (cur->data == piovt) 
		{
			if (eHead == nullptr) 
			{
				eHead = cur;
				eTail = cur;
			}
			else 
			{
				eTail->next = cur;
				eTail = cur;
			}
		}
		else 
		{
			if (bHead == nullptr) 
			{
				bHead = cur;
				bTail = cur;
			}
			else 
			{
				bTail->next = cur;
				bTail = cur;
			}
		}
		cur = next;
	}

	//����������ϲ�(ע��߽���ж�)
	if (nullptr != sTail) 
	{ //�ϲ�small��equal����
		sTail->next = eHead;
		eTail = (eTail == nullptr ? sTail : eTail); // ���м���������Ƿ�Ϊ�յġ�
	}
	if (nullptr != eTail) 
	{ //�ϲ�equal��big����
		eTail->next = bHead;
	}
	head = (sHead != nullptr ? sHead : eHead != nullptr ? eHead : bHead); // head���������е�һ����Ϊnullptr��ֵ��
}


int main110000051111112222(void)
{
	Node *Head1 = nullptr;
	Head1 = creatList();

	printList(Head1);

	partitionList_1(Head1, 5);

	cout << "partitionList_1���ֹ���" << endl;
	printList(Head1);

	Node *Head2 = nullptr;
	Head2 = creatList();

	printList(Head2);
	cout << endl;

	partitionList_2(Head2, 5);

	cout << "partitionList_2���ֹ���" << endl;
	printList(Head2);
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}