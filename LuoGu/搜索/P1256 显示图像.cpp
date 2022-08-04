#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// ͻȻ��������Ǹ�BFS��Դ�����棩���·��ģ���⣬���������������ռ����ģ��о�����������ԭ���... 
// �Ƚ������һ���������òݻ᳤����ͼ...�����¾ͺ�... 
// ������������A��...��Ȼ��д�����ʱ��ûAC��flag������΢�棩 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 200;
int dist[N][N];
PII que[N * N];
int qtop = 0, qback = -1;
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;
void bfs() {
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[now.x][now.y] + 1;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	memset(dist, -1, sizeof dist);
	int x;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &x);
			if (x) dist[i][j] = 0, que[++qback] = PII(i, j);
		}
	} 
	bfs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d", dist[i][j]);
			if (j != m) printf(" ");
		}
		puts("");
	}
	return 0;
}
