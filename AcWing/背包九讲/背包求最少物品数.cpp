#include <iostream>
using namespace std;

// 看来背包问题除了可以用来求最优解和方案数，也可以用来求最少物品数... 
// 这种背包和普通背包差不多，只不过物品价值变成了1，而且还要注意下两个初始化情况.. 

const int N = 1e5 + 10;
int money[N];
int f[N];
int main() {
	int n, v;
	cin >> n;
	// 输入物品花费和物品数量 
	for (int i = 0; i < n; i++) cin >> money[i];
	// 输入背包容积 
	cin >> v;
	for (int i = 0; i < n; i++) {
		for (int j = money[i]; j <= v; j++) {
			// 初始化和普通背包不太相同
			// 每个硬币自身一定有一种组成方案 
			if (j == money[i]) {
				f[j] = 1;
				// 如果当前硬币还没有组成方案，则它的组成方案就是上一个硬币的组成方案+1 
			} else if (f[i] == 0 && f[j - money[i]] != 0) {
				f[j] = f[j - money[i]] + 1;
			} else if (f[j - money[i]] != 0) {
				// 如果有了组成方案，则对比是选的方案花费最小还是不选的花费最小..这里和普通背包差不多 
				f[j] = min(f[j], f[j - money[i]] + 1);
			}
		}
	}
	if (f[v] == 0) cout << -1;
	else cout << f[v];
	return 0;
}
/*
3
1 2 5
11
*/
