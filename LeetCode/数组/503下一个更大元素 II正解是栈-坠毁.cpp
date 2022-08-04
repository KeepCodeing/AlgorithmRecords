#include <iostream>
#include <vector>
using namespace std;
// 分析：循环查找有点像旋转字符串，可以将数组扩大一次然后用两个循环找元素
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int > temp, result;
        temp = nums;
        int nLen = nums.size(), index, tIndex;
        // 扩大数组 
        for (int i = 0; i < nLen; i++) temp.push_back(nums[i]);
        
        for (int i = 0; i < nLen; i++) {
        	index = -1;
        	tIndex = 0;
        	for (int j = nLen; j < 2 * nLen; j++) {
        		tIndex++;
        		if (temp[i] < temp[j]) {
        			index = tIndex;
        			break;
				}
			}
			result.push_back(index);
		}
		for (int i = 0; i < result.size(); i++) cout << result[i] << ' ';
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<int > v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	s.nextGreaterElements(v); 
	return 0;
}
