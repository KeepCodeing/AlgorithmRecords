#include <iostream>
#include <algorithm>
using namespace std;
// 给出一串字符，如：Hello World 114514,YJSP810，要求只翻转单词，不翻转数字

// 思路：空格，标点和纯数字不翻转，所以只用判断当前字符串是否需要翻转即可
bool checkReverse(string str) {
	bool flag = true;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			flag = false;
		} else {
			flag = true;
			break;
		}
	} 
	return flag;
}

string reverseWords(string str) {
	// 先将字符串分割为以空格，标点隔开的多个子串
	string tempStr, result;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ' && str[i] != ',' && str[i] != '.') {
			tempStr += str[i];
		} else {
			if (checkReverse(tempStr)) reverse(tempStr.begin(), tempStr.end());
			result += tempStr + str[i];
			tempStr.clear();
		}
	} 
	// 处理最后可能没有被处理的字符串（低级写法） 
	if (str[str.length() - 1] != '.') {
		if (checkReverse(tempStr)) reverse(tempStr.begin(), tempStr.end());
		result += tempStr;
	}
	return result;
}

 
int main() {
	cout << reverseWords("Hello World 114514,YJSP810.1919.") << endl;
	return 0;
}
