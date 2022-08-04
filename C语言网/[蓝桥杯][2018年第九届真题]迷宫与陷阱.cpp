#include <iostream>
using namespace std;

// 和在洛谷上做过的捡鼠标的题几乎一样...不过那个题不知道为什么最后一个点就是过不去w.. 
// 甚至过不了一半的点..不知道怎么做了... 

const int N = 1010, M = 1e6 * 5 + 10;
char graph[N][N];
int n, k;
struct Node {
	int x, y, step, k;
	Node (int x, int y, int step, int k) : x(x), y(y), step(step), k(k) {};
	Node () {};
} que[M];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int visited[N][N];
int bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = Node (sx, sy, 0, 0);
	while (qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == n - 1 && now.y == n - 1) return now.step;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (graph[nx][ny] == '#' || (now.k <= 0 && graph[nx][ny] == 'X') || (visited[nx][ny] >= 6 && graph[nx][ny] != 'X')) continue;
			// 有无敌状态存在三种可能，一种是走到了%，这种情况可以恢复步数
			// 一种是走到了X，这种情况可以通过消耗步数走过去
			// 最后一种是走的普通格子，这种情况不用消耗步数... 
			if (graph[nx][ny] == '%') que[++qback] = Node(nx, ny, now.step + 1, now.k + k);
			else if (graph[nx][ny] == 'X') que[++qback] = Node(nx, ny, now.step + 1, now.k - 1);			
			else que[++qback] = Node(nx, ny, now.step + 1, now.k);	
			if (graph[nx][ny] != 'X') visited[nx][ny]++;
//			if (graph[nx][ny] != 'X') graph[nx][ny] = '#';
		}		
	} 
	return -1;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cin >> graph[i][j];
	cout << bfs(0, 0);
	return 0;
} 
