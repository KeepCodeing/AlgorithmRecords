#include <iostream>
#define endl '\n'
using namespace std;
const int N = 2500 + 10;
int nums[N];
int n, m;

int dfs(int level, int deepth, int sum, int cnt) {
	
	if (level >= deepth) {
		cout << sum << endl;
		return 0;
	}
	dfs(level + 1, deepth, sum + nums[level], cnt - 1);
	dfs(level + 1, deepth, sum, cnt);	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> nums[i];
	dfs(0, n, 0, n);
	return 0;
}
