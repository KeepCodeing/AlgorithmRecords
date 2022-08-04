#include <iostream>
using namespace std;

// 看起来可以拿来练下记忆化搜索.. 
// 调了半天，发现自己爆搜都有点倒车了w..不过以前也确实没注意过这个细节就是了.. 
// 在写DFS的时候，最重要的递归出口应该写在最前面，比如这个题，它如果写DFS其实有两个递归
// 出口，一个是所有树种完了的情况，还有就是没有树可以种了（数组出界），这里其之前把后者
// 写在了前面，由此导致的是所有树都种完了的情况只出现了一次...把正确的出口顺序改好就能
// 正常出结果了...另外这里还要和回溯对比下，其因为DFS写不出来写了个回溯，结果依然因为递归
// 出口的顺序坠毁了w...值得一提的是把下标出界这个出口注释了回溯确实正常运行了，但是为什么
// 这里回溯不用指定这个出口呢？答案就在它的循环里，其实这种情况已经被天然的剪去了，因为i
// 始终只能<=deepth的... 

const int N = 40;
int nums[N];
int res = -0x3fffffff;
int dfs(int level, int deepth, int m, int val) {
	// 注意出口顺序，重要的放前面.. 
	if (m == 0) return val;
	// 小心出界，这也是出口之一，另外因为DFS没有回溯那样的天然剪枝所以这个得特别写出来... 
	if (level > deepth) return -0x3fffffff;
	// 选当前树 
//	cout << dfs(level + 2, deepth, m - 1, val + nums[level]) << endl;
	res = max(dfs(level + 2, deepth, m - 1, val + nums[level]), res);
	// 不选当前树，不选没有返回值... 
	dfs(level + 1, deepth, m, val);
}
int main() {
	int n, m;
	cin >> n >> m;
	if (m > n / 2) {
		cout << "Error!" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	dfs(1, n, m, 0);
	cout << res << endl;
	return 0;
}
