#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 抽象下问题：给出起点编号，终点编号，顶点间互相连通（无向图），去另一个
// 地方要给钱（边权），现在要求到终点花费最少（边权累计最少，也就是走的地方最少） 

// 裸的最短路问题..用Dijkstra即可 

typedef pair<int, int > PII;
const int N = 2500 + 10, M = 6200 * 2 + 10;
int head[N], ex[M], e[N], w[M], idx = 0;
int dist[M];
bool visited[N];
int n, m, st, ed;
priority_queue<PII, vector<PII >, greater<PII > > que;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
void dijkstra(int st) {
	dist[st] = 0;
	que.push(PII(0, st));
	while (!que.empty()) {
		PII now = que.top();que.pop();
		int wt = now.first, ut = now.second;
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
}
int main() {
	cin >> n >> m >> st >> ed;
	int ut, vt, wt;
	memset(head, -1, sizeof head);
	fill(dist, dist + N, 0x3fffffff);
	for (int i = 1; i <= m; i++) cin >> ut >> vt >> wt, add(ut, vt, wt), add(vt, ut, wt);
	dijkstra(st);
	cout << dist[ed];
	return 0;
}
/*
7 11 5 4
2 4 2
1 4 3
7 2 2
3 4 3
5 7 5
7 3 3
6 1 1
6 3 4
2 4 3
5 6 3
7 2 1

7
*/
