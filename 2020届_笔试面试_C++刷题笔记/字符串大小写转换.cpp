#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main_14141515454(void)
{
	string str = "ASDdcxaSDAsdasd";
	///תСд
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	cout << "ת��ΪСд��Ϊ��" << str << endl;
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	cout << "ת��Ϊ��д��Ϊ��" << str << endl;

	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}