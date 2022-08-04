#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// 这个题是要求的是第二短的最短路，即次短路问题。首先思考下Dijkstra的最短路是怎么求的，这种算法存在一个松弛
// 操作，就是枚举当前点的所有边，然后判断这个当前点通过这条边到另一个点的距离是否最短，如果最短，就将另一个点 
// 的距离更新为更短距离，然后将这个点入队，下次遍历的时候就会从当前点所有边能到的点中边权最小的那个点开始。
// 我们在其思路上稍加修改，就可以得到次短路的求法了。在遍历的时候，不仅要记录最短路的距离，还要记录次短路的距离
// 即根据最短路的距离来判断当前选的这个边是不是第二短的，因为求u->v的次短路无非就两种情况，一种是u的次短路->v，
// 一种是u->v的最短路。明确了这一点之后剩下来的就和Dijkstra最短路版差不多了。 
// 另外要注意代码上的几个区别，比如要保证当前选的边不是最短边，多个边可以多次走（没有visited标记）等... 

typedef pair<int, int > PII;
const int N = 5000 + 10, M = 100000 * 2 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
// 存最短路和次短路距离 
int dist[N], dist2[N];
int n, m;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(dist2, 0x3f, sizeof dist2);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	// 注意这里次短路数组的起点不能进行赋值，不然下面判断当前距离是否是次短的时候会认为起点没有次短路存在，也就是
	// 说后续操作全会被跳过 
	dist[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		// 如果当前点的边权是最小的，那就意味着这个边不能作为次短边使用，所以要跳过 
		if (dist2[ut] < wt) continue;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// 因为wt + w[i]会多次用到，所以可以用个变量存起来 
			int dt = wt + w[i];
			// 求最短距离，用来选次短距离
			if (dist[vt] > dt) {
				dist[vt] = dt;
				que.push(PII(dist[vt], vt)); 
			}
			// 求次短路的核心代码，只要当前边权不是最小的，那就把它入队作为可能的次短边继续遍历，而判断
			// 当前边是否最小就要通过最短路距离来了，也就是说最短路数组充其量只是用来判断当前边是不是最短的... 
			if (dist2[vt] > dt && dist[vt] < dt) { // 求次短距离，只要当前边不是最短的就可以用来求次短路.. 
				dist2[vt] = dt;
				que.push(PII(dist2[vt], vt)); 
			}
		}
	}
	return dist2[n];
}
int main() {
	// 忘了初始化头结点... 
	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &m);
	int ut, vt, wt;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt), add(vt, ut, wt);
	}
	printf("%d", dijkstra(1));
	return 0;
}
