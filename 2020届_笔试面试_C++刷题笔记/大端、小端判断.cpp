#include <iostream>
using namespace std;
int main_���_С��() // main_���_С��
{
	short int c = 0x1122; // 16���ƣ�ÿ������ռ4bit������������ռ8bit����1�ֽ�
	char *p = (char *)(&c); // ȡ�����ֽڡ�
	printf("%x \n", p); // 16�������
	printf("%x \n", *p);
	printf("%x \n", p + 1);
	printf("%x \n", *(p + 1));
	cout << "Hello World!" << endl;
	//��*p=0x11,���Ǵ��; ��*p=0x22,����С��......�˱�������С�ˡ�
	return 0;
}