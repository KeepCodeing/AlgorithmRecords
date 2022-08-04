#include <iostream>
using namespace std;

// 似乎最基本的数字三角形dp都忘了，不妙... 

const int N = 25;
int graph[N][N];
long long f[N][N];
int mv[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
int main() {
	int n, m, mx, my;
	cin >> n >> m >> my >> mx;
	graph[mx][my] = 1;	
	int nx, ny;
	for (int i = 0; i < 8; i++) {
		nx = mx + mv[i][0], ny = my + mv[i][1];
		if (nx > n || nx < 0 || ny > m || ny < 0) continue;
		graph[nx][ny] = 1;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (graph[i][j]) f[i][j] = 0;
			else {
				if (i == 0 && j == 0) f[i][j] = 1;
				else {
					f[i][j] = 0;
					if (i - 1 >= 0) f[i][j] += f[i - 1][j];
					if (j - 1 >= 0) f[i][j] += f[i][j - 1];
				}
			}
		}
	}
	cout << f[n][m];
	return 0;
}
