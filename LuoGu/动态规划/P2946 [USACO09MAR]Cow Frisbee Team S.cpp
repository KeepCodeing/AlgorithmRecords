#include <iostream>
#define endl '\n'
using namespace std;
const int N = 2000 + 10;
int nums[N];
int f[N][2];
int n, x, cnt = 0;

int dfs(int level, int deepth, int sum) {
	
//	if (f[level]) return f[level];
	
	if (level >= deepth) return sum !=0 && !(sum % x);
	
	f[level][0] += dfs(level + 1, deepth, sum + nums[level]);
	f[level][1] += dfs(level + 1, deepth, sum);
	
	return max(f[level][0], f[level][1]);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> nums[i];
	
	cout << dfs(0, n, 0) % (100000000) << endl;
	
	return 0;
}
