#include <iostream>
using namespace std;
long long nums[100010];

// 和上一个题不太一样，这个题类似滑动窗口 

int main() {
	int n, k;
	cin >> n >> k;
	int temp;
	nums[0] = 0;
	for (int i = 1; i <= n; i++) cin >> temp, nums[i] = nums[i - 1] + temp;
	// 数据很大，本来开的无符号，但是考虑到后一个前缀和减前一个前缀和
	// 可能出现负值，所以又改回来了 
	long long ans = 0;
	// 下面k-1，所以最后一个元素算不到，还得加回来 
//	for (int i = 1; i <= n - k + 1; i++) {
//		// 和上一个题比变化的地方，首先是k-1，如果直接加k就多加了一个
//		// 元素，而题目要求的是连续的前缀和，而不是从i~k的前缀和，所以
//		// 这里还要把前一个前缀和减掉 
//		ans += nums[i + k - 1] - nums[i - 1];
//	}
	// 另外上面循环的写法有点绕，比较好的写法是i直接从k开始
	for (int i = k; i <= n; i++) {
		ans += nums[i] - nums[i - k];
	} 
	cout << ans << endl;
	return 0;
}
