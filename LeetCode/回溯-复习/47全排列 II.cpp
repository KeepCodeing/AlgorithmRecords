#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ШЅжи.. 
class Solution {
public:
	vector<vector<int> > result;
	void dfs(int level, int deepth, vector<int >& temp, bool visited[], vector<int>& nums) {
		if (level == deepth) {
			result.push_back(temp);
			return; 
		}
		int pre = nums[0] - 1;
		for (int i = 0; i < deepth; i++) {
			if (!visited[i] && pre != nums[i]) {
				visited[i] = true;
				temp.push_back(nums[i]);
				dfs(level + 1, deepth, temp, visited, nums);
				temp.pop_back(); 
				visited[i] = false;
				pre = nums[i];
			}
		}
	}
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        if (nums.size() == 0 || nums.empty()) return result;
        bool *visited = new bool[nums.size()]();
        sort(nums.begin(), nums.end());
        vector<int > temp;
        dfs(0, nums.size(), temp, visited, nums);
        delete[] visited;
        return result;
    }
};

int main() {
	return 0;
}
