#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 分析：因为元素可以重复使用，所以可以从头加起，直到获得了合法解或者大于了合法解
// 在进行下次回溯，这个题看起来是个子集类型的题，路径上的节点可能都要用到 

// 基本套模板的题，但是要注意可使用相同元素时出现非法解如何自动递增下一层的方法 
class Solution {
public:
	vector<vector<int> > result;
	vector<int > temp;
	vector<int > c;
	void dfs(int target, int start, int deepth) {
		if (target == 0) {
			result.push_back(temp);
			return; 
		}
		// 关键点在这里，实现target小于0自动向下增加一层的关键就是用i代替start
		// 如果出现了非法解，就会进入到下一层回溯，这时i就会自增一次 
		for (int i = start; i < deepth; i++) {
			int cur = c[i];
			if (target - cur < 0) continue;
			temp.push_back(cur);
			dfs(target - cur, i, deepth);
			temp.pop_back(); 
		}
	}
	
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return result;
        sort(candidates.begin(), candidates.end());
        this->c = candidates;
        dfs(target, 0, candidates.size());
        return result;
    }
};
int main() {
	return 0;
}
