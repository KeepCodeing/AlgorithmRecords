#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// ����ⲻ�Ǽ򵥵����Թ����·��������һ���㵽��һ���㣬�ٴ�����㵽����㣬���Դ�����ֱ�����е㶼��������·
// ˼·������BFS����ΪBFS�����·�����ʣ��ȴӵ�һ���㿪ʼ���ҵ��ڶ���������·��Ȼ���ٴӵڶ����㿪ʼ�Դ�����
// ���Ҫ��ʮ�����·... 

// ����AtCode���һ��ˮ�⣬�����Ҫ���������·... 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 1010, M = 15;
int n, m, pcnt;
char graph[N][N];
PII starts[M];
bool visited[N][N];
struct pos {
	int x, y, step;
	pos (int x, int y, int step) : x(x), y(y), step(step) {};
	pos () {};
};
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
pos que[N * N + 10];
int bfs(PII st) {
	char snum = graph[st.x][st.y];
	// ע��������յ�����У�һ��ʼ�������S�������յ���1 
	int ed = snum == 'S' ? '1' : snum + 1;
	int qback = 0, qtop = 0;
	que[qtop] = pos(st.x, st.y, 0);
	while (qtop <= qback) {
		pos now = que[qtop++];
		if (graph[now.x][now.y] == ed) return now.step;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (visited[nx][ny] || graph[nx][ny] == 'X') continue;
			visited[nx][ny] = true;
			que[++qback] = pos(nx, ny, now.step + 1);
		}
	}
}
int main() {
	int res = 0;
	scanf("%d%d%d", &n, &m, &pcnt);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			// ע�⣬��㲻�Ǵ�����1��ʼ�ģ����Ǵ���ĸS��ʼ�ģ�Ҳ����Ҫ���S��1��1��2...�ľ��룬������Ȼ�ð�����
			// ���ľ����¼���� 
			if (graph[i][j] == 'S') starts[0] = PII(i, j);
			// ע���������趨һ��idx������¼��������⣬��Ϊ��ͼ��ĵ㲻һ���ǰ�1..2..��˳����ֵģ��������
			// �����棬���ⲻ�ÿ��ǻ᲻�����1��3���������Ϊ����ֻ�ܳԱ�������ֵ��1������ 
			if (graph[i][j] <= '9' && graph[i][j] >= '0') starts[graph[i][j] - '0'] = PII(i, j);
		}
	}
	// ���һ������Ϊȫ������յ㣬��˲����ٴ�����㿪ʼ�����· 
	for (int i = 0; i < pcnt; i++) {
		memset(visited, 0, sizeof visited);
		res += bfs(starts[i]);
	}
	printf("%d\n", res);
	return 0;
}
