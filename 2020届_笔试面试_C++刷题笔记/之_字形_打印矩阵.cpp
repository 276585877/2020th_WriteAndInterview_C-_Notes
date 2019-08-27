#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

template<typename T>
void printMatrix(vector<vector<T>>& my_matrix) {
	for (int i = 0; i < my_matrix.size(); ++i) {
		for (int j = 0; j < my_matrix[0].size(); ++j) {
			cout << my_matrix[i][j] << ",";
		}
	}
}
/*
����һ������matrix,���ա�֮�����εķ�ʽ��ӡ�������,����: 1 2 3 4 5 6 7 8 9 10 11 12.
��֮�����δ�ӡ�Ľ��Ϊ:1,2,5,9,6,3,4,7,10,11,8,12����ռ临�Ӷ�ΪO(1) O(1)O(1).

�����꣨tR��tC���ĳ�ʼΪ��0,0���������ž���ĵ�һ���ƶ���tC++��,���ﵽ��һ�����ұߵ�Ԫ�غ������ž������һ���ƶ� (tR++)��
�����꣨dR��dC���ĳ�ʼΪ��0,0���������ž���ĵ�һ���ƶ���dR++�����������һ�����±ߵ�Ԫ��ʱ�������ž�������һ��һ����dC++����
��������������ͬ���ƶ���ÿ���ƶ����������������������߾��Ǿ����е�һ��б�ߣ���ӡб���ϵ�Ԫ�ؼ��ɡ�
����ϴ�б���Ǵ����������ϴ�ӡ�ģ����һ���Ǵ����������´�ӡ����֮��Ȼ����֮�����԰Ѵ�ӡ�ķ�����bool������ʾ��ÿ��ȡ�����ɡ�

�ο����ͣ�<https://blog.csdn.net/alxe_made/article/details/90712149>
*/
template<typename T>
void printLevel(vector<vector<T>>& my_matrix, int tR, int tC, int dR, int dC, bool updown) 
{
	if (updown) {
		while (tR != dR + 1) {
			cout << my_matrix[tR++][tC--] << ",";
		}
	}
	else {
		while (dR != tR - 1) {
			cout << my_matrix[dR--][dC++] << ",";
		}
	}
}

template<typename T>
void printMatrixZigZag(vector<vector<T>>& my_matrix) {
	int tR = 0;
	int tC = 0;
	int dR = 0;
	int dC = 0;
	bool updown = false;
	int endR = my_matrix.size() - 1;
	int endC = my_matrix[0].size() - 1;
	while (tR < endR + 1) 
	{
		printLevel(my_matrix, tR, tC, dR, dC, updown);
		tR = (tC == endC ? tR + 1 : tR); // �Ƿ������һ�У����ˣ���+1
		tC = (tC == endC ? tC : tC + 1); // �Ƿ������һ�У����ˣ��в���
		dC = (dR == endR ? dC + 1 : dC); // �Ƿ������һ�У����ˣ���+1
		dR = (dR == endR ? dR : dR + 1); // �Ƿ������һ�У����ˣ��в���
		updown = !updown; // ����ʾ�߼�ȡ����~��ʾ��λȡ��
	}
	cout << "\n";
}


int main011222000315220505202(void)
{
	vector<vector<int>> my_matrix = { {1, 2, 3, 4},
									  {5, 6, 7, 8},
									  {9, 10,11,12} };
	cout << "origin matrix is:" << endl;
	printMatrix(my_matrix);
	cout << "\n";
	cout << "zigzig matrix is:" << endl;
	printMatrixZigZag(my_matrix);

	cout << "Write By JZQ!" << endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}