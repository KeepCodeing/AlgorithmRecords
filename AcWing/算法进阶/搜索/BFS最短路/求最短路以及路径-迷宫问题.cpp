#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 模板还是和BFS求最短路一样，只不过这里把记录走过的数组扩展成了pair，通过这个pair记录下上一步走的路径
// 这样就能反推出走到终点的路径了 
// 另外这里还不能设置到达了某个点就退出，不然会形成死循环，可能是因为上一个点到了这个点但并不连续（虚心） 

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
	// 默认用pre的x属性来表示这个点访问过没 
	// memset虽然能赋的值比较单一，但是不会像fill赋值二维数组那样失败 
	memset(pre, -1, sizeof pre);
	// 终点之后没有值了，但是为了将其标记为访问过了所以还是要赋值 
	pre[sx][sy] = PII(0, 0);
	while (hh <= tt) {
		PII now = que[hh++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			// 如果为墙 
			if (graph[nx][ny]) continue;
			// 如果这个元素访问过了 
			if (pre[nx][ny].x != -1) continue;
			// 下一个点的上一个位置就是now 
			pre[nx][ny] = now;
			// hh是当前元素下标，tt是队列中最后一个元素的下标，所以要入队元素应该是++tt 
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
	// 类似链表的遍历操作，这里因为是路径是反着来的，所以可能需要用一个缓存数组来正序输出
	// 但是如果我们从终点开始向起点遍历，路径就是正着的了 
	bfs(n, n);
	PII end(1, 1);
	while (true) {
		// 输出的位置从0开始，而其下标从1开始，所以这里要还原回去 
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
