#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 在网上找了下题解，这个题没有想象的那么难。回想之间做的一个题，叫Dijkstra？，这个题要我们求最短路径，我们记录的方法
// 就是用个pre数组记录当前点的上一个点是哪个点，因为我们走到的一定是最短路，所以这个方法是可行的。那么思考下这个题，
// 是否也可以转换为记录路径的题呢？答案是可以的，首先这个题本质上还是求最短路，所以第一次走到的点一定是最短的，那么
// 既然这个点的距离是最短的，那它的花费肯定也是必选的，因此我们用pre数组记录上一个点的花费，然后加起来就行了。思考下
// 为什么不能记录编号，因为记录编号较为麻烦，如果使用链式向前星难以通过节点编号获得修路的花费。
// 综上所述，在对问题进行转换后完全可以通过记录上一个点的花费的方式来解决这个题。

// 不是这样吧？上面的小并感想法完全不用看了...
// 这个题其实很简单，只不过被其想复杂了，每次出现最短路的时候更新结点花费就行了，如果路径相同就取最小值，至于
// 记录前驱完全是被误导了... 

typedef pair<int, int > PII;
const int N = 10000 + 10, M = 20000 * 2 + 10;
int head[N], e[M], ex[M], w[M], d[M], idx = 0;
int dist[N], cost[N];
bool visited[N];
void add(int ut, int vt, int wt, int dt) {
	e[idx] = vt, w[idx] = wt, d[idx] = dt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra(int st) {
	// 注意多个数据，所以要多次初始化.. 
	memset(dist, 0x3f, sizeof dist);
	memset(cost, 0, sizeof cost);
	memset(visited, 0, sizeof visited);
	// 用pair是因为这个题和花费几乎没有什么关系，只有在记录的时候会用到
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	// 这里和求最短路路径的那个题不同，这里不要求记录顺序，所以不用
	// 初始化为-1之类的标记结束，直接全加起来就行了
	dist[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				// 记录当前节点的最小花费，这里的最小花费就是d[i]，而不是某博文里的pre[ut]之类的东西... 
				cost[vt] = d[i];
				que.push(PII(dist[vt], vt));
			} else if (dist[vt] == wt + w[i]) {
				// 如果出现了最短路相同的节点，取最小值就行了... 
				cost[vt] = min(cost[vt], d[i]);
			}
		}
	}
}
int main() {
	int n, m, ut, vt, wt, dt;
	while (true) {
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		// 初始化头结点，其它数组把idx置零就行了，因为判断是否有边判断的还是是否有head.. 
		memset(head, -1, sizeof head);
		idx = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d%d", &ut, &vt, &wt, &dt);
			add(ut, vt, wt, dt), add(vt, ut, wt, dt);
		}
		dijkstra(1);
		int ans = 0;
		// 累加和 
		for (int i = 1; i <= n; i++) ans += cost[i];
		printf("%d\n", ans);
	}
	return 0;
}
