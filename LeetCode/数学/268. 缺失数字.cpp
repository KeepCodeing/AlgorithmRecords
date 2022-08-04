// 0~n少一个数字，能想到求和然后做差得到的就是那个数字.. 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nsum = 0, nLen = nums.size();
        for (auto& i : nums) nsum += i;
        return nLen * (1 + nLen) / 2 - nsum;
    }
};
