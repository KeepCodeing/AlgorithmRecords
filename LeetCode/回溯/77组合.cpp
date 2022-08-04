#include <iostream>
#include <vector>
using namespace std;
// 分析：类似全排列，应该也是个套模板的题
class Solution {
public:
	vector<int > temp;
	vector<vector<int> > result;
	void dfs(int level, int deepth, int n) {
		// 关于出口条件其似乎没有弄懂过，该了 
		// 之前写成了2，属实⑧行... 
		if (temp.size() == deepth) {
			for (int i = 0; i < temp.size(); i++) cout << temp[i] << ' ';
			result.push_back(temp); 
			return;
		}
		for (int i = level; i <= n; i++) {
			temp.push_back(i);
			dfs(i + 1, deepth, n);
			temp.pop_back(); 
		}
	}
    vector<vector<int> > combine(int n, int k) {
        if (k == 0) return result;
        dfs(1, k, n);
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	s.combine(4, 2); 
	return 0;
}
