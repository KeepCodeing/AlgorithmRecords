#include <iostream>
#include <vector>
using namespace std;
// 分析：我们可以排序后返回arr.size()/2处的元素，该元素一定是众数，但是这样效率太低。
// 同样，我们可以用HashTable计数，但这样需要额外空间。如果追求最高效率的话，我们就需要
// 用到Boyer-Moore 投票算法，该算法的核心思想就是用一个计数器判断当前元素的出现次数
// 碰到不同元素计数器-1，反之+1，如果计数器为0了，说明当前元素不是众数，这时我们可以
// "忘掉"之前的数，更新一个新的众数，因为我们舍去了相同数量的非众数与众数，所以对结果
// 并不产生影响
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, result;
        int nLen = nums.size();
        for (int i = 0; i < nLen; i++) {
        	// 更新当前众数 
        	if (cnt == 0) result = nums[i];
        	// 更新计数器 
			cnt += nums[i] == result ? 1 : -1;
		}
		return result;
    }
}; 
int main() {
	return 0;
}
