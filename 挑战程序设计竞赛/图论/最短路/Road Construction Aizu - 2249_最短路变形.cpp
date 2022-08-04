#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 又是半天看不懂题目w，总体来说这个题要求的就是从1号点到所有点的最短距离，同时还要求花费最小。对于前面的那个
// 问题而言跑个Dijkstra就完事了，那如何保证花费也最小呢？考虑下部分背包问题的思路，一个贪心，按照性价比进行排序
// 那么这个题我们是不是也可以这样做嗯？似乎可行，但是这样可能是错的，不过依然可以借助这种思路来，我们在保证距离
// 最短的前提下，如果有两个路径距离相同，选用花费最小的那个就行了..
// 话说这个题很像最小生成树，不过还是有区别的，最小生成树要求边权和最小，最短路要求路径最短... 
// 坠毁.. 

const int N = 10000 + 10, M = 20000 * 2 + 10;
int head[N], e[M], ex[M], w[M], d[M], idx = 0;
int dist[N], cost[N];
int n, m;
bool visited[N];
void add(int ut, int vt, int wt, int dt) {
	e[idx] = vt, w[idx] = wt, d[idx] = dt, ex[idx] = head[ut], head[ut] = idx++;
}
struct Node {
	int ut, wt, dt;
	Node (int ut, int wt, int dt) : ut(ut), wt(wt), dt(dt) {};
	Node () {};
	// 注意这里的const 
	bool operator<(const Node& n) const {
		if (wt != n.wt) return wt > n.wt;
		return dt > n.dt;
	}
	bool operator>(const Node& n) const {
		
	}
};
int dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(cost, 0x3f, sizeof cost);
	memset(visited, 0, sizeof visited);
	priority_queue<Node, vector<Node >, greater<Node > > que;
	que.push(Node(st, 0, 0));
	dist[st] = 0, cost[st] = 0;
	while (que.size()) {
		Node now = que.top();que.pop();
		cout << now.ut << ' ' << now.wt << ' ' << now.dt << endl;
		int ut = now.ut, wt = now.wt, dt = now.dt;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				
				// cout << d[i] << ' ' << vt << endl;
				que.push(Node(vt, dist[vt], cost[vt])); 
			}
			cost[vt] = min(dt + d[i], cost[vt]);
		}
	} 
	for (int i = 1; i <= n; i++) cout << cost[i] << ' ';
	cout << endl;
	return 0;
}
int main() {
	int ut, vt, wt, dt;
	while (true) {
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		// 多组数据，因此要多次初始化，另外应该不用初始化除了头结点数组的其它数组，只用改下idx就行 
		memset(head, -1, sizeof head);
		idx = 0;
		while (m--) {
			scanf("%d%d%d%d", &ut, &vt, &wt, &dt);
			// 双向边，这里还要多加个花费属性，一开始以为可以用个结构体之类的东西存，不过这样似乎不可行，只有
			// 遍历要用的时候才行... 
			add(ut, vt, wt, dt), add(vt, ut, wt, dt);
		}
		printf("%d\n", dijkstra(1));
	}
	return 0;
}
