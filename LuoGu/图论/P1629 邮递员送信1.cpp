#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// 大概还是图论小鬼（通过大话数据结构学的基础，然后看的啊哈算法学的模板w）就看到了这个题，那时候完全懵逼
// 大概是知道题目要求最短路，但是完全不知道怎么写的样子吧...
// 思路是跑两遍最短路，一遍求1到所有顶点的距离（去的距离），再跑一遍反向图，求所有点到1的距离（回的距离）即可 
// 另外这个题和cow party那个题不同，这个题数据量更大，跑n次最短路肯定会TLE的... 

// 其实这里写一个dijkstra就够了，对正向图跑完了把dist存起来，然后跑反向图的时候再还原dist就行，为什么要写
// 两个函数其实是因为两个图不一样，这里的解决方案是把顶点，边权都存起来，跑完正向图还原idx，然后再用正向图
// 的数组建立反向图，这样就能少写一个函数了.. 

const int N = 1e3 + 10, M = 1e5 + 10, INF = 0x3fffffff;
typedef pair<int, int > PII;
int head1[N], e1[M], ex1[M], w1[M], idx1 = 0;
int head2[N], e2[M], ex2[M], w2[M], idx2 = 0;
int dist1[N], dist2[N];
bool visited[N];
void add1(int ut, int vt, int wt) {
	e1[idx1] = vt, w1[idx1] = wt, ex1[idx1] = head1[ut], head1[ut] = idx1++;
}
void add2(int ut, int vt, int wt) {
	e2[idx2] = vt, w2[idx2] = wt, ex2[idx2] = head2[ut], head2[ut] = idx2++;
}
// 算所有点去的距离 
void dijkstra1(int st) {
	fill(dist1, dist1 + N, INF);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist1[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head1[ut]; i != -1; i = ex1[i]) {
			int vt = e1[i];
			if (dist1[vt] > w1[i] + wt) {
				dist1[vt] = w1[i] + wt;
				que.push(PII(dist1[vt], vt)); 
			}
		}
	}
}
// 算所有点回的距离 
void dijkstra2(int st) {
	fill(dist2, dist2 + N, INF);
	fill(visited, visited + N, false);
	priority_queue<PII, vector<PII >, greater<PII > > que;
	dist2[st] = 0;
	que.push(PII(0, st));
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head2[ut]; i != -1; i = ex2[i]) {
			int vt = e2[i];
			if (dist2[vt] > w2[i] + wt) {
				dist2[vt] = w2[i] + wt;
				que.push(PII(dist2[vt], vt)); 
			}
		}
	}
}
int main() {
	int n, m, ut, vt, wt;
	scanf("%d%d", &n, &m);
	fill(head1, head1 + N, -1);
	fill(head2, head2 + N, -1);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add1(ut, vt, wt), add2(vt, ut, wt); // 有向图，这里反向建图（也就是把边的方向反过来） 
	}
	dijkstra1(1);
	dijkstra2(1);
	int res = 0;
	// 一遍AC（喜） 
	for (int i = 1; i <= n; i++) res += dist1[i] + dist2[i];
	cout << res;
	return 0;
}
