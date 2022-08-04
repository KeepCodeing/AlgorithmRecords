#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS，但是应该要注意下空间占用问题，还有棋盘对应位置 

struct Node {
	int x, y;
	int cnt;
	string path;
	Node (int x, int y, string path, int cnt) : x(x), y(y), path(path), cnt(cnt) {};
	Node () {};
};
int move[8][2] = {
	{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};
bool visited[10][10];
int sx, sy, ex, ey;
string getPath(int x, int y) {
	// x == 1 -> D, y == 1 -> R, x == -1 -> U, y == -1 -> L
	string str;
	// 注意这里其x轴的起始位置，向左走在普通x轴上是减，但是在这里要改成加 
	// 另外样例给出的似乎是x优先算方向，不过反着来比较难以理解... 
	if (y == 1) {
		str += 'L';
	} else if (y == -1) {
		str += 'R';
	}
	if (x == 1) {
		str += 'D';
	} else if (x == -1) {
		str += 'U';
	}
	return str;
}
void bfs() {
	queue<Node > que;
	que.push((Node){sx, sy, "", 0});
	while (!que.empty()) {
		Node now = que.front();que.pop();
		if (now.x == ex && now.y == ey) {
			cout << now.cnt << endl;
			for (int i = 0; i < now.path.size(); i++) {
				if (now.path[i] != '.') cout << now.path[i];
				else cout << endl; 
			}
		}
		for (int i = 0; i < 8; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			que.push((Node){nx, ny, now.path + getPath(move[i][0], move[i][1]) + '.', now.cnt + 1});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	string t;
	cin >> t;
	sx = t[0] - 'a', sy = t[1] - '0' - 1;
	cin >> t;
	ex = t[0] - 'a', ey = t[1] - '0' - 1;
	// x是7，y是0，其是反着来的 
	bfs();
	return 0;
}
