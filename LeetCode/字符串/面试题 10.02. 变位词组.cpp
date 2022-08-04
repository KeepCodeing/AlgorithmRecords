#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 和紫书上的那个异位词一样，只不过这里要做个分组，考虑到Trie树在LeetCode上比较
// 蛋疼所以还是写map算了...
// 看了下之前写的，那个题要统计的是无法被组成的词，这么看这个题用Trie还会麻烦点... 
// 那么思路就是对每个元素进行排序，然后映射到map里，这里应该可以省很多vector，但是
// 得保证插入顺序之类的东西... 

class Solution {
public:
	map<string, vector<string > > vmp;
	vector<vector<string > > res;
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
		int sLen = strs.size();
		if (sLen == 0) return res;
		string temp;
		for (int i = 0; i < sLen; i++) {
			temp = strs[i];
			sort(temp.begin(), temp.end());
			vmp[temp].push_back(strs[i]);
		}
		for (map<string, vector<string > >::iterator it = vmp.begin(); it != vmp.end(); it++) 
			res.push_back(it->second); 
		return res;
    }
};

int main() {
	return 0;
}
