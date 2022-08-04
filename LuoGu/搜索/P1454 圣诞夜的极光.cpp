#include <iostream>
#include <cstdio>
using namespace std;

// 漫水填充，题目说是曼哈顿距离，但是实际上就是两个点相邻（虚心） ，通过样例
// 可以看出来有八个方向可走，这里用BFS实现，虽然DFS也行 

// 不是这样哦，还是得按题目来 

// BFS版壮烈成仁了ww 

// 推了下，所谓的曼哈顿距离就是在原有的八个方向上加了四个方向，也就是上下左右这四个方向，在曼哈顿距离里
// 这四个方向可以多走一次

// 并查集其实也可以做连通块计数的题，但是其一直不是很理解（无能），所有这种题还是用BFS或DFS来好了 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 110;
char graph[N][N];
PII que[N * N];
int n, m;
int move[12][2] = {
{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1},
{2, 0}, {-2, 0}, {0, 2}, {0, -2}
};
void bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	graph[sx][sy] = '-';
	que[qtop] = PII(sx, sy);
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 12; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (graph[nx][ny] != '#') continue;
			graph[nx][ny] = '-';
			que[++qback] = PII(nx, ny);
		}
	}	
}
int main() {
	cin >> n >> m;
	// 用gets加快读入，用gets数组下标就尽量统一从0开始，因为
	// 行标可以自己设置，但是列表只能从0开始 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == '#') {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
