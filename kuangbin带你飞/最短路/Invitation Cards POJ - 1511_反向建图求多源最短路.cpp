#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 题面是在是迷w，不过还是想到了反向建图求多源最短路，这个题本质来说和银牛派对还有邮递员送信是一样的，都是要求
// 1到n的最短路和n到1的最短路，前者普通最短路就行了，后者反向建图从1跑就行了...另外这个题似乎卡了最大值之类的东西
// 要开longlong，最大值也要设置的比普通最短路大... 

typedef pair<int, int > PII;
typedef long long LL;
// 突然想起来是单向边，不是单向边也就没有所谓的反向建图了吧w 
const int N = 1000000 + 10;
// 注意最大值的设置 
const LL INF = 0x3f3f3f3f3f3f3f3f;
int head[N], e[N], ex[N], w[N], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int _head[N], _e[N], _ex[N], _w[N], _idx = 0;
LL _dist[N], __dist[N];
bool visited[N];
void _add(int ut, int vt, int wt) {
	_e[_idx] = vt, _w[_idx] = wt, _ex[_idx] = _head[ut], _head[ut] = _idx++;
}
void _init() {
	for (int i = 0; i < N; i++) _dist[i] = __dist[i] = INF;
}
LL dijkstra(int st, int n, int headt[], int et[], int ext[], int wt[], LL dist[]) {
	// 注意visited要多次初始化，因为会跑两次最短路... 
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wtt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = headt[ut]; i != -1; i = ext[i]) {
			int vt = et[i];
			if (dist[vt] > wtt + wt[i]) {
				dist[vt] = wtt + wt[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	} 
	LL res = 0;
	for (int i = 1; i <= n; i++) res += dist[i];
	return res;
}
int main() {
	int T, n, m, ut, vt, wt;
	scanf("%d", &T);
	while (T--) {
		memset(head, -1, sizeof head);
		memset(_head, -1, sizeof _head);
		scanf("%d%d", &n, &m);
		while (m--) {
			scanf("%d%d%d", &ut, &vt, &wt);
			add(ut, vt, wt), _add(vt, ut, wt);
		}
		// 初始化两个距离数组，还有访问数组 
		_init();
		// 答案就是正反图的两个最短路之和
		printf("%lld\n", dijkstra(1, n, head, e, ex, w, _dist) + dijkstra(1, n, _head, _e, _ex, _w, __dist));
	}
	return 0;
}
