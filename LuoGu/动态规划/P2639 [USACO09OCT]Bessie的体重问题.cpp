#include <iostream>
using namespace std;

// 这个题好像也是个01背包问题，只不过它没有value这个选项了，但是根据题解里的解释，我们依然可以
// 给它加个“value”即将value设置为草的重量，不过这个题也有人说是装箱问题，暂且没搞

int f[50000]; 

struct elements {
	int w, v;
	elements(int w1 = 0, int v1 = 0) {
		w = w1, v = v1;
	}
};

int main() {
	int w, n;
	cin >> w >> n;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].w;
		// 将其价值设置为重量，这样就能套用01背包模板了
		e[i].v = e[i].w; 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = w; j >= 0; j--) {
			if (j >= e[i].w) {
				f[j] = max(f[j], f[j - e[i].w] + e[i].v);
			}
		}
	}
	cout << f[w];
	delete[] e;
	return 0;
}
