#include <iostream>
#define endl '\n'
using namespace std;
const int N = 100 + 10;
struct Node {
	int rmb, rp, tm;
} node[N];
int f[N][N];

/*
10
100 100 100
100 100 100
100 100 100
100 100 100
100 100 100
100 100 100
100 100 100
1 1 20
1 1 20
1 1 20
100 100
*/

int dfs(int level, int deepth, int r, int p) {
	
	if (f[r][p]) return f[r][p];
	
	if (level >= deepth) return 100010;

	int ra, rb;
		
	if (r - node[level].rmb >= 0 && p - node[level].rp >= 0)
		ra = dfs(level + 1, deepth, r - node[level].rmb, p - node[level].rp) + node[level].tm;
		
	rb = dfs(level + 1, deepth, r, p);
	
	cout << ra << ' ' << rb << endl;
	
	f[r][p] = min(ra, rb);
	
	return f[r][p];
}

int mxCnt = 0, res = 0;

void dfs2(int level, int deepth, int r, int p, int s, int cnt) {
	
	if (level >= deepth) {
		if (mxCnt < cnt) {
			mxCnt = cnt;
			res = s;
		}
		return;
	}
	
	if (r - node[level].rmb >= 0 && p - node[level].rp >= 0)
		dfs2(level + 1, deepth, r - node[level].rmb, p - node[level].rp, s + node[level].tm, cnt + 1);
 	dfs2(level + 1, deepth, r, p, s, cnt);	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, r;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> node[i].rmb >> node[i].rp >> node[i].tm;
	cin >> m >> r;
	dfs2(0, n, m, r, 0, 0);
	cout << res << endl;
	return 0;
}
