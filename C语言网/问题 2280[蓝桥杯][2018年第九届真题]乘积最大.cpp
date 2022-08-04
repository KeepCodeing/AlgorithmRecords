#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010, mod = 1e9 + 7;
typedef long long LL;
int nums[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums, nums + n);
	LL ans1 = 1, ans2 = 1;
	for (int i = 0; i < k; i++) ans1 *= nums[i] % mod;
	for (int i = n - 1, j = 0; j < k; j++, i--) ans2 *= nums[i] % mod;
	cout << ans1 << ans2;
	cout << max(ans1, ans2);
	return 0;
}
