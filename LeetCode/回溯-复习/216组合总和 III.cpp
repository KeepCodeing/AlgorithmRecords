#include <iostream>
#include <vector>
using namespace std;

// 这个题一共三种题型，第一个允许使用同一个位置上的数字，第二个不允许使用同一个位置上的数字，
// 第三个不允许使用同一个数字，第一个主要是走到底，第二个就是普通的回溯题，第三个加入了去重
// 部分的逻辑（然而并没有去重，只是给定了数据范围） 

class Solution {
public:
	vector<vector<int> > result;
	void dfs(int level, int deepth, int target, vector<int >& temp) {
		if (target < 0) return;
		// 这里的出口写的就是target满足解且元素个数满足解 
		if (target == 0 && temp.size() == deepth) {
			result.push_back(temp);
			return; 
		}
		for (int i = level; i <= 9; i++) {
			if (target < i) continue;
			temp.push_back(i);
			// 其实target没必要取出来加减，递归里自动还原就行 
			dfs(i + 1, deepth, target - i, temp);
			temp.pop_back(); 
		}
	}
    vector<vector<int> > combinationSum3(int k, int n) {
        if (n == 0 || k == 0) return result;
        vector<int > temp;
        dfs(1, k, n, temp);
        return result;
    }
}; 

int main() {
	Solution s = Solution();
	vector<vector<int > > r = s.combinationSum3(3, 9); 
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
