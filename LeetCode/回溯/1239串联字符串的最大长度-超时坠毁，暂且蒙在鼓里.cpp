#include <iostream>
#include <set>
#include <vector>
using namespace std;
// 分析：回溯列举所有可能，同时用一个set去重判断最长串联字符串的大小，并记录一个最大值 
// 单纯的暴力回溯超时坠毁了，而且判断答案也写在里回溯里，暂且蒙在鼓里 

// 另外关于字符串去重其直接用set导致效率极低，评论区里的位压缩算法得学习下 
class Solution {
public:
	int maxLen = 0;
	set<char > charSet;
	vector<string > temp;
	vector<string > strArr;
	// 评论题解里的位压缩算法，利用该算法去重无需使用set
	// 这个算法的主要思路是当需要去重的字符串的不同字符不超过int位32时，通过某个
	// int变量的位记录字符是否出现过 
	bool isUnique(string& s, int& t) {
		int sLen = s.size();
	    for (int i = 0; i < sLen; i++) {
	    	//获取字符对应位
	        int n = s[i]-'a';	
	        //判断该位是否为0
	        if (t & (1<<n)) {
	            return false;
	        }
	        t |= (1<<n);
	    }
    	return true;
	}

	bool isAnswer() {
		string tempStr;
		int tLen, sLen;
		set<char > tempSet;
		// 先将当前组合转换为一个整体字符串，再判断里面字符是否重复 
		tLen = temp.size();
		for (int i = 0; i < tLen; i++) {
			tempStr += temp[i];
		}
		sLen = tempStr.size();
		// cout << tempStr << endl;
		// 判断重复 
		for (int i = 0; i < sLen; i++) {
			if (tempSet.count(tempStr[i])) return false;
			tempSet.insert(tempStr[i]); 
		}
		// 新增的更新答案，在这里判断是否重复和出口里判断是否重复功能冗余了，池沼 
		if (maxLen < tempSet.size()) maxLen = tempSet.size();
		return true;
	}
	void dfs(int level, int deepth) {
		// 这里写的有问题，貌似达到出口条件了temp也没有存放所有可能解，
		// 在这里打印的解也和递归树不一样，所有其把更新结果的函数改成
		// 了isAnswer，而isAnswer在回溯过程中更新答案，暂且蒙在鼓里 
		if (level == deepth) {
			// 题目给出的可行解是指没有字符重复的串联字符串，所有在这里还要剪枝
			// 去掉非法解
			//isAnswer();
			//if (!isAnswer()) return;
			// 防止存放了上一次的字符导致长度错乱 
//			charSet.clear();
//			int tempLen = temp.size();
//			for (int i = 0; i < tempLen; i++) { 
//				cout << temp[i];
//			}
//			cout << endl;
			
			// 将所有的可能的字符串组合的字符去重 
//			for (int i = 0; i < tempLen; i++) {
//				int charLen = temp[i].size();
//				for (int j = 0; j < charLen; j++) {
//					charSet.insert(temp[i][j]); 
//				}
//			} 
//			// 更新最大长度 
//			int charSetLen = charSet.size();
//			if (charSetLen > maxLen) maxLen = charSetLen;
			return;
		}
		for (int i = level; i < deepth; i++) {
			temp.push_back(strArr[i]);
			// isAnswer();
			dfs(i + 1, deepth);
			// 在回溯的过程中更新答案，至于为什么还不知道，但是在回溯的过程中
			// 答案才是完全的，或许是产生的递归树不完全？ 
			isAnswer();
			temp.pop_back();
		}
	}
    int maxLength(vector<string >& arr) {
        if (arr.size() <= 0) return 0;
        // 如果只有一个字符串，返回不重复字符的个数即可 
        if (arr.size() == 1) {
        	int strLen = arr[0].size();
        	for (int i = 0; i < strLen; i++) {
        		charSet.insert(arr[0][i]); 
			}
			return charSet.size();
		}
        this->strArr = arr;
        dfs(0, arr.size());
        return maxLen;
    }
};
int main() {
	Solution s = Solution();
	vector<string > v;
//	v.push_back("un");
//	v.push_back("iq");
//	v.push_back("ue");
	v.push_back("jnfbyktlrqumowxd");
	v.push_back("mvhgcpxnjzrdei");
	cout << s.maxLength(v); 
	return 0;
}
