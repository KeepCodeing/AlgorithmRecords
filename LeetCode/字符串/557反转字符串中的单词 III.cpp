#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 分析：将字符串以空格为界限拆分成多个字字符串即可，至于翻转可以用库函数，也可以用双指针
// 谔谔，其没用库函数效率低的不行... 

// 这种翻转题似乎可以先将字符串切分为多串（最后一串可以加个空格分隔） ，然后利用栈来解 
class Solution {
public:
	vector<string > splitStr(string s, char reg) {
		vector<string > result;
		// 这里可以在s后面加个reg，可以防止漏掉最后一个字符串 
		s += reg;
		int sLen = s.size();
		string temp;
		for (int i = 0; i < sLen; i++) {
			if (s[i] != reg) {
				temp += s[i];
			} else {
				result.push_back(temp);
				temp.clear(); 
			}
		}
		return result;
	}
	string reverseStr(string s) {
		vector<string > strs = splitStr(s, ' ');
		string result;
		int sLen = strs.size();
		for (int i = 0; i < sLen; i++) {
			int left = 0, right = strs[i].size() - 1;
			while(left < right) {
				swap(strs[i][left++], strs[i][right--]);
			}
			result += strs[i];
			if (i != sLen - 1) result += ' ';
		}
		return result;
	}
    string reverseWords(string s) {
        if (s.size() == 0 || s.empty()) return "";
        return reverseStr(s);
    }
};
int main() {
	Solution s = Solution();
	cout << s.reverseWords("Let's take LeetCode contest"); 
	return 0;
}
