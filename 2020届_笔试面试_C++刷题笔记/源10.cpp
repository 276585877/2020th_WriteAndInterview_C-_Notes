//#include <iostream>
//#include <string>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//int main(void)
//{
//	int m = 36, s = 255, t = 10;
//	int count = 0;
//	int sum = 0;
//	while (s > 0 && count < t)
//	{
//		int times = m / 10; // ��˲�ƶ��ٴ�
//		if (times > 0) // ��˲�ƣ���˲��
//		{
//			while (times-- > 0 && count < t)
//			{
//				s -= 50;
//				sum += 50;
//				m -= 10;
//				count++;
//			}
//		}
//		else // ����˲�ƣ�ͣ�����ָ�
//		{
//			times = s / 50; // ʣ�¾�����Ҫ˲�ƶ��ٴ�
//			while (times-- > 0 && count < t)
//			{
//				while (m < 10 && count < t)
//				{
//					m += 4; // ÿ�ظ�4����Ҫ1��
//					count++;
//				}
//				if (count >= t)
//				{
//					break;
//				}
//				s -= 50;
//				sum += 50;
//				m -= 10;
//				count++;
//			}
//			if ( s > 0)
//			{
//				count += (s / 13 == 0 ? 1 : (s % 13 == 0 ? s / 13 : s / 13 + 1));
//				sum += s;
//				s = 0;
//			}
//		}
//	}
//	if (count <= t)
//	{
//		cout << "Yes " << count << endl;
//	}
//	else
//	{
//		cout << "No " << sum << endl;
//	}
//	return 0;
//}