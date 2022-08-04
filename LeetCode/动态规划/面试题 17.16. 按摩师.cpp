#include <iostream>
#include <vector>
using namespace std;

// 因为池沼只能想出一半的状态转移方程
// 首先考虑最后一步，最后一个选择的元素一定是第i个位置的元素，又因为不能选择相邻的元素，因此子问题就是
// i - 2
// 那么我们的状态转移方程就应该是f[i] = max{f[i - 2] + nums[i], f[i - 1]}，这里其就没想出来不选的情况是
// 怎么判断，不选的情况就是当前最大收益就是上次的最大收益...
// 另外这个题的初始条件也很特殊，首先想下只有一个元素的情况，那最大收益就是这个元素，再想下有两个元素的情况
// 那最大收益就是这个两个元素的最大值，由此，f[0] = nums[0], f[1] = max(nums[0], nums[1])，这样就可以对付
// 上面说的情况了..，还有就是下标，很迷，用1开始和用0开始是有区别的... 

class Solution {
public:
    int massage(vector<int>& nums) {
		int nLen = nums.size();
		if (nLen == 0) return 0;
		if (nLen == 1) return nums[0];
		int f[nLen + 10];
		f[0] = nums[0];
		f[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nLen; i++) 
			f[i] = max(f[i - 1], f[i - 2] + nums[i]);
		return f[nLen];
    } 
}; 

int main() {
	return 0;
}
