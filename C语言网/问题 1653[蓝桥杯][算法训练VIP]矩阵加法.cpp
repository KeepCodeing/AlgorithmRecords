#include <iostream>
using namespace std;
int m[110][110][110];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				int t;
				cin >> t;
				//cin >> m[i][j][k];
				m[1][j][k] = t;
			}
		}
	}
	return 0;
}
