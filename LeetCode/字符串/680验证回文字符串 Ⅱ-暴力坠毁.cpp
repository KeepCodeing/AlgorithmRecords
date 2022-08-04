#include <iostream>
using namespace std;
// 分析：题目说可以删除一个字符，那么我们可以进行n次循环，每次循环跳过n字符，暴力解
class Solution {
public:
	bool isHuiWen(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right) {
			if (s[left++] != s[right--]) return false;
		}
		return true;
	}
    bool validPalindrome(string s) {
    	// 空字符或一个字符都算回文 
        if (s.size() <=1 || s.empty()) return true;
        // 先判断下是不是回文，如果是就没必要删除字符了
		if (isHuiWen(s)) return true;
		// 如果不是回文，尝试删除字符
		int sLen = s.size();
		bool flag = true;
		for (int i = 0; i < sLen; i++) {
			string temp;
			for (int n = 0; n < sLen; n++) {
				if (i == n) continue;
				temp += s[n];
			}
			// 标记当前数组能否转换 
			if (!isHuiWen(temp)) flag = false;
			// 如果能组成回文就直接返回 
			else return true;
			temp.clear();
		}
		return flag;
    }
}; 
int main() {
	Solution s = Solution();
	string t;
	cin >> t;
	cout << s.validPalindrome(t); 
	return 0;
}
