#include <iostream>
using namespace std;

// 从刚开始学算法到现在都没有AC的题w...
// 简单来说就是个迷宫类型的DP，要开long long，然后注意各种走法.. 
// 状态定义:f[i][j]表示(i, j)这个点的走法，当i == 0时，也就是当前这个点在第一行，那么这个点的状态只能从前一个列转移
// 过来，而不是直接简单的认为在这一行的点只有一种从左边走过来的走法，这样很显然没有考虑到如果前一列被拦住了怎么办...
// 同理，j == 0也是如此，然后注意下初始条件，(0, 0)这个点只有一种走法，其它除了行和列上的点都有两种走法，即从i - 1处
// 走下来，和从j - 1处走过来，这两种走法的和就是(i, j)这个点的走法和了... 

typedef long long LL;
const int N = 25;
bool graph[N][N];
LL f[N][N];
int mv[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
int ex, ey, hx, hy;
void cpl(int hx, int hy) {
	int nx, ny;
	graph[hx][hy] = true;
	// 马的位置应该不算障碍，这符合象棋规则 
	for (int i = 0; i < 8; i++) {
		nx = hx + mv[i][0], ny = hy + mv[i][1];
		if (nx > ex || nx < 0 || ny > ey || ny < 0) continue;
		graph[nx][ny] = true;
	}
}
int main() {
	// 注意起点是(0, 0)，终点是(ex, ey) 
	cin >> ex >> ey >> hx >> hy;
	cpl(hx, hy);
	f[0][0] = 1;
	for (int i = 0; i <= ex; i++) {
		for (int j = 0; j <= ey; j++) {
			// 如果是障碍，就没有走法 
			if (graph[i][j]) f[i][j] = 0;
			// 如果在行上或者在列上，当前点的走法就只能和上一个点相同（上一个点能走1步，这个点也只能走一步，上一个点走不了
			// 这个点及其以后的点都走不了） 
			else if (i == 0 || j == 0) {
				if (i == 0 && j != 0) f[i][j] = f[i][j - 1];
				else if (j == 0 && i != 0) f[i][j] = f[i - 1][j];
			}
			// 不是行列上的点就有两种走法，从上走过来，或者从左走过来... 
			else f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	cout << f[ex][ey];
	return 0;
}
/*
for (int i = 0; i <= ex; i++) {
	for (int j = 0; j <= ey; j++) {
		cout << graph[i][j] << ' ';
	}
	cout << endl;
}
*/
