#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

/***************************************
1.C��ָ����ʽ���
	printf("%05o\n",35);    //���˽��Ƹ�ʽ���������5λ��λ����
	printf("%03d\n",35);    //��ʮ���Ƹ�ʽ���������3λ��λ����
	printf("%05x\n",35);    //��ʮ�����Ƹ�ʽ���������5λ��λ����

2.C++��ָ����ʽ���
	cout << "35��8����:" << std::oct << 35<< endl;
	cout << "35��10����" << std::dec << 35 << endl;
	cout << "35��16����:" << std::hex << 35 << endl;
	cout << "35��2����: " << bitset<8>(35) << endl;      //<8>����ʾ����8λ���

��.C/C++���ֽ���ת���⺯��
1.strol()���������Խ�һ�������2-36�����ַ���ת��Ϊʮ����������
	����ԭ�ͣ�long int strtol(const char *nptr, char **endptr, int base)
	��ʽ��base��Ҫת�������Ľ��ƣ��Ƿ��ַ��ḳֵ��endptr��nptr��Ҫת�����ַ���
	���ӣ�
	char a[20]="10549stend#12";
	char *stop;
	int ans=strtol(a, &stop, 8);   //���˽�����"1054"ת��ʮ���ƣ������Ϊ�Ƿ��ַ�
2.itoa�������������Խ�һ��10������ת��Ϊ�����2-36�����ַ�����:
	����ԭ�ͣ�char*itoa(int value,char*string,int radix);
	��ʽ��itoa(num, str, 2); num��һ��int�͵ģ���Ҫת����10��������str��ת������������ֵΪĿ����ơ�
	���ӣ�
	int num = 10;
	char str[100];
	_itoa(num, str, 2);  //c++��һ����_itoa����itoaҲ��,
3.sprintf()���������Խ�һ��10������ת��Ϊָ����ʽ��n�����ַ�������
	����ԭ�ͣ�int sprintf( char *buffer, const char *format, [ argument] �� )
	���ӣ�
	char s[100]={0};
	sprintf(s, "%d", 123); //ʮ�����������"123"
	sprintf(s, "%4d%4d", 123, 4567); //ָ����Ȳ������߲��ո񣬲�����" 1234567"
	sprintf(s, "%8o", 123);    //�˽�����������ռ8��λ��
	sprintf(s, "%8x", 4567); //Сд16 ���ƣ����ռ8 ��λ�ã��Ҷ���
	sprintf(s, "%10.3f", 3.1415626); //������" 3.142"
	int i = 100;
	sprintf(s, "%.2f", i);    //ע�����ǲ��Ե�
	sprintf(s, "%.2f", (double)i);    //Ҫ�������ַ�ʽ����
***************************************/

/***************************************
// ����2~36������ת��Ϊ10���ƣ��������תʮ���ƣ�
// s:�������radix���Ƶ��ַ���������ǰ׺������0x
// ans:����10���Ƶ�����
***************************************/
static int radixToTen(string s, int radix)
{
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		char t = s[i];
		if (t >= '0'&&t <= '9')
		{
			ans = ans * radix + t - '0';
		}
		else
		{
			ans = ans * radix + t - 'A' + 10; // ��Сд��'a'��'A'����
		}
	}
	return ans;
}
/***************************************
// ��10������ת��Ϊ�����radix��������ʮ����ת������ƣ�
// n:������Ĵ�ת��ʮ���Ƶ�����
// ans:����radix���Ƶ��ַ���������ǰ׺������0x
***************************************/
static string TenToredix(int n, int radix)
{
	string ans = "";
	do 
	{
		int t = n % radix;
		if (t >= 0 && t <= 9)
		{    
			ans += t + '0';
		}
		else 
		{
			ans += t - 10 + 'A'; // ��Сд��'a'��'A'����
		}
		n /= radix;
	} while (n != 0);    //ʹ��do{}while�����Է�ֹ����Ϊ0�����
	reverse(ans.begin(), ans.end());
	//while (ans.size() < 8) // ����8λʹ��
	//{
	//	ans = "0" + ans;
	//}
	return ans;
}

int main_���������ʮ�����໥ת��(void)
{
	//int input;
	//while (cin >> hex >> input) // a or A
	//{
	//	cout << dec << input << endl; // 10 and 10
	//	cout << hex <<input << endl; // A or a
	//	cout << hex << setiosflags(ios::uppercase) << input << endl; // A and A
	//	printf("%x\n", input); // a and a
	//	printf("%d\n", input); // 10 and 10
	//	cout << endl;
	//}

	int input;
	cin >> input;
	string str = TenToredix(input, 16);
	cout << "str = " << str << endl;

	string input2;
	cin >> input2;
	int out = radixToTen(input2, 16);
	cout << "out = " << out << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}