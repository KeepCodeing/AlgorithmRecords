#include <iostream>
#include <vector>
using namespace std;
// 回溯，从当前位开始往后增加字符，每增加一位就判断下是不是回文字符串
class Solution {
public:
	vector<vector<string> > result;
	vector<string > temp;
	string str;
	bool isHuiWen(int start, int end) {
		int left = start, right = end;
		while (left < right) {
			if (str[left++] != str[right--]) return false;
		}
		return true;
	}
	void dfs(int level, int deepth) {
		if (level == deepth) {
			result.push_back(temp); 
			return; 
		}
		for (int i = level; i < deepth; i++) {
			// 评论的题解说直接截取子字符串比较消耗时间，所以这里通过下标+双指针对比是否是回文
			// 字符串 
			if (!isHuiWen(level, i)) {
				// 这里level和i不是相同的，因为回溯的过程中level会还原
				// 也就是说这是在回溯的过程中判断已经选了的字符串是否是回文字符 
				continue;
			}
			// 注意这里之前写的是 str.substr(level, i + 1)，这和题解一样，但在c++里
			// substr应该是从当前字符开始向后n位截取，所以要写成这样 
			// 一开始是把当前位截取了，在回溯的过程中就是把当前位后所有位依次截取 
			temp.push_back(str.substr(level, i - level + 1)); 
			dfs(i + 1, deepth);
			temp.pop_back();
		}
	}
    vector<vector<string> > partition(string s) {
    	if (s.size() <= 0) return result;
    	this->str = s;
        dfs(0, s.size());
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<vector<string> > v = s.partition("aab"); 
	for (int i = 0; i < v.size(); i++) {
		for (int n = 0; n < v[i].size(); n++) {
			cout << v[i][n] << ' ';
		}
		cout << endl;
	}
	return 0;
}
