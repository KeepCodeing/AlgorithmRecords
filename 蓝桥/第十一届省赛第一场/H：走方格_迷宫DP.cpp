#include <iostream>
using namespace std;
const int N = 40;
bool graph[N][N];
int f[N][N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i % 2 == 0 && j % 2 == 0) graph[i][j] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// LeetCode上踩的坑w，起点可能为障碍，虽然这个题好像不会... 
			if (graph[i][j]) f[i][j] = 0;
			else if (i == 1 && j == 1) f[i][j] = 1;
			else if (i == 1 && j != 1) f[i][j] = f[i][j - 1];
			else if (i != 1 && j == 1) f[i][j] = f[i - 1][j];
			else f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	cout << f[n][m];
	return 0;
}
