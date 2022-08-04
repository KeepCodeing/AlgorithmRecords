#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 想到了个奇妙的做法，两次BFS，一次求洪水淹没全图的时间，一次求刺猬走到终点的时间
// 用刺猬的步数代表已经走的时间，如果已经走的时间超过了洪水的时间，就说明不能走了 
// 想了下或许一次BFS就行，先试试 

// 下一步的时间必须是严格大于当前时间的 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 60, INF = 1e9;
int r, c;
int sx, sy, ex, ey;
char graph[N][N];
int d1[N][N], d2[N][N];
bool visited[N][N];
PII que[N * N];
int qtop = 0, qback = -1;
int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs(int cw) {
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > r || nx < 1 || ny > c || ny < 1) continue;
			if (cw == 1) {
				if (d1[nx][ny] != -1) continue;
				d1[nx][ny] = d1[now.x][now.y] + 1;
			} else {
				if (d2[nx][ny] != -1) continue;
				d2[nx][ny] = d2[now.x][now.y] + 1;
			}
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	cin >> r >> c;
	memset(d1, -1, sizeof d1);
	memset(d2, -1, sizeof d2);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'S') sx = i, sy = j;
		 	else if (graph[i][j] == '*') que[++qback] = PII(i, j), d1[i][j] = 0;
			else if (graph[i][j] == 'D') ex = i, ey = j, d2[i][j] = 0;
			else if (graph[i][j] == 'X') d1[i][j] = -2, d2[i][j] = -2;
		}
	}
	//bfs(1, 1);
	bfs(1);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << d1[i][j] << ' ';
		}
		cout << endl;
	}
	puts("");
	qtop = qback = 0;
	que[qtop] = PII(ex, ey);
	bfs(2);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << d2[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
