#include <iostream>
using namespace std;
// 给定一个字符串，要求将其中的空格替换为%20
// 思路：利用字符串的replace方法，C++中的replace()方法与其他OOP语言略有不同
// 首先，指定从哪里开始替换，再指定替换多少个字符，还有用什么字符替换 
int main() {
	string a = "Hello World C++ IS NOT GOD";
	// 这里可以一次只替换一个空格，直到所有空格都没了
	while(true) {
		int index = a.find(" ");
		// 注意这里的find方法，如果找不到元素了，它会返回一个特殊标记，可以用字符串.npos来获取 
		if (index == a.npos) break;
		// 依次替换所有空格 
		a.replace(index, 1, "%20");
	} 
	cout << a << endl;
	return 0;
}
