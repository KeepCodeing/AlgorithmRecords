#include <iostream>
#include <algorithm>
using namespace std;
// 分析：基础数学问题，有坑，比如负数，出界的问题等 

class Solution {
public:
    bool isPalindrome(int x) {
    	// 防止0除 
    	if (x == 0) return true;
    	// 该题描述的是读起来，所以负数一定不行 
    	if (x < 0) return false;
        // int r = 0, t = x;
        // 直接翻转可能会出现超过int数据范围的情况 
        // 翻转成字符串对比（无能） 
        int t = x;
        string r1, r2;
        while (t) {
        	r1 += (char)((t % 10) + '0');
        	t /= 10;
		}
		r2 = r1;
		reverse(r1.begin(), r1.end());
		return r1 == r2;
    }
};
int main() {
	Solution s = Solution();
	cout << s.isPalindrome(111); 
	return 0;
}
