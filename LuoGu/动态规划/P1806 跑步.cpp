#include <iostream>
using namespace std;

// 突然发现这是个01背包求方案数... 
// 把要跑的距离n看做是背包容积，每次可以跑的距离i看做物品代价，因为每次跑的距离只能比上一次的距离大（递增）
// 所以i其实是只能选一次的，由此可以推出这是个01背包... 

// 不开long long见祖宗 
typedef long long LL;
const int N = 510;
LL f[N];
int main() {
	int n;
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			// 01背包求方案数的状态转移方程 
			f[j] += f[j - i];
		}
	}
	cout << f[n] - 1;
	return 0;
} 
