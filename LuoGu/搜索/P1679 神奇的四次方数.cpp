#include <iostream>
using namespace std;
const int LEN = 18;

// 思路就是枚举所有可能，正解是完全背包，不过爆搜加剪枝也能过 

int nums[LEN] = {1,16,81,256,625,1296,2401,4096,6561,10000,14641,20736,28561,38416,50625,65536,83521,104976};
int minCnt = 0x3FFFFFFF;
void dfs(int level, int num, int cnt, int used) {
	if (num <= 0) {
		if (num == 0) {
			minCnt = min(minCnt, cnt);
		}
		return;
	}
	for (int i = level; i >= 0; i--) { 
		// 必要的剪枝，虽然n不大，但是如果枚举到了很小的数，比如1
		// 程序就会卡死 
		// 那么这样也就是说并不是完完全全依赖记忆化，虽然重叠子问题依然无法得到解决
		// 但是我们可以记录一个最优解，借此进行剪枝 
		if (used >= minCnt) continue;
		dfs(i, num - nums[i], cnt + 1, used + 1);
	}
}

int main() {
	int n;
	cin >> n;
	int deepth = lower_bound(nums, nums + LEN, n) - nums;
	dfs(deepth, n, 0, 0);
	cout << minCnt;
	return 0;
}
