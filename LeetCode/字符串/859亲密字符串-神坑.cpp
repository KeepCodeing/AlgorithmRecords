#include <iostream>
#include <map> 
#include <vector>
#include <set>
using namespace std;
// 分析：暂且想到了通过滑动取子字符串的方式来解决（不可行，交换顺序不一定是连着的）
// 考虑通过统计A，B字符串的不同字符个数来解，如果不同字符个数为2说明可行，否则不可行 

// 评论的解答 
//统计字符串A，B中字符不匹配的下标。
//不匹配的下标个数不等于 0 或 2 时，不能由A得到B。
//不匹配的下标个数等于0时，A与B中字符完全相同，还需要A中有重复字符。
//不匹配的下标个数等于2时，判断交换两对字符后是否匹配。

class Solution {
public:
    bool buddyStrings(string A, string B) {
    	// 各种潜在条件 

		// 长度不够
		if (A.size() < 2 || B.size() < 2) return false; 
		
        // A为空或者B为空 
        if (!A.size() || A.empty() || !B.size() || B.empty()) return false;
        // A的长度不等于B的长度
		if (A.size() != B.size()) return false;
		// 坑，如果两个字符串长度都为2且相等比如ab，它们是不同的，但如果是aa，那就是相同的了
		if (A.size() == 2 && B.size() == 2 && A[0] == B[1] && A[1] == B[0]) return true;
		// A等于B ，错误条件，题目说只能交换A的元素，也就是说两个字符想等一定不同 
    	// 那么A与B都为空也不行，因为长度不够（写在特殊情况后防止误判） 
    	// 该条件可行，如abab... 
        // if (A == B) return false;
		int cnt = 0; 
		int aLen = A.size();
		// 对比字符数量 （这个地方居然把value写成了char类型...） 
//		map<char, char > m;
//		for (int i = 0; i < aLen; i++) {
//			m[A[i]]++;
//		}
//		for (int i = 0; i < aLen; i++) {
//			if (m[B[i]] <= 0) return false;
//			m[B[i]]--;
//		}
		vector<int > temp;
		// 对比A，B字符 
        for (int i = 0; i < aLen; i++) {
        	if (A[i] != B[i]) {
        		cnt++;
        		// 存放两个不同字符的下标 
        		temp.push_back(i);
			}
        	if (cnt > 2) return false;
		}
		if (temp.size() == 0) {
            return set<char>(A.begin(), A.end()).size() < A.size();
        } else if (temp.size() == 2) {
            return A[temp[0]] == B[temp[1]] &&
                   A[temp[1]] == B[temp[0]];
        }
		return false;
    }
}; 
int main() {
	Solution s = Solution();
	string a, b;
	cin >> a >> b;
	cout << s.buddyStrings(a, b); 
	return 0;
}
