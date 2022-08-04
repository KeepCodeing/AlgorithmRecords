#include <iostream>
#include <vector>
using namespace std;
// 分析：每次遍历记录第一个字符串的当前开头元素即可，在后续遍历中对比开头是否相同
// 相同继续对比，不同跳出循环 

// 考虑不全，题意没有理解到位 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	// 没有判断传入空字符串的情况，导致其循环卡死 
    	if (strs.empty() || !strs.size()) return "";
    	int sLen = strs.size();
    	bool flag = true;
    	int start = 0;
    	char head;
    	// 首先遍历集合 
    	while (flag) {
	    		for (int i = 0; i < sLen; i++) {
	        	// 标记开头 
	        	if (i == 0) {
					head = strs[0][start];
				}
				// 对比开头，防止元素出界（出界判断之前为小于，考虑不周到） 
				if (strs[i][start] != head || start >= strs[i].size()) {
        			flag = false;
        			break;
				}
			}
			if (!flag) break;
			start++;
		}
		string result;
        for (int i = 0; i < start; i++) {
            result += strs[0][i];
        }
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<string > v;
	string str;
	while (cin >> str) {
		v.push_back(str);
	}
	cout << s.longestCommonPrefix(v);
	return 0;
}
