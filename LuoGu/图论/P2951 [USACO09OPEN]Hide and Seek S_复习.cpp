#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

// 最短路复习第四弹，那么这个题就是从1跑一次最短路，然后求最长路的编号，个数...
// 思考下能不能用最小生成树做，答案是不行，因为最小生成树类似重构了整个图，那这样的话新的到的图不一定就是1为起点的，而且
// 这样也无法统计从1到其它点的最短路的个数，长度等... 

// 去注释搞CE了..看到了好久之前写的代码了，还是用的vector，那时候写的比较复杂，也难怪搞不出来w 

typedef pair<int, int > PII;
const int N = 20000 + 500, M = 50000 * 5 + 100;
int head[N], e[M], ex[M], idx = 0;
int dist[N];
bool visited[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	memset(visited, 0, sizeof visited);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st));
	dist[st] = 0;
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// 注意这里，因为边权始终为1，因此可以省去一个w数组，但是pair这里不能省，因为第一个点到自己的边权时特殊为0的 
			if (dist[vt] > wt + 1) {
				dist[vt] = wt + 1;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
}
int main() {
	int n, m;
	// 忘记初始就只有TLEw 
	memset(head, -1, sizeof head);
	scanf("%d%d", &n, &m);
	int ut, vt;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &ut, &vt);
		add(ut, vt), add(vt, ut);
	}
	dijkstra(1);
	int id = -1, ds = 0, cnt = 1;
	// 因为怕出错所有先统计了最大值，然后再更新答案（无能） 
	for (int i = 1; i <= n; i++) ds = max(dist[i], ds);
	for (int i = 1; i <= n; i++) {
		// 记录第一个最大值点以及统计这样的点的个数... 
		if (dist[i] == ds && id == -1) id = i; 
		else if (dist[i] == ds) cnt++;
	}
	printf("%d %d %d", id, ds, cnt);
	return 0;
}
