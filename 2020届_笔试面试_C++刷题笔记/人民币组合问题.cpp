#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
/*
��Ŀһ��
Ŀǰ�����ϵ�ֽ����Ҫ��1Ԫ��5Ԫ��10Ԫ��20Ԫ��50Ԫ��100Ԫ���֣����Ҫ��һ����ƷstrTargetNumԪ���ж����ֻ�����ɷ�ʽ��
��Ŀ����
���ڹ涨��ÿ�ֻ��ҵ��������ΪstrValueSequences = "6 5 4 3 2 1";
*/

// �ָ��ַ���
static void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
	{ 
		v.push_back(s.substr(pos1));
	}	
}

// �ַ�������תΪint����
static void StringToInt(vector<string>& s, vector<int> &v)
{
	for (auto i = 0; !s.empty(); i++)
	{
		v.push_back(std::stoi(s.front()));
		s.erase(s.begin());
	}
}


int process(std::string strTargetNum, std::string strValueSequences) 
{
	//insert your code here:
	int m = std::stoi(strTargetNum);
	vector<string> numstr;
	SplitString(strValueSequences, numstr, " ");
	vector<int> nums;
	StringToInt(numstr, nums);
	int sum = 0; // �����������ܼ�Ǯ
	int count = 0; //������������ϴ���
	int money[] = { 1,5,10,20,50,100 };//ֽ�����

	for (int i = 0; i <= nums[5]; i++) {
		//100Ԫ���ܳ��ֵ������������޶�����nums�����ã�i <= m / money[5]
		for (int j = 0; j <= nums[4]; j++) {
			//50Ԫ���ܳ��ֵ�����
			for (int k = 0; k <= nums[3]; k++) {
				//20Ԫ���ܳ��ֵ�����
				for (int l = 0; l <= nums[2]; l++) {
					//10Ԫ���ܳ��ֵ�����
					for (int n = 0; n <= nums[1]; n++) {
						int o = m - (i * money[5] + j * money[4] + k * money[3] + l * money[2] + n * money[1]); //1Ԫ������
						int sum = i * money[5] + j * money[4] + k * money[3] + l * money[2] + n * money[1] + o * money[0];
						if (sum == m && o >= 0 && o <= nums[0]) {
							count += (i + j + k + l + n + o);
						}
					}
				}
			}
		}
	}
	return count;
}

int main58978979865416418(void)
{
	std::string strValueSequences = "6 5 4 3 2 1";
	std::string strTargetNum = "11";
	int count = 0;
	count = process(strTargetNum, strValueSequences);
	cout << "count:" << count << endl;
	
	cout<<"Write By JZQ!"<<endl;
	//�Զ��Ű棺ctrl+k+F
	return 0;
}