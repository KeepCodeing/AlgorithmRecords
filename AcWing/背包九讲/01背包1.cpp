#include <iostream>
using namespace std;

// 首先考虑01背包的二维状态解法：01背包一共有两个状态，物品价值和物品重量
// 设f[i][j]表示只看第i个物品，总体积为j时的总价值最大是多少

// result = max(f[n][0~v]即所有物品都选完能达到的最大价值

// 1. 不选第i个物品： f[i][j] = f[i - 1][j]，即不选第i个物品能获得的最大总价值就是前一个物品的最大总价值
// 2. 选第i个物品:f[i][j] = f[i - 1][j - v[i]] + w[i]，即选第i个物品能获得的最大价值就是背包体积减去物品
// 重量加上能获得的收入

// 最终的结果就是max{1. 2.} 

const int N = 1010;
int val[N], wei[N];
int f[N][N];
int main() {
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++) cin >> val[i] >> wei[i];
	for (int i = 1; i <= n; i++) {
		// 有多少钱花多少钱 
		for (int j = val[i]; j <= v; j++) f[i][j] = max(f[i - 1][j], f[i - 1][j - val[i]] + wei[i]);
	}
	int res = -1;
	// 对比那种选法价值最大 
	for (int i = 0; i <= v; i++) res = max(f[n][i], res);
	cout << res;
	return 0;
}
