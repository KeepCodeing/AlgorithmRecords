#include <iostream>
#include <cstdio>
using namespace std;

// 边权全相等的图可以用BFS求最短路，这里主要是来用BFS遍历下图，因为之前都没搞过所以不会w 

// 有向图 
const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
// 和求曼哈顿距离的那类题类似，用dist表示距离和访问否，当前扩展的
// 点的距离就等于上一个点的距离加上边权 
int dist[N];
int que[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
int bfs(int st, int n) {
	fill(dist, dist + N, -1);
	int qtop = 0, qback = 0;
	que[qtop] = st;
	dist[st] = 0;
	while (qtop <= qback) {
		int ut = que[qtop++];
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// 注意这里和最短路问题的不同之处：最短路问题不能根据dist来判断一个点是否被遍历过，因为一个点的边可能
			// 被多次松弛。而这里当前点的距离只能从上一个点扩展而来，所以判断是否访问得防止循环里面，而且这里和普通
			// 迷宫问题也是类型的.... 
			if (dist[vt] != -1) continue;
			dist[vt] = dist[ut] + 1;
			que[++qback] = vt;
		}
	}
	return dist[n];
}
int main() {
	int n, m, ut, vt;
	fill(head, head + N, -1);
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &ut, &vt);
		add(ut, vt);
	}
	printf("%d", bfs(1, n));
	return 0;
}
/*
4 5
1 2
2 3
3 4
1 3
1 4

1
*/
