#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

static const string BASE64CODE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

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
			ans += t - 10 + 'a'; // ��Сд��'a'��'A'����
		}
		n /= radix;
	} while (n != 0);    //ʹ��do{}while�����Է�ֹ����Ϊ0�����
	reverse(ans.begin(), ans.end());
	while (ans.size() < 8) // ����8λʹ��
	{
		ans = "0" + ans;
	}
	return ans;
}

static string encode(string &data)
{
	if (data.size() == 0)
	{
		return data;
	}
	vector<int> ASCII;
	string BINARY = "";
	for (auto it : data)
	{
		ASCII.push_back((int)it); // תΪASCII��
		BINARY += TenToredix(ASCII.back(), 2); // ��ASCII��תΪ2���ơ�
	}
	//�����Ȳ��ܱ�6���������ڵ�λ��0���ܱ�6����Ϊֹ
	while (BINARY.size() % 6 != 0)
	{
		BINARY += "0";
	}
	//��6��һ���ֳ��ִ�����
	vector<string> BINARY_6;
	string temp = "";
	while (BINARY.size() / 6 > 0)
	{
		temp = BINARY.substr(0, 6);
		BINARY = BINARY.substr(6);
		BINARY_6.push_back(temp);
	}
	// ȷ�����ղ�λ����
	int overLen = 0;
	if (data.size() % 3 != 0)
	{
		overLen = 3 - data.size() % 3;
	}
	// ��ű�����
	vector<int> index(BINARY_6.size(), 0);
	string code(index.size() + overLen , 0);
	for (int i = 0; i < BINARY_6.size(); i++)
	{
		// ������λת����ʮ��������
		index[i] = radixToTen(BINARY_6[i], 2);
		//Base64 : Value -> Encoding
		code[i] = BASE64CODE[index[i]];
	}
	// ��λ��=��
	switch (overLen)
	{
	case 2:
		code[code.size() - 2] = '=';//����Ҫbreak
	case 1:
		code[code.size() - 1] = '=';
	default:
		break;
	}
	return code;
}

int main_Base64����(void)
{
	string input;
	while (cin >> input)
	{
		cout << encode(input) << endl;
	}
	return 0;
}

// ����
//public static String decode(String srcData) {
//	//���Ԫ�����С�=���ĸ���������֮ȥ��
//	int counter = 0;
//	if (srcData.contains("=")) {
//		counter = 1;
//		if (srcData.substring(srcData.length() - 2, srcData.length() - 1).equals("=")) {
//			counter = 2;
//		}
//	}
//	srcData = srcData.replaceAll("=", "");
//	//�����ĸ���Base64�����ת���ɶ�ӦValue����ת���ɶ���λ ��Ȼ�����ж���λ����6λ��������ж���λ���һ���ִ�
//	char[] srcCh = srcData.toCharArray();
//	StringBuffer bin6SB = new StringBuffer();
//	int index;
//	String bin6Str;
//	for (int i = 0; i < srcCh.length; i++) {
//		//���Base64������Value
//		index = base64Code.indexOf(srcCh[i]);
//		//��ValueתΪ����λ
//		bin6Str = Integer.toBinaryString(index);
//		//�ڳ��Ȳ���6λ�Ķ���λ�ĸ�λ�ϲ�0ֱ������6λ���ٱ�����ִ�
//		while (bin6Str.length() < 6) {
//			bin6Str = "0" + bin6Str;
//		}
//		bin6SB.append(bin6Str);
//	}
//	String bin6Str_all = bin6SB.toString();
//	//�������λ�ִ����жಹ��0����֮ȥ��
//	if (counter == 1) {
//		bin6Str_all = bin6Str_all.substring(0, bin6Str_all.length() - 2);
//	}
//	else if (counter == 2) {
//		bin6Str_all = bin6Str_all.substring(0, bin6Str_all.length() - 4);
//	}
//	//��8��һ���ֳ��ִ�����
//	List<String> bin8List = new ArrayList<String>();
//	String temp;
//	while (bin6Str_all.length() / 6 > 0) {
//		temp = bin6Str_all.substring(0, 8);
//		bin6Str_all = bin6Str_all.substring(8);
//		bin8List.add(temp);
//	}
//	String[] bin8Str = bin8List.toArray(new String[bin8List.size()]);
//	//�����ִ������ÿ��Ԫ�أ���һ�����λ��ת��ʮ����������ǿ��ת����char����
//	char[] ascii = new char[bin8Str.length];
//	for (int i = 0; i < ascii.length; i++) {
//		ascii[i] = (char)Integer.parseInt(bin8Str[i], 2);
//	}
//	return String.valueOf(ascii);
//}
