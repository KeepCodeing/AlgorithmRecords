#include <iostream>
#include <vector>
using namespace std;
// 感觉这个题可重复使用的条件有点类似电话号码组合那题，就是要在层次的增加这里进行操作 

// 原来电话号码组合那个题把level写成i是因为这一题的原因，这一题没有哪一题的多个“选择方案”
// 所以不需要额外指定下一层遍历那些选择 

class Solution {
public:
	vector<vector<int> > result;
	// 据说vector加个&引用符可以加快运行速度？ 
	void dfs(int level, int deepth, int target, int sum, vector<int >& temp, vector<int>& candidates) {
		// 解不合法，当然这也可以写在循环里 
		if (sum > target) return;
		if (sum == target) {
			result.push_back(temp); 
			return;
		}
		for (int i = level; i < deepth; i++) {
			sum += candidates[i];
			temp.push_back(candidates[i]); 
			// 核心思路：如果这里sum不满足解，回溯到上一层时i就会进行自增，这样再次进行递归时
			// 就会用下一个数 
			dfs(i, deepth, target, sum, temp, candidates);
			sum -= candidates[i];
			temp.pop_back();
		}
	}
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0 || candidates.empty()) return result;
        vector<int > temp;
        dfs(0, candidates.size(), target, 0, temp, candidates);
        return result;
    }
};
int main() {
	vector<int > c;
	vector<vector<int > > result;
	c.push_back(2);
	c.push_back(3);
	c.push_back(6);
	c.push_back(7);
	Solution s = Solution();
	result = s.combinationSum(c, 7);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
