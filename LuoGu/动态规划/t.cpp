#include <iostream>
#include <algorithm>

int n, m, r;
const int kMaxN = 100, kMaxM = 100, kMaxR = 100; // ������ͷ�� k�����������淶 
int rmb[kMaxN + 5], rp[kMaxN + 5], time[kMaxN + 5];
int dpNum[kMaxM + 5][kMaxR + 5], dpTime[kMaxM + 5][kMaxR + 5]; // ���� dp 

int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> rmb[i] >> rp[i] >> time[i];
	std::cin >> m >> r;

	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= rmb[i]; --j) // С�ģ���Ҫ�� j �� m д�죬������ѭ�� 
			for (int k = r; k >= rp[i]; --k) {
				// ������ݵ��������� 
				if (dpNum[j][k] < dpNum[j - rmb[i]][k - rp[i]] + 1) {
					dpNum[j][k] = dpNum[j - rmb[i]][k - rp[i]] + 1; // ����++ 
					dpTime[j][k] = dpTime[j - rmb[i]][k - rp[i]] + time[i]; // ���ѵ�ʱ��ӽ�ȥ 
				}
				else if (dpNum[j][k] == dpNum[j - rmb[i]][k - rp[i]] + 1)
					// ������ݵ�ͬ��������ӣ�ѡ��ʱ�����ٵķ��� 
					dpTime[j][k] = std::min(dpTime[j][k], dpTime[j - rmb[i]][k - rp[i]] + time[i]);
			}
	
	// ����Ҫ�����ܷ��ݵ����ӣ���Ϊ����ݲ����������ֵһ��Ϊ 0 
	std::cout << dpTime[m][r] << std::endl;
}
