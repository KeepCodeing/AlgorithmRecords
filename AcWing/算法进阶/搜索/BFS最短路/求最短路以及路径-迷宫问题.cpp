#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// ģ�廹�Ǻ�BFS�����·һ����ֻ��������Ѽ�¼�߹���������չ����pair��ͨ�����pair��¼����һ���ߵ�·��
// �������ܷ��Ƴ��ߵ��յ��·���� 
// �������ﻹ�������õ�����ĳ������˳�����Ȼ���γ���ѭ������������Ϊ��һ���㵽������㵫�������������ģ� 

#define x first 
#define y second 
typedef pair<int, int > PII;
const int N = 1010;
int graph[N][N];
int n;
PII pre[N][N], que[N * N];
int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs(int sx, int sy) {
	int hh = 0, tt = 0;
	que[0] = PII(sx, sy);
	// Ĭ����pre��x��������ʾ�������ʹ�û 
	// memset��Ȼ�ܸ���ֵ�Ƚϵ�һ�����ǲ�����fill��ֵ��ά��������ʧ�� 
	memset(pre, -1, sizeof pre);
	// �յ�֮��û��ֵ�ˣ�����Ϊ�˽�����Ϊ���ʹ������Ի���Ҫ��ֵ 
	pre[sx][sy] = PII(0, 0);
	while (hh <= tt) {
		PII now = que[hh++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			// ���Ϊǽ 
			if (graph[nx][ny]) continue;
			// ������Ԫ�ط��ʹ��� 
			if (pre[nx][ny].x != -1) continue;
			// ��һ�������һ��λ�þ���now 
			pre[nx][ny] = now;
			// hh�ǵ�ǰԪ���±꣬tt�Ƕ��������һ��Ԫ�ص��±꣬����Ҫ���Ԫ��Ӧ����++tt 
			que[++tt] = PII(nx, ny);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	// ��������ı���������������Ϊ��·���Ƿ������ģ����Կ�����Ҫ��һ�������������������
	// ����������Ǵ��յ㿪ʼ����������·���������ŵ��� 
	bfs(n, n);
	PII end(1, 1);
	while (true) {
		// �����λ�ô�0��ʼ�������±��1��ʼ����������Ҫ��ԭ��ȥ 
		printf("%d %d\n", end.x - 1, end.y - 1);
		if (end.x == n && end.y == n) break;
		end = pre[end.x][end.y];
	}
	return 0;
}
/*
5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

0 0
1 0
2 0
2 1
2 2
2 3
2 4
3 4
4 4
*/ 
