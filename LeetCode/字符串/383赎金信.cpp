#include <iostream>
#include <map>
using namespace std;
// 思路：只要原文的字符串多于信的字符串即可，利用map计数

// 这个题也可以用数组存字符个数，因为字符限定是小写字符，所以可以用下标存放字符个数 
// arr[c-'a'].. 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    	// 如果原文的字符串个数还没有信的字符串个数多就说明一定不能组成 
        if (magazine.size() < ransomNote.size()) return false;
        int mSize = magazine.size();
        int rSize = ransomNote.size();
        map<char, int > cMap;
		for (int i = 0; i < mSize; i++) {
			cMap[magazine[i]]++;
		}
		for (int i = 0; i < rSize; i++) {
			// 如果字数不够用或者该字符根本没有出现过就返回false 
			if (cMap[ransomNote[i]] <= 0) return false;
			cMap[ransomNote[i]]--;
		}
		return true;
    }
}; 
int main() {
	Solution s = Solution();
	cout << s.canConstruct("aa", "aab"); 
	return 0;
}
