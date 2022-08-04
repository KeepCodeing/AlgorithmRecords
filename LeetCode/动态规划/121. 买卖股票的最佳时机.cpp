#include <iostream>
#include <vector>
using namespace std;

// 思路：比较当前收益是否大于当前股票数减去最小股票数即可 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int pLen = prices.size();
        int minSum = prices[0], maxSum = 0;
        for (int i = 1; i < pLen; i++) {
        	maxSum = max(maxSum, prices[i] - minSum);
        	minSum = min(minSum, prices[i]);
		}
        return maxSum;
    }
};

int main() {
	Solution s = Solution();
	vector<int > v;
	// [7,1,5,3,6,4]
	v.push_back(7); 
	v.push_back(1); 
	v.push_back(5); 
	v.push_back(3); 
	v.push_back(6); 
	v.push_back(4); 
	
	cout << s.maxProfit(v); 
	return 0;
}
