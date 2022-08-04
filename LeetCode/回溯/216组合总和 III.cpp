#include <iostream>
#include <vector>
using namespace std;
// 分析：利用回溯，从1开始依次列举，出口条件为次数或者某个组合满足了和

// dfs解，看题解发现回溯解的话还要判断剩下多少个数可选，相应的出口条件也要改写下 
class Solution {
public:
	int target;
	vector<int > temp;
	vector<vector<int > > result;
	// level：当前数，deepth用来限制vector大小，sum存放当前和
	void dfs(int level, int deepth, int sum) {
		// 出口条件
		if (level >= 10 || sum >= target) {
			if (sum == target && temp.size() == deepth) result.push_back(temp); 
			return;
		} 
		// 开始试探
		temp.push_back(level);
		sum += level;
		dfs(level + 1, deepth, sum);
		sum -= level;
		temp.pop_back(); 
		dfs(level + 1, deepth, sum);
	}
    vector<vector<int> > combinationSum3(int k, int n) {
    	if (k == 0 || n == 0) return result;
    	this->target = n;
        dfs(1, k, 0);
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<vector<int > > v;
	v = s.combinationSum3(3, 7);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
