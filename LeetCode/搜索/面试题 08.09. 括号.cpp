#include <iostream>
#include <vector>
using namespace std;

// 水题w，爆搜就完事了
// 蓝桥杯考到了，那时候倒是想了下写出来了，现在倒是没怎么想，不过也有点不了解为什么的感觉... 

class Solution {
public:
	vector<string > res;
	void dfs(int left, int right, string str) {
		if (!left && !right) {
			res.push_back(str);
			return; 
		}
		// 先用左括号，左括号用完了用右括号 
		if (left > 0) dfs(left - 1, right, str + "(");
		// 用右括号，但是要注意右括号的数量要比左括号多，不然会出现意料外的字符串 
		if (right > 0 && left < right) dfs(left, right - 1, str + ")");
	}
	
    vector<string> generateParenthesis(int n) {
    	if (!n) return res;
		dfs(n, n, "");
		return res;
    }
}; 

int main() {
	return 0;
}
