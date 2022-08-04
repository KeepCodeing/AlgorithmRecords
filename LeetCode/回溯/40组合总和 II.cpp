#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 分析：回溯解，每次递归标记已经使用的数，再传递累计和，如果当累计和大于target或者当前数
// 大于target就返回，当然也可以用target减去当前数，判断是否为0

//class Solution {
//public:
//	int *visited;
//	vector<int > temp;
//	vector<vector<int > > result;
//	void dfs(int level, int deepth, vector<int>& candidates, int target) {
//		if (target <= 0 || level == deepth) {
//			for (int i = 0; i < temp.size(); i++) cout << temp[i] << ' ';
//			cout << endl;
//			return;
//		}
//		for (int i = level; i < deepth; i++) {
//			if (target - candidates[level] < 0) continue; 
//			if (candidates[i] > target) continue;
////			if (i > level && candidates[i] == candidates[i - 1]) {
////                continue;
////            }
//			temp.push_back(candidates[level]); 
//			dfs(level + 1, deepth, candidates, target - candidates[level]);
//			temp.pop_back();
//		}
//	}
//    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
//        visited = new int[candidates.size()]();
//        dfs(0, candidates.size(), candidates, target);
//        delete[] visited;
//        return result;
//    }
//}; 

class Solution {
public:
	vector<int > nums;
	vector<int > temp;
	vector<vector<int > > result;
	int deepth;
	void dfs(int level, int target) {
		// 找到解的出口：target为0，或者已经达到递归树的最底层 
		if (target <= 0 || level == deepth) {
			if (target == 0) {
//				for (int i = 0; i < temp.size(); i++) cout << temp[i] << ' ';
//				cout << endl;
				result.push_back(temp); 
			}
			return;
		}
		for (int i = level; i < deepth; i++) {
			// 判断当前值是否大于target，如果大于就没必要在用target减了 
			if (nums[i] > target) continue;
			// 判断当前元素是否与上一个元素重复，如果重复即可以剪枝 
			if (i > level && nums[i - 1] == nums[i]) {
                continue;
            }
			temp.push_back(nums[i]); 
			// 注意这里不是level加1，level只是当前层数，i才是当前选择
			// i+1表示下一个选择 
			dfs(i + 1, target - nums[i]);
			// dfs(level + 1, target - nums[i]);
			temp.pop_back();
		}
	}
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    	// 这里的排序可以使数组的元素变得“不重复”，即单个重复元素不可能出现在第一位 
    	// 只有对数组进行排序才能剪枝 
    	sort(candidates.begin(), candidates.end());
        this->nums = candidates;
        this->deepth = candidates.size();
        dfs(0, target);
//        for (int i = 0; i < result.size(); i++) {
//        	for (int n = 0; n < result[i].size(); n++) {
//        		cout << result[i][n] << ' ';
//			}
//			cout << endl;
//		}
		return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<int > v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);  
	v.push_back(2);  

	s.combinationSum2(v, 6); 
	return 0;
}
