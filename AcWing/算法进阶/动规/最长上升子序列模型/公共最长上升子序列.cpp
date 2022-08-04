#include <iostream>
#define endl '\n'
using namespace std; 

const int N = 300 + 10;
int t1[N], t2[N], f[N][N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> t1[i];
	for (int i = 1; i <= m; i++) cin >> t2[i];
	
	// 求最长公共子序列 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (t1[i] == t2[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}
