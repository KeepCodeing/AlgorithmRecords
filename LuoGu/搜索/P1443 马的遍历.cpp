#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// �����Ҳ����ĳ�㵽��ͼ�����е����̾��룬ֻ�������߷��ĳ�����߷���... 

// ������̣�����������Ԫ��...��һ˲ʧ��֢�����Ҹ����� 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 410;
int dist[N][N];
PII que[N * N];
int move[8][2] = {{2, 1},  {-2, 1}, {2, -1}, {-2, -1},  {-1, 2}, {1, 2}, {-1, -2}, {1, -2}};
int n, m, sx, sy;
void bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	dist[sx][sy] = 0;
	que[qtop] = PII(sx, sy);
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 8; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			// cout << nx << ' ' << ny << endl;
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[now.x][now.y] + 1;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	cin >> n >> m >> sx >> sy;
	memset(dist, -1, sizeof dist);
	bfs(sx, sy);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%-5d", dist[i][j]);
		}
		puts("");
	}
	return 0;
}
