#include <iostream>
#include <queue>
using namespace std;
const int N = 100010, M = 2 * N;
int head[N], e[M], ex[M], idx = 0;
int indg[N], topu[N];
void add(int k, int val) {
	e[idx] = val, ex[idx] = head[k], head[k] = idx++;
}
int n, m;
bool topusort() {
	queue<int > que;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!indg[i]) {
			que.push(i);
			topu[++cnt] = i;
		}
	}
	int u;
	while (!que.empty()) {
		u = que.front();que.pop();
		for (int i = head[u]; i != -1; i = ex[i]) {
			int j = e[i];
			indg[j]--;
			if (!indg[j]) {
				que.push(j);
				topu[++cnt] = j; 
			}
		}
	}
	if (cnt == n) return true;
	return false;
}
int main() {
	fill(head, head + N, -1);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		indg[v]++;
		add(u, v);
	}
	if (topusort()) {
		for (int i = 1; i <= n; i++) cout << topu[i] << ' ';
	} else {
		cout << -1;
	}
	return 0;
}
