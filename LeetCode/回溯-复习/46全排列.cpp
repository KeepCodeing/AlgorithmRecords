#include <iostream>
#include <vector>
using namespace std;
// 老铁们啊，虽然不是同一时间，但还是同一IDE，老8我再次给大家表演一把全排列，奥利给兄弟们写了

// 全排列为什么传的是level+1?：画图就能看出来，底层的叶子节点才是结果，而且选择并不是选一个
// 少一个，而是选一个换一个，所以传的是level，其它类型的题是选一个少一个，所以传的的i+1 
class Solution {
public:
	vector<vector<int> > result;
	void dfs(int level, int deepth, vector<int >& temp, vector<int>& nums, bool visited[]) {
		if (level == deepth) {
			result.push_back(temp);
			return; 
		}
		for (int i = 0; i < deepth; i++) {
			if (!visited[i]) {
				visited[i] = true;
				temp.push_back(nums[i]);
				dfs(level + 1, deepth, temp, nums, visited);
				visited[i] = false;
				temp.pop_back(); 
			}
		}
	}
    vector<vector<int> > permute(vector<int>& nums) {
        if (nums.size() == 0 || nums.empty()) return result;
        vector<int> temp;
        // 注意初始化 
        bool *visited = new bool[nums.size()]();
        dfs(0, nums.size(), temp, nums, visited);
        delete[] visited;
        return result;
    }
}; 

int main() {
	Solution s = Solution();
	vector<int > v;
	vector<vector<int > > r;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	r = s.permute(v); 
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
} 
