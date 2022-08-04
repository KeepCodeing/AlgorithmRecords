#include <iostream>
using namespace std;

// 定义f[i]为以nums[i]为结尾的最大上升子序列和，那么可以根据前面的知识得到f[i] = max(f[i], f[j] + nums[j]) 

const int N = 300 + 10;
int nums[N], f[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	for (int i = 1; i <= n; i++) {
		f[i] = nums[i];
		for (int j = 1; j < i; j++) {
			// 注意这里的定义：是以nums[i]为结尾的上升子序列的最大和，那么如果我们选了f[j]，也就是以nums[j]结尾
			// 的上升子序列的最大和，它后面就只能选nums[i]了，之前写的nums[j]，大概是没明白状态的定义... 
			if (nums[i] > nums[j]) f[i] = max(f[i], f[j] + nums[i]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) cout << f[i] << endl;
	cout << ans << endl;
	return 0;
}
