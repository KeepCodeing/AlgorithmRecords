#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// BFS复习第一弹，这个题很坑，坑在输入上，另外思路其实也不太好想，不过做多了就知道套路了... 
// 输入的是类似数轴的地图，所以坐标之类的得处理下，另外根据LeetCode上的套路，不用再遍历一遍地图，直接返回最后一个点
// 被遍历到的时间就行，另外行列输入也是反着的... 

// 这里对于数轴转计算机轴的方案是把输入输出时的行列倒着开始，这样起点和终点，地图就都符合计算机里的了... 
// 然而上面的说法不完全正确，思考下计算机轴和数轴的样子，可以发现计算机轴就是把数轴的y反过来了，那输入的时候y从大到小就行了.. 

// 不知道为什么直接返回坐标慢了一倍，这样看来可能是变量的引用之类的原因，所以还是用遍历取最大值的方法算了..w

// 另外数轴转计算机轴的思路是其提交代码时看到了以前的代码才想起来的，不过那时候并没有什么理解，现在倒是完全懂了，温故而知新呢w 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 110;
int n, m;
char graph[N][N];
PII que[N * N];
int dist[N][N];
int bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = PII(sx, sy);
	memset(dist, -1, sizeof dist);
	dist[sx][sy] = 0;
	PII now;
	while (qtop <= qback) {
		now = que[qtop++];
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i != 0 || j != 0) {
					int nx = now.x + i, ny = now.y + j;
					if (nx > n || nx < 1 || ny > m || ny < 1) continue;
					if (dist[nx][ny] != -1 || graph[nx][ny] == '*') continue;
					dist[nx][ny] = dist[now.x][now.y] + 1;
					que[++qback] = PII(nx, ny);
				}
			}
		}
	}
	return dist[now.x][now.y];
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			printf("%d ", dist[i][j]);
//		}
//		puts("");
//	}
}
int main() {
	int sx, sy;
	// 这里起点得反着来，因为我们sx是作为行标使用的，sy是作为列标使用的，也就对应的是y和x，所以得反着来 
	scanf("%d%d%d%d", &m, &n, &sy, &sx);
	for (int i = n; i >= 1; i--) {
		// 注意这里m代表的是x轴上的元素，n代表的是y上的元素，数轴坐标转计算机坐标的技巧就是把y轴反过来... 
		for (int j = 1 ; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	printf("%d", bfs(sx, sy));
	return 0;
}
