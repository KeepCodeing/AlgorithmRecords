#include <iostream>
using namespace std;

// 一眼前缀和，不过这里要判断下类型才能进行累加 

const int N = 1e5 + 10;
int a[N], b[N], c[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	int x;
	a[0] = b[0] = c[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = a[i - 1], b[i] = b[i - 1], c[i] = c[i - 1];
		if (x == 1) a[i] += 1;
		else if (x == 2) b[i] += 1;
		else c[i] += 1;
	} 
	int l, r;
	while (q--) {
		cin >> l >> r;
		// 注意l要-1，因为第一个前缀和的下标是从0开始的 
		l -= 1;
		// 前缀和 
		cout << a[r] - a[l] << ' ' << b[r] - b[l] << ' ' << c[r] - c[l] << endl;
	}
	return 0;
}
