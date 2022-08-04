#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 去重就完事了 

// 这么一看回溯的代码都差不多，关键在下次选择和出口条件上 
class Solution {
public:
	vector<vector<int> > result;
	void dfs(int level, int deepth, vector<int >& temp, vector<int>& nums) {
		result.push_back(temp);
		int pre = nums[0] - 1;
		for (int i = level; i < deepth; i++) {
			if (nums[i] != pre) {
				temp.push_back(nums[i]);
				dfs(i + 1, deepth, temp, nums);
				temp.pop_back();
				pre = nums[i]; 
			}
		} 
	}
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0 || nums.empty()) return result;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        dfs(0, nums.size(), temp, nums);
        return result;
    }
};

int main() {
	return 0;
}
