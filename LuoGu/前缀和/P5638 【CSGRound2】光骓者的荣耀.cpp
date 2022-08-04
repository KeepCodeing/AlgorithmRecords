#include <iostream>
using namespace std;
long nums[1000010];
int main() {
	int n, k;
	cin >> n >> k;
	int temp;
	nums[0] = 0;
	for (int i = 1; i <= n - 1; i++) cin >> temp, nums[i] = nums[i] + temp;
	long ans = 0x3FFFFFFF;
	for (int i = 1; i <= n - k; i++) {
		ans = min(nums[i + k] - nums[i], ans);
	}
	cout << ans;
	return 0;
} 
