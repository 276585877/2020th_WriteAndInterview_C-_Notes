//#include <iostream>
//#include <vector>
//#include <numeric>
//#include <limits>
//#include <algorithm>
//
//using namespace std;
//
//static bool compare(int a, int b)
//{
//	return a > b;
//}
//
///*������������������ʵ����ĿҪ��Ĺ���
//��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
//******************************��ʼд����******************************/
//int solution(vector < int > prices, int budget) {
//	sort(prices.begin(), prices.end(), compare);
//	int count = 0;
//	while (budget > 0)
//	{
//		if (budget >= prices[0])
//		{
//			budget -= prices[0];
//			//prices.erase(prices.begin());
//			count++;
//		}
//		else if (!prices.empty())
//		{
//			prices.erase(prices.begin());
//		}
//		else // budget < prices[0] �� prices.empty()
//		{
//			return -1;
//		}
//	}
//	return count;
//}
///******************************����д����******************************/
//
//
//int main() {
//	int res;
//
//	int _prices_size = 0;
//	cin >> _prices_size;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	vector<int> _prices;
//	int _prices_item;
//	for (int _prices_i = 0; _prices_i < _prices_size; _prices_i++) {
//		cin >> _prices_item;
//		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		_prices.push_back(_prices_item);
//	}
//
//
//	int _budget;
//	cin >> _budget;
//	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//
//
//	res = solution(_prices, _budget);
//	cout << res << endl;
//
//	return 0;
//
//}
