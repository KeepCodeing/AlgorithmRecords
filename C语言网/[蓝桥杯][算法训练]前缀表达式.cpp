#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
stack<int > st;
bool isnum(char n) {
	return '0' <= n && n <= '9'; 
}
int str2num(string str) {
	int res;
	stringstream ss;
	ss << str, ss >> res;
	return res;
}
int main() {
	string str, temp;
	cin >> str;
	int sLen = str.size();
	char pre;
	for (int i = 0; i < sLen; i++) {
		if (isnum(i)) {
			temp += str[i];
		} else {
			pre = str[i];
			if (!temp.empty()) st.push(str2num(temp)); 
			if (st.size() >= 2) {
				int a = st.top();st.pop();
				int b = st.top();st.pop();
				switch(pre) {
					case
				}
			}
			temp = "";
		}
	}
	return 0;
}
