#include <iostream>
using namespace std;
// 思路：可以自己写一个滑动比较hash值的算法

// 用自己写的hash值算法坠毁了五次（绝望）其中四次都是因为自己考虑不全（无能）
// hash算法存在的问题为两个不同字符串的字母序不同，但其hash值相同，如ab和ba，
// 这就会导致错误匹配，所以最后还是用的substr来匹配的 

class Solution {
public:
	// 自定义的获取哈希值的函数 
	int getHash(string s) {
		const int seed = 133;
		long hash = 0;
		// 坠毁，其自己写的hash值算法无法保证hash唯一 
		for (int i = 0; i < s.size(); i++) {
			hash = s[i] * seed + hash;
		}
		return hash % 114514;
	}
    int strStr(string haystack, string needle) {
    	// 如果都为空字符那么也算匹配到了 
    	if ((haystack.empty() || haystack.size() == 0) && (needle.size() == 0 || needle.empty())) return 0;
    	// 当要匹配的字符不存在时返回0，题目要求 
        if (needle.size() == 0 || needle.empty()) return 0;
        int nSize = needle.size();
        int hSize = haystack.size();
        int result = 0;
        // 开始滑动对比 
        // 这里要“特意出界”防止漏掉最后一个字符串 
		for (int i = 0; i <= hSize - nSize; i++) {
			// 直接对比字符串，简单粗暴 
			if (haystack.substr(i, nSize) == needle) return i;
		} 
		return -1;
    }
}; 
int main() {
	Solution s = Solution();
	string a, b;
	cin >> a >> b;
	cout << s.strStr(a, b); 
	return 0;
}
