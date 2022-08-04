#include <iostream>
using namespace std;
const int N = 3010;
typedef long long LL;
int nums[N];
// 方案数可能会很大 
LL f[N];
int main() {
	int n, m;
	cin >> n >> m;
	// 注意初始化，不然答案永远为0... 
	f[0] = 1;
	// 这个地方可以直接改成求完全背包方案数 
	for (int i = 1; i <= n; i++) cin >> nums[i];
	for (int i = 1; i <= n; i++) {
		for (int j = nums[i]; j <= m; j++) {
			f[j] += f[j - nums[i]];
		}
	}
	cout << f[m];
	return 0;
}
