#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// BFS复习第二弹，这个题主要用来复习BFS求最短路以及输出最短路径，DFS可能不复习了，毕竟代码很简单w 

// 总结下错误：首先是终点的上一个点的设置错误，终点不存在上一个点，其次就是下一个点的上一个点的设置，其用了个PII把原来的PII
// 的点对取出来然后又转换成了PII，画蛇添足..，然后就是输出答案时的起点的设置，其设置成了终点，然而因为是反着遍历的所以应该
// 是从起点开始，这样还能保证输出顺序，再者就是输出时下一个点的设置，其也写的很奇怪，不过其实除了终点点的上一个点
// 设置和遍历时起点的设置有点问题以外其他基本没大问题，而是因为上面两个问题导致的死循环瞎改改成那样的... 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 120;
int n, m;
char graph[N][N];
PII que[N * N];
PII pre[N][N];
int mv[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	memset(pre, -1, sizeof pre);
	que[qtop] = PII(sx, sy);
	// 这里应该用一个不存在的点作为起点，因为终点的上一个点是不存在的 
	pre[sx][sy] = PII(0, 0);
	while (qtop <= qback) {
		PII now = que[qtop++];
		if (now.x == 1 && now.y == 1) return;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			// 这里忘了判断还有障碍的情况... 
			if (pre[nx][ny].x != -1 || graph[nx][ny] != '.') continue;
			// 这里不用PII(now.x, now.y)，直接赋值now就行 
			pre[nx][ny] = now;
//			cout << nx << ' ' << ny << endl;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m ;j++) {
			cin >> graph[i][j];
		}
	}
	bfs(n, m);
	PII end = PII(1, 1);
//	cout << pre[end.x][end.y].x << ' ' << pre[end.x][end.y].y << endl;
	while (true) {
		printf("%d %d\n", end.x, end.y);
		if (end.x == n && end.y == m) break;
		// 这里写的比较奇妙深刻，PII套PII... 
		end = pre[end.x][end.y];
//		end = PII(pre[nx][ny]);
	}
	return 0;
}
