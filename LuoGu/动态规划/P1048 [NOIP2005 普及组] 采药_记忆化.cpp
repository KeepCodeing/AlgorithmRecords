#include <iostream>
#define endl '\n'
using namespace std;

const int N = 1e4 + 10, M = 1e7 + 10;
long long c[N], v[N];
long long f[M];

long long dfs(int cost, int left) {
	if (f[cost]) return f[cost];
	if (!left) return 0;
	
	int r1 = 0, r2 = 0;
	if (cost - c[left] >= 0) r1 = dfs(cost - c[left], left) + v[left];
	r2 = dfs(cost, left - 1);
	
	return f[cost] = max(r1, r2);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> c[i] >> v[i];
	cout << dfs(n, m);
	return 0;
} 
