#include <iostream>
#include <cstring>
using namespace std;

// 这种题似乎在洛谷上做过，不过不知道为什么洛谷上的错了...那么这个题就是先从火跑遍BFS，然后计算火蔓延到整个地图的时间
// 再从人跑遍BFS，判断下人能不能在火蔓延到地图上某点之前走过这个点...那么想下怎么判断人走没走出地图，应该可以记录下最后
// 一个点的坐标，如果在地图外就说明可以出去，那么这样的话应该可以写个判断，判断当前点是否出界，出界就说明可行，如果整个
// 地图都没有点出界就说明不可行...

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 1000 + 100;
int T, n, m, sx, sy;
char graph[N][N];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int qtop1 = 0, qback1 = 0;
int dist[N][N];
PII que1[N * N];
// 用来获取火蔓延到整个地图的时间的BFS，样例里似乎只有一个火，但是题目
// 没有说只有一个火，所以可能有很多火..
void bfs1() {
	while (qtop1 <= qback1) {
		PII now = que1[qtop1++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (dist[nx][ny] != -1 || graph[nx][ny] != '.') continue;
			dist[nx][ny] = dist[now.x][now.y] + 1;
			que1[++qback1] = PII(nx, ny);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
}
// 用来模拟人的行动
struct Node {
	int x, y, step;
	Node (int x, int y, int step) : x(x), y(y), step(step) {};
	Node () {};
} que[N * N];
bool visited[N][N];
int bfs2() {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, 0);
	while (qtop <= qback) {
		Node now = que[qtop++];
		// 这里判断是否能够走出去
		if (now.x <= 0 || now.x >= n - 1 || now.y <= 0 || now.y >= m - 1) return now.step;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 虽然假设可以走出去，但是数组下标还是得合法的
			if (visited[nx][ny] || graph[nx][ny] == '#') continue;
			if (now.step + 1 >= dist[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m) continue;
			visited[nx][ny] = true;
			que[++qback] = Node(nx, ny, now.step + 1);
		}
	}
	return -1;
}
int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m;
		// 初始化
		memset(dist, -1, sizeof dist);
		memset(visited, 0, sizeof visited);
		for (int i = 0; i < N; i++) {
			for (int j = 0 ; j < N; j++) graph[i][j] = 'e';
		}
		qtop1 = 0, qback1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[i][j];
				// 入队所有火
				if (graph[i][j] == 'F') que1[qback1++] = PII(i, j), dist[i][j] = 0;
				else if (graph[i][j] == 'J') sx = i, sy = j;
			}
		}
		bfs1();
		int res = bfs2();
		if (res == -1) cout << "IMPOSSIBLE";
		else cout << res;
		cout << endl;
	}
	return 0;
}
/*
1
4 5
####
#J#F
....
....
....
*/
