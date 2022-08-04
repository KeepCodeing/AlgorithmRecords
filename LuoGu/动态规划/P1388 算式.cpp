#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;
const int N = 20;
int nums[N];

int dfs(int i, int mul, int add, int sum) {
	
	if (mul) dfs(i + 1, mul - 1, add, sum * nums[i]);
	if (add) dfs(i + 1, mul, add - 1, sum + nums[i]);
	dfs(i + 1, mul, add, sum);
	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	dfs(1, k, n - k + 1, 0);
	return 0;
}
