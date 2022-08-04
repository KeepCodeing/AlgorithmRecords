#include <iostream>
#include <vector>
using namespace std;

// 在走楼梯的基础上添加了价值
// 走楼梯题的核心就是前一步的步数加前前一步的步数，所以在此基础上我们还是只需列举走法，然后加上钱即可

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
