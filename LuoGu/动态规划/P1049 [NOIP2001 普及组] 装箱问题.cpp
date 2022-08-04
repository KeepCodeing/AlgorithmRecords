#include <iostream>
#define endl '\n'
using namespace std;
const int N = 30 + 10, M = 20000 + 10;
int nums[N];
int f[N][M];

int dfs(int i, int m) {
	
	if (f[i][m]) return f[i][m];
	
	if (i < 1) return 0;
//	if (m < 0) return 0;
	int r1 = -999999, r2 = -999999;
	if (m >= nums[i]) r1 = dfs(i - 1, m - nums[i]) + nums[i];
	r2 = dfs(i - 1, m);
		
	return f[i][m] = max(r1, r2);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> m;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	cout << m - dfs(n, m);
	return 0;
}
