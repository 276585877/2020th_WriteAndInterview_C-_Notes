#include <iostream>
using namespace std;
int main_���_С��() {
	int c = 0x12345; // 16��������
	char *a = (char *)(&c); // ȡ�����ֽڡ�
	printf("%x \n", a); // 16�������
	printf("%x \n", *a);
	printf("%x \n", a + 1);
	printf("%x \n", *(a + 1));
	cout << "Hello World!" << endl;

	return 0;
}