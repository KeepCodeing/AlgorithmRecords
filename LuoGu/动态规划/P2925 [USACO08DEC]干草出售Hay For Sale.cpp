#include <iostream>
using namespace std;

// 这看起来也是一道01背包题，但是没有价值，所以我们要手动指定价值

struct elements {
	int w, v;
	// 写太多忘了给初始值，结果报错了 
	elements(int w1 = 0, int v1 = 0) {
		w = w1, v = v1;
	}
};
int f[50001];
int main() {
	int m, n;
	cin >> m >> n;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].w;
		// 手动指定价值 
		e[i].v = e[i].w;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 0; j--) {
			if (j >= e[i].w) {
				f[j] = max(f[j], f[j - e[i].w] + e[i].v);
			}
		}
	}
	cout << f[m];
	delete[] e;
	return 0;
}
