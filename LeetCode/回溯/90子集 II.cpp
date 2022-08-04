#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 分析：主要是个去重的问题，可以先排序，再记录上一个元素

// 回溯解 
// 奇妙深刻，其写了半天没搞明白这时在求一个子集问题的解，图也画了却不知道该怎么取
// 节点...，刻意练习不可避 
class Solution {
public:
	vector<vector<int> > result;
	vector<int > temp;
	vector<int > nums;
	void dfs(int level, int deepth) {
		result.push_back(temp); 
		// 记录是否和上一个元素相同 
		int pre = nums[0] - 1;
		for (int i = level; i < deepth; i++) {
			// 相同说明存在重复解，进行剪枝 
			if (pre == nums[i]) continue;
			temp.push_back(nums[i]);
			dfs(i + 1, deepth);
			// 更新节点值 
			pre = nums[i];
			temp.pop_back(); 
		}
	}
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0 || nums.empty()) return result;
        sort(nums.begin(), nums.end());
        this->nums = nums;
		dfs(0, this->nums.size());
		return result;
    }
};

// DFS解坠毁... 
// DFS解法似乎不能这样去重，会少元素 
//class Solution {
//public:
//	vector<vector<int> > result;
//	vector<int > temp;
//	vector<int > nums;
//	int pre;
//	void dfs(int level, int deepth) {
//		if (level == deepth) {
//			result.push_back(temp); 
//			return;
//		}
//		if (pre == nums[level]) {
//			return;
//		}
//		// cout << pre << ' ' << nums[level] << endl;
//		temp.push_back(nums[level]);
//		dfs(level + 1, deepth);
//		pre = nums[level];
//		temp.pop_back();
//		dfs(level + 1, deepth); 
//		
//	}
//    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
//        if (nums.size() == 0 || nums.empty()) return result;
//        sort(nums.begin(), nums.end());
//        pre = nums[0] - 1;
//        this->nums = nums;
//		dfs(0, this->nums.size());
//		
//		//result.push_back() 
//		return result;
//    }
//}; 
int main() {
	Solution s = Solution();
	vector<int > v;
	vector<vector<int > > r;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3); 
	// v.push_back(2); 
	r = s.subsetsWithDup(v); 
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
