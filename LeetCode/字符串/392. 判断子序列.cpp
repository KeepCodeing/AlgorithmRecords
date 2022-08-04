#include <iostream>
#include <algorithm>
using namespace std;

// 虽然题目标签是动态规划，但是这个题用string的find来做更加简单

// 坠毁，还是得一个个对比
class Solution {
	public:
		bool isSubsequence(string s, string t) {
			if(s.size() == 0)return true;
			int start = 0;
			int len = s.size();
			for(int i = 0; i < t.size(); i++) {
				if(s[start] == t[i])
					start++;
				if(start == len) return true;
			}
			return false;
		}
};
int main() {
	Solution s = Solution();
	s.isSubsequence("abc", "ahbgdc");
	return 0;
}
