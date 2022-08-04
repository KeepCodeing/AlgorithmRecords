#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 思路：保证前面的和加当前数更大就行
        int n = nums.size();
        int dp[n + 1] = {0};
        dp[0] = 0;
        // 更新当前最大值 
        for (int i = 1; i <= n; i++) {
            // 如果前面的数大于0，说明加上值才会增加，相反还不如不加,nums的下标从0开始，所以要i-1
            dp[i] = max(dp[i - 1], 0) + nums[i - 1];
        }
        // 更新答案
        int ans = dp[1];
        for (int i = 2; i <= n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
int main() {
	return 0;
}
