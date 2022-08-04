#include <iostream>
#include <vector>
using namespace std;
// 分析：暂且打算用异或作，题目要求不使用任何额外空间，且复杂度为O(n)，感觉这是唯一算法
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    	// 为空的判断，LeetCode上这似乎是必须的 
    	if (nums.size() == 0 || nums.empty()) return nums;
    	int nLen = nums.size();
    	int x = 0;
    	
        for (int i = 0; i < nLen; i++) {
        	x ^= nums[i];
        	cout << x << endl;
		}
		cout << x << endl;
		cout << '-' << endl;
		for (int i = 0; i < nLen; i++) {
        	x ^= nums[i];
        	cout << nums[i] << endl;
		}
		return nums;
    }
}; 
int main() {
	Solution s = Solution();
	vector<int > v;
	// 4,3,2,7,8,2,3,1
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(7);
	v.push_back(8);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	s.findDuplicates(v); 
	return 0;
}
