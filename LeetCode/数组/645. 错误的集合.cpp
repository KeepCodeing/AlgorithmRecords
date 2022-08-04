// 为了今天的刷三题积分，水了一个原题，还有这个题... 
// [1,2,3,4, 4, 4, 5]自己的测试数据... 
class Solution {
public:
    vector<int > vec;
    set<int > st;
    vector<int> findErrorNums(vector<int>& nums) {
        bool flag = true;
        // 直接开个set，把所有数字放进去，然后判断下是否重复出现，如果是第一次重复出现，作为答案.. 
        for (auto& i : nums) {
            if (st.count(i) && flag) vec.push_back(i), flag = !flag;
            st.insert(i);
        }
        // 这个地方可以省去，就是为了找下那个数字不在集合里，但是按照集合单调递增的特征，可以很明显的发现
		// 如果上面i - 1不在集合里，那么i - 1就是缺失的数字....试了下似乎不可行w... 
        for (int i = 1; i <= nums.size(); i++) {
            if (!st.count(i)) {
                vec.push_back(i);
                break;
            }
        }
        return vec;
    }
};
