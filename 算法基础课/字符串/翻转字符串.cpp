#include <iostream>
#include <algorithm>
using namespace std;
// 给定一个字符串，要求将其翻转过来 
// 思路：两种方法，利用额外空间存储和使用STL函数 
int main() {
	string a = "Hello";
	string b = "World";
	string temp;
	for (int i = a.size() - 1; i >= 0; i--) {
		temp += a[i];
	}
	cout << temp << endl;
	reverse(b.begin(), b.end());
	cout << b << endl;
	return 0;
}
