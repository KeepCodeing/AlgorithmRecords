#include <iostream>
#include <vector>
#include <map>
// 两数之和，用哈希表解就完事了
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int > m;
        int nLen = nums.size();
        for (int i = 0; i < nLen; i++) {
        	// 如果找到了另一个数，返回下标 
        	if (m.count(target - nums[i])) {
        		vector<int > result(2);
        		result[0] = m[target - nums[i]];
        		result[1] = i;
        		return result;
			}
			// 否则记录当前数及其下标 
			m[nums[i]] = i; 
		}
		// 注意这一句，和洛谷一样，最终必须有个返回值，不然无法编译 
		return result;
    }
};
int main() {
	Solution s = Solution();
	 
	return 0;
}
