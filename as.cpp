#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#define endl '\n'
#define x first
#define y second
using namespace std;
typedef pair<int, int > PII;
const int N = 55;
char graph[N][N], res[N][N];
int n = 50, m = 50;
struct Node {
	int val, x, y;
	Node (int vt, int xt, int yt): val(vt), x(xt), y(yt) {};
	
	bool operator> (const Node& a) const {
		return val > a.val;
	}
};
map<PII, int > dist;
map<PII, PII > path;
int mv[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
bool judge(int x, int y, int nx, int ny) {
	if (nx < 1 || nx > n || ny < 1 || ny > m) return false;
	if (graph[nx][ny] == 'x') return false;
	return !dist.count(PII(nx, ny)) || dist[PII(nx, ny)] > dist[PII(x, y)] + 1;
}
int mhd(int nx, int ny, int ex, int ey) {
	return abs(nx - ex) + abs(ny - ey);
}
int astar(int sx, int sy, int ex, int ey) {
	priority_queue<Node, vector<Node >, greater<Node > > que;
	que.push(Node(0, sx, sy));
	dist[PII(sx, sy)] = 0;
	while (que.size()) {
		Node now = que.top(); que.pop();
		if (now.x == ex && now.y == ey) {
			PII st = PII(sx, sy), ed = PII(ex, ey);
			int tot = 0;
			while (st != ed) {
				res[ed.x][ed.y] = '*';
				ed = path[ed];
				tot++;
			}
			return tot;
		}
		for (int i = 0; i < 8; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (judge(now.x, now.y, nx, ny)) {
				int c = dist[PII(now.x, now.y)] + 1;
				dist[PII(nx, ny)] = c;
				path[PII(nx, ny)] = PII(now.x, now.y); 
				que.push(Node(mhd(nx, ny, ex, ey) + c, nx, ny)); 
			}	
		}
	} 
	return -114;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int sx, sy, ex, ey;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			res[i][j] = graph[i][j];
			if (graph[i][j] == 's') sx = i, sy = j;
			if (graph[i][j] == 'd') ex = i, ey = j;
		}
	}
	cout << astar(sx, sy, ex, ey) << endl;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << res[i][j];
		}
		cout << endl;
	}
	return 0;
}
