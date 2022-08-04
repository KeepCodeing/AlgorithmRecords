#include <iostream>
using namespace std;

// 给定两个字符串，求出其公共最长子串，如ABCD,DBCT，最长公共子串长度为2 

// 思路：暴力求解，从第一个相同字符到最后一个相同字符，即是最长公共子串 

int longestCommonSubstring(string s1, string s2) {
	if (s1.empty() || s2.empty()) return 0;
	int maxLen = 0;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			int tempIndex = 0;
			// 防止出界 
			while (i + tempIndex < s1.size() && j + tempIndex < s2.size()) {
				// 对比字符，相同继续往后对比 
				if (s1[i + tempIndex] == s2[j + tempIndex]) tempIndex++;
				else break;
			}
			if (tempIndex > maxLen) maxLen = tempIndex;
		}
	}
	return maxLen;
} 

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << longestCommonSubstring(s1, s2) << endl;
	return 0;
}
