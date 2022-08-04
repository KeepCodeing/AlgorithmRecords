#include <iostream>
#include <vector> 
#include <algorithm>
#include <map>
using namespace std;

// 常规做法是排序+HashTable，但是看题解发现好像也可以自己实现一个hash函数，这样的话异位词字符相同
// 然后把它们乘在一起，获得的结果一定相同 

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string > > t;
        vector<vector<string> > result;
        if (strs.size() == 0 || strs.empty()) return result;
        int sLen = strs.size();
        // 统计异位词，将其放到一个vector里 
        for (int i = 0; i < sLen; i++) {
        	string temp = strs[i];
        	// 排序，方便对比 
        	sort(strs[i].begin(), strs[i].end());
        	t[strs[i]].push_back(temp);
		}
		// 将value取出来封装 
		for (map<string, vector<string > >::iterator it = t.begin(); it != t.end(); it++) {
			result.push_back(it -> second); 
		}
		return result;
    }
};

int main() {
	return 0;
}
