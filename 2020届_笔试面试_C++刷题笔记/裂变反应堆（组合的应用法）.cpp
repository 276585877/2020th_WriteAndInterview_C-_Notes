/*
��Ŀ������
ά�˶಩ʿ������һ���ѱ䷴Ӧ�ѣ���ȡ�ô���Һ��״̬�ķ��������ʡ���Ӧ�ѵ�������V���ء�
����Nƿ�ķ�����Һ�壬ÿ������һ����������һ�����������Һ�嵹�뷴Ӧ��ʱ��Ҳ����һЩ��λ��������
���ڣ�ά�˶���Ҫ�����������󻯡����ǣ���һ���������������о���ԭ��Ԫ�ص�����֪ʶ����ʷ��
��ʶ����Ӧ���ڷ�����Һ����������ܳ����ض����ٽ�����M������Ӧ�ͻ�ʧ�أ����������ҵı�ը��
дһ���㷨���������ӷ�Ӧ�ѻ��������������������������������

���룺
�ú���/���������������������------
reactorCap��һ����������ʾ��Ӧ�ѵ�����(V);
numberOfRadLiquid,һ����������ʾ����Сƿ������(N);
criticalMass��һ����������ʾ��Ӧ�ѵ�����ٽ�����(M);
volumes��һ�������б���˳���ʾN�ݷ�����Һ������;
masses��һ�������б���˳���ʾN�ݷ�����Һ�������;
energies,һ�������б���˳���ʾN�ݷ�����Һ�������������

�����
����һ����������ʾ�ɸ�����Լ�������´ӷ�Ӧ���в��������������

ʾ����
���룺
reactorCap=100
numberOfRadLiquid=5
criticalMass=15
volumes=[50,40,30,20,10]
masses=[1,2,3,9,5]
energies=[300,480,270,200,180]
�����
960

���ͣ�
ͨ��ѡ��1��2��5��ƿ�е�Һ�壬����������=300+480+180=960��
����Һ����ϲ����������=50+40+10=100��������reactorCap,
��ɷ�Ӧ���е�������=1+2+5=8��������criticalMass��

����˼·������һ������������������0-1�������⣬0-1����������Բο��ҵ���һƪ���ģ�0-1�������⣬
����ֻ�轫һ�����������Ķ�ά��̬�滮����һ����ά��̬�滮��
���͡�https://blog.csdn.net/hongtao_6/article/details/97246319��

�������˼·��
��N��ƿ�ӣ�������ƿ�ӱ���ţ���N=5Ϊ������ô����1 2 3 4 5��������5������������ϣ�����
�ȴ�5��ƿ����ȡ5�����õ���ϣ�
1  2  3  4  5
�ٴ�5��ƿ����ȡ4�����õ���ϣ�
1  2  3  4
1  2  3  5
1  2  4  5
1  3  4  5
2  3  4  5
�ٴ�5��ƿ����ȡ3�����õ���ϣ�
1  2  3
1  2  4
1  2  5
1  3  4
1  3  5
1  4  5
2  3  4
2  3  5
2  4  5
3  4  5
�ٴ�5��ƿ����ȡ2�����õ���ϣ�
1  2
1  3
1  4
1  5
2  3
2  4
2  5
3  4
3  5
4  5
�ٴ�5��ƿ����ȡ1�����õ���ϣ�
1
2
3
4
5
ÿһ�εõ���Ϻ󣬱���������ϣ��ҵ���������������������ɡ�
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��ӡ��ά����vector<vector<int>> array
static void print_2D_Array(vector<vector<int>> array)
{
	for (unsigned i = 0; i < array.size(); ++i)
	{
		for (vector<int>::iterator it = array[i].begin(); it != array[i].end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

// ����������㷨: C(n, m): ��n��������ѡm�������һ���µ���, ���ж��������, �ֱ���ʲô 
// ��v[]����ѡm��Ԫ�����һ�����, ��˳���޹�
static vector<vector<int>> Cnm(vector<int> v, int m)
{
	if (v.size() < m)
	{
		return{};               // �Ҳ������������
	}

	vector<vector<int>> ret;
	if (v.size() == m)          // v[]��Ԫ��ȫѡ
	{
		ret.push_back(v);       // Ψһ��һ�����
		return ret;
	}
	if (m == 1)                // v[]����ѡ1����
	{
		for (auto it : v)
		{
			ret.push_back(vector<int> {it}); // m��ѡ��ÿ��ѡһ��
		}
		return ret;
	}

	while (v.size() >= m)
	{
		int first = v.front();
		v.begin() = v.erase(v.begin());
		// ��ʣ�µ�v[1~]����ѡm-1����
		auto ret_temp = Cnm(v, m - 1);
		for (auto it : ret_temp)
		{
			it.begin() = it.insert(it.begin(), first);
			ret.push_back(it);
		}
	}
	return ret;
}

int find(int reactorCap, int numberOfRadLiquid, int criticalMass, int volumes[], int masses[], int energies[])
{
	int maxEnergies = 0;

	std::vector<int> v = {};//ÿ��ƿ�ӱ��
	for (int i = 0; i < numberOfRadLiquid; i++)
		v.push_back(i + 1);

	cout << "ÿ��ƿ�ӱ��:";
	for (auto it : v)
	{
		cout << it << "  "; // 1  2  3  4  5
	}
	cout << endl;

	for (int i = numberOfRadLiquid; i >= 1; i--)
	{
		auto res = Cnm(v, i); // C55  C54  C53  C52  C51
		print_2D_Array(res);

		for (auto it : res) // it������������е�һ����ϡ�
		{
			int sum_volumes = 0;
			int sum_masses = 0;
			int sum_energies = 0;
			for (auto it2 : it)
			{ // ����ÿһ����ϣ����ѡ�����ϵ��ܺ͡�
				sum_volumes += volumes[it2 - 1];
				sum_masses += masses[it2 - 1];
				sum_energies += energies[it2 - 1];
			}
			// �����������ҵ�ǰ��ϵó���sum_energies > maxEnergies���͸���maxEnergies
			if (sum_volumes <= reactorCap && sum_masses <= criticalMass && sum_energies > maxEnergies)
			{
				maxEnergies = sum_energies;
			}
		}
	}
	return maxEnergies;
}

int main_���()
{
	int reactorCap = 100;//����50 
	int numberOfRadLiquid = 5;//����
	int criticalMass = 15;//�ٽ�����

	int volumes[5] = { 50, 40, 30, 20, 10 };//���
	int masses[5] = { 1, 2, 3, 9, 5 };//����
	int energies[5] = { 300, 480, 270, 200, 180 };//����

	int sum_energies = find(reactorCap, numberOfRadLiquid, criticalMass, volumes, masses, energies);

	cout << sum_energies << endl;
	return 0;
}