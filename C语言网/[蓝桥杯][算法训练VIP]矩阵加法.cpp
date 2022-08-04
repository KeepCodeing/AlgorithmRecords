#include <iostream>
using namespace std;
const int N = 110;
int n1[N][N];
int main() {
	int n, m, t;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> n1[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> t;
			n1[i][j] += t;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << n1[i][j];
			if (j != n) cout << ' ';
		}
		if (i != n) cout << endl;
	}
	return 0;
}
