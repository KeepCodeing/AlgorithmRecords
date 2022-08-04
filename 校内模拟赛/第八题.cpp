#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1010;
typedef pair<int, int > PII;
char graph[N][N];
int n, m;
vector<PII > vec;
bool check(int x, int y) {
	return (x < 1 || x > n || y < 1 || y > m);
}
int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	int k;
	scanf("%d", &k);
	for (int o = 1; o <= k; o++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (graph[i][j] == 'g') {
					for (int f = 0; f < 4; f++) {
						int nx = i + move[f][0], ny = j + move[f][1];
						if (check(nx, ny)) continue;
						// graph[nx][ny] = 'g';
						vec.push_back(PII(nx, ny));
					}
				}
			}
		}
//		for (int i = 1; i <= n; i++) {
//			printf("%s", graph[i]);
//			if (i != n) puts("");
//		}
//		cout << endl << "------" << endl;
		for (int u = 0; u < vec.size(); u++) graph[vec[u].first][vec[u].second] = 'g';
		vec.clear();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << graph[i][j];
		}
		if (i != n) cout << endl;
	}
//	for (int i = 1; i <= n; i++) {
//		printf("%s", graph[i]);
//		if (i != n) puts("");
//	}
	return 0;
}
