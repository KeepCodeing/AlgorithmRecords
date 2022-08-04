#include <iostream>
using namespace std;

// 同样是01背包问题（不是这样哦）

// 这是一道完全背包题，因为可以重复选取，运行了测试数据才发现...（暂且没有背模板2020.2.7 23:33） 

int f[50000];

struct elements {
	int t, v;
	elements(int t1 = 0, int v1 = 0) {
		t = t1, v = v1;
	}
};

int main() {
	int m, n;
	cin >> m >> n;
	// 题目的特判 
	if (n == 0) {
		cout << 0;
		return 0;
	}
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].v >> e[i].t;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 0; j--) {
			if (j >= e[i].t) {
				f[j] = max(f[j], f[j - e[i].t] + e[i].v);
			}
		}
	}
	cout << f[m];
	delete[] e;
	return 0;
}
