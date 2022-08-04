#include <iostream>
#include <vector>
using namespace std;
// 分析：这个题是决策添加左括号还是右括号，不是说每次回溯都新增一个合法括号，所以
// 相应的有两种情况，用左括号还是右括号由左右剩余的括号数决定。

// 注意这里的str变量，其之前一直用的vector存字符，看起来没必要了... 
class Solution {
public:
	vector<string > result;
	void dfs(string str, int left, int right) {
		// 当左右括号都用完了，说明产生了一个合法解 
		if (left == 0 && right == 0) {
			result.push_back(str);
			return; 
		}
		// 剪枝
		if (left > right) return;
		// 防止错误添加 
		if (left > 0) dfs(str + "(", left - 1, right);
		if (right > 0) dfs(str + ")", left ,right - 1);
			
	}
    vector<string> generateParenthesis(int n) {
        if (n == 0) return result;
        dfs("", n, n);
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<string > t = s.generateParenthesis(3); 
	for (int i = 0; i < t.size(); i++) {
		cout << t[i] << endl;
	}
	return 0;
}
