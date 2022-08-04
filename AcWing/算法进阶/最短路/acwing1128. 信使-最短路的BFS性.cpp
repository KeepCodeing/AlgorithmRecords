#include <iostream>
#include <queue>
using namespace std;

// 这个题题意比较奇特，它的意思是从1号点开始，向所有与1号点有边的点进行扩展，
// 如果画图的话看起来像BFS的扩散过程。然后被扩展到的点再进行扩展，依次类推
// 直到所有点都被扩散到了（如果有点没能扩散到就说明无解）。看起来比较迷，但是
// 如果我们把边权带进去画下图就可以发现，这个题这里和BFS的最短路性质一样，也就是
// 说第一次被扩展到的点的距离一定是最短的，至于扩展回去的过程因为这个性质的存在
// 也就可以忽略不计了。那么这个题也是一个差不多裸的最短路问题，另外因为数据范围
// 很小，所以可以用floyd算一遍全源最短路，然后统计下各点能否到1号点，以及它们
// 到1号点的距离之和。

// 这里为了fuxi Dijkstra就用这个写罢 

typedef pair<int, int > PII;
const int N = 110, M = 210, INF = 0x3fffffff;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[M];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra(int st) {
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		// 这里i其实是idx，也就是节点编号 
		for (int i = head[ut]; i != -1; i = ex[i]) {
			// 取出这个节点的编号 
			int vt = e[i];
			// 判断下是否可以通过ut到w[i]进行松弛..这里所有取下标的操作其实都是在取节点编号，不过想来想去
			// 还是觉得理解比较麻烦（无能），干脆就按感觉打算了... 
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	} 
}
int main() {
	int n, m;
	cin >> n >> m;
	int ut, vt, wt;
	fill(head, head + N, -1);
	fill(dist, dist + N, INF);
	for (int i = 1; i <= m; i++) cin >> ut >> vt >> wt, add(ut, vt, wt), add(vt, ut, wt);
	dijkstra(1);
	int res = -1;
	for (int i = 1; i <= n; i++) {
		// 解不合法 
		if (dist[i] == INF) {
			cout << -1;
			return 0;
		}
		// 因为存在BFS的特性，所以1号点到最后一个点的最短距离一定是最大的，这里就是
		// 找最后的最大最短距离，有点类似乳草那个题 
		res = max(res, dist[i]);
	}
	cout << res;
	return 0;
}
/*
4 4
1 2 4
2 3 7
2 4 1
3 4 6

11
*/
