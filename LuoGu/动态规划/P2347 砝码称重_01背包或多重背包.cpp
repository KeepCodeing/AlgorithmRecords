#include <iostream>
#include <vector>
using namespace std;

// 裸题，物品数量：6个砝码，背包容积：砝码重量之和，物品价值：砝码重量，这里一个砝码可能有很多个，那么可以转换成多重背包做，
// 当然数据范围很小直接搞成01背包也是可以的... 

typedef pair<int, int > PII;
typedef long long LL;
const int N = 10, M = 1000 + 10;
int wei[N] = {1, 2, 3, 5, 10, 20};
int num, m = 0;
vector<PII > ele;
int f[M];
int main() {
	for (int i = 0; i < 6; i++) {
		cin >> num;
		// 背包容积等于砝码重量之和，这里num是有多少个砝码 
		m += num * wei[i];
		// 倍增优化 
		for (int k = 1; k <= num; k <<= 1) {
			// 重量和价值相等
			ele.push_back(PII(k * wei[i], k * wei[i])); 
			num -= k;
		}
		if (num > 0) ele.push_back(PII(num * wei[i], num * wei[i]));
	}
	int vLen = ele.size();
	f[0] = 1;
	for (int i = 0; i < vLen; i++) {
		for (int j = m; j >= ele[i].first; j--) {
			f[j] += f[j - ele[i].second];
		}
	}
	int res = 0;
	for (int i = 1; i <= m; i++) res += f[i];
	cout << "Total=" << res;
	return 0; 
}
