#include<iostream>
using namespace std;
int a[100] = { 1,2,3,5,12,12,12,15,29,55 };//�����е�������С����
int k;//Ҫ�ҵ�����
int found(int low, int high)
{
	int mid = low + (high - low) / 2;
	if (low > high)//�������û���ҵ��𰸣�����-1
		return -1;
	else
	{
		if (a[mid] == k)
			return mid;//�ҵ�!����λ��.
		else
			return a[mid] > k ? found(low, mid - 1) : found(mid + 1, high);
		//else if (a[mid] > k)
		//	return found(low, mid - 1);//�����
		//else
		//	return found(mid + 1, high);//���ұ�
	}
}
//int BinSearch(SeqList *R��int n, KeyType K)
//{
//	//�������R[0..n-1]�н��ж��ֲ��ң��ɹ�ʱ���ؽ���λ�ã�ʧ��ʱ����-1
//	int low = 0, high = n - 1, mid��     //�õ�ǰ���������ϡ��½�ĳ�ֵ
//		while (low <= high)
//		{
//			if (R[low].key == K)
//				return low;
//			if (R[high].key == k)
//				return high;          //��ǰ��������R[low..high]�ǿ�
//			mid = low + (high - low) / 2;
//			/*ʹ��(low+high)/2�����������������
//			�����������ڵ�low+high�Ľ�����ڱ��ʽ����������ܱ�ʾ�����ֵʱ��
//				�����������������/2�ǲ��������ȷ����ģ���low+((high-low)/2)
//				�������������*/
//			if (R[mid].key == K)
//				return mid;             //���ҳɹ�����
//			if (R[mid].key < K)
//				low = mid + 1;              //������R[mid+1..high]�в���
//			else
//				high = mid - 1;             //������R[low..mid-1]�в���
//		}
//	if (low > high)
//		return -1;//��low>highʱ��ʾ������������û�н��������ʧ��
//}

int main_���ַ�()
{
	cin >> k;//����Ҫ�ҵ�����   c���԰�cin��Ϊscanf����
	cout << found(0, 9);//������a[0]��a[9]    c���԰�cout��Ϊprintf����
	return 0;
}