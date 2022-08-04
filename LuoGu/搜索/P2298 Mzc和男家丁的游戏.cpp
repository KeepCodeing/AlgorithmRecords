#include <iostream>
#include <queue>
using namespace std;
const int N = 2020;
char graph[N][N];
int n, m;
int x1, y1, x2, y2;
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct Node {
	int x, y, step;
	Node () {};
	Node (int x, int y, int step) : x(x), y(y), step(step) {};
};
int bfs() {
	queue<Node > que;
	que.push(Node(x1, y1, 0));
	Node now;
	while (!que.empty()) {
		now = que.front();que.pop();
		if (now.x == x2 && now.y == y2) return now.step;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			// 看起来还是不能只写个!='.'，因为终点也不是'.'... 
			if (graph[nx][ny] == '#') continue;
			graph[nx][ny] = '#';
			que.push(Node(nx, ny, now.step + 1)); 
		}
	} 
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'm') x1 = i, y1 = j;
			if (graph[i][j] == 'd') x2 = i, y2 =j;
		}
	}
	int ans = bfs();
	if (ans != -1) cout << ans;
	else cout << "No Way!";
	return 0;
}
