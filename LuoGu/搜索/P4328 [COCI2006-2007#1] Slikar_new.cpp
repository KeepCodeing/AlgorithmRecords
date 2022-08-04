#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// �뵽�˸����������������BFS��һ�����ˮ��ûȫͼ��ʱ�䣬һ�������ߵ��յ��ʱ��
// �ô�⬵Ĳ��������Ѿ��ߵ�ʱ�䣬����Ѿ��ߵ�ʱ�䳬���˺�ˮ��ʱ�䣬��˵���������� 
// �����»���һ��BFS���У������� 

// ��һ����ʱ��������ϸ���ڵ�ǰʱ��� 

#define x first
#define y second
typedef pair<int, int > PII;
struct pos {
	int x, y, step;
	pos(int x, int y, int step) : x(x), y(y), step(step) {};
	pos () {};
};
const int N = 60;
int r, c;
int sx, sy, ex, ey;
char graph[N][N];
int d1[N][N];
PII que[N * N];
pos que2[N * N];
int qtop = 0, qback = -1;
int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs() {
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > r || nx < 1 || ny > c || ny < 1) continue;
			if (d1[nx][ny] != -1) continue;
			d1[nx][ny] = d1[now.x][now.y] + 1;
			que[++qback] = PII(nx, ny);
		}
	}
}
int ans = 0x3fffffff;
void bfs2(int sx, int sy) {
	int q2top = 0, q2back = 0;
	que2[q2top] = pos(sx, sy, 1);
	graph[sx][sy] = '*';
	while (q2top <= q2back) {
		pos now = que2[q2top++];
		if (now.x == ex && now.y == ey) {
			// return now.step;
			ans = min(ans, now.step);
		}
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > r || nx < 1 || ny > c || ny < 1) continue;
			if (graph[nx][ny] == '*' || graph[nx][ny] == 'X') continue;
			if (now.step >= d1[nx][ny]) continue;
			graph[nx][ny] = '*';
			que2[++q2back] = pos(nx, ny, now.step + 1);
		}
	}
	// return -2;
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	cin >> r >> c;
	memset(d1, -1, sizeof d1);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'S') sx = i, sy = j;
		 	else if (graph[i][j] == '*') que[++qback] = PII(i, j), d1[i][j] = 0;
			else if (graph[i][j] == 'D') ex = i, ey = j, d1[i][j] = 1e9;
			else if (graph[i][j] == 'X') d1[i][j] = 0;
		}
	}
	bfs();
	bfs2(sx, sy);
	if (ans != 0x3fffffff) cout << ans - 1;
	else cout << "KAKTUS";
//	cout << endl;
//	for (int i = 1; i <= r; i++) {
//		for (int j = 1; j <= c; j++) {
//			cout << d1[i][j] << ' ';
//		}
//		cout << endl;
//	}
	return 0;
}
