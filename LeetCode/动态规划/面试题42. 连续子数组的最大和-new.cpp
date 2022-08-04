#include <iostream>
using namespace std;

// 之前太naive基本是看题解写的，这里看了教程再写一遍...
// 首先确认最后一步，最后一个选择的元素一定是第i个位置的元素，那么子问题就变成了i - 1位置的元素的和最大，
// 由此可以得到动态转移方程为f[i] = max{f[i - 1] + nums[i]}，再考虑下如何使得和最大，题解给的解法是只要
// f[i - 1] + nums[i] > nums[i]就行，也就是当前和>0，迷...，暂且不写代码... 
 
int main() {
	return 0;
}
