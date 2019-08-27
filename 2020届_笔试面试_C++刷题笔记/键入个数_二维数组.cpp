#include "iostream"
using namespace std;
/*
Vector�͵�һά��ά���飬��STL����������
*/

int **get_2D_array(int &N, int &M) //ע��һ�㣬�ֲ�����������ڴ洫�ݲ�����,����һ
{
	static int **array_2D_temp = new int *[N];//����ָ��ָ��N��һ��ָ�룬
	for (int i = 0;i < N; i++)
	{
		array_2D_temp[i] = new int[M];
	}
	return array_2D_temp; //���Ǿֲ������ĵ�ַ������Ϊstatic�������ⷵ�ء�
}

void get_2D_array(int **array_2D, int &N, int &M)//���������������������ά������ڴ棬������������һά������ڴ�
{
	if (array_2D == nullptr || N < 0 || M < 0)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		array_2D[i] = new int[M];
	}
}

void deldete_2D_array(int **array_2D, int &N, int &M)
{
	if (array_2D == nullptr || N < 0 || M < 0)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		delete []array_2D[i];
		array_2D[i] = nullptr;
	}
	delete array_2D;
	array_2D = nullptr;
	//��ʵ�϶�ά����ռ���ͷŻ����Ը��򵥵��ã�delete [] array2D;
}

void printf_2D_array(int **array_2D, int &N, int &M)
{
	if (array_2D == nullptr || N < 0 || M < 0)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0;j <M;j++)
		{
			cout << array_2D[i][j] << '\t';
		}
		cout << endl;
	}
}

void write_value_2D_array(int **array_2D, int &N, int &M)
{
	if (array_2D == nullptr || N < 0 || M < 0)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> array_2D[i][j];
		}
	}
}



int main_0233333(void)
{
	int N = 0, M = 0;  //N��M��
	cin >> N >> M;
	////////////////////////////////////������,,������������ã�
	int **array_2D = new int *[N];  //����ָ��ָ��N��һ��ָ��
	get_2D_array(array_2D, N, M);
	////////////////////////////////////

	/////////////////////////////////����һ
	//int **array_2D = nullptr;
	//array_2D = get_2D_array(N, M); //ע��һ�㣬�ֲ�����������ڴ�ĵ�ַ���ݲ�����,
	/////////////////////////////////
	
	write_value_2D_array(array_2D, N, M);

	printf_2D_array(array_2D, N, M);

	deldete_2D_array(array_2D, N, M);


	cout << "JZQ!" << endl;
	system("pause");
	return 0;
	//�Զ��Ű棺ctrl+K,ctrl+F
}