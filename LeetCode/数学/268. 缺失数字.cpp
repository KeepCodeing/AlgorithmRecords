// 0~n��һ�����֣����뵽���Ȼ������õ��ľ����Ǹ�����.. 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nsum = 0, nLen = nums.size();
        for (auto& i : nums) nsum += i;
        return nLen * (1 + nLen) / 2 - nsum;
    }
};
