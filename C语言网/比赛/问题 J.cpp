#include <iostream>
using namespace std;
const int N = 110;
int graph[N][N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= 1; j--) {
			cout << graph[j][i];
			if (j != 1) cout << ' ';
		}
		if (i != m) cout << endl;
	}
	return 0;
}
