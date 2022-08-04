#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// 板子题，不过要注意字典序，根据题目要求，可以使终点最小，如果终点编号相同，就使起点最小... 

// 不知道为什么RE了两次，一般来说建图开空间就根据题目给的数据来就行了..然后改的特别大，
// 但是最后一个点TLE了w，吸氧混过去了... 
const int N = 1e6 * 5 + 10, M = 1e6 * 5 + 10;
struct Node {
	int u, v;
	bool operator<(const Node& n) const {
		// 根据邻接表后进先出的原则，这里的排序规则应该是终点从大到小，
		// 起点从小到大.. 
		if (n.v != v) return v > n.v;
		return u < n.u;
	}
} tp[M];
int head[N], e[M], ex[M], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
bool visited[N];
void dfs(int ut) {
	printf("%d ", ut);
	visited[ut] = true;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (!visited[vt]) dfs(vt);
	}
}
int que[N];
void bfs(int ut) {
	int qtop = 0, qback = 0;
	que[qtop] = ut;
	while (qtop <= qback) {
		int now = que[qtop++];
		// 这里之前没搞明白为什么会有重复的点输出w，然后才发现now不管怎么样都会被输出，然后结合前面学的
		// Dijkstra改造了下原本是下面入队时进行的访问过标记，改成了当前元素被标记，然后输出.. 
		if (!visited[now]) printf("%d ", now), visited[now] = true;
		for (int i = head[now]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (!visited[vt]) que[++qback] = vt;
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d%d", &tp[i].u, &tp[i].v);
	sort(tp, tp + m);
	// 单向边... 
	memset(head, -1, sizeof head);
	for (int i = 0; i < m; i++) add(tp[i].u, tp[i].v);
	memset(visited, 0, sizeof visited);
	dfs(1);
	puts("");
	memset(visited, 0, sizeof visited);
	bfs(1);
	return 0;
}
