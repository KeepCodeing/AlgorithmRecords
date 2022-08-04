#include <iostream>
using namespace std;

// 不知道是不是完全背包，先写写，感觉也可以贪心解 
// 看起来不是完全背包，其实其写的时候也感觉这个题
// 和背包不一样，背包要求的是能装最多的价值的物品，
// 这个题要求的是最小消耗 

struct elements {
	int w, m;
	elements(int w1 = 0, int m1 = 0) {
		w = w1, m = m1;
	}
};
elements *e;
int f[50001];
int main() {
	int n, h;
	cin >> n >> h;
	e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].w >> e[i].m;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= e[i].w; j++) {
			f[j] = max(f[j], f[j - e[i].w] + e[i].m);
		}
	}
	cout << f[n];
	return 0;
}
