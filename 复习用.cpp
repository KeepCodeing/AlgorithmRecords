#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;

const int N = 1e5 + 10, M = N * 2; 
int head[N], e[M], ex[M], w[M], idx = 0;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dist[N];
bool vis[N];
int spfa(int st, int ed) {
	memset(dist, 0x3f, sizeof head);
	que.push(st);
	dist[st] = 0;
	while (que.size()) {
		int ut = que.front(); que.pop();
		vis[ut] = false;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (dist[vt] > dist[ut] + w[i]) {
				dist[vt] = dist[ut] + w[i];
				if (!vis[vt]) {
					que.push(vt);
					vis[vt] = true;
				}
			}
		}
	}
}

int main() {
	memset(head, -1, sizeof head);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, ut, vt, wt;
	cin >> n >> m;
	while (m--) {
		cin >> ut >> vt >> wt;
		add(ut, vt, wt);
		add(vt, ut, wt);
	}
	return 0;
}
