#include <iostream>
#include <map>
using namespace std;
// 思路：每种特殊组合都是在其右边有搭配的字符串，所以我们可以在遇到这种字符时
// 判断其右边的字符串 

// 自己的垃圾穷举法，算能过 
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
        	if (s[i] == 'I') {
                if (s[i + 1] == 'V') {res += 4;i++;}
                else if (s[i + 1] == 'X') {res += 9;i++;}
                else res += 1;
            } else if (s[i] == 'X') {
                if (s[i + 1] == 'L') {res += 40;i++;}
                else if (s[i + 1] == 'C') {res += 90;i++;}
                else res += 10;
            } else if (s[i] == 'C') {
                if (s[i + 1] == 'D') {res += 400;i++;}
                else if (s[i + 1] == 'M') {res += 900;i++;}
                else res += 100;
            } else if (s[i] == 'L') {
            	res += 50;
			} else if (s[i] == 'D') {
				res += 500;
			} else if (s[i] == 'V') {
				res += 5;
			} else if (s[i] == 'M') {
				res += 1000;
			}
		}
        return res;
    }
};
// 评论题解的思路：先把各种可能的特殊数字存在一个map里，因为所有可能解
// 都是两位，所以在遍历时可以先从当前字符开始向后取一个字符，然后在map
// 里查找有没有对应的键，如果有，说明当前字符串为特殊数字，否则说明当前
// 字符串不为特殊数字，就不向后取一位，直接在map里找该字符对应的值



int solve(string s) {
	map<string, int > m;
	// 列举所有数字的结果 
	m["I"] = 1;
	m["IV"] =  4;
    m["V"] =  5;
    m["IX"] =  9;
    m["X"]  = 10;
    m["XL"]  = 40;
    m["L"]  = 50;
    m["XC"]  = 90;
    m["C"]  = 100;
    m["CD"] =  400;
    m["D"]  = 500;
    m["CM"] =  900;
    m["M"] =  1000;
    int res = 0;
	for (int i = 0; i < s.size(); i++) {
		// 开始从当前位向后取子字符串 
		//如果是特殊数字，加特殊值 
		cout << s.substr(i, 2)<< endl;
		if (m.count(s.substr(i, 2)) && i != s.size() - 1) {
			res += m[s.substr(i, 2)];
			// 注意这里的自增，否则会产生重复使用某个字符的情况 
			i++;
		} else {
			// 如果不是特殊数字，加自己的值 
			// 因为这里直接取获得的是一个字符，不满足key的要求，所以
			// 用取子字符串的方式取 
			// cout << s.substr(i, 1)<< endl;
			res += m[s.substr(i, 1)];
		}
	}
	return res;
}
 
int main() {
	Solution s  = Solution();
	string t;
	cin >> t;
	cout << solve(t);
	return 0;
}
