#include <iostream>
#define endl '\n'
using namespace std;

const int N = 100 + 10;
int nums[N], f[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	// 可以优化，只用求一次LIS和反序LIS，然后枚举中点算max(f1[i] + f2[i] - 1)...
	// 为什么可以这样呢？因为我们的状态定义就是f[i]为nums[i]结尾时的LIS长度，重复计算是没必要的... 
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	
	// 以i为中心，求[1, k]的递增子序列，再求[k, n]的递减子序列，然后
	// [max(f1) + max(f2)]就是以i为中心最多能留下多少人，那么用n减去
	// 就得到了最少要去掉的人的数量（注意这里k两个地方都用到了，这是
	// 因为k-1 < k > k + 1 
	
	int lis = 0, lms = 0, ans = 9999999;
	for (int k = 1; k <= n; k++) {
		lis = 0, lms = 0;
		// 求最长上升子序列 
		for (int i = 1; i <= k; i++) {
			f[i] = 1;
			for (int j = 1; j < i; j++) {
				if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
			}
			lis = max(lis, f[i]);
		} 
		// 求最长下降子序列（其实就是从尾部开始求最长上升子序列，从右向左
		// 看可以发现这种方向的递增从左向右看是递减...），
		// 这里因为要求多次所以每次将数组反过来明显不明智
		for (int i = n; i >= k; i--) {
			f[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
			}
			lms = max(lms, f[i]);
		} 	
		// 注意最后要-1，这是因为nums[k]的贡献会被算两次，可以想下一下这样一个极端例子，lis = 1, lms = 1，也就是
		// 说只有k的时候，我们算出来的是2，所以要减去这个重复算的值 
		ans = min(ans, n - (lis + lms - 1));
	}
	cout << ans << endl;
	return 0;
}
