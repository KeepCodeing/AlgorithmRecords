#include <iostream>
using namespace std;

// 类似斐波那契数列... 

class Solution {
public:
    int tribonacci(int n) {
        int num[40];
        num[0] = 0, num[1] = num[2] = 1;
        for (int i = 3; i <= n; i++) {
        	num[i] = num[i - 3] + num[i - 2] + num[i - 1];
		}
		// LeetCode直接new数组会报错，即是删除了也不行，所以这里用个
		// 定长数组 
		return num[n];
    }
};
int main() {
	int n;
	cin >> n;
	Solution s = Solution();
	cout << s.tribonacci(n); 
	return 0;
}
