#include <iostream>
#include <algorithm>
using namespace std;
// 思路：顺序遍历，碰到元音字母记录其下标，下次碰到元音字母根据下标交换并且
// 更新下标 

// 事实证明顺序交换坠毁了，还是得用双指针的思想对着交换 
class SolutionFail {
public:
    string reverseVowels(string s) {
    	int sLen = s.size();
    	int index = -1;
    	char tChar;
        for (int i = 0; i <= sLen; i++) {
        	char temp = tolower(s[i]);
        	if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
        		// 这里这样写不能满足全部情况，当元音字母出现在第0位时else就不会执行 
        		// 改写成-1 
        		if (index == -1) {
        			index = i;
				} else {
					// 这里本打算i++防止重复交换的，然而如果是顺序交换的话这样写或许还是错的 
        			tChar = s[index];
        			s[index] = s[i];
        			s[i] = tChar;
					index = i;
				}
			}
		}
		return s;
    }
};
class Solution {
public:
	bool isCase(char c) {
		// 注意这里之前写的 tolower(c) == 'a' || c == ...，这样写只将A这种情况小写了 
		c = tolower(c);
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) { 
        	// 如果不是元音字符继续推进 
        	if (!isCase(s[left])) left++;
			else if (!isCase(s[right])) right--;
			// 如果都是元音字符了，交换，再更新位置，防止重复交换 
			else swap(s[left++], s[right--]);
		}
		// cout << s;
		return s;
    }
};
int main() {
	Solution s = Solution(); 
	s.reverseVowels("Ui");
	return 0;
}
