#include <iostream>
using namespace std;
const int N = 110;
int v[N], w[N];
int f[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		for (int j = 1; j <= s; j++) cin >> v[j] >> w[j];
		// 和01背包不同的地方就是遍历顺序是反着的，先遍历
		// 背包容积，再遍历物品个数 
		// 虽然循环反过来了，但是状态还是不变的，所以没必要硬背 
		for (int j = m; j >= 0; j--) {
			for (int k = s; k >= 1; k--) {
				// 判断是当前价值最大还是减去物品容积，加上当前物品价值最大 
				if (j >= v[k])
				f[j] = max(f[j], f[j - v[k]] + w[k]);
			}
		}
	} 
	cout << f[m];
	return 0;
}
