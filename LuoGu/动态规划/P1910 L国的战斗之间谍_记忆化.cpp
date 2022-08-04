#include <iostream>
#define endl '\n'
using namespace std;
const int N = 100 + 10, M = 1000 + 10, X = 1000 + 10;
int val[N], c1[N], c2[N];
int f[N][M][M];
int dfs(int cost1, int cost2, int left) {
	if (!left) return 0;
	if (f[left][cost1][cost2]) return f[left][cost1][cost2];
	
	int r1 = 0, r2 = 0;
	if (cost1 - c1[left] >= 0 && c2 - c1[left] >= 0)
		r1 = dfs(cost1 - c1[left], cost2 - c2[left], left - 1) + val[left];
	r2 = dfs(cost1, cost2, left - 1);
	
	return f[left][cost1][cost2] = max(r1, r2);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) cin >> val[i] >> c1[i] >> c2[i];
	cout << dfs(m, x, n);
	return 0;
}
