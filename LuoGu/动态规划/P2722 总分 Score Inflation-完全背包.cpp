#include <iostream>
using namespace std;

// 同样是完全背包，套就完事了 
struct subject {
	int t, v;
	subject(int t1 = 0, int v1 = 0) {
		t = t1, v = v1;
	}
};
int f[10005];
int main() {
	int t, n;
	cin >> t >> n;
	subject *s = new subject[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> s[i].v >> s[i].t;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			if (j >= s[i].t) {
				f[j] = max(f[j], f[j - s[i].t] + s[i].v);
			}
		}
	}
	cout << f[t];
	delete[] s;
	return 0;
}
