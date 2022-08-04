#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// 最基础的模板题了...似乎可以不加很多思考就能写出来了，果然练习是王道w，以前写一行
// 想一行的作用，导致的反而是自我矛盾呢.. 

typedef pair<int, int > PII;
const int N = 1000 + 10, M = 2000 * 2 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
bool visited[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st, int ed) {
	memset(dist, 0x3f, sizeof dist);
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
			if (dist[vt] > wt + w[i]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		} 
	}
	return dist[ed];
}
int main() {
	memset(head, -1, sizeof head);
	int m, n, ut, vt, wt;
	// 注意先输入的边数，再输入的点数 
	cin >> m >> n;
	while (m--) {
		cin >> ut >> vt >> wt;
		add(ut, vt, wt), add(vt, ut, wt);
	}
	cout << dijkstra(1, n);
	return 0;
}
