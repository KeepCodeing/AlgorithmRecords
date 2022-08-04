#include <iostream>
#include <algorithm>
using namespace std;

// 分析：有点类似之前的一道翻转元音字符的题，这个题同样用双指针，不过翻转的条件变成了字符串 

class Solution {
public:
	// 判断是否是字符的方法 
	bool isAlpha(char c) {
		return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z';
	}
    string reverseOnlyLetters(string S) {
    	// LeetCode的惯例 
        if (S.size() == 0 || S.empty()) return S;
        int left = 0, right = S.size() - 1;
        while (left < right) {
        	// 找不到字符则继续靠拢，等两边都找到了就交换位置 
        	if (!isAlpha(S[left])) {
        		left++;
			} else if (!isAlpha(S[right])) {
				right--;
			} else {
				// 防止重复查找 
				swap(S[left++], S[right--]);
			}
		}
		return S;
    }
};

int main() {
	Solution s = Solution();
	string t;
	cin >> t;
	cout << s.reverseOnlyLetters(t); 
	return 0;
}
