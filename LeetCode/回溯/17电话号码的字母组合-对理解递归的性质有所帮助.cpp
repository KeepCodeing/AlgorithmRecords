#include <iostream>
#include <vector>
#include <map>
using namespace std;
// 分析：这个题因为不是和其他题一样，只有一个回溯的主体，所以解起来也不太一样
// 举例说要求"234"的组合，转换成字母就是m['2'] = "abc", m['3'] = "def", m['4'] = "ghi"，
// 它们的组合为adg,adh,adi...， 整个递归过程就是先进入到最后那个字符所在的那一层（最低层）
// 然后将最后一个字符逐个拼接到之前的字符之后，再回到倒数第二个字符那层，因为这一层的第一个
// 字符已经拼接过了，所以将其第二个字符拼接到最后，再进入最后一层依次拼接，直到所有字符都被遍历
// 完了 

// 这个题主要是递归的思想，先走到当前字符串的最后，然后把字符串映射拼上去，或许这也是一种启发
// 之前的题基本套模板，也还是做的出来，但是总觉得考虑的太少 
class Solution {
public:
	vector<string> result;
	string d;
	map<char, string > m;
	void dfs(int level, int deepth, string str) {
		// 出口是每一个字符都被拼接过了 
		if (str.size() == deepth) {
			result.push_back(str); 
			return;
		}
		// m[d[level]].size()，d是原字符串，如"234"，level是当前层次，
		// m是一个map，里面映射了键对应的字符串，这句话的意思就是从第一个
		// 字符开始，将每位字符取出，拼到结果上 
		for (int i = 0; i < m[d[level]].size(); i++) {
			// 给结果拼字符 
			dfs(level + 1, deepth, str + m[d[level]][i]);
		}
	}
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0 || digits.empty()) return result;
        this->d = digits;
        m['2'] = "abc", m['3'] = "def", m['4'] = "ghi", m['5'] = "jkl";
        m['6'] = "mno", m['7'] = "pqrs", m['8'] = "tuv", m['9'] = "wxyz";
        dfs(0, this->d.size(), "");
        return result;
    }
};

// 坠毁了的套模板解 
//class Solution {
//public:
//	vector<string> result;
//	string t;
//	vector<char > str;
//	void dfs(int level, int deepth, char start) {
//		if (str.size() == deepth && str[0] == start) {
//			string temp;
//			for (int i = 0; i < str.size(); i++) temp += str[i];
//			cout << temp << endl;
//			result.push_back(temp); 
//		}
//		for (int i = level; i < deepth; i++) {
//			str.push_back(t[i]);
//			dfs(i + 1, deepth, start);
//			str.pop_back(); 
//		}
//	}
//    vector<string> letterCombinations(string digits) {
//        if (digits.size() == 0 || digits.empty()) return result;
//        map<char, string > m;
//        m['2'] = "abc", m['3'] = "def", m['4'] = "ghi", m['5'] = "jkl";
//        m['6'] = "mno", m['7'] = "pqrs", m['8'] = "tuv", m['9'] = "wxyz";
//        for (int i = 0; i < digits.size() - 1; i++) {
//        	string st = m[digits[i]];
//        	for (int j = 0; j < st.size(); j++) {
//        		this->t += st[j];
//        		this->t += m[digits[i + 1]];
//        		dfs(0, t.size(), st[j]);
//			}
//		}
//        return result;
//    }
//};
int main() {
	Solution s = Solution();
	s.letterCombinations("23"); 
	return 0;
}
