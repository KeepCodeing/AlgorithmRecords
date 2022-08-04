#include <iostream>
using namespace std;

// 记忆化搜索版
class Solution1 {
public:
	int dfs(int n, int dp[]) {
		if (n <= 1) return 1;
		if (dp[n] != -1) return dp[n];
		dp[n] = dfs(n - 1, dp) + dfs(n - 2, dp);
		return dp[n];
	}
	int climbStairs(int n) {
		int dp[n + 1] = {-1};
		
		return dfs(n, dp);
	}
};

// 动态规划版 
class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        // 边界条件
        // 假设一个起始条件0，已知1步的情况只有一种情况
        dp[0] = dp[1] = 1;
        // 假设dp[i]为最优解，状态转移方程照搬
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main() {
	Solution s = Solution();
	cout << s.climbStairs(3); 
	return 0;
}
