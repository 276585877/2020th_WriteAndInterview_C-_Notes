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

/***************************************
����˼·������һ������������������0-1�������⣬
����ֻ�轫һ�����������Ķ�ά��̬�滮����һ����ά��̬�滮��
***************************************/
static int maxEnergyGenerate(int reactorCap, int numberOfRadLiquid, int criticalMass, int volumes[], int masses[], int energies[])
{
	vector<vector<vector<int>>> maxValue(numberOfRadLiquid + 1, vector<vector<int>>(reactorCap + 1, vector<int>(criticalMass + 1, 0)));
	
	for (int i = 1; i <= numberOfRadLiquid; i++)
	{
		for (int j = 1; j <= reactorCap; j++)
		{
			for (int k = 1; k <= criticalMass; k++)
			{
				if (i == 1)
				{
					maxValue[i][j][k] = (((volumes[i - 1] <= j) && (masses[i - 1] <= k)) == true ? energies[i - 1] : 0);
				}
				else
				{
					int topValue = maxValue[i - 1][j][k];  // ��һ�������ֵ
					// ��ǰ��Ʒ�ļ�ֵ + ʣ��ռ�ļ�ֵ
					int thisValue = 0;
					if ((volumes[i - 1] <= j) && (masses[i - 1] <= k))
					{
						thisValue = energies[i - 1] + maxValue[i - 1][j - volumes[i - 1]][k - masses[i - 1]];
					}
					else
					{
						thisValue = topValue;
					}
					maxValue[i][j][k] = (topValue > thisValue ? topValue : thisValue);
				}
			}
		}
	}

	vector<bool> result(numberOfRadLiquid, false);
	for (int i = numberOfRadLiquid, j = reactorCap, k = criticalMass; i > 0; i--)
	{
		if (maxValue[i][j][k] > maxValue[i - 1][j][k])
		{
			result[i - 1] = true;
			j = j - volumes[i - 1];
			k = k - masses[i - 1];
		}
	}
	int sum = 0;
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i])
		{
			sum += energies[i];
		}
	}
	return sum;
}


int main_�ѱ䷴Ӧ��_����() // main_�ѱ䷴Ӧ��_����
{
	int reactorCap = 100;//����50 
	int numberOfRadLiquid = 5;//����
	int criticalMass = 15;//�ٽ�����

	int volumes[5] = { 50, 40, 30, 20, 10 };//���
	int masses[5] = { 1, 2, 3, 9, 5 };//����
	int energies[5] = { 300, 480, 270, 200, 180 };//����

	int sum_energies = maxEnergyGenerate(reactorCap, numberOfRadLiquid, criticalMass, volumes, masses, energies);

	cout << sum_energies << endl;
	return 0;
}