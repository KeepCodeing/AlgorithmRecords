#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// BFS��ϰ�ڶ������������Ҫ������ϰBFS�����·�Լ�������·����DFS���ܲ���ϰ�ˣ��Ͼ�����ܼ�w 

// �ܽ��´����������յ����һ��������ô����յ㲻������һ���㣬��ξ�����һ�������һ��������ã������˸�PII��ԭ����PII
// �ĵ��ȡ����Ȼ����ת������PII����������..��Ȼ����������ʱ���������ã������ó����յ㣬Ȼ����Ϊ�Ƿ��ű���������Ӧ��
// �Ǵ���㿪ʼ���������ܱ�֤���˳�����߾������ʱ��һ��������ã���Ҳд�ĺ���֣�������ʵ�����յ�����һ����
// ���úͱ���ʱ���������е�����������������û�����⣬������Ϊ�����������⵼�µ���ѭ��Ϲ�ĸĳ�������... 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 120;
int n, m;
char graph[N][N];
PII que[N * N];
PII pre[N][N];
int mv[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	memset(pre, -1, sizeof pre);
	que[qtop] = PII(sx, sy);
	// ����Ӧ����һ�������ڵĵ���Ϊ��㣬��Ϊ�յ����һ�����ǲ����ڵ� 
	pre[sx][sy] = PII(0, 0);
	while (qtop <= qback) {
		PII now = que[qtop++];
		if (now.x == 1 && now.y == 1) return;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			// ���������жϻ����ϰ������... 
			if (pre[nx][ny].x != -1 || graph[nx][ny] != '.') continue;
			// ���ﲻ��PII(now.x, now.y)��ֱ�Ӹ�ֵnow���� 
			pre[nx][ny] = now;
//			cout << nx << ' ' << ny << endl;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m ;j++) {
			cin >> graph[i][j];
		}
	}
	bfs(n, m);
	PII end = PII(1, 1);
//	cout << pre[end.x][end.y].x << ' ' << pre[end.x][end.y].y << endl;
	while (true) {
		printf("%d %d\n", end.x, end.y);
		if (end.x == n && end.y == m) break;
		// ����д�ıȽ�������̣�PII��PII... 
		end = pre[end.x][end.y];
//		end = PII(pre[nx][ny]);
	}
	return 0;
}
