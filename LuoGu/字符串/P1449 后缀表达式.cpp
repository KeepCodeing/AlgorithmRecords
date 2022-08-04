#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

// 前置知识：
/*
- 前缀表达式遵循先序：中左右
- 中缀表达式遵循中序：左中右
- 后缀表达式遵循后序：左右中
只要记住：什么表达式就是什么序，什么序就是'中'在哪个位置，这里中表示操作符的位置...
这三种表达式都可以借用栈来实现，具体方法如下：
以后缀表达式为例，它的处理方式和哈夫曼树类似，首先如果读入的是数字，将其压入栈中，如果读取到的是操作符，
将栈顶两个元素弹出，并且进行相应操作，然后将结果继续压入栈中重复，直到栈里只剩一个元素... 
*/ 

int str2num (string num) {
	stringstream ss;
	int res = 0;
	ss << num, ss >> res;
	return res;
}
bool check(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}
stack<long long > st;
int main() {
	string str, num = "";
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			num += str[i];
		} else {
			// 当当前字符是.或者操作符时，将统计到的字符串转换为数字，然后压到栈里，因为可能出现+++之类的非数字
			// 字符连续出现，故而还要判断下当前字符是否合法... 
			if (num != "") st.push(str2num(num)); 
			num = "";
			if (check(str[i])) {
				// 先进后出 
				int b = st.top();st.pop();
				int a = st.top();st.pop();
//				cout << a << str[i] << b << endl;
				int res;
				switch(str[i]) {
					case '+' : 
						res = a + b;
						break;
					case '-' : 
						res = a - b;
						break;
					case '*' : 
						res = a * b;
						break;
					case '/' :
						// 这个题目有个坑点，那就是没说还有整除这种操作... 
						res = a / b;
						break;
				}
				st.push(res);
			}
			
		}
	}
	// 最后一定只剩一个数字.. 
	cout << st.top();
	return 0;
}
