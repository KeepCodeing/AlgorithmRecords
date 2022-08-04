#include <iostream>
using namespace std;
const int N = 2010, M = 8010;
int head[M], e[M], ex[M], idx = 0;
int cnt[N];
bool visited[N];
int x, y;
void add(int u, int v) {
	e[idx] = u, ex[idx] = head[v], head[v] = idx++;
}
void dfs(int cur) {
	visited[cur] = true;
	if (cur == y) {
		cnt[cur]
	}
	visited[cur] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int n, ee;
	cin >> n >> ee;
	
	while (ee--) {
		cin >> x >> y;
		add(x, y), add(y, x);
	}
	
	return 0;
}
