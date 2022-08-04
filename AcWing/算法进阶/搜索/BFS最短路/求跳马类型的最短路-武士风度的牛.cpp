#include <iostream>
using namespace std;

// �ͻ�����BFS���·����һ����������Ϊ��˵���׻�������������һֱ��û�����������⣬��Ҫ����Ծ�Ĳ���Ҫ�Լ�
// ��һ�飨���棩,������ƶ���Ŀռ��������������µ�һ���Ƴ����������ε��߷��������� 

const int N = 155;
// ���ǱȽ�ϰ����·�����ýṹ��棬�������Ƚ��鷳�����棩 
struct Node {
	int x, y, step;
	Node () {};
	Node (int x, int y, int step) : x(x), y(y), step(step) {};
};
int n, m;
char graph[N][N];
int sx, sy, ex, ey;
Node que[N * N];
// �����͵��߷���ֽ�ϻ�һ�¾����Ƴ��� 
int move[8][2] = {{1, 2}, {2, 1}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int bfs(int sx, int sy) {
	que[0] = Node(sx, sy, 0);
	int qtop = 0, qback = 0;
	// ���������ǵı����� 
	graph[sx][sy] = '*';
	while (qtop <= qback) {
		Node now = que[qtop++];
		// ��һ����������·�� 
		if (now.x == ex && now.y == ey) return now.step;
		// �߰˸����� 
		for (int i = 0; i < 8; i++) {
			int nx = move[i][0] + now.x, ny = move[i][1] + now.y;
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			// ��Ϊ���Ӱ��ϰ�������'.'���� 
			if (graph[nx][ny] == '*') continue;
			graph[nx][ny] = '*';
			que[++qback] = Node(nx, ny, now.step + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	// С�ӣ�������������������������
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
