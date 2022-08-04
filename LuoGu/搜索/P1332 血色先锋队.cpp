#include <iostream>
#include <cstring>
using namespace std;

// 又有点小问题，这个题是最短距离模型中的多源最短距离，注意点就是从为“1”的点开始遍历，其它
// 和普通BFS几乎没有区别 

#define x first
#define y second
const int N = 510;
typedef pair<int, int > PII;
int n, m, a, b;
// 用dist数组来记录各个1点到当前的距离 
int dist[N][N];
PII que[N * N];
int qtop = 0, qback = 0;
int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs() {
	// 普通BFS 
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (dist[nx][ny] != -1) continue;
			// 下一个点的距离就是上一个点的距离加+1 
			dist[nx][ny] = dist[now.x][now.y] + 1;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> a >> b;
	int x, y;
	// dist数组必须最先初始化，不然后面无法存距离还有判断是否访问 
	memset(dist, -1, sizeof dist);
	// 和普通BFS不一样的地方：要从“1”点遍历 
	while (a--) {
		// 入队 
		cin >> x >> y;
		// 小问题：这里写成了qtop++，想了下如果这样写bfs里的循环都不会执行 
		que[qback++] = PII(x, y);
		// 自己到自己的距离为0，另外通过dist数组将其标记为未访问 
		dist[x][y] = 0;
	}
	bfs();
	while (b--) {
		cin >> x >> y;
		// 最后输出最短距离就行 
		cout << dist[x][y] << endl;
	}
	return 0;
}
