#include <iostream>
#define endl '\n'
using namespace std;
const int N = 100 + 10;
struct Node {
	int rmb, rp, tm;
} node[N];
int f[N][N];

int dfs(int level, int deepth, int r, int p) {
	
	if (f[r][p]) return f[r][p];
	
	if (level >= deepth) return 0;

	int ra, rb;
		
	if (r - node[level].rmb >= 0 && p - node[level].rp >= 0)
		ra = dfs(level + 1, deepth, r - node[level].rmb, p - node[level].rp) + node[level].tm;
		
	rb = dfs(level + 1, deepth, r, p);
	
	f[r][p] = min(ra, rb);
	
	return f[r][p];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, r;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> node[i].rmb >> node[i].rp >> node[i].tm;
	cin >> m >> r;
	cout << dfs(0, n, m, r) << endl;
	return 0;
}
