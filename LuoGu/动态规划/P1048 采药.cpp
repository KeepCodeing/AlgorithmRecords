#include <iostream>
using namespace std;

// 01背包，不多谈 
struct cao {
	int t, v;
	cao(int t1 = 0, int v1 = 0) {
		t = t1, v = v1;
	}
};
int f[1005];
int main() {
	int t, n;
	cin >> t >> n;
	cao *c = new cao[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> c[i].t >> c[i].v;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = t; j >= c[i].t; j--) {
			f[j] = max(f[j], f[j - c[i].t] + c[i].v);
		}
	}
	cout << f[t];
	delete[] c;
	return 0;
}
