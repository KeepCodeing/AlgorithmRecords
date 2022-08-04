#include <iostream>
#define endl '\n'
using namespace std;
const int N = 5000 + 10;
int f[N][N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) f[i][j] = 1;
			else if (i == 0) f[i][j] = f[i][j - 1];
			else if (j == 0) f[i][j] = f[i - 1][j];
			else f[i][j] = (f[i - 1][j] + f[i][j - 1]) % 64513624;
		}
	}
	cout << f[n - 1][m - 1];
	return 0;
}
