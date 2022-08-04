#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 和上一题是相同的题型，也可以用Kruskal解，不过这种题正解应该是最短路最大化最小值，思路就是改下求状态的方式，
// 下面给一个参考代码... 
// 另外这种生成树似乎叫做最大生成树...总之就是边权和最大w，那么这种求最长边的题应该都可以用最大生成树来做了... 
// 另外想起来另一个题，在挑战的最短路里，要求最短路的最小边权和，那个题在判断最短路里记录下边权就行了，当然
// 其也尝试用最小生成树做了，不过坠毁了。那时候的总结是如果对点的顺序有要求（即在不改变原图的前提下求最短路）
// 那么一般就不能用最小生成树。这个题正好验证了这一点，这个题不用求最短路，只用求最长边，那么干脆重构图然后跑
// Kruskal就行了... 

// 没给边数，无脑开大w 
const int N = 1000 + 10, M = 1e6 * 5;
struct G {
	int u, v, w;
	bool operator<(const G& g) const {
		// 注意这里是最大生成树，所以边权应该从大到小，如果写成最小生成树那种，就要在连边的过程中统计最长边，
		// 而这里如果直接降序排序就不用统计最长边了，第一个成环的边一定是最长边.. 
		return w > g.w;
	}
} graph[M];
struct unionFind {
	int bin[N];
	void _init() {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int T, n, m;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		u._init();
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
		sort(graph, graph + m);
		for (int i = 0; i < m; i++) {
			if (!u.ask(graph[i].u, graph[i].v)) {
				u.uni(graph[i].u, graph[i].v);
				if (u.ask(1, n)) {
					printf("Scenario #%d:\n", t);
					printf("%d\n\n", graph[i].w);
					break;
				}
			}
		}
	}
	return 0;
}
/*
1
3 3
1 2 3
1 3 4
2 3 3
*/

//参考代码，主要是Dijkstra初始化和求边权有所改变.. 
//#include <cstdio>
//#include <queue>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 1005, M = 200005, INF = 0x3f3f3f3f;
//int t, n, m, u, v, w, len, h[N], d[N];//d[i]代表1到i的路径中的最小值中的最大一个 
//bool vis[N];
//struct E {
//	int v, w, next;
//} e[M];
//struct Node {
//	int v, d;
//	Node(int d, int v): d(d), v(v){}
//	bool operator < (const Node&w) const {
//		return d < w.d;//d大的应该先出来 
//	}
//};
//void add(int u, int v, int w) {
//	e[len].v = v;
//	e[len].next = h[u];
//	e[len].w = w;
//	h[u] = len++;
//}
//void djkstra() {
//	memset(vis, false, sizeof(vis));
//	memset(d, 0, sizeof(d));
//	d[1] = INF; //第一个点应该是无穷大 
//	priority_queue<Node> q;
//	q.push(Node(0, 1)); 
//	while (!q.empty()) {
//		int u = q.top().v;
//		q.pop();
//		if (vis[u]) continue;
//		vis[u] = true;
//		for (int j = h[u]; j; j = e[j].next) {
//			int v = e[j].v;
//			int w = min(d[u], e[j].w); //看这条边 和之前的最小值谁小
//			if (d[v] < w) {
//				d[v] = w;
//				q.push(Node(d[v], v)); 
//			} 
//		} 
//	}
//}
//int main() {
//	scanf("%d", &t);
//	for (int cas = 1; cas <= t; cas++) {
//		memset(h, 0, sizeof(h)), len = 1;
//		scanf("%d%d", &n, &m);
//		for (int i = 1; i <= m; i++) {
//			scanf("%d%d%d", &u, &v, &w);
//			add(u, v, w); add(v, u, w);
//		} 
//		djkstra();
//		printf("Scenario #%d:\n%d\n\n", cas, d[n]);
//	} 
//	return 0;
//} 

