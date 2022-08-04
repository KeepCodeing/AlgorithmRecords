#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 当成好像写成粑粑了，这次改了下ao了点，主要也是个去重的问题，不过之前用vector存字符串属实不太行 

// 啊这...这个题好像是个子集类型的题，其之前把条件判断写回溯里或许是因为这个原因 

// 蛋疼，不知道为什么普通回溯获得不了第一个元素，用子集方法做又得麻烦点 

// 草，差点坠毁，效率极低的屑算法 

class Solution {
public:
	int result = 0;
	bool isAlphaUsed(string t) {
		for (int i = 0; i < t.size(); i++) {
			if (count(t.begin(), t.end(), t[i]) > 1) return true;
		}
		return false;
	}
	void dfs(int level, int deepth, vector<string>& arr, string t) {

		if (result < t.size() && !isAlphaUsed(t)) result = t.size();

		for (int i = level; i < deepth; i++) {
			dfs(i + 1, deepth, arr, t + arr[i]);
		}
	}
    int maxLength(vector<string>& arr) {
        if (arr.size() == 0 || arr.empty()) return 0;
        dfs(0, arr.size(), arr, "");
        return result;
    }
};

int main() {
	Solution s = Solution();
	vector<string > arr;
	arr.push_back("yy");
	arr.push_back("bkhwmpbiisbldzknpm");
//	arr.push_back("jnfbyktlrqumowxd"); 
//	arr.push_back("mvhgcpxnjzrdei"); 
//	arr.push_back("ue"); 
//	arr.push_back("un"); 
//	arr.push_back("iq"); 
	cout << s.maxLength(arr); 
	return 0;
}
