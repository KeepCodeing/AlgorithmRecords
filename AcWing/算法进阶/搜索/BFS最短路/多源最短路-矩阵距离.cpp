#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;

// 这个题目要求的是所有0到1的最近距离，比较朴素的想法就是对每个0进行一次bfs，但是我们知道
// bfs中某个点第一次出现求得的绝对就是最短路径，所以可以反着想，从每个点1开始遍历，然后更新
// 点0的距离 

// 在洛谷做了个题，发现这个题的graph其实没什么用，或者说多源最短路模型的题graph都没什么用
// 在这种模型的题里面graph充其量就是入队特殊的起点元素，只有dist才是存结果和访问否的数组 

#define x first 
#define y second 
typedef pair<int, int > PII;
const int N = 1010, M = N * N;
int n, m;
int dist[N][N];
char graph[N][N];
PII que[M];
int qtop = 0, qback = 0;
int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs() {
	// 常规bfs
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			// 因为第一次碰到的点就是最短距离，所以没必要重复更新 
			if (dist[nx][ny] != -1) continue;

			// 更新距离，当前距离就是上一点距离+1 
			dist[nx][ny] = dist[now.x][now.y] + 1;
			cout << dist[nx][ny] << endl;
			// 再从这个点开始遍历
			que[++qback] = PII(nx, ny); 
		}
	}
} 
int main() {
	scanf("%d%d", &n, &m);
	// 之前居然在bfs里初始化的dist数组，那这样搞置零就没用了 
	memset(dist, -1, sizeof dist);
	cout << sizeof dist << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 被scanf坑了，scanf把换行也当成了字符读入了，地图直接都是个错的 
			cin >> graph[i][j];
			if (graph[i][j] == '1') {
				// 将1点坐标入队，顺便将点1的距离置零，因为1到自己的距离就是0 
				que[qback++] = PII(i, j);
				dist[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << dist[i][j] << ' ';
		cout << endl;
	}
	cout << qtop << ' ' << qback << endl;
	bfs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", dist[i][j]);
		}
		puts("");
	}
	return 0;
}
/*
3 4
0001
0011
0110

3 2 1 0
2 1 0 0
1 0 0 1
*/
