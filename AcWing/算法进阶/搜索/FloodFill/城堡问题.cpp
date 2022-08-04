#include <iostream>
using namespace std;

// 依旧是个FloodFill题，但是如果按照出题人给的图来模拟估计很难做出来 

// 将first，second转换为x，y 
#define x first
#define y second
const int N = 55, M = N * N;
typedef pair<int, int > PII;
int graph[N][N];
int n, m;
bool visited[N][N];
// 用数组模拟队列 
PII que[M];
// 顺序必须是左上右下，这个分别对应了西北东南 
int move[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int bfs(int sx, int sy) {
	// 队尾，当前元素，hh也代表了连通块的大小 
	int tt = 0, hh = 0;	
	int area = 0;
	que[0] = PII(sx, sy);
	// 标记起点 
	visited[sx][sy] = true;
	while (hh <= tt) {
		// 取出队头元素 
		PII now = que[hh++];
		int k = graph[now.x][now.y];
		area++;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			// 出界判断，访问过判断，四个方向是否有墙 
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (visited[nx][ny]) continue;
			if (k >> i & 1) continue;
			visited[nx][ny] = true;
			// 入队元素 
			que[++tt] = PII(nx, ny);
			
		}
	}
	return area;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	int cnt  = 0, maxArea = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j]) {
				cnt++;
				maxArea = max(maxArea, bfs(i, j));
			}	
		}
	}
	cout << cnt << endl << maxArea;
	return 0;
}
/*
4 7 
11 6 11 6 3 10 6 
7 9 6 13 5 15 5 
1 10 12 7 13 7 5 
13 11 10 8 10 12 13

5 9
*/
