#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 没有弄懂的点：level和i哪里，一开始写成了i=level，这样写无法遍历整个字符串，又把
// level写成了i，这样的话没办法做到进入下一层的效果

// 解决方案：i从0开始到可遍历字符串长度，这个区间内的字符都是要拼接的，level独自增加
// 这样才能做到换层的效果 

// 其它的收获：在画递归树的时候可以把对应的循环，层次写出来，将分支对应成循环，将树
// 的层次对应成level，同时可以把每一层有哪些变量需要循环，那些变量可以产生分支写出来 

class Solution {
public:
	vector<string > result;
	void dfs(int deepth, string str, string digits, map<char, string > m, int level) {
		if (str.size() == deepth) {
			// cout << str << endl; 
			result.push_back(str);
			return; 
		}
		string mStr = m[digits[level]];
		for (int i = 0; i < mStr.size(); i++) {
			// 啊这...之前还把i作为参数传进去了，结果发现没卵用，这个题
			// 或许也是套模板，只不过i从定值开始了... 
			dfs(deepth, str + mStr[i], digits, m, level + 1);
		}
	}
    vector<string> letterCombinations(string digits) {
        if (digits.empty() || digits.size() == 0) return result;
        map<char, string > m;
        m['2'] = "abc", m['3'] = "def", m['4'] = "ghi", m['5'] = "jkl", m['6'] = "mno";
    	m['7'] = "pqrs", m['8'] = "tuv", m['9'] = "wxyz";
    	dfs(digits.size(), "", digits, m, 0);
    	return result;
	}
};
int main() {
	Solution s = Solution();
	s.letterCombinations("23"); 
	return 0;
}
