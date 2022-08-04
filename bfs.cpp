#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
const int N = 100;
int n = 50, m = 50;
char graph[N][N];
int mv[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
bool vis[N][N];
struct Node {
	int x, y, val;	
	bool operator> (const Node a) const {
		return val > a.val;
	}
	Node(int valt, int xt, int yt): val(valt), x(xt), y(yt) {};
};
int bfs(int sx, int sy, int ex, int ey) {
	queue<Node > que;
	que.push(Node(0, sx, sy));
	while (que.size()) {
		Node now = que.front(); que.pop();
		if (now.x == ex && now.y == ey) return now.val;
		for (int i = 0; i < 8; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (vis[nx][ny]) continue;
			if (graph[nx][ny] == 'x') continue;
			vis[nx][ny] = true;
			que.push(Node(now.val + 1, nx, ny)); 
		}
	} 
}
int main() {
	int sx, sy, ex, ey;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 's') sx = i, sy = j;
			if (graph[i][j] == 'd') ex = i, ey = j;
		}
	}
	cout << bfs(sx, sy, ex, ey) << endl;
	return 0;
}
