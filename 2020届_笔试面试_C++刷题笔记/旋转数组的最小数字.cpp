#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

/***************************************
��Ŀ����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
��˼·����
�����һ�����㷨���Ǵ����ұ����������ǵ����ģ�ֱ���ҵ�һ��С�����Ϳ���ֹͣ�ˡ�
***************************************/
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
		{
			return 0;
		}
		//int min = INT_MAX; // ���ַ�ʽҪ��N�Σ�
		//for (auto it : rotateArray)
		//{
		//	if (min > it)
		//	{
		//		min = it;
		//	}
		//}
		//return min;

		// �����ǵ����ģ�ֱ���ҵ�һ��С�����Ϳ���ֹͣ�ˡ�
		for (int i = 0; i < rotateArray.size() - 1; i++)
		{
			if (rotateArray[i] > rotateArray[i + 1]) // ֻҪ�ҵ�һ�������ǰ��С�ģ���ô���ֵ������С��
			{
				return rotateArray[i + 1];
			}
		}
		return rotateArray[0];  //û�������Ҳ�Ϊ�գ����һ��Ԫ����С
	}
};


int main_��ת�������С����(void)
{


	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}