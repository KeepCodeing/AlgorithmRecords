#include <iostream>
#include <stack>
#include <map>
using namespace std;
// 分析：当输入反括号的时候对比其前面是不是正括号即可，利用栈来满足这种需求，同时
// 可以用map存放字符对 
class Solution {
public:
    bool isValid(string s) {
    	// 题目规定 
    	if (s.size() == 0 || s.empty()) return true;
    	// 开头为反括号肯定不合法 
    	if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false; 
    	// 长度不对称肯定不合法
		if (s.size() % 2 != 0) return false; 
        map<char, char > m;
        m[')'] = '(', m[']'] = '[', m['}'] = '{';
        int sSize = s.size(); 
        stack<char > strStack;
        // 压入元素 
        for (int i = 0; i < sSize; i++) {
        	// 如果是反括号，出栈对比是否匹配正括号 
        	if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
        		// 出栈对比 
        		if (m[s[i]] != strStack.top()) return false;
        		// C++不会自动删除元素，所以要手动调用方法删除 
        		strStack.pop();
        		continue;
			}
        	strStack.push(s[i]);
		}
		// 如果输入的全是正括号，则栈元素不会改变，而如果全部匹配完了栈就空了 
		return strStack.empty();
    }
};
int main() {
	Solution s = Solution();
	string t;
	cin >> t;
	cout << s.isValid(t);
	return 0;
}
