#include <iostream>
#include <algorithm>
using namespace std;
// 因为不考虑大小写，符号等，所以可以去除这两种字符，然后获得一个新字符串再反转对比
// 注意题目中说空字符也算回文字符，可能有坑在这里（然而并没有）

// 又忽略掉了数字的情况，无能 
class Solution {
public:
	char toLowCase(char c) {
		return c >= 'A' && c <= 'Z' ? c + 32 : c;
	}
    bool isPalindrome(string s) {
    	int sLen = s.size();
    	string temp1, temp2;
    	for (int i = 0; i < sLen; i++) {
    		// 忽略了数字 
    		if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
    			temp1 += toLowCase(s[i]);
			}
			
		}
		temp2 = temp1;
		reverse(temp1.begin(), temp1.end());
		// cout << temp2 << endl << temp1 << endl;
		return temp1 == temp2;
    }
};
int main() {
	Solution s = Solution();
	cout << s.isPalindrome("0P");
	return 0;
}
