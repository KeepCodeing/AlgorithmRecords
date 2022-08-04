#include <iostream>
using namespace std;

// 有点倒车的感觉w
// 做这个题之前以为自己以前做过了，然后开始想算法，先想了个O(n^3)，然而没有验证
// 后来想了个O(n^2)的算法，完全的暴力，然后发现上一个算法是个假的w，还想了下trie
// 不过没什么意义... 

// 写了半天发现O(n^2)超时了（绝望） 

class Solution {
public:
	bool checker(string str) {
		bool bucket[256];
		int sLen = str.size();
		fill(bucket, bucket + 256, false);
		for (int i = 0; i < sLen; i++) {
			if (bucket[str[i]]) return false;
			bucket[str[i]] = true;
		}
		return true;
	}
    int lengthOfLongestSubstring(string s) {
        string temp;
		int sLen = s.size(), res = -1, tLen;
		for (int i = 0; i < sLen; i++) {
			// 这里截取很烦人，应该是从i到sLen都截取一遍，但是如果直接写j = 1; j < slen会多截取很多次，所以这里得
			// 写成sLen - i + 1，防止多次截取 
			for (int j = 1; j < sLen - i + 1; j++) {
				// 这里利用了substr的特性，不指定结尾自动截取到字符串尾，这样可以很方便的从后往前截取子串
				// 到i这个位置，相比指定为i，j更方便，而后者其调了会没调出来w 
				temp = s.substr(i, j), tLen = temp.size();
				// 这里判重脑瘫了，要判的是子字符串里的字符有没有重复，不是判断子字符串有没有重复w 
				if (checker(temp)) res = max(res, tLen); 
			}
		}
		return res;
    }
};

bool checker(string str) {
	bool bucket[256];
	int sLen = str.size();
	fill(bucket, bucket + 256, false);
	for (int i = 0; i < sLen; i++) {
		if (bucket[str[i]]) return false;
		bucket[str[i]] = true;
	}
	return true;
}
// 先搞个面向过程的 
int main() {
	
	return 0;
}
