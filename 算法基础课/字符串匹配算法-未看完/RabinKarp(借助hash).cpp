#include <iostream>
using namespace std;
// 暴力法匹配字符：首先从字符串A开头遍历，每次都判断当前字符是否与B的开头字符相同，
// 相同则继续匹配，如果匹配失败，就继续往后遍历，效率太低 
// RabinKarp算法：滑动对比，首先获取B字符串的hash值，再从A字符开头获取B字符串长度的字符
// 对比它们的hash值，不同则将A中的对比局域向后滑动一位，这个算法并不能对提升效率有很大的
// 帮助，不过思想值得学习 
const int seed = 31;
// 自定义的hash值算法，在数据量过大的情况下不能保证hash值唯一 
long getHashCode(string str) {
	long hash = 0;
	for (int i = 0; i < str.size(); i++) hash = hash * seed + (int)str[i]; 
	return hash % 1145141919;
} 
// string 类自带的substr方法有些小问题，字符串"12345" 调用substr(0,2)返回"12"，调用substr(1,2)返回"23"
// 所以自己写了一个 ，substr方法似乎截取的是从a点向后便宜b个单位的子串，而不是下标a到下标b... 
string strSub(string str, int start, int end) {
	string result;
	for (int i = start; i <= end; i++) {
		result += str[i];
	}
	return result;
}
bool matchStr(string a, string b) {
	// 匹配字符的核心算法，每次向后滑动对比hash值
	int aSize = a.size(), bSize = b.size(); 
	for (int i = 0; i < aSize - bSize + 1; i++) {
		// cout << i << ' ' << i + bSize << endl;
		// cout << strSub(a, i, i + bSize - 1) << endl;
		// subStr方法里是<=end，故减一 
		if (getHashCode(strSub(a, i, i + bSize - 1)) == getHashCode(b)) return true;
	}
	return false;
}
int main() {
	string a, b;
	 cin >> a >> b;
	 cout << matchStr(a, b) << endl;
	return 0;
}
