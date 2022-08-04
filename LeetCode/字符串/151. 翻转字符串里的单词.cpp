#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

// 洛谷入门题刷了好多...虽然没什么意思，不过也算是在找题刷吧，像之前那样反而只会焦虑之类的...
// 那么这个题是LeetCode上的水题，意思就是根据空格切分字符串然后倒序输出。因为有可能空格很多，
// 写个循环加判断可能比较麻烦，比较简单的方法是用字符串流，字符串流可以自动去掉空格然后输出。
// 倒序的话用栈或者vector都可以...

class Solution {
public:
	stack<string > st;
    string reverseWords(string s) {
		string temp, res;
		stringstream ss;
		ss << s;
		while (ss >> temp) st.push(temp); 
    	while (st.size()) {
    		res += st.top();st.pop();
    		// 注意是先出栈的 
    		if (st.size() != 0) res += ' ';
		}
        return res;
	}
}; 

int main() {
	string str = "hello world i  love   C++ it is    fun", temp;
	stringstream ss;
	ss << str;
	while (ss >> temp) {
		cout << temp << ' ';
	}
	return 0;
}
