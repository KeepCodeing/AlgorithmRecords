#include <iostream>
using namespace std;

// ���仯������
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

// ��̬�滮�� 
class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        // �߽�����
        // ����һ����ʼ����0����֪1�������ֻ��һ�����
        dp[0] = dp[1] = 1;
        // ����dp[i]Ϊ���Ž⣬״̬ת�Ʒ����հ�
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
