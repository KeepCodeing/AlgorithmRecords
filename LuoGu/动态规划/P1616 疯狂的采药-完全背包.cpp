#include <iostream>
using namespace std;

// 完全背包似乎也是套01背包模板，只不过把倒序遍历改成了顺序遍历 

struct elements {
	int t, v;
	elements(int t1 = 0, int v1 = 0) {
		t = t1, v = v1;
	}
};
// 解空间设置太小，RE了 
// T的范围有 100000...

// 看来设置解空间的根据是背包容积，因为最优解
// 是第T个元素.. 
int f[100005];
int main() {
	int t, n;
	cin >> t >> n;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].t >> e[i].v;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			if (j >= e[i].t) {
				f[j] = max(f[j], f[j - e[i].t] + e[i].v);
			}
		}
	}
	cout << f[t];
	delete[] e;
	return 0;
}
