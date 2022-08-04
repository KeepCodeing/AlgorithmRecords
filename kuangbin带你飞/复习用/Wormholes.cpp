#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 500 + 10, M = 2700 * 2 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
bool visited[N];
int dist[N], cnt[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
} 
string spfa(int st, int n) {
	memset(visited, 0, sizeof visited);
	memset(dist, 0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	queue<int > que;
	que.push(st);
	dist[st] = 0;
	while (que.size()) {
		int ut = que.front();que.pop();
		visited[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				if (!visited[vt]) {
					visited[vt] = true;
					cnt[vt]++;
					// 这里应该是>=n因为最坏情况下存在的最短路径经过的点都只有n - 1个... 
					if (cnt[vt] >= n) return "YES";
					que.push(vt);
				}
			}
		}
	}
	return "NO";
}
int main() {
	int F, n, m, t;
	int ut, vt, wt;
	scanf("%d", &F);
	while (F--) {
		memset(head, -1, sizeof head);
		scanf("%d%d%d", &n, &m, &t);
		while (m--) {
			scanf("%d%d%d", &ut, &vt, &wt);
			add(ut, vt, wt);
			add(vt, ut, wt);
		}
		while (t--) {
			scanf("%d%d%d", &ut, &vt, &wt);
			add(ut, vt, -wt);
		}
		cout << spfa(1, n) << endl;
	}
	return 0;
}
