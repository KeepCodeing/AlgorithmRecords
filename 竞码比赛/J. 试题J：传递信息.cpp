#include <iostream>
using namespace std;
const int N = 5 * 10000 + 10, M = 200000 + 10;
int head[M], e[M], ex[M], w[M], idx = 0;
bool visited[N];
// 因为变量名一样而忘记了怎么存图的池沼*愤怒* 
void add(int k, int vi, int wi) {
	e[idx] = vi, w[idx] = wi, ex[idx] = head[k], head[k] = idx++;
}
int n, m, s, t;
unsigned long long res = 0x3fffffff;
// 1073741823
// 10000000000
void dfs(int st, unsigned long long minVal) {
	if (minVal >= res) return;
	visited[st] = true;
	if (st == t) {
		//cout << minVal << endl;
		res = min(minVal, res);
		visited[t] = false;
		return;
	}
	for (int i = head[st]; i != -1; i = ex[i]) {
		int j = e[i];
		if (visited[j]) continue;
		dfs(j, minVal * w[i]);
	}
	visited[st] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(head, head + M, -1);
	cin >> n >> m >> s >> t;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	dfs(s, 1);
	cout << res;
	return 0;
}
