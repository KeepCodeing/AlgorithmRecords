#include <iostream>
#include <vector>
using namespace std;

// ����������ѡ��ѡ�����⣬��Ϊ�����Ҫ��������ѡ����������Ҫ����
// �ľ���ѡ��ǰ����֮ǰ��ֵ����ѡ��ǰ���ӣ���ѡ��ǰ����֮ǰ��ֵ��

// dp[i-1]ǰ�淿�ӵļ�ֵ�ͣ�dp[i-2]+num[i]����ѡǰһ�����ӣ�ѡ����
// �ķ��� 

class Solution {
public:
    int rob(vector<int>& nums) {
    	// ���� 
    	if (nums.size() == 0 || nums.empty()) return 0;
        // ����dp[i]��ʾ��i�ŷ������ļ�ֵ
        int nLen = nums.size();
        int dp[nLen + 1];
        // ֮ǰ��0�ı߽�����д����nums[0]�������� 
        dp[0] = 0;
        // ���ñ߽����� 
		dp[1] = nums[0];
		for (int i = 2; i <= nLen; i++) {
			// �Ƚ���ǰ��Ԫ�صĺʹ��ǵ�ǰԪ�ؼ�����Ԫ�غʹ� 
			dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
		}
		return dp[nLen];
	}
};

int main() {
	
	return 0;
}
