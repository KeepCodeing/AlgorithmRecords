#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// �������һ����ȫһ�����⣬��ʱ�뵽���ܱ�BFS������㵽���е��ʱ�䣬����û�뵽��ô�ж��ߵ��˰�ȫ�ĵط�...
// ��ȷ���������Ƚ���ͼ���³�����׹�����Сʱ����ʽ�ĵ�ͼ��Ȼ�������·�����ߵ�-1�㣨û����ǵĵ㣩�����ߵ�
// �˰�ȫ�ĵط������ɷ��ز��������򷵻��޷����Ｔ��... 

// һ��AC�����Ҹ�����w 

const int N = 310;
int graph[N][N];
int mv[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct pos {
	int x, y, step;
	pos (int x, int y, int step) : x(x), y(y), step(step) {};
	pos () {};
} que[N * N + 10];
bool visited[N][N];
bool checker(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}
int bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = pos(sx, sy, 0);
	while (qtop <= qback) {
		pos now = que[qtop++];
		// ������˰�ȫ�㣬���ش� 
		if (graph[now.x][now.y] == -1) return now.step;
		for (int i = 1; i < 5; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (checker(nx, ny)) continue;
			// �ж��Ƿ�����Լ���ǰ�ߵĲ����Ƿ񳬹�������׹���ʱ�� 
			if (visited[nx][ny] || graph[now.x][now.y] <= now.step) continue;
			visited[nx][ny] = true;
			que[++qback] = pos(nx, ny, now.step + 1);
		}
	}
	// ��ȵ��������û�������ܵ��ﷵ��-1... 
	return -1;
}
int main() {
	int n, x, y, t;
	scanf("%d", &n);
	memset(graph, -1, sizeof graph);
	while (n--) {
		scanf("%d%d%d", &x, &y, &t);
		for (int i = 0; i < 5; i++) {
			// ����ͼ������Ϯ����ʱ�����Ϊ���ʱ�䣬ע�������ƶ���ʽ��5�֣���Ϊһ��ʼ�ĵ�Ҳ���ܱ����� 
			int nx = x + mv[i][0], ny = y + mv[i][1];
			// ���µ�ͼ�����������Ĺؼ�֮��֮һ... 
			if (checker(nx, ny)) continue;
			if (graph[nx][ny] == -1) graph[nx][ny] = t;
			else graph[nx][ny] = min(graph[nx][ny], t);
		}
	}
	// �����·
	printf("%d", bfs(0, 0));
	return 0;
}
