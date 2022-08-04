#include <iostream>
#include <cstring>
using namespace std;

// 题目没说要最短路径，而且答案不唯一，但是要输出走过的路径
// 那么最好用BFS，这样可以方便的退出和输出路径 

// 谔谔，出现了两个问题 

#define x first
#define y second
const int N = 150, M = N * N;
typedef pair<int, int > PII;
char graph[N][N];
PII pre[N][N], que[M];
int r, c;
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = PII(sx, sy);
	pre[sx][sy] = PII(0, 0);
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > r || nx < 1 || ny > c || ny < 1) continue;
			if (pre[nx][ny].x != -1) continue;
			if (graph[nx][ny] != '.') continue;
			pre[nx][ny] = now;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> graph[i][j];
		}
	}
	memset(pre, -1, sizeof pre);
	// 问题2：没有倒着搜，一开始是正着搜的... 
	bfs(r, c);
	// 问题1：起点设置错误，之前写的(0, 0)，导致死循环，这或许是因为教程里起点从0开始所导致的错误印象
	// (0, 0)没有pre点  
	PII end(1, 1);
	while (true) {
		cout << end.x << ' ' << end.y << endl;
		if (end.x == r && end.y == c) break;
		end = pre[end.x][end.y];
	}
	return 0;
}
