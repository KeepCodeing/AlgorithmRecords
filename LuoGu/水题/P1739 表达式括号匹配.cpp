#include <iostream>
#include <cstdio>
using namespace std;

// 栈的应用 
// 草，题目里有神必字符，string读取不能，不过题解里的解法也比较好 
// RE的真正原因：栈为空但依然非法读取，删除 
/*else if (c == ')') {
			if (!s.empty() && s.size() > 0) {
				if (s.top() != '(') {
					flag = false;
					break;
				}
			}
			if (!s.empty() && s.size() > 0) s.pop();
		}*/
		
// 改了三回，谔谔 
int main() {
	char c;
	// 改用计数 
	int left = 0, right = 0;
	while ((c = getchar()) != '@') {
		if (c == '(') {
			left++; 
		} else if (c == ')') {
			right++;
		}
		if (right > left) {
			cout << "NO";
			return 0;
		} 
	}
	// 少判断了一点，如果右括号多余左括号，还有就是
	// 没有左括号的情况 
	cout << (left == right ? "YES" : "NO");
	return 0;
}
