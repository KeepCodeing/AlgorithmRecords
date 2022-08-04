#include <iostream>
#include <vector>
using namespace std;
// 用vector实现一次全排列，不考虑重复 
class Solution {
public:
	vector<vector<int > > result;
	vector<int > temp;
	bool *visited;
	void dfs(int level, int deepth) {
		if (level == deepth) {
			result.push_back(temp);
			return; 
		}
		// 这里规定从1开始 
		for (int i = 1; i <= deepth; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			temp.push_back(i);
			// 从这里可以看出来全集问题和子集问题的区别，全集问题强调的是每一层元素
			// 而子集问题强调的是每次选择的元素，全集问题一定是获得了全部结果才会生成
			// 一个解，而子集问题可能递归树上每一个路径都算一个解。 
			dfs(level + 1, deepth);
			visited[i] = false;
			temp.pop_back();
		}
	}
	vector<vector<int > > qpl(int n) {
		if (n == 0) return result;
		// 注意动态分配空间的数组的初始化问题，如果不进行初始化可能会导致错误 
		visited = new bool[n]();
		dfs(0, n);
		delete[] visited;
		return result;
	}
};
int main() {
	Solution s = Solution();
	vector<vector<int > > result = s.qpl(3); 
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
