#include <iostream>
#include <map>
using namespace std;
// 给出一串字符，形如(())，{()}等，要求判断其是否是合法括号，()，[]，{}等都是合法括号

// 分析：如果把整个字符串看成一个整体，解题就比较复杂了，而如果一个个字符看，判断')'前面
// 是不是'('，']'，'}'等同理，可以用栈来写，但是之前写过了，尝试用递归写 

string str;
bool flag = true;
char visited[100] = {' '};
map<char, char > m;
// level用来标记当前是字符串中的那个字符 
char solve(char c, int level) {
	// 不对称退出 
	if (str.size() % 2 != 0) {
		flag = false;
		return ' ';
	}
	if (level >= str.size()) return ' ';
	// 遇到反括号返回，和前面的括号对比
	if (c == ')' || c == ']' || c == '}') {
		// cout << c << endl;
		return c;
	}
	for (int i = 1; i <= str.size() / 2; i++) {
		if (visited[i] == ' ') continue;
		visited[i] = c;
		cout << solve(str[level + i], level + 1) << endl;
		visited[i] = c;
	}
	
	// cout << c << endl;
}
int main() {
	m['('] = ')', m['{'] = '}', m['['] = ']';
	cin >> str;
	// ([{}])
	solve(str[0], 0);
	return 0;
}
