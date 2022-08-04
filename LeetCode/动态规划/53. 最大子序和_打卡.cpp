#include <iostream>
using namespace std;

// 明明是模板题却还是WA了两次（无能）
// 最后一步，最后一步即选第j个数当前子序和最大，那么子问题就是使得前j-1个元素的和最大，于是
// 状态转移方程就是f[i] = max{f[i - 1] + nums[i]}，但是这里这个状态转移方程是有问题的，我们要求前j-1个元素和最大
// 也就需要保证加上nums[i]不会使得总和更小（也可能是是小于0），于是正确的状态转移方程应该是f[i] = max{nums[i], f[i - 1] + nums[i]}
// so...还是比较蒙w，总之多大几遍算是有点门道了，但是还是不能自己推出正确的方程，或者写不出程序之类的...主要是初始化
// 和状态转移方程的问题... 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nLen = nums.size();
        if (nLen == 1) return nums[0];
        int f[nLen + 10], res = -0x3fffffff;
        f[0] = nums[0];
        for (int i = 1; i < nLen; i++) {
            f[i] = max(nums[i], f[i - 1] + nums[i]);
            res = max(res, f[i]);
        }
        // for (int i = 0; i < nLen; i++) res = max(res, f[i]);
        return res;
    }
};

int main() {
	return 0;
}
