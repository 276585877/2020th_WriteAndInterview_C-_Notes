#include "���������㷨.h"

/*
���Ļ���˼���ǣ�������һ��Ԫ�أ�һ��ȡͷԪ�ػ���ĩβԪ�أ���Ϊ��׼Key��
��Ҫ��������ݷָ�ɶ����������֣����С��key���ұߴ���key

Ȼ���ٰ��˷����������������ݷֱ���п�����������������̿��Եݹ���У�
�Դ˴ﵽ�������ݱ���������С�

//https://baike.baidu.com/item/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/369842?fromtitle=%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F%E6%B3%95&fromid=612251&fr=aladdin
*/

template<class T>
int *partition(T *array, int L, int R);

template<class T>
void swap(T * array, int x, int y);

template<class T>
void Quicksort(T *array, int L, int R)
{
	int *position = nullptr;
	if (L >= R)
	{
		return;
	}
	position = partition(array, L, R);
	Quicksort(array, L, position[0] - 1);
	Quicksort(array, position[1] + 1, R);
	delete position;
}

template<class T>
int * partition(T * array, int L, int R)
{
	int *help = new int[2];
	int key = array[R];// ��¼��Ϊ����(����С�ķֶκʹ�ķֶ�)
	int lessRange = L - 1;
	int bigRange = R + 1;
	while (L < bigRange)
	{
		if (array[L] < key)
		{
			swap(array, ++lessRange, L++);
		}
		else if (array[L] > key)
		{
			swap(array, --bigRange, L);
		}
		else
		{
			L++;
		}
	}
	help[0] = lessRange + 1;
	help[1] = bigRange - 1;
	return help;
}

template<class T>
void swap(T * array, int x, int y)
{
	int temp = 0;
	temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}


//template<class T>
//void Quicksort(T *array, int low, int high)
//{
//	if (low >= high)
//	{
//		return;//�ݹ������־
//	}
//	int first = low;
//	int last = high;
//	int key = array[first];//���ֱ�ĵ�һ����¼��Ϊ����(����С�ķֶκʹ�ķֶ�)
//	while (first < last)
//	{
//		while (first < last && array[last] >= key)
//		{
//			--last;
//		}
//		array[first] = array[last];/*����keyС���Ƶ��Ͷ�*/
//		while (first<last && array[first] <= key)
//		{
//			++first;
//		}
//		array[last] = array[first];/*����key����Ƶ��߶�*/
//	}
//	array[first] = key;//����ȷ�������ֵ�������first = last��(һ�����)
//	Quicksort(array, low, first - 1);//����ߵ����ݶ�����
//	Quicksort(array, first + 1, high);//���ұߵ����ݶ�����
//}

