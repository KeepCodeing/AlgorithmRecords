#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 分析：可以截取子字符串然后用HashTable计数

class Solution {
public:
	vector<string > result;
    vector<string> findRepeatedDnaSequences(string s) {
    	// 如果长度为10就不可能有子字符串出现1次以上了 
        if (s.size() <= 10 || s.empty()) return result;
        int sLen = s.size();
        map<string, int > sMap;
        // 惯例的等于，防止漏掉最后的字符串 
        for (int i = 0; i <= sLen - 10; i++) {
        	// 这里可以做点优化？判断当前字符是否出现过了，出现了直接加入vector 
        	sMap[s.substr(i, 10)]++;
		}
		for (map<string, int >::iterator it = sMap.begin(); it != sMap.end(); it++) {
			if (it->second > 1) result.push_back(it->first); 
		}
		return result;
    }
};
 
int main() {
	Solution s = Solution();
	string t;
	cin >> t;
	// AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT
	vector<string > v = s.findRepeatedDnaSequences(t); 
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
	return 0;
}
