#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// 不会各种神触做法，这里用最短路求下距离就行了.. 另外因为边权全为1
// 所以其实可以不用距离数组。另外如果边权全唯一，那么是不是可以用BFS
// 求，不太清楚（无能），BFS基本没怎么用在图上（遍历都不太会）... 

// 另外pair也是必须的，虽然只针对第一个元素的边权为0而言，不过没了这玩意
// 还是不习惯w 

typedef pair<int, int > PII;
const int N = 1e5 + 10, M = N * 2 + 10, INF = 0x3fffffff;
int head[N], e[M], ex[M], idx = 0;
int dist[M];
bool visited[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st, int d, int n) {
	fill(dist, dist + M, INF);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0; 
	int res = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > 1 + wt) {
				dist[vt] = 1 + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}	
	for (int i = 2; i <= n; i++) {
		//printf("%d ", dist[i]);
		res += (int)(dist[i] <= d);
	}
	return res;
}
int main() {
	int n, d, ut, vt;
	fill(head, head + N, -1);
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &ut, &vt);
		add(ut, vt), add(vt, ut);
	}
	printf("%d", dijkstra(1, d, n));
	return 0;
}
