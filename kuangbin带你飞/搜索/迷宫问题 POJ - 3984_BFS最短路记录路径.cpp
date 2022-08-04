#include <iostream>
#include <cstring>
using namespace std;

// 写过的题，之前fuxi还发现忘了w，据说这个题只有一个数据点，很水呢w，目前唯一一个能看出来写法而且一次AC的题... 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 10;
int graph[N][N];
PII que[N * N], pre[N][N];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs(int sx, int sy) {
	// 这里设置为-1只是为了判断是否走过，下面输出路径的时候还是要以真正的终点为主... 
	memset(pre, -1, sizeof pre);
	int qtop = 0, qback = 0;
	que[qtop] = PII(sx, sy); 
	pre[sx][sy] = PII(-1, -1);
	while (qtop <= qback) {
		PII now = que[qtop++];
		// if (now.x == 0 && now.y == 0) return;这里不能提前返回，不然记录的路径不完整 
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			// 不要忘记1不能走 
			if (graph[nx][ny]) continue;
			if (pre[nx][ny].x != -1) continue;
			pre[nx][ny] = now;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cin >> graph[i][j];
		}
	}
	bfs(4, 4);
	// 从终点跑BFS，终点跑到的终点就是起点，再从起点回溯回去还原路径... 
	PII end = PII(0, 0);
	while (true) {
		cout << "(" << end.x <<", " << end.y << ")" << endl;
		// 走到终点停止，不是==-1判断走没走过，这样会形成死循环 
		if (end.x == 4 && end.y == 4) break;
		end = pre[end.x][end.y];
	}
	return 0;
}
