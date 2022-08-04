#include <iostream>
using namespace std;

// 和基本的BFS最短路几乎一样，但是因为其说到底还是条懒狗所以一直都没有做过这种题，主要是跳跃的步数要自己
// 推一遍（迫真）,而且其贫弱的空间想象能力还导致第一次推出来个田字形的走法（绝望） 

const int N = 155;
// 还是比较习惯有路径数用结构体存，用数组存比较麻烦（迫真） 
struct Node {
	int x, y, step;
	Node () {};
	Node (int x, int y, int step) : x(x), y(y), step(step) {};
};
int n, m;
char graph[N][N];
int sx, sy, ex, ey;
Node que[N * N];
// 日字型的走法，纸上画一下就能推出来 
int move[8][2] = {{1, 2}, {2, 1}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int bfs(int sx, int sy) {
	que[0] = Node(sx, sy, 0);
	int qtop = 0, qback = 0;
	// 很容易忘记的标记起点 
	graph[sx][sy] = '*';
	while (qtop <= qback) {
		Node now = que[qtop++];
		// 第一个解就是最短路径 
		if (now.x == ex && now.y == ey) return now.step;
		// 走八个方向 
		for (int i = 0; i < 8; i++) {
			int nx = move[i][0] + now.x, ny = move[i][1] + now.y;
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			// 因为池沼把障碍当成了'.'，迷 
			if (graph[nx][ny] == '*') continue;
			graph[nx][ny] = '*';
			que[++qback] = Node(nx, ny, now.step + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	// 小坑：先输入的列数，再输入的行数
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'K') sx = i, sy = j;
			if (graph[i][j] == 'H') ex = i, ey = j;
		}
	}
	cout << bfs(sx, sy);
	return 0;
}
/*
10 11
..........
....*.....
..........
...*.*....
.......*..
..*..*...H
*.........
...*...*..
.K........
...*.....*
..*....*..

5
*/
