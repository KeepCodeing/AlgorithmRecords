#include <iostream>
char stk[130];
using namespace std;
bool check(char c) {
	return c == '(' || c == '[' || c == '{';
}
bool cmpChar(char a, char b) {
	if (a == '(') {
		if (b == ')') return true;
		return false;
	}
	if (a == '[') {
		if (b == ']') return true;
		return false;
	}
	if (a== '{') {
		if (b == '}') return true;
		return false;
	}
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		int tt = -1;
		bool flag = true;
		for (int i = 0; i < str.size(); i++) {
			// 正括号入栈，出现反括号出栈对比 
			if (check(str[i])) {
				stk[++tt] = str[i];
			} else {
				// 如果栈为空，但是又出现了反括号，则一定无解 
				if (tt == -1) {
					cout << "No" << endl;
					flag = false;
					break;
				}
				// cout << stk[tt--] << ' ' << str[i] << endl;
				// 如果括号不匹配也无解 
				if (!cmpChar(stk[tt--], str[i])) {
					cout << "No" << endl;
					flag = false;
					break;
				}
			}
		}
		if (flag) cout << "Yes" << endl;
	}
	return 0;
}
