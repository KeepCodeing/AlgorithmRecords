#include <iostream>
#define endl '\n'
using namespace std;
const int N = 2000 + 10;
int nums[N], f[N][N];
int mx = 0;

int dfs(int level, int dep, int left, int day) {
	if (f[level][day]) return f[level][day];
	
	if (!left) return 0;
	
	f[level][day] = max(
		dfs(level + 1, dep, left - 1, day + 1) + nums[level] * day, 
		dfs(level, dep - 1, left - 1, day + 1) + nums[dep] * day
	);
	
	return f[level][day];
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	cout << dfs(0, n - 1, n, 1) << endl;
	return 0;
}
