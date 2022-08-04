// 儿童节的打卡水题，只不过早已不是儿童了呢... 
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
