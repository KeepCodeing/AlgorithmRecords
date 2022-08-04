// 首先可以看出来这是个类似子集问题的题，因为它没有明确的出口条件...其次这个题有点坑的是要去重，而且只有当序列不是单调的时候
// 才用去重，这是因为如果一个类似[1, 2, 3, 1, 1, 1]的序列进行回溯，第一个1就会包括后面三个1的答案，因为这三个1就是最前面的1
// 的一个子序列...再者这里其没有用判断最后一个元素的方法判断是否递增，而是用now和pre两个参数来进行判断，详情见下... 
class Solution {
public:
    vector<int > nums, temp;
    vector<vector<int>> res;
    set<vector<int >> st;
    void dfs(int level, int deepth, int now, int pre) {
        if (temp.size() >= 2 && !st.count(temp)) res.push_back(temp), st.insert(temp);
        for (int i = level; i < deepth; i++) {
        	// 剪枝，可以去掉递增序列的重复，不过上面加了set去重就没多大必要写这个了 
            if (i > level && nums[i] == nums[i - 1]) continue;
            // 剪枝，因为nums[i]会作为now变成下一个开始的元素，而now会变成pre，如果要保证序列递增就得保证上一个元素
			// 小于当前元素（等于也是可行的，题目提到了） 
            if (nums[i] < now) continue;
            // 普通回溯套路 
            temp.push_back(nums[i]);
            dfs(i + 1, deepth, nums[i], now);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.empty()) return res;
        this->nums = nums;
        // 注意这里，我们从第0个元素开始，而按照上面说的，这一层开始的元素不能是第0个元素，因为这样的话上一个元素和这个
		// 元素就是一样的了，也就是我们把当前元素当成了0，上一个元素当成了-1000，那么进入第一个递归后， nums[i]的i一定
		// 是0，now一定也是nums[0]，这就导致第一个dfs的now == pre == nums[0]，对于[100, 90, 80, 90, 100]这种数据，就会
		// 出现错误，也就是因为pre == now == 100，它只能得到[100, 100]这个答案，因为下一个90绝对是小于now == 100的...那么
		// 反过来，将now设置为-1000，pre设置为nums[0]就不会有问题了，这样的话dfs的pre == -1000, now == nums[0]，然后依次
		// 类推，碰到上面那个数据回溯时now == -1000了，也就是任何一个位置的答案都会被统计... 
        dfs(0, nums.size(), -1000, nums[0]);
        return res;
    }
};

