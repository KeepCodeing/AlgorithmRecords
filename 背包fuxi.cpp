#include <iostream>
using namespace std;
const int N = 1010, M = 110;
int a[M], b[M], c[M];
int f[N][N];
int main() {
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= b[i]; j--) {
			for (int k = x; k >= c[i]; k--) {
				f[j][k] = max(f[j][k], f[j - b[i]][k - c[i]] + a[i]);
			}
		}
	}
	cout << f[m][x];
	return 0;
}
