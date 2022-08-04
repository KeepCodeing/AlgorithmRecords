#include <iostream>
using namespace std;

// 也是01背包，但是没有价值这个项，而且之前写的似乎有点小bug 

struct elements {
	int w, v;
	elements(int w1 = 0, int v1 = 0) {
		w = w1, v = v1;
	}
};
int f[50000];
int main() {
	int s, n;
	cin >> s >> n;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].w;
		e[i].v = e[i].w;
	}
	for (int i = 1; i <= n; i++) {
		// bug就是这里，j>=0会导致一个物品重复添加，不过其暂且没有碰到过 
		for (int j = s; j >= e[i].w; j--) {
			if (j >= e[i].w) {
				f[j] = max(f[j], f[j - e[i].w] + e[i].v);
			}
		}
	}
	// 要求输出剩余空间 
	cout << s - f[s];
	delete[] e;
	return 0;
}
