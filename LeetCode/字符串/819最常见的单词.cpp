#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
// 分析：先分割字符串，再统计字符串出现次数以及判断其是否在禁用词列表中，或者直接在
// 分割的过程中判断其在不在禁用词列表中

class Solution {
public:
	string splitStr(string p, vector<string>& banned) {
		int maxCnt = 0;
		string strTemp, result;
		map<string, int > m;
		// 防止跳过最后一个字符串 
		p += ' ';
		// 对单词进行计数 
		for (int i = 0; i <= p.size(); i++) {
			if (p[i] >= 'A' && p[i] <= 'Z' || p[i] >= 'a' && p[i] <= 'z') {
				strTemp += tolower(p[i]);
			} else {
				
				// conut函数，统计该单词是否存在于banned中，如果存在它会返回元素个数 
				// 注意count不是类方法 
				// 如果不是禁用词 ，注意这里的不为空判断，如果是禁用词在清除字符串之后
				// 碰到了非字母的字符，就会直接进入else并被统计 
				if (count(banned.begin(), banned.end(), strTemp) == 0 && !strTemp.empty()) {
					m[strTemp]++;
					// 统计出现个数，返回出现最多的单词 
					if (m[strTemp] > maxCnt) {
						// 更新出现最多的字符串个数，以及字符串 
						maxCnt = m[strTemp];
						result = strTemp;
					}
				}
				// 不管是不是禁用词都清空字符串 
				strTemp.clear();
			}
		}
		return result;
	}
    string mostCommonWord(string paragraph, vector<string>& banned) {
    	if (paragraph.size() <= 0) return paragraph;
        return splitStr(paragraph, banned);
    }
};
 
int main() { 
	Solution s = Solution();
	vector<string > v;
	v.push_back("hit");
	cout << s.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", v); 
	return 0;
}
