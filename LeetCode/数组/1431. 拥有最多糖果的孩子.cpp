// ��ͯ�ڵĴ�ˮ�⣬ֻ�������Ѳ��Ƕ�ͯ����... 
class Solution {
public:
    vector<bool > res;
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxNum = 0;
        for (auto& i : candies) maxNum = max(maxNum, i);
        for (auto& i : candies) res.push_back(maxNum - i <= extraCandies);
        return res;
    }
};
