#include <iostream>
using namespace std;
const int N = 15, M = 15;
int f[N][M];
int main() {
	int T;
	cin >> T;
	int n, m;
	f[0][0] = 1;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i <= n; i++) {
			for (int k = 1; k <= m; k++) {
				for (int j = i; j <= n; j++) {
					f[j][k] += f[j - i][k - 1];
				}	
			}
		}
		int res = 0;
		for (int i = 0; i <= n; i++) {
			res += f[m][i];
		}
		cout << res << endl;
	}
	
	return 0;
}
