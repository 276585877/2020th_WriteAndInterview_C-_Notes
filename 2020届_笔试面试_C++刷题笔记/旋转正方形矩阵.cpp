#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

template<class T>
static void print_matrix(vector< vector<T> > &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[0].size(); j++)
			cout << arr[i][j] << "  ";
		cout << endl;
	}
}

/*
����һ�������ξ��󣬰Ѹþ��������˳ʱ����ת90�ȵ�����
Ҫ�󣺶���ؼ����Ӷ�ΪO(1)
���磺
���� 1��  ��2��  ��3��  ��4
						  
���� 5��  ��6��  ��7��  ��8
						  
���� 9   �� 10 ��   11 �� 12
						  
���� 13   ��14��   15   ��16

��ӡ���Ϊ��
	13 9  5 1
	14 10 6 2
	15 11 7 3
	16 12 8 4
*/
template<typename T>
void rotateEdage(vector<vector<T>>& array, int tR, int tC, int dR, int dC) {
	int times = dC - tC;
	int tmp = 0;
	for (int i = 0; i != times; i++) 
	{
		tmp = array[tR][tC + i];
		array[tR][tC + i] = array[dR - i][tC];
		array[dR - i][tC] = array[dR][dC - i];
		array[dR][dC - i] = array[tR + i][dC];
		array[tR + i][dC] = tmp;
	}
}

template<typename T>
void rotateMatrix(vector<vector<T>>& my_matrix) {
	int tR = 0; // ���Ͻ�
	int tC = 0;
	int dR = my_matrix.size() - 1;  // ���½�
	int dC = my_matrix[0].size() - 1;
	while (tR <= dR && tC <= dC) {
		rotateEdage(my_matrix, tR++, tC++, dR--, dC--);
	}

}


int main111322353125135(void)
{
	vector<vector<int>> my_matrix = { {1, 2, 3, 4},
									  {5, 6, 7, 8},
									  {9, 10, 11, 12},
									  {13,14, 15, 16} };
	rotateMatrix(my_matrix);

	print_matrix<int>(my_matrix);
	cout << endl;

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}