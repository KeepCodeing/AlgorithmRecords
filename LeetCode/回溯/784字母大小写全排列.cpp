#include <iostream>
#include <vector>
using namespace std;
// 分析：可以画下决策树，然后用回溯法解 

class Solution {
public:
	vector<string > result;
    vector<string> letterCasePermutation(string S) {
        if (S.size() == 0 || S.empty()) return result;
        char *r = new char[S.size()];
        dfs(0, S.size() - 1, r, S);
        delete[] r;
        return result;
    }
    void dfs(int level, int deepth, char r[], string s) {
    	if (level == deepth) {
    		result.push_back(r);
    		return;
		}
		// 首先到决策树底部，然后回溯 
		r[level] = s[level];
		dfs(level + 1, deepth, r, s);
		
		// 如果是字母就要进行转换 
		if (s[level] >= 'A' && s[level] <= 'Z' || s[level] >= 'a' && s[level] <= 'z') {
			// 自动转换大小写 
			r[level] = s[level] ^ (1 << 5);
			dfs(level + 1, deepth, r, s);
		}
	}
};

int main() {
	Solution s = Solution();
	vector<string > v = s.letterCasePermutation("a1b2"); 
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
	return 0;
}
