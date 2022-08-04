#include <iostream>
#include <vector>
using namespace std;
// 印象比较深的题，比较左右括号数量就完事了 ，谔谔，核心是当左右括号都还有的时候进行添加，
// 不是当左括号数量小于右括号数量时添加，左括号数量小于右括号数量只能算是个递归条件，如果
// 左括号大于右括号数量可以进行剪枝 

// 啊这...思路没什么问题，但是字符添加的位置不对 
class Solution {
public:
	vector<string > result;
	void dfs(int left, int right, string str) {
		if (left == 0 && right == 0) {
			// cout << str << endl;
			result.push_back(str); 
		}
		if (left > right) return;
		if (left > 0) {
			// 之前这样写的，生成的括号总为((())) 
			// dfs(left - 1, right, '(' + str);
			dfs(left - 1, right, str + '(');
		} 
		if (right > 0) {
			dfs(left, right - 1, str + ')');
		}
	}
    vector<string> generateParenthesis(int n) {
    	if (n == 0) return result;
    	dfs(n, n, "");
        return result;
    }
};
int main() {
	Solution s = Solution();
	s.generateParenthesis(3); 
	return 0;
}
