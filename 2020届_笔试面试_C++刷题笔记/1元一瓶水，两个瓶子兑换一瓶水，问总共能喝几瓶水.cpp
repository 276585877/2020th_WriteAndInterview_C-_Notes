#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
��c++���ʵ�֣���40��Ǯ��һƿˮ�ļ۸���1Ԫ��2����ƿ���Զһ�1ƿˮ�����ܹ����Ժȶ���ƿ��ˮ��
���Բ��������ϰ��ƿ�ӵ������лл��
�ðɣ���˵�����Ŷ������c++��������ʵ�֣����Ҵ���79ƿ
*/

#define P 1 //��ˮ�ĵ���
#define N 2 //��һƿ��ˮ����Ŀ�ƿ����

//SodaConvert���������ÿ�ƿ��������ˮ����
static int SodaConvert(int x)
{
	if (x < N)
	{
		return 0;
	}
	int ret = x / N;// ��ƿ�һ�����ˮ����
	cout << "ret = " << ret << endl;
	x = ret + x % N; // �һ�����ˮ��ʣ�µĿ�ƿ����֮�� = ���ڵĿ�ƿ��
	return (ret + SodaConvert(x));

}

int main_sda156(void)
{
	int money = 0;
	int n = 0;
	cout << ("�������");
	cin >> money;
	n = money / P;
	int bottle = n + SodaConvert(n);//���պȵ�����ˮ���� = �򵽵� + ��ƿ������
	cout << bottle << "ƿ" << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}