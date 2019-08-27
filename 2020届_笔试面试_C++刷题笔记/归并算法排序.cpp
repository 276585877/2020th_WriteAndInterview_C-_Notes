#include "�鲢�㷨����.h"

/*
�鲢���򷨣�Merge Sort�����¼��MS���Ƿ��η�˼�����õ�һ���䷶������Ҫ�㷨�������Է�Ϊ���²��裺
Step 1����n��Ԫ�طֳ�������n/2Ԫ�ص�������
Step 2����MS�����������еݹ����������Խ�����ԭ���зֽ��n�������У�
Step 3���ϲ�����������õ�����
*/

template<class T>
void Merge(T * array, int L, int mid, int R);
template<class T>
void MSort(T * array, int L, int R);

template<class T>
void MergeSort(T *array, int len)// O(n*logn)
{
	if (array == nullptr || len < 2)
	{
		return;
	}
	MSort(array, 0, len - 1);
}

//ÿ�η�Ϊ��· ��ֻʣ��һ��Ԫ��ʱ���Ͳ���Ҫ�ڻ���
template<class T>
void MSort(T * array, int L, int R)
{
	if (L == R)
	{
		return;
	}
	int mid = L + ((R - L) >> 1);
	MSort(array, L, mid);
	MSort(array, mid + 1, R);
	Merge(array, L, mid, R);
}

template<class T>
void Merge(T * array, int L, int mid, int R)
{
	T * help = new T[R - L + 1];
	int i = 0;
	int p1 = L;
	int p2 = mid + 1;
	while (p1 <= mid && p2 <= R) // ��������ѭ����˵��p1��p2��һ��Խ�硣
	{
		help[i++] = array[p1] < array[p2] ? array[p1++] : array[p2++];
	}
	while (p1 <= mid)
	{
		help[i++] = array[p1++];
	}
	while (p2 <= R)
	{
		help[i++] = array[p2++];
	}
	for (int j = 0; j < i; j++)// i�������������������Ҫ���±��1
	{
		array[L + j] = help[j];
	}
	delete help;
}

/*
template<class T>
void Merge(T src[], T des[], int low, int mid, int high);
template<class T>
void MSort(T src[], T des[], int low, int high, int max);

template<class T>
void MergeSort(T *array, int len)// O(n*logn)
{
	MSort(array, array, 0, len - 1, len);
}

//ÿ�η�Ϊ��· ��ֻʣ��һ��Ԫ��ʱ���Ͳ���Ҫ�ڻ���
template<class T>
void MSort(T src[], T des[], int low, int high, int max)
{
	if (low == high) //ֻ��һ��Ԫ�أ�����Ҫ�鲢���������des[low]
	{
		des[low] = src[low];
	}
	else //������Ԫ�أ�������·����
	{
		int mid = (low + high) / 2;
		T* space = new T[max];

		//�ݹ������·����·�Ļ��� 
		//��ʣ��һ��Ԫ�ص�ʱ���ݹ黮�ֽ�����Ȼ��ʼmerge�鲢����
		if (space != nullptr)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid + 1, high, max);
			Merge(space, des, low, mid, high); //���ù鲢�������й鲢
		}
		delete[]space;
	}
}

template<class T>
void Merge(T src[], T des[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while ((i <= mid) && (j <= high)) //��С�ķŵ�Ŀ�ĵ���
	{
		if (src[i] < src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i <= mid)  //����ʣ����β��Ԫ��
	{
		des[k++] = src[i++];
	}

	while (j <= high) //����ʣ����β��Ԫ��
	{
		des[k++] = src[j++];
	}
}

*/