#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 主要是个去重的问题（对）

// 这个题不能重复用元素，所以相对上一题来说就是选一个少一个，去重大概不需要，需要去重的题目
// 应该是类型全排列II，子集这种问题（误）

// 啊这...害得用pre记录上一个元素来去重

// 为什么要去重？
// 因为可能有相同的值的子节点，那么这样的话就会相应的产生相同的分支
// 而一个合法分支只能用一次，所以需要去重，那么这样的话如果有重复元素
// 就需要进行去重，因为树的特性 

class Solution {
public:
	vector<vector<int> > result;
	void dfs(int level, int deepth, int target, vector<int >& temp, vector<int >& candidates) {
		if (target < 0) return;
		if (target == 0) {
			result.push_back(temp);
			return; 
		}
		int pre = candidates[0] - 1;
		for (int i = level; i < deepth; i++) {
			// 剪枝 
			if (candidates[i] > target || pre == candidates[i]) continue;
			target -= candidates[i];
			temp.push_back(candidates[i]); 
			dfs(i + 1, deepth, target, temp, candidates);
			target += candidates[i];
			temp.pop_back();
			pre = candidates[i];
		}
	}
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0 || candidates.empty()) return result;
        vector<int > temp;
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates.size(), target, temp, candidates);
        return result;
    }
};
int main() {
	Solution s = Solution();
	vector<int > v;
	v.push_back(10); 
	v.push_back(1); 
	v.push_back(2); 
	v.push_back(7); 
	v.push_back(6); 
	v.push_back(1); 
	v.push_back(5); 
	vector<vector<int > > r = s.combinationSum2(v, 8); 
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
