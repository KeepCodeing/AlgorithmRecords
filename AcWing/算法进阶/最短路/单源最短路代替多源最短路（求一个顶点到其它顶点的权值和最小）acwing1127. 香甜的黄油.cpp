#include <iostream>
#include <queue>
using namespace std;

// 题目的意思比较明显，就是要求一个点，使得所有其他点到这个点的距离最小。看起来像个全源最短路问题
// 但是数据范围却比较大，因此可以想到对每个点求一次单源最短路，然后对比最短距离即可。
// floyd O(n^3) Dijkstra O(mlogn) SPFA O(n*m)

const int N = 810, M = 1460 * 2 + 10, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[M];
int pos[N];
bool visited[N];
int n, p, c, t;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st) {
	// 注意每次求最短路都要还原距离数组和访问标记数组.. 
	fill(dist, dist + M, INF);
	fill(visited, visited + N, 0);
	// dijkstra板子，对每个点求最短路.. 
	dist[st] = 0;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > w[i] + wt) {
				dist[vt] = w[i] + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	int res = 0;
	// 统计当前点到所有奶牛所在的牧场的距离，如果不可达说明该点不是合法解 
	for (int i = 1; i <= n; i++) {
		if (dist[pos[i]] == INF) return INF;
		res += dist[pos[i]];
	}
	return res;
}
int main() {
	cin >> n >> p >> c;
	fill(head, head + N, -1);
	for (int i = 1; i <= n; i++) cin >> pos[i];
	int ut, vt, wt;
	for (int i = 1; i <= c; i++) {
		cin >> ut >> vt >> wt;
		add(ut, vt, wt), add(vt, ut, wt);
	} 
	int res = INF;
	// 一共p个点，n个点有奶牛，对1~p之间的所有点求最短路，然后返回 
	// 这些点到牧场的距离之和，之前用了个set，因为题目中说有可能有
	// 某个牧场不止一个奶牛，这样可能可以少求几次最短路罢.. 
	for (int i = 1; i <= p; i++) {
		res = min(dijkstra(i), res);
	}
	cout << res;
	return 0;
}

/*
3 4 5
2
3
4
1 2 1
1 3 5
2 3 7
2 4 3
3 4 5

8
*/
