#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 这个题不是简单的求迷宫最短路，而是求一个点到另一个点，再从这个点到另个点，并以此类推直到所有点都到达的最短路
// 思路就是用BFS，因为BFS有最短路的性质，先从第一个点开始，找到第二个点的最短路，然后再从第二个点开始以此类推
// 最多要找十次最短路... 

// 类似AtCode里的一道水题，这个题要求更多次最短路... 

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
	// 注意这里对终点的特判，一开始的起点是S，它的终点是1 
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
			// 注意，起点不是从数字1开始的，而是从字母S开始的，也就是要求的S到1，1到2...的距离，这里自然得把所有
			// 起点的距离记录下来 
			if (graph[i][j] == 'S') starts[0] = PII(i, j);
			// 注意这里，如果设定一个idx遍历记录会出现问题，因为地图里的点不一定是按1..2..的顺序出现的，所以最好
			// 这样存，另外不用考虑会不会出现1到3的情况，因为老鼠只能吃比它体力值大1的奶酪 
			if (graph[i][j] <= '9' && graph[i][j] >= '0') starts[graph[i][j] - '0'] = PII(i, j);
		}
	}
	// 最后一个点作为全部点的终点，因此不用再从这个点开始求最短路 
	for (int i = 0; i < pcnt; i++) {
		memset(visited, 0, sizeof visited);
		res += bfs(starts[i]);
	}
	printf("%d\n", res);
	return 0;
}
