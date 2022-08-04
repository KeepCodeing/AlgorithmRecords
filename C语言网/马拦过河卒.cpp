#include <iostream>
using namespace std;
typedef long long LL;
const int N = 20;
bool graph[N][N];
int mv[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
int ex, ey, hx, hy;
LL f[N][N];
void cpl(int hx, int hy) {
	int nx, ny;
	graph[hx][hy] = true;
	for (int i = 0; i < 8; i++) {
		nx = hx + mv[i][0], ny = hy + mv[i][1];
		if (nx > ex || nx < 0 || ny > ey || ny < 0) continue;
		graph[nx][ny] = true;
	}
}
int main() {
	cin >> ex >> ey >> hx >> hy;
	cpl(hx, hy);
	for (int i = 0; i <= ex; i++) {
		for (int j = 0; j <= ey; j++) {
			// 惯例的先判断障碍，然后判断走法... 
			if (graph[i][j]) f[i][j] = 0;
			else if (i == 0 && j == 0) f[i][j] = 1;
			else if (i == 0) f[i][j] = f[i][j - 1];
			else if (j == 0) f[i][j] = f[i - 1][j];
			else f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	cout << f[ex][ey];
	return 0;
}
