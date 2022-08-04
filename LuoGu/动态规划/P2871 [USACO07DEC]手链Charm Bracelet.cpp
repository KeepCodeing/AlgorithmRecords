#include <iostream>
using namespace std;

// 这个好像就是最基本的01背包，用一维数组优化版写下 

struct elements {
	int w, v;
	elements(int w1 = 0, int v1 = 0) {
		w = w1, v = v1;
	}
};
int f[50000];
int main() {
	int n, v;
	cin >> n >> v;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].w >> e[i].v;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= 0; j--) {
			if (j >= e[i].w) {
				// 这里之前写成了f[i-1]，这是二维数组未优化的写法...
				// 一维数组优化写法只关心当前能否获得最优解 
				f[j] = max(f[j], f[j - e[i].w] + e[i].v);
			}
		}
	}
	// 一维数组优化版的最优解由背包体积决定 
	cout << f[v];
	delete[] e;
	return 0;
}
