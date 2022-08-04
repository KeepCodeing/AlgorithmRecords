#include <iostream>
using namespace std;

// 前缀和的作用就是快速查找某个区间[l,r]之前的和，有了前缀和就不用
// 每次都去找了，另外要注意边界问题，比较好的方法是S0设置为0，然后下标
// 从1开始 

// 考虑到数据全是最大的情况int可能存不下，所以用long了 
long nums[100010];
int main() {
	// 一般来说数据量大于100w就用scanf，否则用cin 
	// 关闭与C的输入输入的同步，可以加快读写速度 
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	nums[0] = 0;
	int num;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		// 前缀和公式，有点递推的感觉，另外因为第一个和为0而且
		// 下标从0开始，所以不用判断边界 
		nums[i] = nums[i - 1] + num;
	}
	// for (int i = 1; i <= n; i++) cout << nums[i] << endl;
	// 依次判断连续k个整数的区间和
	long ans = -1;
	for (int i = 1; i <= n - k; i++) {
		// 取值公式，就是把无关区间的项给消掉 
		ans = max(nums[i + k] - nums[i], ans);
	} 
	// 因为没打换行全WA了... 
	cout << ans << endl;
	return 0;
}
