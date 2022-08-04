#include <iostream>
#include <algorithm>
using namespace std;

// 递归对两部分字符串求解即可 
// 屑算法每次都截取一个新字符串所以效率很低，可以只记录位置 

void t(string str) {
	if (count(str.begin(), str.end(), '0') == str.size()) {
		cout << "A";
		return;
	}
	if (count(str.begin(), str.end(), '1') == str.size()) {
		cout << "B";
		return;
	}
	int sLen = str.size() / 2;
	cout << "C";
	t(str.substr(0, sLen));
	t(str.substr(sLen));
}
int main() {
	string str;
	cin >> str;
	t(str);
	return 0;
}
