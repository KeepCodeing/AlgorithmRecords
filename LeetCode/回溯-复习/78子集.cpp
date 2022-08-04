#include <iostream>
#include <vector>
using namespace std;

// 子集问题就没有特别明显的出口条件（其实根本没有吧），所有路径上的解都是合法解
class Solution {
public:
	vector<vector<int> > result;
	void dfs(int level, int deepth, vector<int >& temp, vector<int>& nums) {
		// 任意解都合法，那么第一个被添加的就是空集 
		result.push_back(temp);
		for (int i = level; i < deepth; i++) {
			temp.push_back(nums[i]);
			dfs(i + 1, deepth, temp, nums);
			temp.pop_back(); 
		}
	}
    vector<vector<int> > subsets(vector<int>& nums) {
        if (nums.size() == 0 || nums.empty()) return result;
        vector<int > temp;
        dfs(0, nums.size(), temp, nums);
        return result;
    }
};

int main() {
	vector<int > c;
	vector<vector<int > > result;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	Solution s = Solution();
	result = s.subsets(c);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
