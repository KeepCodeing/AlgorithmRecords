#include <iostream>
#include <vector>
using namespace std;

// ����¥�ݵĻ���������˼�ֵ
// ��¥����ĺ��ľ���ǰһ���Ĳ�����ǰǰһ���Ĳ����������ڴ˻��������ǻ���ֻ���о��߷���Ȼ�����Ǯ����

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    	if(cost.size() == 0) return 0;
    	int cLen = cost.size();
        int dp[cLen];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cLen; i++) {
        	dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
		}
		return min(dp[cLen - 1], dp[cLen - 2]);
    }
}; 

int main() {
	return 0;
}
