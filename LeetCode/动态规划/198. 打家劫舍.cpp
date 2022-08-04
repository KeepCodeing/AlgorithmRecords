#include <iostream>
#include <vector>
using namespace std;

// 分析：还是选或不选的问题，因为这个题要求不能连着选，所以我们要考虑
// 的就是选当前房子之前的值大还是选当前房子，不选当前房子之前的值大

// dp[i-1]前面房子的价值和，dp[i-2]+num[i]，不选前一个房子，选相邻
// 的房子 

class Solution {
public:
    int rob(vector<int>& nums) {
    	// 特判 
    	if (nums.size() == 0 || nums.empty()) return 0;
        // 假设dp[i]表示到i号房子最大的价值
        int nLen = nums.size();
        int dp[nLen + 1];
        // 之前把0的边界条件写成了nums[0]，不合理 
        dp[0] = 0;
        // 设置边界条件 
		dp[1] = nums[0];
		for (int i = 2; i <= nLen; i++) {
			// 比较是前面元素的和大还是当前元素加相邻元素和大 
			dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
		}
		return dp[nLen];
	}
};

int main() {
	
	return 0;
}
