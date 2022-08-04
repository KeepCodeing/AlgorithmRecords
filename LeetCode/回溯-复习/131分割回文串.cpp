#include <iostream>
#include <vector>
using namespace std;
// 关键在截取这个地方 

class Solution {
public:
	vector<vector<string> > result;
	string str;
	bool isHuiWen(int start, int end) {
		while (start < end) {
			if (str[start++] != str[end--]) return false;
		}
		return true;
	}
	void dfs(int level, int deepth, vector<string > temp) {
		if (level == deepth) {
			result.push_back(temp); 
			return;
		}
		for (int i = level; i < deepth; i++) {
			if (isHuiWen(level, i)) {
				// 核心部分 
				temp.push_back(str.substr(level, i - level + 1));
				dfs(i + 1, deepth, temp);
				temp.pop_back(); 
			}
		}
	}
    vector<vector<string> > partition(string s) {
        if (s.size() == 0 || s.empty()) return result;
        this->str = s;
        return result;
    }
};

int main() {
	return 0;
}
