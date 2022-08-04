#include <iostream>
#include <algorithm>
using namespace std;
// 给定一个字符串如acbac，该字符串从左边读或从右边读都一样，故为回文串
// 写程序判断某个字符是否是回文串 
// 判断字符是否是回文串只需要将其翻转再对比是否与原字符串相同即可 
bool hwStr(string s) {
	string temp = s;
	reverse(temp.begin(), temp.end());
	return (s == temp);
}
// 形如1221的数字成为回文数字，要求输出四位数中所有这种形式的数
// 思路：可以把这种数简化为ijji形式，可以看成，i作为开头不能等于0
// 所以可以写两层循环，输出i*1000+j*100+j*10+i，即题解
// 这题考虑的主要是回文串的形式，而不是怎么才能满足回文串 
void printHwNum() {
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << (i*1000 + j * 100 + j * 10 + i) << endl; 
		}
	}
} 
int main() {
	printHwNum();
	return 0;
}
