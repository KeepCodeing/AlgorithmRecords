#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 分析：本来想着用桶排的，不过题目给出了字符全为小写且要求统计最小字符满足条件的情况，所以大概可以写
// 两层循环

// 看评论桶排也可行，只不过要额外遍历一遍，其算法也说不上多好... 

/*
for (int i = 0; i < queries.size(); i++) {
        	for (char c = 'a'; c <= 'z'; c++) {
				if (count(queries[i].begin(), queries[i].end(), c)) {
					// 如果找到了最小字符，可以继续判断有多少个满足表达式的
					for (int j =0; j < words.size(); j++) {
						for (char k = 'a'; k <= 'z'; k++) {
							
						}
					
					}
					break; 
				}
			} 
		} 
*/

class Solution {
public:
	vector<int > getCount(vector<string >& v) {
		vector<int > qVector;
        int r;
        for (int i = 0; i < v.size(); i++) {
        	for (char c = 'a'; c <= 'z'; c++) {
        		if (r = count(v[i].begin(), v[i].end(), c)) {
        			qVector.push_back(r); 
        			break;
				}
			}
		}
		return qVector;
	}
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        // 题目给出了长度都大于0，所以干脆可以不判断非法情况
        vector<int > qCount = getCount(queries);
        vector<int > wCount = getCount(words);
        vector<int > result;
        int qLen = qCount.size(), wLen = wCount.size(), t;
        int maxNum = wCount[0];
        // 标记一个最大值，防止无用的循环 
        for (int i = 1; i < wLen; i++) maxNum = maxNum < wCount[i] ? wCount[i] : maxNum;
        // 对比 
		for (int i = 0; i < qLen; i++) {
			t = 0;
			if (qCount[i] < maxNum) {
				for (int j = 0; j < wLen; j++) {
					if (qCount[i] < wCount[j]) {
						t++;	
					}
				}
			}
			result.push_back(t); 
		} 
		return result;
    }
};
 

int main() {
	return 0;
}
