#include <iostream>
#include <algorithm>
using namespace std;
// 给定一个offset，和一个字符串，要求将最后一个字符移动最前面offset次

// 思路：和走马灯很类似，关键要注意offset的值，它可能是0，可能是n，也可能大于或者小于n，
// 针对不同情况可以写不同的处理 

string offsetLow(string str, int offset) {
	// offset小于字符串长度时，可以把后offset个字符翻转，然后加上
	// 前n - offset个字符
	string result;
	for (int i = offset - 1; i <= str.size() - 1; i++) {
		result += str[i];
	} 
	for (int i = 0; i <= str.size() - offset - 1; i++) {
		result += str[i];
	}
	return result;
} 

string offsetHigh(string str, int offset) {
	// oHell
	// loHel
	// lloHe
	// elloH
	// Hello
	// oHell 
	// loHel
	// lloHe
	// elloH
	// Hello
	// 如果offset大于n， 那么只需要将后offset%n个单词放前面即可
	// （因为offset%n == 0的情况已经被排除了） 
	string result;
	for (int i = str.size() - offset % str.size(); i <= str.size() - 1; i++) {
		result += str[i];
	}
	for (int i = 0; i <= str.size() - offset % str.size() - 1; i++) {
		result += str[i];
	}
	return result;
}

string rotateString(string str, int offset) {
	if (offset == 0) return str;
	if (offset % str.size() == 0) {
		reverse(str.begin(), str.end());
		return str;
	}
	if (offset < str.size()) return offsetLow(str, offset);
	if (offset > str.size()) return offsetHigh(str, offset);
}

int main() {

	cout << rotateString("Hello", 7);
	return 0;
}
