#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // ˼·����֤ǰ��ĺͼӵ�ǰ���������
        int n = nums.size();
        int dp[n + 1] = {0};
        dp[0] = 0;
        // ���µ�ǰ���ֵ 
        for (int i = 1; i <= n; i++) {
            // ���ǰ���������0��˵������ֵ�Ż����ӣ��෴�����粻��,nums���±��0��ʼ������Ҫi-1
            dp[i] = max(dp[i - 1], 0) + nums[i - 1];
        }
        // ���´�
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
