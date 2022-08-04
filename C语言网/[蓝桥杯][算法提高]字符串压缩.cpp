#include <iostream>
using namespace std;
const int N = 300;
int bucket[N];
int main() {
	string str;
	// 题目说可能有空格，估计不止一个字符串.. 
	getline(cin, str);
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) {
		int t = ++bucket[str[i]];
		if ((t != 1 && t != 3 && t != 6) && str[i] != ' ') continue;
		cout << str[i];
	} 
	return 0;
} 
