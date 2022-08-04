#include <iostream>
using namespace std;

// 想了半天思路大概就是用个桶统计下字母出现次数，理想情况下或许是可行的
// 不过现在想来能成也是很奇妙了
// 但是可以写个暴力，从短到长截取子串，然后和后面的串对比，任意字符不同
// 就跳出，如果对比完了都没有跳出就说明答案出来了，这么一看这个题似乎
// 还是个滑动窗口+hash的题... 
// 新方法，大发现，其实先可以按照滑动窗口的思路来截取子串，然后利用
// count()函数去原串里找，再利用count()的返回值乘上子串的长度，如果
// 这个结果等于原串长度，则说明出现了答案，草，count()函数不能查找字符串.. 

// 原字符，要统计个数的字符，步长 
int countStr(string s, string t, int r) {
	int cnt = 0;
	// 字符串按步长进行对比的正确方式... 
	for (int i = 0; i < s.size(); i += r) cnt += s.substr(i, r) == t ? 1 : 0;
	return cnt;
}

int main() {
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 1; i <= sLen; i++) {
		// 截取a~a+i的字符，
		int maxLen = countStr(str, str.substr(0, i), i);
		if (i * maxLen == sLen) {
			cout << maxLen;
			break;
		}
	}
	return 0;
} 
