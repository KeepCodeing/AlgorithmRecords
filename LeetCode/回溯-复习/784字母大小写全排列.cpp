#include <iostream>
#include <vector>
using namespace std;

// 学习回溯的第一个题，当时是看题解用dfs写的，如今再用标准回溯写一遍...

// 算是写出来了，不过各种调试还是少不了 
 
class Solution {
public:
	vector<string> result;
	bool isAlpha(char c) {
		return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
	}
	void dfs(int level, int deepth, string str) {
		// 调来调去发现这个题是个子集类型的问题... 
		result.push_back(str); 
		for (int i = level; i < deepth; i++) {
			if (isAlpha(str[i])) {
				// 把自动转换大小写写成&了... 
				str[i] ^= (1 << 5);
				dfs(i + 1, deepth, str);
				str[i] ^= (1 << 5);
			}
		}
	}
    vector<string> letterCasePermutation(string S) {
        if (S.size() == 0 || S.empty()) return result;
		dfs(0, S.size(), S);
        return result;
    }
};

int main() {
	Solution s = Solution();
	vector<string > r = s.letterCasePermutation("a1b2");
	for (int i = 0; i < r.size(); i++) cout << r[i] << endl;
	return 0;
}
