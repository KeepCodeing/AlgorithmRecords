#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str;
	cin >> str;
	// 用这种无脑写法居然过了50%的数据... 
//	swap(str[str.size() - 2], str[str.size() - 1]);
//	cout << str;
// 正解是利用STL里的next_permutation()函数生成下一个排列
// 这个排列一定是按字典序来的，也就是第一个大于当前字符串的
// 字符串，另外还有pre_purmutation()，可以生成上一个字典序的字符串
	next_permutation(str.begin(), str.end());
	cout << str; 
	return 0;
}
